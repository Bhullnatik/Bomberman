//
// Warfare.hh for bomberman in /home/chazal_l//Ydrasaal/PROJECT/Bomberman/Bomberman
//
// Made by leo chazal
// Login   <chazal_l@epitech.net>
//
// Started on  Thu May 30 16:38:41 2013 leo chazal
// Last update Sat Jun  8 17:15:04 2013 jimmy mayoukou
//

#pragma		once

#include	<list>
#include	"AModel.hpp"
#include	"Fire.hh"
#include	"Bomb.hh"

namespace	Bomberman
{
  class		Warfare : Bomberman::AModel
  {
  private:
    std::list<Bomberman::Bomb *>		_bombs;
    std::list<Bomberman::Fire *>		_fire;
    std::list<std::pair<size_t, size_t> >	_trail;
    Bomberman::Map				&_map;
    bool					_triggered;

  public:
    Warfare(Bomberman::Map &);
    ~Warfare();

    void	draw(void);
    void	update(const gdl::GameClock &, gdl::Input &);
    void	initialize(void);
    void	trigger(void);
    std::list<Bomberman::Bomb *>	&getBombs(void);
    const std::list<Bomberman::Bomb *>	&getBombs(void) const;
    const std::list<Bomberman::Fire *>  &getFire(void) const;

  private:
    void	fireTrail(size_t, size_t, Bomberman::Dir, size_t);
    void	burnIt(void);
  };
}

bool	pairSort(const std::pair<size_t, size_t> &, const std::pair<size_t, size_t> &);
bool    pairUnique(const std::pair<size_t, size_t> &, const std::pair<size_t, size_t> &);
