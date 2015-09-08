//
// APlayer.cpp for Bomberman in /home/mayouk_j/CPP/Bomberman
//
// Made by jimmy mayoukou
// Login   <mayouk_j@epitech.net>
//
// Started on  Tue Jun  4 14:30:41 2013 jimmy mayoukou
// Last update Sun Jun  9 19:39:37 2013 leo chazal
//

#include	<algorithm>
#include	"bomberman.hh"
#include	"APlayer.hh"
#include	"Bonus.hh"
#include	"Sound.hh"

Bomberman::APlayer::APlayer(const Bomberman::Save::Player &save, Bomberman::Map &map,
			    std::list<Bomberman::Bomb *> &pool) : Bomberman::AModel(new Bomberman::PlayerView()), _map(map), _bombPool(pool)
{
  this->_pos = save.pos;
  this->_id = save.id;
  this->_speed = save.speed;
  this->_bNbr = save.bombNbr;
  this->_bPwr = save.bombPwr;
  this->_safe = save.safe;
  this->_angle = save.angle;
  this->_score = save.score;
  this->bonusInitialize();
}

Bomberman::APlayer::APlayer(size_t id, Bomberman::Map &map,
			    std::list<Bomberman::Bomb *> &pool,
			    const Vector3f &pos)
  : Bomberman::AModel(new Bomberman::PlayerView()), _map(map), _bombPool(pool)
{
  this->_pos = pos;
  this->_angle = 0;
  this->_id = id;
  this->_safe = 0;
  this->_bNbr = 2;
  this->_bPwr = 2;
  this->_speed = 10;
  this->_score = 0;
  this->bonusInitialize();
}

Bomberman::APlayer::~APlayer()
{

}

void	Bomberman::APlayer::bonusInitialize(void)
{
  this->_bonusFunc[Bomberman::B_BOMB] = &Bomberman::APlayer::upBomb;
  this->_bonusFunc[Bomberman::M_BOMB] = &Bomberman::APlayer::downBomb;
  this->_bonusFunc[Bomberman::B_POWER] = &Bomberman::APlayer::upPower;
  this->_bonusFunc[Bomberman::M_POWER] = &Bomberman::APlayer::downPower;
  this->_bonusFunc[Bomberman::B_SPEED] = &Bomberman::APlayer::upSpeed;
  this->_bonusFunc[Bomberman::M_SPEED] = &Bomberman::APlayer::downSpeed;
  this->_bonusFunc[Bomberman::INVINC] = &Bomberman::APlayer::upInvincible;
}

void				Bomberman::APlayer::serialize(std::ostream &stream) const
{
  Bomberman::Save::Player	save(this);

  stream.write((char *) &save, sizeof(save));
}

bool	Bomberman::APlayer::isAlive(const std::list<Bomberman::Fire *> &fire)
{
  if (this->_safe)
    return (true);
  for (std::list<Bomberman::Fire *>::const_iterator it = fire.begin(); it != fire.end(); it++)
    {
      if ((*it)->getX() == (size_t) this->_pos.x / TILE_SIZE &&
          (*it)->getY() == (size_t) this->_pos.z / TILE_SIZE)
	return (false);
    }
  return (true);
}

size_t	Bomberman::APlayer::getBombNumber() const
{
  return (this->_bNbr);
}

size_t	Bomberman::APlayer::getBombPower() const
{
  return (this->_bPwr);
}

int	Bomberman::APlayer::getSpeed() const
{
  return (this->_speed);
}

size_t	Bomberman::APlayer::getId() const
{
  return (this->_id);
}

const Vector3f	&Bomberman::APlayer::getPosition() const
{
  return (this->_pos);
}

size_t		Bomberman::APlayer::getSafeTime(void) const
{
  return (this->_safe);
}

void	Bomberman::APlayer::placeBomb(const gdl::GameClock &)
{
  if (!this->_map.getTile(this->_pos.x / TILE_SIZE,
			   this->_pos.z / TILE_SIZE).getItem() &&
      this->getRemainingBombs() < this->_bNbr)
    {
      Bomberman::Bomb	*newBomb = new Bomb(this->_id, this->_pos.x, this->_pos.z, this->_bPwr);
      this->_map.setTileContent(this->_pos.x / TILE_SIZE, this->_pos.z / TILE_SIZE, newBomb);
      this->_bombPool.push_back(newBomb);
      Bomberman::Sound::getInstance()->playSound(T_BOMB);
    }
}

float	Bomberman::APlayer::getAngle(void) const
{
  return (this->_angle);
}

void	Bomberman::APlayer::upBomb(void)
{
  ++this->_bNbr;
}

void	Bomberman::APlayer::downBomb(void)
{
  if (this->_bNbr <= 1)
    return;
  --this->_bNbr;
}

void	Bomberman::APlayer::upPower(void)
{
  ++this->_bPwr;
}

void	Bomberman::APlayer::downPower(void)
{
  if (this->_bPwr <= 1)
    return;
  --this->_bPwr;
}

void	Bomberman::APlayer::upSpeed(void)
{
  if (this->_speed < TILE_SIZE)
    this->_speed += 2;
}

void	Bomberman::APlayer::downSpeed(void)
{
  if (this->_speed <= 2)
    return;
  this->_speed -= 2;
}

