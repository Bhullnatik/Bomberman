//
// Error.hh for Bomberman in /home/magrin_j/Project/Bomberman
//
// Made by Jérémy Magrin
// Login   <magrin_j@epitech.net>
//
// Started on  Sun Jun  9 15:35:55 2013 Jérémy Magrin
// Last update Sun Jun  9 16:23:13 2013 Jérémy Magrin
//

#pragma		once

#include	"AModel.hpp"
#include	"MyText.hh"
#include	"Game.hh"
#include	<string>

namespace	Bomberman
{
  class		Error : public Bomberman::AModel
  {
  private:
    Bomberman::MyText		_text;
    float			_width;
    float			_height;
    Bomberman::Game		*_game;
    std::string			_error;

  public:
    Error(Bomberman::Game *, const std::string &error);
    ~Error();

  public:
    void			draw(void);
    void			update(const gdl::GameClock &, gdl::Input &);
    int				getRealPosX(float x);
    int				getRealPosY(float y);
    Bomberman::MyText		getText(void) const;
    const std::string&		getErrorMsg(void) const;
    float			getWidth(void) const;
    float			getHeight(void) const;
  };
}
