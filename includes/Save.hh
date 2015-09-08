//
// Save.hh for Bomberman in /home/mayouk_j/CPP/Bomberman
//
// Made by jimmy mayoukou
// Login   <mayouk_j@epitech.net>
//
// Started on  Sat Jun  1 12:03:27 2013 jimmy mayoukou
// Last update Sun Jun  9 17:10:01 2013 jimmy mayoukou
//

#pragma		once

namespace	Bomberman
{
  class		APlayer;
  class		Bomb;
  class		Engine;
  class		Game;
}

#include	"Vector3f.hpp"

#define		KEY_SAVE	"\0\0\0sAveBomBerManxoxoxo\0\0\0"
#define		KEY_SAVE_LEN	25

namespace	Bomberman
{
  class		Save
  {
  public:
    struct	Player
    {
      Vector3f	pos;
      int	id;
      int	bombNbr;
      int	bombPwr;
      int	speed;
      bool	isHuman;
      float	angle;
      size_t	safe;
      size_t	score;

      Player();
      Player(const Bomberman::APlayer *);
    };

    struct	Bomb
    {
      size_t	power;
      size_t	posX;
      size_t	posY;
      size_t	tick;
      size_t	id;

      Bomb();
      Bomb(const Bomberman::Bomb *);
    };

  public:
    static void		save(const Bomberman::Engine *, const std::string &);
    static Engine	*load(const std::string &, Bomberman::Game *);
  };
}
