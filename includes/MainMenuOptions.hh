//
// MenuOptions.hh for  in /home/hoarau_s/Projets/Bomberman/Bomberman/includes
//
// Made by stephen hoarau
// Login   <hoarau_s@epitech.net>
//
// Started on  Thu Jun  6 15:44:10 2013 stephen hoarau
// Last update Thu Jun  6 16:16:30 2013 stephen hoarau
//

#pragma		once

#include	<OpenGL/gl.h>
#include	<OpenGL/glu.h>
#include	<iostream>
#include	<sstream>
#include	<list>
#include	<sys/types.h>
#include	<dirent.h>
#include	"AModel.hpp"
#include	"Game.hh"
#include	"Window.hpp"
#include	"Text.hpp"
#include	"MyText.hh"
#include	"Sound.hh"

namespace	Bomberman
{

  class		MainMenuOptions : public Bomberman::AModel
  {
  private:
    Bomberman::MyText	_text;
    Bomberman::Game *_game;
    float	_width;
    float	_height;

  public:
    MainMenuOptions(Bomberman::Game *game);
    ~MainMenuOptions();

    void	draw(void);
    void	update(const gdl::GameClock &gc, gdl::Input &input);
    int		getRealPosX(float x);
    int		getRealPosY(float y);
    Bomberman::MyText	getText() const;
  };
}
