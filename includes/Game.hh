//
// Game.hh for Bomberman in /home/mayouk_j/CPP/Bomberman/includes
//
// Made by jimmy mayoukou
// Login   <mayouk_j@epitech.net>
//
// Started on  Wed May  8 04:27:39 2013 jimmy mayoukou
// Last update Sun Jun  9 21:24:32 2013 jimmy mayoukou
//

#pragma		once

#include	<Game.hpp>
#include	<list>
#include	<stack>
#include	"Camera.hh"
#include	"Engine.hh"

namespace	Bomberman
{
  class		Game : public gdl::Game
  {
  private:
    std::list<std::pair<std::string, size_t> >	_highScore;
    std::stack<Bomberman::AModel *>		_views;
    Camera					_cam;
    float					_timeStamp;

  public:
    void					initialize(void);
    void					update(void);
    void					draw(void);
    void					unload(void);
    void					addHighScore(const std::string &, size_t);
    const std::list<std::pair<std::string, size_t> >	&getHighScores() const;
    void					setCurrentView(AModel *);
    void					popCurrentView();
    void					newGame(const std::string &, size_t, size_t);
    void					newGame(const std::string &);
    const gdl::Window				&getWindow() const;
    gdl::Window					&getWindow();
    bool					addTick();

  private:
    void		loadHighscore(void);
    void		saveHighScore(void);
  };
}
