//
// MainMenuHome.cpp for MainMenuHome.cpp in /home/hoarau_s/Projets/Bomberman/Bomberman/srcs
//
// Made by stephen hoarau
// Login   <hoarau_s@epitech.net>
//
// Started on  Thu Jun  6 15:29:07 2013 stephen hoarau
// Last update Sun Jun  9 20:54:59 2013 jimmy mayoukou
//

#include	<unistd.h>
#include	"Sound.hh"
#include	"MainMenuHome.hh"
#include	"MainMenuHomeView.hh"
#include	"MainMenuPlaySolo.hh"
#include	"MainMenuOptions.hh"
#include	"Data.hpp"
#include	"KeyHandler.hh"

Bomberman::MainMenuHome::MainMenuHome(Bomberman::Game *game) : Bomberman::AModel(new Bomberman::MainMenuHomeView)
{
  this->_text.setFont("./assets/fonts/bm.ttf");
  this->_game = game;
  this->_width = this->_game->getWindow().getWidth();
  this->_height = this->_game->getWindow().getHeight();
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

Bomberman::MainMenuHome::~MainMenuHome()
{

}

void		Bomberman::MainMenuHome::draw()
{
  this->_view->draw(this);
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
  glPopMatrix();
  glPopAttrib();
}

void		Bomberman::MainMenuHome::update(const gdl::GameClock &, gdl::Input &input)
{
  this->_width = this->_game->getWindow().getWidth();
  this->_height = this->_game->getWindow().getHeight();

  if (KeyHandler::handle(input, gdl::Mouse::Left))
    {
      int		x = input.getMousePositionX();
      int		y = input.getMousePositionY();

      if ((x >=  getRealPosX(315)  && x <= getRealPosX(480)) &&
	  (y >=  getRealPosY(240)  && y  <= getRealPosY(300)))
	this->_game->setCurrentView(new Bomberman::MainMenuPlaySolo(this->_game));
      else if ((x <= getRealPosX(450) && x >= getRealPosX(350)) &&
	       (y >= getRealPosY(550) && y <= getRealPosY(600)))
	this->_game->setCurrentView(new Bomberman::MainMenuOptions(this->_game));
      Bomberman::Sound::getInstance()->playTrack(T_MENU);
    }
}

int	Bomberman::MainMenuHome::getRealPosX(float x)
{
  return (x * (this->_width / 800.));
}

int	Bomberman::MainMenuHome::getRealPosY(float y)
{
  return (y * (this->_height / 600));
}

Bomberman::MyText	Bomberman::MainMenuHome::getText() const
{
  return (this->_text);
}

