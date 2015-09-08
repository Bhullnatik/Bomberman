//
// Warfare.cpp for bomberman in /home/chazal_l//Ydrasaal/PROJECT/Bomberman/Bomberman
//
// Made by leo chazal
// Login   <chazal_l@epitech.net>
//
// Started on  Thu May 30 16:43:16 2013 leo chazal
// Last update Sun Jun  9 18:51:47 2013 jimmy mayoukou
//

#include	"Warfare.hh"
#include	"Map.hh"
#include	"Bomb.hh"
#include	"Sound.hh"

Bomberman::Warfare::Warfare(Bomberman::Map &map)
  : AModel(NULL), _map(map)
{
  this->_triggered = false;
}

Bomberman::Warfare::~Warfare()
{
}

void	Bomberman::Warfare::draw(void)
{
  for (std::list<Bomberman::Fire *>::iterator it = this->_fire.begin();
       it != this->_fire.end(); it++)
    (*it)->draw();
}

void	Bomberman::Warfare::update(const gdl::GameClock &clock, gdl::Input &input)
{
  for (std::list<Bomberman::Fire *>::iterator it = this->_fire.begin();
       it != this->_fire.end(); it++)
    {
      (*it)->update(clock, input);
      if (!(*it)->isBurning())
	{
	  this->_fire.erase(it);
	  delete (*it);
	  break;
	}
    }
  for (std::list<Bomberman::Bomb *>::iterator it = this->_bombs.begin();
       it != this->_bombs.end(); it++)
    if ((*it)->blewUp())
      this->_triggered = true;
  if (this->_triggered)
    this->trigger();
}

void		Bomberman::Warfare::initialize(void)
{

}

void		Bomberman::Warfare::trigger(void)
{
  while (this->_triggered)
    {
      this->_triggered = false;
      for (std::list<Bomberman::Bomb *>::iterator it = this->_bombs.begin();
	   it != this->_bombs.end(); it++)
	if ((*it)->blewUp())
	  {
	    this->_trail.push_back(std::pair<size_t, size_t>((*it)->getX() / TILE_SIZE,
	    						    (*it)->getY() / TILE_SIZE));
	    this->fireTrail((*it)->getX() / TILE_SIZE,
			    (*it)->getY() / TILE_SIZE,
			    Bomberman::NONE, (*it)->getPower());
	    this->_map.removeItem((*it)->getX() / TILE_SIZE, (*it)->getY() / TILE_SIZE);
	    Bomberman::Sound::getInstance()->playSound(T_EXPLODE);
	    this->_bombs.erase(it);
	    delete (*it);
	    this->_triggered = true;
	    break;
	  }
    }
  this->burnIt();
}

void            Bomberman::Warfare::fireTrail(size_t x, size_t y,
					      Bomberman::Dir dir, size_t pow)
{
  Bomberman::AElement   *item = this->_map.getTile(x, y).getItem();

  this->_trail.push_back(std::pair<size_t, size_t>(x, y));
  if (dir == Bomberman::NONE)
    {
      this->fireTrail(x - 1, y, Bomberman::LEFT, pow - 1);
      this->fireTrail(x + 1, y, Bomberman::RIGHT, pow - 1);
      this->fireTrail(x, y - 1, Bomberman::UP, pow - 1);
      this->fireTrail(x, y + 1, Bomberman::DOWN, pow - 1);
    }
  else if ((!item || (item->getType() != Bomberman::BLOCK &&
                             item->getType() != Bomberman::WALL)))
    {
      if (item && item->getType() == Bomberman::BOMB)
      	item->onFire();
      if (pow)
	this->fireTrail(dir == Bomberman::LEFT ? x - 1 :
			dir == Bomberman::RIGHT ? x + 1 : x,
			dir == Bomberman::UP ? y - 1 :
			dir == Bomberman::DOWN ? y + 1 : y, dir, pow - 1);
    }
}

void		Bomberman::Warfare::burnIt(void)
{
  this->_trail.sort(pairSort);
  this->_trail.unique(pairUnique);

  for (std::list<std::pair<size_t, size_t> >::iterator it = this->_trail.begin();
       it != this->_trail.end(); it++)
    {
      this->_map.getTile((*it).first, (*it).second).onFire();
      if (!this->_map.getTile((*it).first, (*it).second).getItem())
	this->_fire.push_back(new Fire((*it).first, (*it).second));
    }
  this->_trail.clear();
}

bool		pairSort(const std::pair<size_t, size_t> &i,
			 const std::pair<size_t, size_t> &j)
{
  return (i.first == j.first ? i.second < j.second : i.first < j.first);
}

bool		pairUnique(const std::pair<size_t, size_t> &i,
			   const std::pair<size_t, size_t> &j)
{
  return (i.first == j.first && i.second == j.second);
}

std::list<Bomberman::Bomb *>	&Bomberman::Warfare::getBombs(void)
{
  return (this->_bombs);
}


const std::list<Bomberman::Bomb *>	&Bomberman::Warfare::getBombs(void) const
{
  return (this->_bombs);
}

const std::list<Bomberman::Fire *>      &Bomberman::Warfare::getFire(void) const
{
  return (this->_fire);
}
