//
// Block.cpp for Bomberman in /home/magrin_j/Project/Bomberman/Local/Dev
//
// Made by magrin_j
// Login   <magrin_j@epitech.net>
//
// Started on  Mon May 13 10:58:20 2013 magrin_j
// Last update Tue Jun  4 15:39:54 2013 leo chazal
//

#include		<OpenGL/gl.h>
#include		<OpenGL/glu.h>
#include		"Block.hh"
#include		"BlockView.hh"

#include		<iostream>

Bomberman::Block::Block()
  : AElement(Bomberman::BlockView::getInstance(), Bomberman::BLOCK, true)
{

}

Bomberman::Block::~Block()
{

}

Bomberman::Block	*Bomberman::Block::getInstance(void)
{
  static Block		*instance = new Block();

  return (instance);
}

void			Bomberman::Block::draw()
{
  this->_view->draw(this);
}

void			Bomberman::Block::update(const gdl::GameClock &, gdl::Input &)
{

}

void			Bomberman::Block::onFire(void)
{

}
