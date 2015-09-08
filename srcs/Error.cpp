//
// Error.cpp for Bomberman in /home/magrin_j/Project/Bomberman
//
// Made by Jérémy Magrin
// Login   <magrin_j@epitech.net>
//
// Started on  Sun Jun  9 15:35:47 2013 Jérémy Magrin
// Last update Sun Jun  9 20:52:26 2013 jimmy mayoukou
//

#include	"Error.hh"
#include	"ErrorView.hh"
#include	"KeyHandler.hh"

Bomberman::Error::Error(Bomberman::Game *game, const std::string &error) :
  Bomberman::AModel(new Bomberman::ErrorView()), _error(error)
{
  this->_text.setFont("./assets/fonts/bm.ttf");
  this->_game = game;
  this->_width = this->_game->getWindow().getWidth();
  this->_height = this->_game->getWindow().getHeight();
}

Bomberman::Error::~Error()
{

}

void			Bomberman::Error::draw(void)
{
  this->_view->draw(this);
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
  glPopMatrix();
  glPopAttrib();
}

void			Bomberman::Error::update(const gdl::GameClock &, gdl::Input &input)
{
  this->_width = this->_game->getWindow().getWidth();
  this->_height = this->_game->getWindow().getHeight();
  if (KeyHandler::handle(input, gdl::Mouse::Left) || KeyHandler::handle(input, gdl::Keys::Return))
    this->_game->popCurrentView();
}

int                     Bomberman::Error::getRealPosX(float x)
{
  return (x * (this->_width / 800.));
}

int                     Bomberman::Error::getRealPosY(float y)
{
  return (y * (this->_height / 600.));
}

Bomberman::MyText       Bomberman::Error::getText(void) const
{
  return (this->_text);
}

const std::string&	Bomberman::Error::getErrorMsg(void) const
{
  return (this->_error);
}

float			Bomberman::Error::getWidth(void) const
{
  return (this->_width);
}

float			Bomberman::Error::getHeight(void) const
{
  return (this->_height);
}
