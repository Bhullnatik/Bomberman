//
// MainMenuCredit.cpp for Bomberman in /home/magrin_j/Project/Bomberman
//
// Made by Jérémy Magrin
// Login   <magrin_j@epitech.net>
//
// Started on  Sun Jun  9 13:44:05 2013 Jérémy Magrin
// Last update Sun Jun  9 20:54:20 2013 jimmy mayoukou
//

#include	"MainMenuCreditView.hh"
#include	"MainMenuCredit.hh"
#include	"Data.hpp"
#include	"Sound.hh"
#include	"KeyHandler.hh"

Bomberman::MainMenuCredit::MainMenuCredit(Bomberman::Game *game) :
  Bomberman::AModel(new Bomberman::MainMenuCreditView())
{
  this->_text.setFont("./assets/fonts/bm.ttf");
  this->_game = game;
  this->_width = this->_game->getWindow().getWidth();
  this->_height = this->_game->getWindow().getHeight();
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  this->_view->initialize();
}

Bomberman::MainMenuCredit::~MainMenuCredit()
{

}

void			Bomberman::MainMenuCredit::draw()
{
  this->_view->draw(this);
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
  glPopMatrix();
  glPopAttrib();
}

void	Bomberman::MainMenuCredit::update(const gdl::GameClock &, gdl::Input &input)
{
  Bomberman::Sound::getInstance()->playTrack(T_CREDIT);
  this->_width = this->_game->getWindow().getWidth();
  this->_height = this->_game->getWindow().getHeight();
  if (KeyHandler::handle(input, gdl::Mouse::Left) || KeyHandler::handle(input, gdl::Keys::Escape))
    this->_game->popCurrentView();
}

Bomberman::MyText	Bomberman::MainMenuCredit::getText(void) const
{
  return (this->_text);
}
