//
// MainMenuCredit.hh for Bomberman in /home/magrin_j/Project/Bomberman
//
// Made by Jérémy Magrin
// Login   <magrin_j@epitech.net>
//
// Started on  Sun Jun  9 13:44:02 2013 Jérémy Magrin
// Last update Sun Jun  9 20:54:07 2013 jimmy mayoukou
//

#pragma		once

#include	<OpenGL/gl.h>
#include	<OpenGL/glu.h>
#include	"AModel.hpp"
#include	"MyText.hh"
#include	"Game.hh"

namespace	Bomberman
{
  class		MainMenuCredit : public AModel
  {
  private:
    Bomberman::MyText		_text;
    float			_width;
    float			_height;
    Bomberman::Game		*_game;

  public:
    MainMenuCredit(Bomberman::Game *game);
    ~MainMenuCredit();

  public:
    void		draw(void);
    void		update(const gdl::GameClock &, gdl::Input &);
    Bomberman::MyText	getText(void) const;
  };
}
