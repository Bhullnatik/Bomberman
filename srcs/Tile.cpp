//
// Tile.cpp for bomberman in /home/chazal_l//Ydrasaal/PROJECT/Bomberman/Bomberman
//
// Made by leo chazal
// Login   <chazal_l@epitech.net>
//
// Started on  Wed May 15 20:43:19 2013 leo chazal
// Last update Sat Jun  8 20:07:32 2013 Cyril Kapoustine
//

#include	"Tile.hh"
#include	"TileView.hh"
#include	"bomberman.hh"
#include	"Bonus.hh"
#include	"Fire.hh"

#include	<iostream>

Bomberman::Tile::Tile(size_t x, size_t y, Bomberman::AElement *item)
  : AModel(Bomberman::TileView::getInstance()), _item(item)
{
  this->_x = x;
  this->_y = y;
}

Bomberman::Tile::~Tile()
{
}

Bomberman::Tile::Tile(const Bomberman::Tile &tile)
  : AModel(Bomberman::TileView::getInstance())
{
  *this = tile;
}

Bomberman::Tile	&Bomberman::Tile::operator=(const Tile &tile)
{
  this->_x = tile._x;
  this->_y = tile._y;
  this->_item = tile._item;
  return (*this);
}

size_t	Bomberman::Tile::getX(void) const
{
  return (this->_x);
}

size_t	Bomberman::Tile::getY(void) const
{
  return (this->_y);
}

Bomberman::AElement	*Bomberman::Tile::getItem(void) const
{
  return (this->_item);
}

void	Bomberman::Tile::draw(void)
{
  this->_view->setPosition(this->_x * TILE_SIZE, 0, this->_y * TILE_SIZE);
  this->_view->draw(this);
  if (this->_item != NULL)
    {
      this->_item->getView()->setPosition(this->_x * TILE_SIZE, 0, this->_y * TILE_SIZE);
      this->_item->draw();
    }
}

void	Bomberman::Tile::update(const gdl::GameClock &gameClock, gdl::Input &input)
{
  if (this->_item)
    this->_item->update(gameClock, input);
}

void	Bomberman::Tile::setContent(Bomberman::AElement *item)
{
  this->_item = item;
}

void	Bomberman::Tile::onFire(void)
{
  if (this->_item)
    switch (this->_item->getType())
      {
      case Bomberman::BONUS:
	this->_item->onFire();
	this->setContent(NULL);
	break;
      case Bomberman::BOMB:
	this->_item->onFire();
	break;
      case Bomberman::BLOCK:
	this->_item->onFire();
	this->setContent(NULL);
	if (!Bomberman::Bonus::isBonus())
	  this->_item = new Bomberman::Bonus();
	break;
      default:
	break;
      }
}
