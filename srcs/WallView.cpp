//
// WallView.cpp for bomberman in /home/chazal_l//Ydrasaal/PROJECT/Bomberman/Bomberman
//
// Made by leo chazal
// Login   <chazal_l@epitech.net>
//
// Started on  Thu May 16 16:54:47 2013 leo chazal
// Last update Fri Jun  7 17:33:44 2013 leo chazal
//

#include        "bomberman.hh"
#include        "Wall.hh"
#include        "WallView.hh"
#include	"Geometrics.hh"
#include	"Data.hpp"

Bomberman::WallView::WallView()
{
  this->initialize();
}

Bomberman::WallView::~WallView()
{

}

Bomberman::WallView      *Bomberman::WallView::getInstance(void)
{
  static WallView        *instance = new WallView();

  return (instance);
}

void                    Bomberman::WallView::initialize(void)
{
  this->_texture[Bomberman::T_METAL] = gdl::Image::load(TEXT_WALL_METAL);
  this->_texture[Bomberman::T_ICE] = gdl::Image::load(TEXT_WALL_ICE);
  this->_texture[Bomberman::T_CURSE] = gdl::Image::load(TEXT_WALL_CURSED);
  this->_texture[Bomberman::T_SKY] = gdl::Image::load(TEXT_WALL_SKY);
  this->_texture[Bomberman::T_SAND] = gdl::Image::load(TEXT_WALL_SAND);
}

void                    Bomberman::WallView::draw(const AModel *)
{
  Bomberman::Type	type = Bomberman::Data::getInstance()->getLevelType();

  if (type == Bomberman::T_SAND)
    Bomberman::Geometrics::pyramid(this->_texture[type], this->_pos);
  else
    Bomberman::Geometrics::cube(this->_texture[type], this->_pos);
}
