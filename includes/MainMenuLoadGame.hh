//
// MainMenuLoadGame.hh for  in /home/hoarau_s/Projets/Bomberman/Bomberman/srcs
//
// Made by stephen hoarau
// Login   <hoarau_s@epitech.net>
//
// Started on  Thu Jun  6 17:35:42 2013 stephen hoarau
// Last update Thu Jun  6 18:49:29 2013 stephen hoarau
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

  class		MainMenuLoadGame : public Bomberman::AModel
  {
  private:
    Bomberman::MyText	_text;
    int		_player;
    int		_idx;
    int		_ia;
    int		_pos;
    std::list<std::string> _choices;
    Bomberman::Game *_game;
    float	_width;
    float	_height;
    std::string _selected;

  public:
    MainMenuLoadGame(Bomberman::Game *game);
    ~MainMenuLoadGame();

    void	draw(void);
    void	update(const gdl::GameClock &gc, gdl::Input &input);
    void	manageSelectMap(int x, int y);
    bool	checkNext();
    void	startNewGame();
    int		getRealPosX(float x);
    int		getRealPosY(float y);
    void	init_saves_choices();
    void	loadSave();

    std::string		getSelected(int mouse);
    Bomberman::MyText	getText() const;
    std::string		getSelection() const;
    std::list<std::string>	getList() const;
    int			getIdx() const;
  };
}

