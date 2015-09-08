//
// BlockView.cpp for bomberman in /home/chazal_l//Ydrasaal/PROJECT/Bomberman/Bomberman
//
// Made by leo chazal
// Login   <chazal_l@epitech.net>
//
// Started on  Wed May 15 19:43:49 2013 leo chazal
// Last update Fri Jun  7 17:34:14 2013 leo chazal
//

#include	"bomberman.hh"
#include	"Block.hh"
#include	"BlockView.hh"
#include	"Geometrics.hh"
#include	"Data.hpp"

Bomberman::BlockView::BlockView()
{
  this->initialize();
}

Bomberman::BlockView::~BlockView()
{

}

Bomberman::BlockView      *Bomberman::BlockView::getInstance(void)
{
  static BlockView        *instance = new BlockView();

  return (instance);
}

void                    Bomberman::BlockView::initialize(void)
{
  this->_texture[Bomberman::T_METAL] = gdl::Image::load(TEXT_BLOCK_METAL);
  this->_texture[Bomberman::T_ICE] = gdl::Image::load(TEXT_BLOCK_ICE);
  this->_texture[Bomberman::T_CURSE] = gdl::Image::load(TEXT_BLOCK_CURSED);
  this->_texture[Bomberman::T_SKY] = gdl::Image::load(TEXT_BLOCK_SKY);
  this->_texture[Bomberman::T_SAND] = gdl::Image::load(TEXT_BLOCK_SAND);
}

void                    Bomberman::BlockView::draw(const AModel *)
{
  Bomberman::Geometrics::cube(this->_texture[Bomberman::Data::getInstance()->getLevelType()],
			      this->_pos);
}
