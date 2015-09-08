//
// IA.hh for  in /home/kapous_c/Bomberman/includes
//
// Made by Cyril Kapoustine
// Login   <kapous_c@epitech.net>
//
// Started on  Wed Jun  5 12:39:56 2013 Cyril Kapoustine
// Last update Sun Jun  9 19:50:57 2013 leo chazal
//

#pragma		once

#include	<GameClock.hpp>
#include	<Input.hpp>
#include	"APlayer.hh"
#include	"IA.hh"
#include	<cmath>

#define		TO_COORD(x)	(std::abs(floor(((x)) / TILE_SIZE)))
#define		TO_REAL(x)	((((x) * TILE_SIZE) - (TILE_SIZE / 2.0f)) + TILE_SIZE)
#define		TO_DEGREE(x)	((x) * 180 / M_PI)
#define		STEP		29

namespace	Bomberman
{
  enum		ObjectiveType
    {
      SURVIVE = 0,
      GETBONUS,
      DBLOCK
    };

  class		IA : public Bomberman::APlayer
  {

  private:
    const std::list<Bomberman::APlayer *>	&_players;
    ObjectiveType	_typeObj;
    float		_Xobj;
    float		_Yobj;
    double		_angle;
    float		_tmpPosX;
    float		_tmpPosY;

  public:
    IA(const Bomberman::Save::Player &, Bomberman::Map &, std::list<Bomberman::Bomb *> &, const std::list<Bomberman::APlayer *> &);
    IA(size_t, Bomberman::Map &, std::list<Bomberman::Bomb *> &,
       const std::list<Bomberman::APlayer *> &, const Vector3f &);
    ~IA();

  public:
    void	draw(void);
    void	update(const gdl::GameClock &, gdl::Input &);
    std::string	getName(void) const;

  private:
    bool		inCenter(size_t x, size_t y);
    bool		inDestination(void);
    void		findSolution(std::list<Bomberman::Dir> &);
    bool		ifWalkable(float, float, Bomberman::Dir);
    bool		verifObj(void);
    void		makeMoveDecision(std::list<Bomberman::Dir> &);
    void		destroyBlock(void);
    bool		near(float, float, Bomberman::Element, Bomberman::Dir dir = Bomberman::NONE);
    bool		detectPowerUp(void);
    bool		detectDangerZone(void);
    bool		findSafePlace(void);
  };
}
