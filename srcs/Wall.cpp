//
// Wall.cpp for bomberman in /home/chazal_l//Ydrasaal/PROJECT/Bomberman/Bomberman
//
// Made by leo chazal
// Login   <chazal_l@epitech.net>
//
// Started on  Thu May 16 16:52:35 2013 leo chazal
// Last update Tue Jun  4 15:39:21 2013 leo chazal
//

#include                <OpenGL/gl.h>
#include                <OpenGL/glu.h>
#include                "Wall.hh"
#include                "WallView.hh"

#include                <iostream>

Bomberman::Wall::Wall()
  : AElement(Bomberman::WallView::getInstance(), Bomberman::WALL, true)
{

}

Bomberman::Wall::~Wall()
{

}

Bomberman::Wall        *Bomberman::Wall::getInstance(void)
{
  static Wall          *instance = new Wall();

  return (instance);
}

void                    Bomberman::Wall::draw()
{
  this->_view->draw(this);
}

void                    Bomberman::Wall::update(const gdl::GameClock &, gdl::Input &)
{

}

void			Bomberman::Wall::onFire(void)
{

}
