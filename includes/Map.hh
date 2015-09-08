//
// Map.hh for Map in /home/kapous_c/Bomberman/includes
//
// Made by cyril kapoustine
// Login   <kapous_c@epitech.net>
//
// Started on  Thu May  9 16:56:58 2013 cyril kapoustine
// Last update Sat Jun  8 20:00:09 2013 Cyril Kapoustine
//

#pragma		once

#include	<istream>
#include	<string>
#include	<vector>
#include	"Bomb.hh"
#include	"ISerializable.hpp"
#include	"Tile.hh"

namespace		Bomberman
{
  class			Map : public Bomberman::AModel, ISerializable
  {
  private:
    std::vector<Bomberman::Tile>	_level;
    size_t				_sizeX;
    size_t				_sizeY;

  public:
    Map(std::istream &);
    Map(const std::string &);
    Map(size_t);
    ~Map();
    Map();
    Map(const Bomberman::Map &);
    Bomberman::Map	&operator=(const Bomberman::Map &);

  public:
    void		draw(void);
    void		initialize(void);
    void		update(const gdl::GameClock &, gdl::Input &);

  public:
    size_t				getSizeX() const;
    size_t				getSizeY() const;
    const std::vector<Bomberman::Tile>	&getLevel(void) const;
    Bomberman::Tile			&getTile(size_t, size_t);
    const Bomberman::Tile		&getTile(size_t, size_t) const;
    void				removeItem(size_t, size_t);
    void				setTileContent(size_t, size_t, Bomberman::AElement *);

  public:
    void		serialize(std::ostream &) const;

  private:
    size_t		POS(size_t, size_t) const;
    void		generateMap(std::istream &);

  private:
    void		fillLine(const std::string &, size_t &);
  };
}
