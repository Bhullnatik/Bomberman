//
// Engine.hh for Bomberman in /home/chazal_l//Ydrasaal/PROJECT/Bomberman/Bomberman
//
// Made by leo chazal
// Login   <chazal_l@epitech.net>
//
// Started on  Wed May  8 16:02:00 2013 leo chazal
// Last update Sun Jun  9 21:40:15 2013 Jérémy Magrin
//

#pragma		once

namespace	Bomberman
{
  class		Game;
}

#include	<fstream>
#include	<list>
#include	"APlayer.hh"
#include	"Bomb.hh"
#include	"Map.hh"
#include	"Warfare.hh"

namespace	Bomberman
{
  class		Engine : public Bomberman::AModel, ISerializable
  {

  private:
    Bomberman::Map			_map;
    Bomberman::Warfare			_war;
    std::list<Bomberman::APlayer *>	_player;
    Bomberman::Game			*_main;
    bool				_hasKeys;
    bool				_paused;

  public:
    Engine(Bomberman::Game *, size_t);
    Engine(Bomberman::Game *, const std::string &);
    Engine(Bomberman::Game *, std::ifstream &);
    ~Engine(void);

    size_t			getSizeXMap() const;
    size_t			getSizeYMap() const;
    const std::list<Vector3f>	getPlayerList() const;
    void			draw(void);
    void			initialize(size_t, size_t);
    void			update(const gdl::GameClock &, gdl::Input &);
    void			fireTrail(size_t, size_t, Bomberman::Dir, size_t);
    void			serialize(std::ostream &) const;
    void			setCameraMode(Bomberman::Camera &, const gdl::Window &);
    void			pause(gdl::Input &);
    void			drawPause(void);

  private:
    void			validPosPlayer(void) const;
    Vector3f			getPlayerSpawn();
    void			trigger(void);
    void			endGame(bool);
    void			createPlayer(bool);
    void			createPlayer(const Bomberman::Save::Player &);
  };
}
