//
// IntroView.cpp for IntroView in /home/magrin_j/Project/Bomberman
//
// Made by Jérémy Magrin
// Login   <magrin_j@epitech.net>
//
// Started on  Sat Jun  1 16:36:39 2013 Jérémy Magrin
// Last update Sat Jun  8 12:57:22 2013 leo chazal
//

#include	<OpenGL/gl.h>
#include	<OpenGL/glu.h>
#include	"bomberman.hh"
#include	"IntroView.hh"
#include	"Intro.hh"
#include	"Drawable.hh"

#include <iostream>

Bomberman::IntroView::IntroView()
{
  this->initialize();
}

Bomberman::IntroView::~IntroView()
{

}

void					Bomberman::IntroView::initialize()
{
  this->_image = gdl::Image::load(INTRO_BACKGROUND);
  this->_title = gdl::Image::load(INTRO_TITLE);
  this->_bomb = gdl::Image::load(INTRO_BOMB);
  this->_fire = gdl::Image::load(INTRO_FIRE);
}

void	Bomberman::IntroView::draw(const Bomberman::AModel *model)
{
  const Bomberman::Intro	*intro = dynamic_cast<const Bomberman::Intro *>(model);
  std::list<Bomberman::BInfo>	bombs = intro->getState();

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  Bomberman::Drawable::pushOrthoMatrix(1, 1);
  Bomberman::Drawable::drawAt(0, 0, 1, 1, this->_image);
  for (std::list<Bomberman::BInfo>::const_iterator it = bombs.begin();
       it != bombs.end(); it++)
    {
      if ((*it).lit)
	intro->getTicks() >= 200 ?
	  Bomberman::Drawable::drawAt((*it).x, (*it).y,
				      (*it).x + .3, (*it).y + .3,
				      this->_fire) :
	  Bomberman::Drawable::drawAt((*it).x, (*it).y,
				      (*it).x + .1, (*it).y + .1,
				      this->_bomb);
    }
  if (intro->getTicks() >= 200)
    Bomberman::Drawable::drawAt(0, .25, 1, .75, this->_title);
  glDisable(GL_BLEND);
  Bomberman::Drawable::popOrthoMatrix();
}
