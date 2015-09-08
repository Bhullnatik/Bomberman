//
// Bomb.hh for bomberman in /home/chazal_l//Ydrasaal/PROJECT/Bomberman/Bomberman
//
// Made by leo chazal
// Login   <chazal_l@epitech.net>
//
// Started on  Fri May 24 12:31:29 2013 leo chazal
// Last update Sat Jun  8 17:13:41 2013 jimmy mayoukou
//

#pragma		once

#include	"AElement.hpp"
#include	"ISerializable.hpp"
#include	"Save.hh"

namespace	Bomberman
{
  class		Bomb : public Bomberman::AElement, ISerializable
  {
  private:
    size_t	_tick;
    size_t	_id;
    size_t	_posX;
    size_t	_posY;
    size_t	_pwr;
    bool	_blown;

  public:
    Bomb(size_t, size_t, size_t, size_t);
    Bomb(const Bomberman::Save::Bomb &);
    ~Bomb();

  public:
    void	draw(void);
    void	update(const gdl::GameClock &, gdl::Input &);
    void	onFire(void);

  public:
    bool	blewUp(void) const;
    size_t	getX(void) const;
    size_t	getY(void) const;
    size_t	getPower(void) const;
    size_t	getId(void) const;
    size_t	getTicks(void) const;

  public:
    void	serialize(std::ostream &stream) const;
  };
}
