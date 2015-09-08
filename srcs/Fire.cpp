//
// Fire.cpp for bomberman in /home/chazal_l//Ydrasaal/PROJECT/Bomberman/Bomberman
//
// Made by leo chazal
// Login   <chazal_l@epitech.net>
//
// Started on  Mon May 27 19:18:44 2013 leo chazal
// Last update Fri Jun  7 18:23:09 2013 leo chazal
//

#include	"Fire.hh"
#include	"FireView.hh"

Bomberman::Fire::Fire()
  : AModel(Bomberman::FireView::getInstance())
{

}

Bomberman::Fire::Fire(size_t x, size_t y)
  : AModel(Bomberman::FireView::getInstance()),
    _tick(FIRE_TICKS), _x(x), _y(y), _burning(true)
{

}

Bomberman::Fire::~Fire()
{

}

void		Bomberman::Fire::draw(void)
{
  this->_view->draw(this);
}

void		Bomberman::Fire::update(const gdl::GameClock &, gdl::Input &)
{
  this->_tick--;
  if (!this->_tick)
    this->_burning = false;
}

bool		Bomberman::Fire::isBurning(void) const
{
  return (this->_burning);
}

size_t          Bomberman::Fire::getX(void) const
{
  return (this->_x);
}

size_t          Bomberman::Fire::getY(void) const
{
  return (this->_y);
}

size_t		Bomberman::Fire::getTicks(void) const
{
  return (this->_tick);
}
