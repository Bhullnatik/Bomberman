//
// TitleScreen.hpp for bomberman in /home/chazal_l//Ydrasaal/PROJECT/Bomberman/Bomberman
//
// Made by leo chazal
// Login   <chazal_l@epitech.net>
//
// Started on  Sat Jun  8 06:36:24 2013 leo chazal
// Last update Sat Jun  8 10:32:24 2013 leo chazal
//

#include	<Image.hpp>
#include	"AModel.hpp"
#include	"Game.hh"

namespace	Bomberman
{
  class		TitleScreen : public AModel
  {
  private:
    gdl::Image	_texture;
    gdl::Image	_wording;
    bool	_wordUp;
    Bomberman::Game	*_main;

  public:
    TitleScreen(Bomberman::Game *);
    ~TitleScreen();

    void	draw(void);
    void	update(const gdl::GameClock &, gdl::Input &);

  private:
    void	initialize(void);
  };
}
