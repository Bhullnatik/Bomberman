//
// Background.cpp for Bomberman in /home/magrin_j/Project/Bomberman
//
// Made by Jérémy Magrin
// Login   <magrin_j@epitech.net>
//
// Started on  Fri Jun  7 17:11:01 2013 Jérémy Magrin
// Last update Sun Jun  9 22:03:26 2013 leo chazal
//

#include		<OpenGL/gl.h>
#include		<OpenGL/glu.h>
#include		"Drawable.hh"
#include		"bomberman.hh"

#include	<iostream>

Bomberman::Drawable::Drawable()
{
  this->initialize();
}

Bomberman::Drawable::~Drawable()
{

}

Bomberman::Drawable	*Bomberman::Drawable::getInstance(void)
{
  static Bomberman::Drawable	*instance = new Bomberman::Drawable();

  return (instance);
}

void			Bomberman::Drawable::drawAt(float x, float y,
						    float xTo, float yTo,
						    gdl::Image &img)
{
  img.bind();
  glBegin(GL_QUADS);
  glTexCoord2f(0, 0);
  glVertex2f(x, y);
  glTexCoord2f(1, 0);
  glVertex2f(xTo, y);
  glTexCoord2f(1, 1);
  glVertex2f(xTo, yTo);
  glTexCoord2f(0, 1);
  glVertex2f(x, yTo);
  glEnd();
}

void	Bomberman::Drawable::pushOrthoMatrix(float x, float y)
{
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  glOrtho(0, x, y, 0, -1, 1);
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glLoadIdentity();
  glDisable(GL_DEPTH_TEST);
}

void	Bomberman::Drawable::popOrthoMatrix(void)
{
  glEnable(GL_DEPTH_TEST);
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
  glPopMatrix();
}

void	Bomberman::Drawable::initialize(void)
{
  this->_drawables[0] = gdl::Image::load(BG_METAL);
  this->_drawables[1] = gdl::Image::load(BG_ICE);
  this->_drawables[2] = gdl::Image::load(BG_CURSE);
  this->_drawables[3] = gdl::Image::load(BG_SKY);
  this->_drawables[4] = gdl::Image::load(BG_SAND);
  this->_drawables[5] = gdl::Image::load(BG_LOBBY);
  this->_drawables[6] = gdl::Image::load(BG_LOAD);
  this->_drawables[7] = gdl::Image::load(BG_CREDIT);
  this->_drawables[8] = gdl::Image::load(BG_PAUSE);
  this->_drawables[9] = gdl::Image::load(BG_PRELOAD);
  this->_drawables[10] = gdl::Image::load(BG_ERROR);
}

void	Bomberman::Drawable::drawBg(size_t id)
{
  Bomberman::Drawable::pushOrthoMatrix(1, 1);
  Bomberman::Drawable::drawAt(0, 0, 1, 1, this->_drawables[id]);
  Bomberman::Drawable::popOrthoMatrix();
}
