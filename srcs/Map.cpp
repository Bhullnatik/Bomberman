//
// Map.cpp for Map in /home/kapous_c/Bomberman/srcs
//
// Made by cyril kapoustine
// Login   <kapous_c@epitech.net>
//
// Started on  Mon May 13 15:11:13 2013 cyril kapoustine
// Last update Sun Jun  9 20:45:00 2013 Cyril Kapoustine
//

#include	<iostream>
#include	<fstream>
#include	<stdexcept>
#include	<cmath>
#include	<ctime>
#include	<cstdlib>
#include	"Block.hh"
#include	"Map.hh"
#include	"MapView.hh"
#include	"Utilities.hh"
#include	"Wall.hh"

Bomberman::Map::Map() : AModel(NULL)
{
}

Bomberman::Map::Map(std::istream &stream) : AModel(Bomberman::MapView::getInstance())
{
  this->generateMap(stream);
}

Bomberman::Map::Map(const std::string &filename) : AModel(Bomberman::MapView::getInstance())
{
  if (!Utilities::checkExtension(filename, MAP_EXTENSION))
    throw std::ios_base::failure("Bad file extension");
  std::ifstream	stream(filename.c_str());

  if (!stream)
    throw std::runtime_error("Bomberman: Could not open map " + filename);
  this->generateMap(stream);
  stream.close();
}

Bomberman::Map::Map(size_t pNumber) : AModel(Bomberman::MapView::getInstance())
{
  size_t mapSegSize = 6, mapSize = floor(sqrt(pNumber));
  size_t tmp_x = 1, tmp_y = 1, it = 0;

  srand(time(NULL));
  while (it <= (mapSegSize * mapSize + 2))
    this->_level.push_back(Tile(it++, 0, Bomberman::Wall::getInstance()));
  it = 0;
  while (tmp_y <= (mapSegSize * mapSize + 1))
    {
      tmp_x = 1;
      this->_level.push_back(Tile(0, tmp_y, Bomberman::Wall::getInstance()));
      while (tmp_x <= (mapSegSize * mapSize + 1))
	{
	  if ((tmp_x && (tmp_x % 2) == 0) && (tmp_y && (tmp_y % 2) == 0))
	    this->_level.push_back(Tile(tmp_x, tmp_y, Bomberman::Wall::getInstance()));
	  else {
	    if (!(rand() % 3))
	      this->_level.push_back(Tile(tmp_x, tmp_y, Bomberman::Block::getInstance()));
	    else
	      this->_level.push_back(Tile(tmp_x, tmp_y, NULL));
	  }
	  ++tmp_x;
	}
      this->_level.push_back(Tile(tmp_x, tmp_y, Bomberman::Wall::getInstance()));
      ++tmp_y;
    }
  while (it <= (mapSegSize * mapSize + 2))
    this->_level.push_back(Tile(it++, tmp_y, Bomberman::Wall::getInstance()));
  this->_sizeX = tmp_x + 1;
  this->_sizeY = tmp_y + 1;
}

Bomberman::Map::~Map()
{
}

Bomberman::Map::Map(const Bomberman::Map &copy) : AModel(NULL)
{
  *this = copy;
}

Bomberman::Map	&Bomberman::Map::operator=(const Bomberman::Map &copy)
{
  this->_level = copy._level;
  this->_sizeX = copy._sizeX;
  this->_sizeY = copy._sizeY;
  this->_view = copy._view;
  return (*this);
}

size_t	Bomberman::Map::POS(size_t x, size_t y) const
{
  return (x + y * this->_sizeX);
}

void		Bomberman::Map::generateMap(std::istream &stream)
{
  std::string	line;
  size_t	x(0), y(0), len(0);
  bool		startWalls = true;

  while (getline(stream, line))
    {
      if (len != 0 && line.length() != len)
	throw std::runtime_error("Bomberman Map formatting error : Not quadrilateral Map");
      len = line.length();
      if (startWalls)
	{
	  while (x <= len + 1)
	    this->_level.push_back(Tile(x++, y, Bomberman::Wall::getInstance()));
	  startWalls = false;
	}
      ++y;
      fillLine(line, y);
      x = 0;
    }
  ++y;
  while (x <= len + 1)
    this->_level.push_back(Tile(x++, y, Bomberman::Wall::getInstance()));
  this->_sizeX = x;
  this->_sizeY = y + 1;
}

void		Bomberman::Map::fillLine(const std::string &line, size_t &y)
{
  size_t	it(0);

  this->_level.push_back(Tile(it, y, Bomberman::Wall::getInstance()));
  for (it = 0; line[it]; ++it)
    {
      switch (line[it])
	{
	case ('.'):
	  {
	    this->_level.push_back(Tile(it + 1, y, NULL));
	    break ;
	  }
	case ('W'):
	  {
	    this->_level.push_back(Tile(it + 1, y, Bomberman::Wall::getInstance()));
	    break ;
	  }
	case ('B'):
	  {
	    this->_level.push_back(Tile(it + 1, y, Bomberman::Block::getInstance()));
	    break ;
	  }
	default:
	  throw std::runtime_error("Error while generating map: Bad map format");
	}
    }
  this->_level.push_back(Tile(it + 1, y, Bomberman::Wall::getInstance()));
}

size_t	Bomberman::Map::getSizeX() const
{
  return (this->_sizeX);
}

size_t	Bomberman::Map::getSizeY() const
{
  return (this->_sizeY);
}

void	Bomberman::Map::draw()
{
  this->_view->draw(this);
}

void	Bomberman::Map::initialize()
{
}

void	Bomberman::Map::update(const gdl::GameClock &gameClock, gdl::Input &input)
{
  for (std::vector<Bomberman::Tile>::iterator it = this->_level.begin();
       it != this->_level.end(); it++)
    (*it).update(gameClock, input);
}

const std::vector<Bomberman::Tile>	&Bomberman::Map::getLevel() const
{
  return (this->_level);
}

Bomberman::Tile	&Bomberman::Map::getTile(size_t x, size_t y)
{
  return (this->_level[POS(x, y)]);
}

const Bomberman::Tile	&Bomberman::Map::getTile(size_t x, size_t y) const
{
  return (this->_level[POS(x, y)]);
}

void	Bomberman::Map::removeItem(size_t x, size_t y)
{
  this->_level[POS(x, y)].setContent(NULL);
}

void	Bomberman::Map::setTileContent(size_t x, size_t y, Bomberman::AElement *element)
{
  this->_level[POS(x, y)].setContent(element);
}

void		Bomberman::Map::serialize(std::ostream &stream) const
{
  Bomberman::Element	elem;
  size_t		currPos;

  for (std::vector<Bomberman::Tile>::const_iterator it = this->_level.begin(); it != this->_level.end(); it++)
    {
      currPos = std::distance(this->_level.begin(), it);
      if (currPos > this->_sizeX && !(currPos % this->_sizeX))
	stream << std::endl;
      if ((currPos % this->_sizeX) == this->_sizeX - 1 || currPos <= this->_sizeX - 1||
		  currPos >= (this->_sizeX * (this->_sizeY - 1)) || !(currPos % this->_sizeX))
	continue;
      elem = ((*it).getItem() ? (*it).getItem()->getType() : Bomberman::NELEM);
      switch (elem)
	{
	case (Bomberman::WALL):
	  stream << "W";
	  break;
	case (Bomberman::BLOCK):
	  stream << "B";
	  break;
	case (Bomberman::NELEM):
	default:
	  stream << ".";
	  break;
	}
    }
}
