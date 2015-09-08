//
// MenuOptions.cpp for  in /home/hoarau_s/Projets/Bomberman/Bomberman/srcs
//
// Made by stephen hoarau
// Login   <hoarau_s@epitech.net>
//
// Started on  Thu Jun  6 15:40:42 2013 stephen hoarau
// Last update Sun Jun  9 20:56:13 2013 jimmy mayoukou
//

#include	<unistd.h>
#include	"Sound.hh"
#include	"MainMenuOptions.hh"
#include	"MainMenuOptionsView.hh"
#include	"Data.hpp"
#include	"KeyHandler.hh"

Bomberman::MainMenuOptions::MainMenuOptions(Bomberman::Game *game) : Bomberman::AModel(new Bomberman::MainMenuOptionsView)
{
  this->_text.setFont("./assets/fonts/bm.ttf");
  this->_game = game;
  this->_width = this->_game->getWindow().getWidth();
  this->_height = this->_game->getWindow().getHeight();
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

Bomberman::MainMenuOptions::~MainMenuOptions()
{

}

void		Bomberman::MainMenuOptions::draw()
{
  this->_view->draw(this);
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
  glPopMatrix();
  glPopAttrib();
}

void		Bomberman::MainMenuOptions::update(const gdl::GameClock &, gdl::Input &input)
{
  this->_width = this->_game->getWindow().getWidth();
  this->_height = this->_game->getWindow().getHeight();

  if (KeyHandler::handle(input, gdl::Mouse::Left))
    this->_game->popCurrentView();
}

int	Bomberman::MainMenuOptions::getRealPosX(float x)
{
  return (x * (this->_width / 800.));
}

int	Bomberman::MainMenuOptions::getRealPosY(float y)
{
  return (y * (this->_height / 600));
}

Bomberman::MyText	Bomberman::MainMenuOptions::getText() const
{
  return (this->_text);
}

