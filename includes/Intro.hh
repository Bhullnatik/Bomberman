//
// Intro.hh for Bomberman in /home/magrin_j/Project/Bomberman
//
// Made by Jérémy Magrin
// Login   <magrin_j@epitech.net>
//
// Started on  Sat Jun  1 16:18:32 2013 Jérémy Magrin
// Last update Sat Jun  8 12:13:23 2013 leo chazal
//

#pragma		once

#include	<GameClock.hpp>
#include	<Input.hpp>
#include	"AModel.hpp"
#include	"Game.hh"

namespace	Bomberman
{
  struct         BInfo
  {
    float       x;
    float       y;
    size_t      count;
    bool	lit;
    BInfo(float x, float y, size_t count)
      : x(x), y(y), count(count), lit(false)
    {

    }
  };

  class		Intro : public Bomberman::AModel
  {
  private:
    size_t		_ticks;
    Bomberman::Game	*_main;
    std::list<BInfo>    _state;

  public:
    Intro(Bomberman::Game *);
    ~Intro();

    void	draw(void);
    void	update(const gdl::GameClock &, gdl::Input &);
    size_t	getTicks(void) const;
    const std::list<BInfo>	&getState(void) const;

  private:
    void	initialize(void);
  };
}
