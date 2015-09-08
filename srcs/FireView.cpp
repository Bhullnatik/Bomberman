//
// FireView.cpp for bomberman in /home/chazal_l//Ydrasaal/PROJECT/Bomberman/Bomberman
//
// Made by leo chazal
// Login   <chazal_l@epitech.net>
//
// Started on  Mon May 27 19:24:12 2013 leo chazal
// Last update Fri Jun  7 18:54:24 2013 leo chazal
//

#include        "bomberman.hh"
#include        "Fire.hh"
#include        "FireView.hh"
#include	"Geometrics.hh"

Bomberman::FireView::FireView()
{
  this->initialize();
}

Bomberman::FireView::~FireView()
{

}

Bomberman::FireView	*Bomberman::FireView::getInstance(void)
{
  static FireView	*instance = new FireView();

  return (instance);
}

void			Bomberman::FireView::initialize(void)
{
  this->_texture = gdl::Image::load(TEXT_FIRE);
}

#include	<iostream>

void			Bomberman::FireView::draw(const AModel *model)
{
  const Bomberman::Fire		*fire = dynamic_cast<const Bomberman::Fire *>(model);

  this->setPosition(fire->getX() * TILE_SIZE, 0, fire->getY() * TILE_SIZE);
  Bomberman::Geometrics::cube(this->_texture, this->_pos,
			      TILE_SIZE, TILE_SIZE / 1.2);
}
