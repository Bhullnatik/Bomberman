//
// Bomb.cpp for bomberman in /home/chazal_l//Ydrasaal/PROJECT/Bomberman/Bomberman
//
// Made by leo chazal
// Login   <chazal_l@epitech.net>
//
// Started on  Fri May 24 12:52:36 2013 leo chazal
// Last update Sun Jun  9 18:46:55 2013 jimmy mayoukou
//

#include	"Bomb.hh"
#include	"BombView.hh"

#include	<iostream>

Bomberman::Bomb::Bomb(size_t id, size_t x, size_t y, size_t pwr) : AElement(new Bomberman::BombView(), Bomberman::BOMB, true)
{
  this->_tick = BLOWUP_TICKS;
  this->_id = id;
  this->_posX = x;
  this->_posY = y;
  this->_pwr = pwr;
  this->_blown = false;
}

Bomberman::Bomb::Bomb(const Bomberman::Save::Bomb &save) : AElement(new Bomberman::BombView(), Bomberman::BOMB, true)
{
  this->_tick = save.tick;
  this->_id = save.id;
  this->_posX = save.posX;
  this->_posY = save.posY;
  this->_pwr = save.power;
  this->_blown = false;
}

Bomberman::Bomb::~Bomb(void)
{

}

void	Bomberman::Bomb::draw(void)
{
  this->_view->draw(this);
}

void			Bomberman::Bomb::update(const gdl::GameClock &gameClock, gdl::Input &)
{
  Bomberman::BombView	*bombView = static_cast<Bomberman::BombView*>(this->_view);

  this->_tick--;
  if (!this->_tick)
    this->_blown = true;
  bombView->getModel().update(gameClock);
  bombView->runAnim("grow");
}

bool		Bomberman::Bomb::blewUp(void) const
{
  return (this->_blown);
}

void	Bomberman::Bomb::onFire(void)
{
  this->_blown = true;
}

size_t	Bomberman::Bomb::getX(void) const
{
  return (this->_posX);
}

size_t	Bomberman::Bomb::getY(void) const
{
  return (this->_posY);
}

size_t	Bomberman::Bomb::getPower(void) const
{
  return (this->_pwr);
}

size_t	Bomberman::Bomb::getId(void) const
{
  return (this->_id);
}

size_t	Bomberman::Bomb::getTicks(void) const
{
  return (this->_tick);
}

void	Bomberman::Bomb::serialize(std::ostream &stream) const
{
  Bomberman::Save::Bomb	save(this);

  stream.write((char *) &save, sizeof(save));
}
