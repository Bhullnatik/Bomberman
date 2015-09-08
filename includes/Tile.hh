//
// Tile.hh for bomberman in /home/chazal_l//Ydrasaal/PROJECT/Bomberman/Bomberman
//
// Made by leo chazal
// Login   <chazal_l@epitech.net>
//
// Started on  Wed May 15 20:38:16 2013 leo chazal
// Last update Sat Jun  8 20:07:48 2013 Cyril Kapoustine
//

#pragma		once

#include	"AElement.hpp"

namespace	Bomberman
{
  class		Tile : public Bomberman::AModel
  {
  private:
    size_t	_x;
    size_t	_y;
    Bomberman::AElement	*_item;

  public:
    Tile(size_t, size_t, Bomberman::AElement *);
    ~Tile();
    Tile(const Tile &);
    Tile	&operator=(const Tile &);

    void	draw(void);
    void	update(const gdl::GameClock &, gdl::Input &);
    void	onFire(void);
    size_t	getX(void) const;
    size_t	getY(void) const;
    Bomberman::AElement	*getItem(void) const;
    void	setContent(Bomberman::AElement *);
    void	burn(void);
  };
}
