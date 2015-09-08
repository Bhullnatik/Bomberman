//
// Fire.hh for bomberman in /home/chazal_l//Ydrasaal/PROJECT/Bomberman/Bomberman
//
// Made by leo chazal
// Login   <chazal_l@epitech.net>
//
// Started on  Mon May 27 19:16:06 2013 leo chazal
// Last update Fri Jun  7 18:22:40 2013 leo chazal
//

#pragma		once

#include	"AElement.hpp"

namespace	Bomberman
{
  class		Fire : public Bomberman::AModel
  {
  private:
    size_t	_tick;
    size_t	_x;
    size_t	_y;
    bool	_burning;

  public:
    Fire(size_t, size_t);
    ~Fire();

    void	draw(void);
    void	update(const gdl::GameClock &, gdl::Input &);
    bool	isBurning(void) const;
    size_t      getX(void) const;
    size_t      getY(void) const;
    size_t	getTicks(void) const;

  private:
    Fire();

    void	burn(float);
  };
}
