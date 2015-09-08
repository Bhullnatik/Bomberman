//
// APlayer.hh for Bomberman in /home/mayouk_j/CPP/Bomberman
//
// Made by jimmy mayoukou
// Login   <mayouk_j@epitech.net>
//
// Started on  Tue Jun  4 13:35:37 2013 jimmy mayoukou
// Last update Sun Jun  9 19:57:25 2013 leo chazal
//

#pragma		once

#include	<list>
#include	"Bomb.hh"
#include	"Color.hpp"
#include	"Fire.hh"
#include	"ISerializable.hpp"
#include	"Map.hh"
#include	"PlayerView.hh"
#include	"Save.hh"

namespace	Bomberman
{
  class		APlayer : public Bomberman::AModel, ISerializable
  {
  protected:
    Bomberman::Map	&_map;
    Vector3f	_pos;
    float	_angle;
    size_t	_id;
    size_t	_bNbr;
    size_t	_bPwr;
    int		_speed;
    size_t	_score;
    std::list<Bomberman::Bomb *>	&_bombPool;
    void	(Bomberman::APlayer::*_bonusFunc[BONUS_NUMBER])();
    size_t	_safe;

  public:
    APlayer(const Bomberman::Save::Player &, Bomberman::Map &, std::list<Bomberman::Bomb *> &);
    APlayer(size_t, Bomberman::Map &, std::list<Bomberman::Bomb *> &, const Vector3f &);
    virtual ~APlayer();

  public:
    void		serialize(std::ostream &) const;

  public:
    bool		isAlive(const std::list<Bomberman::Fire *> &);
    size_t		getBombNumber() const;
    size_t		getBombPower() const;
    int			getSpeed() const;
    size_t		getId() const;
    const Vector3f	&getPosition() const;
    void		placeBomb(const gdl::GameClock &);
    float		getAngle(void) const;
    size_t		getRemainingBombs(void) const;
    size_t		getSafeTime(void) const;
    size_t		getScore() const;
    void		addScore(size_t);
    virtual std::string	getName(void) const = 0;

  protected:
    void		upBomb(void);
    void		downBomb(void);
    void		upPower(void);
    void		downPower(void);
    void		upSpeed(void);
    void		downSpeed(void);
    void		upInvincible(void);

  protected:
    void	translateTo(Bomberman::PlayerView *, std::list<Bomberman::Dir> &);
    void	move(Bomberman::Dir);
    bool	getElementCollision(Bomberman::Dir);
    bool	handleCollision(size_t, size_t, size_t, size_t);
    void	handleBonus(const Bomberman::Tile &, size_t, size_t);

  private:
    APlayer();

  private:
    void	stopRunAndIdle(Bomberman::PlayerView *) const;
    void	bonusInitialize(void);
  };
}
