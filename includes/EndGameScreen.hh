//
// EndGameScreen.hh for bomberman in /home/chazal_l//Ydrasaal/PROJECT/Bomberman/Bomberman
//
// Made by leo chazal
// Login   <chazal_l@epitech.net>
//
// Started on  Sat Jun  8 10:06:50 2013 leo chazal
// Last update Sun Jun  9 17:49:55 2013 jimmy mayoukou
//

#include        <Image.hpp>
#include        "AModel.hpp"
#include	"APlayer.hh"
#include	"Game.hh"

namespace       Bomberman
{
  class         EndGameScreen : public AModel
  {
  private:
    gdl::Image		_texture;
    Bomberman::Game	*_main;
    size_t		_size;
    bool		_human;
    size_t		_score;

  public:
    EndGameScreen(Bomberman::Game *, const std::list<Bomberman::APlayer *> &, bool);
    ~EndGameScreen();

    void        draw(void);
    void        update(const gdl::GameClock &, gdl::Input &);

  private:
    void        initialize();
  };
}
