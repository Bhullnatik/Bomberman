//
// TileView.cpp for bomberman in /home/chazal_l//Ydrasaal/PROJECT/Bomberman/Bomberman
//
// Made by leo chazal
// Login   <chazal_l@epitech.net>
//
// Started on  Wed May 15 21:09:41 2013 leo chazal
// Last update Fri Jun  7 17:33:26 2013 leo chazal
//

#include        <OpenGL/gl.h>
#include        <OpenGL/glu.h>

#include	"bomberman.hh"
#include	"Tile.hh"
#include	"TileView.hh"
#include	"Data.hpp"

Bomberman::TileView::TileView()
{
  this->initialize();
}

Bomberman::TileView::~TileView()
{

}

Bomberman::TileView      *Bomberman::TileView::getInstance(void)
{
  static TileView        *instance = new TileView();

  return (instance);
}

void                    Bomberman::TileView::initialize(void)
{
  this->_texture[Bomberman::T_METAL] = gdl::Image::load(TEXT_FLOOR_METAL);
  this->_texture[Bomberman::T_ICE] = gdl::Image::load(TEXT_FLOOR_ICE);
  this->_texture[Bomberman::T_CURSE] = gdl::Image::load(TEXT_FLOOR_CURSED);
  this->_texture[Bomberman::T_SKY] = gdl::Image::load(TEXT_FLOOR_SKY);
  this->_texture[Bomberman::T_SAND] = gdl::Image::load(TEXT_FLOOR_SAND);
}

void                    Bomberman::TileView::draw(const AModel *)
{
  this->_texture[Bomberman::Data::getInstance()->getLevelType()].bind();

  glBegin(GL_QUADS);

  glColor3f(1.0f, 0.50f, 0.75f);
  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(this->_pos.x, this->_pos.y, this->_pos.z);
  glTexCoord2f(0.0f, 1.0f);
  glVertex3f(this->_pos.x, this->_pos.y, this->_pos.z + TILE_SIZE);
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f(this->_pos.x + TILE_SIZE, this->_pos.y, this->_pos.z + TILE_SIZE);
  glTexCoord2f(1.0f, 0.0f);
  glVertex3f(this->_pos.x + TILE_SIZE, this->_pos.y, this->_pos.z);

  glEnd();
}