void	Bomberman::APlayer::upInvincible(void)
{
  this->_score += 1000;
  this->_safe = INVINC_TICKS;
}

size_t	Bomberman::APlayer::getRemainingBombs(void) const
{
  size_t	bNbr = 0;

  for (std::list<Bomberman::Bomb *>::const_iterator it = this->_bombPool.begin();
       it != this->_bombPool.end(); it++)
    {
      if ((*it)->getId() == this->_id)
	bNbr++;
    }
  return (bNbr);
}

void		Bomberman::APlayer::stopRunAndIdle(Bomberman::PlayerView *playerView) const
{
  playerView->stopAnim("run");
  playerView->runAnim("idle");
}

void		Bomberman::APlayer::translateTo(Bomberman::PlayerView *playerView,
					       std::list<Bomberman::Dir> &dirList)
{
  std::list<Bomberman::Dir>::iterator min;
  std::list<Bomberman::Dir>::iterator max;

  min = std::min_element(dirList.begin(), dirList.end());
  max = std::max_element(dirList.begin(), dirList.end());
  for (std::list<Bomberman::Dir>::iterator it = dirList.begin(); it != dirList.end(); it++)
    if ((*it) != Bomberman::NONE)
      {
	this->move(*it);
	playerView->runAnim("run");
      }
    else
      this->stopRunAndIdle(playerView);
  if (dirList.empty())
    this->stopRunAndIdle(playerView);
  if (min != dirList.end() && max != dirList.end())
    {
      if (*min != *max)
	{
	  if ((*min) == RIGHT && (*max) == DOWN)
	    this->_angle = 45;
	  else
	    this->_angle = *max - 45;
	}
      else
	this->_angle = *min;
    }
}

void		Bomberman::APlayer::move(Bomberman::Dir dir)
{
  if (!this->getElementCollision(dir))
    {
      this->_pos.x += (dir == Bomberman::RIGHT ? this->_speed
		      : dir == Bomberman::LEFT ? -this->_speed : 0);
      this->_pos.z += (dir == Bomberman::DOWN ? this->_speed
		      : dir == Bomberman::UP ? -this->_speed : 0);
    }
}

bool		Bomberman::APlayer::getElementCollision(Bomberman::Dir dir)
{
  int		size = PLAYER_SIZE / 2;
  size_t	l_o = (this->_pos.x + (dir == Bomberman::RIGHT ? size + this->_speed :
				      dir == Bomberman::LEFT ? -(size + this->_speed) :
				      -size)) / TILE_SIZE;
  size_t        ol_o = (this->_pos.x + (dir == Bomberman::RIGHT ? size : -size)) / TILE_SIZE;
  size_t	r_o = (this->_pos.z + (dir == Bomberman::DOWN ? size + this->_speed :
				      dir == Bomberman::UP ? -(size + this->_speed) :
				      -size)) / TILE_SIZE;
  size_t        or_o = (this->_pos.z + (dir == Bomberman::DOWN ? size : -size)) / TILE_SIZE;
  size_t	l_t = (this->_pos.x + (dir == Bomberman::LEFT ? -(size + this->_speed) :
				      dir == Bomberman::RIGHT ? (size + this->_speed) :
				      size)) / TILE_SIZE;
  size_t	ol_t = (this->_pos.x + (dir == Bomberman::LEFT ? -size : size)) / TILE_SIZE;
  size_t	r_t = (this->_pos.z + (dir == Bomberman::UP ? -(size + this->_speed) :
				      dir == Bomberman::DOWN ? (size + this->_speed) :
				      size)) / TILE_SIZE;
  size_t	or_t = (this->_pos.z + (dir == Bomberman::UP ? -size : size)) / TILE_SIZE;

  if (l_o != ol_o || r_o != or_o || l_t != ol_t || r_t != or_t)
    return (this->handleCollision(l_o, r_o, l_t, r_t));
  return (false);
}

bool		Bomberman::APlayer::handleCollision(size_t ca, size_t cb, size_t cc, size_t cd)
{
  Bomberman::Tile	&to = this->_map.getTile(ca, cb);
  Bomberman::Tile	&tt = this->_map.getTile(cc, cd);

  if (!((to.getItem() && to.getItem()->isBlocking()) ||
	(tt.getItem() && tt.getItem()->isBlocking())))
    {
      this->handleBonus(to, ca, cb);
      if (ca != cc || cb != cd)
	this->handleBonus(tt, cc, cd);
      return (false);
    }
  return (true);
}

void		Bomberman::APlayer::handleBonus(const Bomberman::Tile &tile, size_t x, size_t y)
{
  Bomberman::Bonus	*bonus = dynamic_cast<Bomberman::Bonus *>(tile.getItem());

  if (bonus)
    {
      this->_score += 500;
      (this->*_bonusFunc[bonus->getBonus()])();
      Bomberman::Sound::getInstance()->playSound(bonus->isMalus() ? T_MALUS : T_BONUS);
      delete (bonus);
      this->_map.removeItem(x, y);
    }
}

void            Bomberman::APlayer::addScore(size_t score)
{
  this->_score += score;
}

size_t		Bomberman::APlayer::getScore() const
{
  return (this->_score);
}
