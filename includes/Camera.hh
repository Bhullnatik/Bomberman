//
// Camera.hh for Bomberman in /home/magrin_j/Project/Bomberman/Bomberman
//
// Made by magrin_j
// Login   <magrin_j@epitech.net>
//
// Started on  Wed May  8 18:25:58 2013 magrin_j
// Last update Wed Jun  5 19:17:59 2013 jimmy mayoukou
//

#pragma		once

#include	<Input.hpp>
#include	<GameClock.hpp>
#include	<Window.hpp>
#include	<Image.hpp>
#include	<list>

#include	"Vector3f.hpp"
#include	"bomberman.hh"

#define		POW(x)			((x) * (x))

namespace	Bomberman
{
  class		Camera
  {
  private:
    std::list<Vector3f>			_players;
    Vector3f				_look;
    Vector3f				_eyePos;
    Vector3f				_upPos;
    size_t				_sizeMapX;
    size_t				_sizeMapY;
    float				_fovy;
    bool				_init;

  public:
    Camera();
    ~Camera();

  public:
    void		set(Vector3f, const std::list<Vector3f> &, Vector3f);
    void		setEyePos(Vector3f);
    void		setPlayers(const std::list<Vector3f> &);
    void		setUpPos(Vector3f);
    void		setSizeMap(size_t x, size_t y);
    void		initialize(const gdl::Window &);
    void		update(const gdl::GameClock &, gdl::Input &, const gdl::Window &);

  private:
    void		setVectorPos(void);
    void		findCenterPlayers(void);
    void		resize(const gdl::Window &);
  };
}
