//
// Bonus.hh for Bomberman in /home/magrin_j/Project/Bomberman/Bomberman
//
// Made by magrin_j
// Login   <magrin_j@epitech.net>
//
// Started on  Mon May 13 11:43:54 2013 magrin_j
// Last update Fri Jun  7 21:11:23 2013 leo chazal
//

#pragma		once

#include	"AElement.hpp"

namespace	Bomberman
{
  enum		TypeBonus
    {
      B_BOMB = 0,
      M_BOMB = 1,
      B_POWER = 2,
      M_POWER = 3,
      B_SPEED = 4,
      M_SPEED = 5,
      INVINC = 6
    };

  class		Bonus : public Bomberman::AElement
  {
  private:
    TypeBonus				_bonus;
    int					_rotate;
    bool				_isMalus;

  public:
    Bonus();
    ~Bonus();

    void				draw();
    void				update(const gdl::GameClock &, gdl::Input &);
    void				onFire(void);
    void				rollType(void);
    static bool				isBonus(void);
    TypeBonus				getBonus(void) const;
    bool				isMalus(void) const;
  };
}
