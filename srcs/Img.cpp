//
// Img.cpp for Img in /home/magrin_j/Project/Bomberman
//
// Made by Jérémy Magrin
// Login   <magrin_j@epitech.net>
//
// Started on  Sun Jun  2 15:09:45 2013 Jérémy Magrin
// Last update Sat Jun  8 10:33:21 2013 leo chazal
//

#include		<OpenGL/gl.h>
#include		<OpenGL/glu.h>
#include		"Img.hh"

Bomberman::Img::Img()
{

}

Bomberman::Img::~Img()
{

}

void				Bomberman::Img::load(const std::string &filename)
{
  this->_texture = gdl::Image::load(filename);
  this->_width = this->_texture.getWidth();
  this->_height = this->_texture.getHeight();
}

void				Bomberman::Img::draw(void)
{
  this->_texture.bind();
  glBegin(GL_QUADS);

  glTexCoord2f(0.0f, 0.0f);
  glVertex2f(this->_pos.x, this->_pos.y);
  glTexCoord2f(1.0f, 0.0f);
  glVertex2f(this->_pos.x + this->_width, this->_pos.y);
  glTexCoord2f(1.0f, 1.0f);
  glVertex2f(this->_pos.x + this->_width, this->_pos.y + this->_height);
  glTexCoord2f(0.0f, 1.0f);
  glVertex2f(this->_pos.x, this->_pos.y + this->_height);

  glEnd();
}

unsigned int   			Bomberman::Img::getWidth(void) const
{
  return (this->_width);
}

unsigned int   			Bomberman::Img::getHeight(void) const
{
  return (this->_height);
}

void				Bomberman::Img::setPosition(Vector3f pos)
{
  this->_pos = pos;
}

void				Bomberman::Img::setPosition(float x, float y, float z)
{
  this->_pos = Vector3f(x, y, z);
}

void				Bomberman::Img::setSize(float width, float height)
{
  this->_width = width;
  this->_height = height;
}

void				Bomberman::Img::setWidth(float width)
{
  this->_width = width;
}

void				Bomberman::Img::setHeight(float height)
{
  this->_height = height;
}
