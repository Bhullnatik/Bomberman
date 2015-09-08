//
// IA.cpp for IA in /home/kapous_c/Bomberman/srcs
//
// Made by Cyril Kapoustine
// Login   <kapous_c@epitech.net>
//
// Started on  Wed Jun  5 12:49:27 2013 Cyril Kapoustine
// Last update Sun Jun  9 19:53:54 2013 leo chazal
//

#include	<algorithm>
#include	<vector>
#include	"Bonus.hh"
#include	"Data.hpp"
#include	"Save.hh"
#include	"IA.hh"

#include	<iostream>

Bomberman::IA::IA(const Bomberman::Save::Player &save, Bomberman::Map &map, std::list<Bomberman::Bomb *> &bombs, const std::list<Bomberman::APlayer *> &players) : APlayer(save, map, bombs), _players(players)
{
  this->_Xobj = TILE_SIZE + (TILE_SIZE / 2);
  this->_Yobj = TILE_SIZE + (TILE_SIZE / 2);
  this->_angle = 0.0f;
  this->_tmpPosX = 0.0f;
  this->_tmpPosY = 0.0f;
}

Bomberman::IA::IA(size_t id, Bomberman::Map &map, std::list<Bomberman::Bomb *> &bombs,
		  const std::list<Bomberman::APlayer *> &players, const Vector3f &pos) : APlayer(id, map, bombs, pos), _players(players)
{
  this->_Xobj = TILE_SIZE + (TILE_SIZE / 2);
  this->_Yobj = TILE_SIZE + (TILE_SIZE / 2);
  this->_angle = 0.0f;
  this->_tmpPosX = 0.0f;
  this->_tmpPosY = 0.0f;
}

Bomberman::IA::~IA()
{
}

void	Bomberman::IA::draw()
{
  this->_view->draw(this);
}

bool			Bomberman::IA::inCenter(size_t x, size_t y)
{
  size_t		pixX;
  size_t		pixY;

  pixX = TO_REAL(x);
  pixY = TO_REAL(y);
  if (this->getPosition().x >= pixX - STEP &&
      this->getPosition().x <= pixX + STEP &&
      this->getPosition().z >= pixY - STEP &&
      this->getPosition().z <= pixY + STEP)
    return (true);
  return (false);
}

void			Bomberman::IA::findSolution(std::list<Bomberman::Dir> &dirList)
{
  if (this->ifWalkable(this->getPosition().x, this->getPosition().z, Bomberman::UP))
    {
      dirList.push_back(Bomberman::UP);
      this->_tmpPosX = this->getPosition().x;
      this->_tmpPosY = TO_REAL(TO_COORD(this->getPosition().z) - 1);
    }
  else if (this->ifWalkable(this->getPosition().x, this->getPosition().z, Bomberman::DOWN))
    {
      dirList.push_back(Bomberman::DOWN);
      this->_tmpPosX = this->getPosition().x;
      this->_tmpPosY = TO_REAL(TO_COORD(this->getPosition().z) + 1);
    }
  else if (this->ifWalkable(this->getPosition().x, this->getPosition().z, Bomberman::LEFT))
    {
      dirList.push_back(Bomberman::LEFT);
      this->_tmpPosX = TO_REAL(TO_COORD(this->getPosition().x) - 1);
      this->_tmpPosY = this->getPosition().z;
    }
  else if (this->ifWalkable(this->getPosition().x, this->getPosition().z, Bomberman::RIGHT))
    {
      dirList.push_back(Bomberman::RIGHT);
      this->_tmpPosX = this->getPosition().x;
      this->_tmpPosY = TO_REAL(TO_COORD(this->getPosition().z) + 1);
    }
}

bool			Bomberman::IA::ifWalkable(float x, float y, Bomberman::Dir dir)
{
  if (!this->inCenter(TO_COORD(x), TO_COORD(y)))
    return (true);
  if (this->near(x, y, Bomberman::WALL, dir) ||
      this->near(x, y, Bomberman::BLOCK, dir) ||
      this->near(x, y, Bomberman::BOMB, dir))
    return (false);
  return (true);
}

bool			Bomberman::IA::verifObj(void)
{
  size_t                        bombPower;

  bombPower = TILE_SIZE + (TILE_SIZE / 2);
  if (((this->getPosition().x <= this->_Xobj + bombPower) &&
       (this->getPosition().x >= this->_Xobj - bombPower)) &&
      ((this->getPosition().z >= this->_Yobj - (TILE_SIZE / 2)) &&
       (this->getPosition().z <= this->_Yobj + (TILE_SIZE / 2))))
    return (true);
  if (((this->getPosition().z <= this->_Yobj + bombPower) &&
       (this->getPosition().z >= this->_Yobj - bombPower)) &&
      ((this->getPosition().x >= this->_Xobj - (TILE_SIZE / 2)) &&
       (this->getPosition().x <= this->_Xobj + (TILE_SIZE / 2))))
    return (true);
  return (false);
}

void			Bomberman::IA::makeMoveDecision(std::list<Bomberman::Dir> &dirList)
{
  double		hyp = std::abs(sqrt(pow(this->_Xobj - this->getPosition().x, 2) +
				       pow(this->_Yobj - this->getPosition().z, 2)));
  double		adj = std::abs(sqrt(pow(this->_Yobj - this->getPosition().z, 2)));

  if (!this->_angle || this->inCenter(TO_COORD(this->_tmpPosX), TO_COORD(this->_tmpPosY)))
    this->_angle = TO_DEGREE(acos(adj / hyp));
  if (this->getPosition().x == this->_Xobj && this->getPosition().z == this->_Yobj)
    {
      dirList.push_back(Bomberman::NONE);
      return ;
    }
  if (this->_Xobj >= this->getPosition().x &&
      this->_Yobj >= this->getPosition().z)
    this->_angle -= 180.0f;
  else if (this->_Xobj < this->getPosition().x &&
	   this->_Yobj >= this->getPosition().z)
    this->_angle = (this->_angle - 180.0f) + 180.0f;
  else if (this->_Xobj < this->getPosition().x &&
	   this->_Yobj < this->getPosition().z)
    this->_angle += 180.0f;
  this->_angle = std::abs(this->_angle);
  if (this->_angle > 315.0f && this->_angle <= 45.0f)
    {
      if (this->ifWalkable(this->getPosition().x, this->getPosition().z, Bomberman::UP))
	{
	  dirList.push_back(Bomberman::UP);
	  this->_tmpPosX = this->getPosition().x;
	  this->_tmpPosY = TO_REAL(TO_COORD(this->getPosition().z) - 1);
	}
      else
	this->findSolution(dirList);
    }
  else if (this->_angle > 45.0f && this->_angle <= 135.0f)
    {
      if (this->ifWalkable(this->getPosition().x, this->getPosition().z, Bomberman::RIGHT))
	{
	  dirList.push_back(Bomberman::RIGHT);
	  this->_tmpPosX = TO_REAL(TO_COORD(this->getPosition().x) + 1);
	  this->_tmpPosY = this->getPosition().z;
	}
      else
	this->findSolution(dirList);
    }
  else if (this->_angle > 135.0f && this->_angle <= 225.0f)
    {
      if (this->ifWalkable(this->getPosition().x, this->getPosition().z, Bomberman::DOWN))
	{
	  dirList.push_back(Bomberman::DOWN);
	  this->_tmpPosX = this->getPosition().x;
	  this->_tmpPosY = TO_REAL(TO_COORD(this->getPosition().z) + 1);
	}
      else
	this->findSolution(dirList);
    }
  else
    {
      if (this->ifWalkable(this->getPosition().x, this->getPosition().z, Bomberman::LEFT))
	{
	  dirList.push_back(Bomberman::LEFT);
	  this->_tmpPosX = TO_REAL(TO_COORD(this->getPosition().x) - 1);
	  this->_tmpPosY = this->getPosition().z;
	}
      else
	this->findSolution(dirList);
    }
  if (static_cast<size_t>(TO_COORD(this->_tmpPosX)) > this->_map.getSizeX() - 2)
    this->_tmpPosX -= 1;
  if (static_cast<size_t>(TO_COORD(this->_tmpPosY)) > this->_map.getSizeY() - 2)
    this->_tmpPosY -= 1;
  if (this->_tmpPosX == 0)
    this->_tmpPosX++;
  if (this->_tmpPosY == 0)
    this->_tmpPosY++;
}

void			Bomberman::IA::destroyBlock(void)
{
  size_t       		pX = 0;
  size_t       		pY = 0;
  double		dist = 0;

  for (std::vector<Bomberman::Tile>::const_iterator it = this->_map.getLevel().begin();
       it != this->_map.getLevel().end(); it++)
    {
      if ((*it).getItem() && (*it).getItem()->getType() == BLOCK)
        {
	  if (dist == 0 ||
	      dist > std::abs(sqrt(pow(((*it).getX() * TILE_SIZE + (TILE_SIZE / 2)) - this->getPosition().x, 2) +
			      pow(((*it).getY() * TILE_SIZE + (TILE_SIZE / 2)) - this->getPosition().z, 2))))
            {
	      pX = (*it).getX() * TILE_SIZE + (TILE_SIZE / 2);
              pY = (*it).getY() * TILE_SIZE + (TILE_SIZE / 2);
              dist = std::abs(sqrt(pow(pX - this->getPosition().x, 2) + pow(pY - this->getPosition().z, 2)));
	    }
        }
    }
  if (!pX && !pY)
    return ;
  this->_Xobj = pX;
  this->_Yobj = pY;
}

bool			Bomberman::IA::near(float x, float y, Bomberman::Element element, Bomberman::Dir dir)
{
  Bomberman::AElement	*nearby[4] = {NULL, NULL, NULL, NULL};

  nearby[0] = this->_map.getTile(TO_COORD(x) + 1, TO_COORD(y)).getItem();
  nearby[1] = this->_map.getTile(TO_COORD(x) - 1, TO_COORD(y)).getItem();
  nearby[2] = this->_map.getTile(TO_COORD(x), TO_COORD(y) + 1).getItem();
  nearby[3] = this->_map.getTile(TO_COORD(x), TO_COORD(y) - 1).getItem();
  if ((dir == Bomberman::NONE || dir == Bomberman::RIGHT) &&
      nearby[0] && nearby[0]->getType() == element)
    return (true);
  if ((dir == Bomberman::NONE || dir == Bomberman::LEFT) &&
      nearby[1] && nearby[1]->getType() == element)
    return (true);
  if ((dir == Bomberman::NONE || dir == Bomberman::DOWN) &&
      nearby[2] && nearby[2]->getType() == element)
    return (true);
  if ((dir == Bomberman::NONE || dir == Bomberman::UP) &&
      nearby[3] && nearby[3]->getType() == element)
    return (true);
  return (false);
}

bool			Bomberman::IA::detectPowerUp(void)
{
  size_t       		bonusX = 0;
  size_t       		bonusY = 0;
  double		dist = 0;

  for (std::vector<Bomberman::Tile>::const_iterator it = this->_map.getLevel().begin();
       it != this->_map.getLevel().end(); it++)
    {
      if ((*it).getItem() && (*it).getItem()->getType() == BONUS)
        {
	  if (dist == 0 ||
	      dist > std::abs(sqrt(pow(((*it).getX() * TILE_SIZE + (TILE_SIZE / 2)) - this->getPosition().x, 2) +
			      pow(((*it).getY()  * TILE_SIZE + (TILE_SIZE / 2)) - this->getPosition().z, 2))))
            {
	      bonusX = (*it).getX();
              bonusY = (*it).getY();
              dist = std::abs(sqrt(pow(bonusX - this->getPosition().x, 2) + pow(bonusY - this->getPosition().z, 2)));
            }
        }
    }
  if (!bonusX && !bonusY)
    return (false);
  this->_Xobj = bonusX * TILE_SIZE + (TILE_SIZE / 2);
  this->_Yobj = bonusY * TILE_SIZE + (TILE_SIZE / 2);
  return (true);
}

bool		Bomberman::IA::detectDangerZone(void)
{
  for (std::vector<Bomberman::Tile>::const_iterator it = this->_map.getLevel().begin();
       it != this->_map.getLevel().end(); it++)
    {
      if ((*it).getItem() && (*it).getItem()->getType() == BOMB)
	{
	  Bomberman::Bomb		*bomb = dynamic_cast<Bomberman::Bomb *>((*it).getItem());
	  size_t			bombX = bomb->getX();
	  size_t			bombY = bomb->getY();
	  size_t			bombPower;

	  if (!bomb)
	    break;
	  bombPower = bomb->getPower() * TILE_SIZE + (TILE_SIZE / 2);
	  if (((this->getPosition().x <= bombX + bombPower) &&
	       (this->getPosition().x >= bombX - bombPower)) &&
	      ((this->getPosition().z >= bombY - (TILE_SIZE / 2)) &&
	       (this->getPosition().z <= bombY + (TILE_SIZE / 2))))
	    return (true);
	  if (((this->getPosition().z <= bombY + bombPower) &&
	       (this->getPosition().z >= bombY - bombPower)) &&
	      ((this->getPosition().x >= bombX - (TILE_SIZE / 2)) &&
	       (this->getPosition().x <= bombX + (TILE_SIZE / 2))))
	    return (true);
	}
      else if ((*it).getItem() && (*it).getItem()->getType() == FIRE)
	{
	  Bomberman::Fire		*fire = dynamic_cast<Bomberman::Fire *>((*it).getItem());
	  size_t			bombX = fire->getX();
	  size_t			bombY = fire->getY();
	  size_t			bombPower;

	  bombPower = (TILE_SIZE / 2) + 10;
	  if (((this->getPosition().x <= bombX + bombPower) &&
	       (this->getPosition().x >= bombX - bombPower)) &&
	      ((this->getPosition().z >= bombY - (TILE_SIZE / 2)) &&
	       (this->getPosition().z <= bombY + (TILE_SIZE / 2))))
	    return (true);
	  if (((this->getPosition().z <= bombY + bombPower) &&
	       (this->getPosition().z >= bombY - bombPower)) &&
	      ((this->getPosition().x >= bombX - (TILE_SIZE / 2)) &&
	       (this->getPosition().x <= bombX + (TILE_SIZE / 2))))
	    return (true);
	}
    }
  return (false);
}

bool		Bomberman::IA::findSafePlace()
{
  size_t	safeX = 0.0f;
  size_t	safeY = 0.0f;
  double	dist = 0;

  for (std::vector<Bomberman::Tile>::const_iterator it = this->_map.getLevel().begin();
       it != this->_map.getLevel().end(); it++)
    {
      if (!(*it).getItem())
	{
	  if (this->detectDangerZone())
	    {
	      if (dist == 0 || dist > std::abs(sqrt(pow(((*it).getX() * TILE_SIZE + (TILE_SIZE / 2)) -
						   this->getPosition().x, 2) +
					       pow(((*it).getY()  * TILE_SIZE + (TILE_SIZE / 2))
						   - this->getPosition().z, 2))))
		{
		  safeX = (*it).getX() * TILE_SIZE + (TILE_SIZE / 2);
		  safeY = (*it).getY() * TILE_SIZE + (TILE_SIZE / 2);
		  dist = std::abs(sqrt(pow(safeX - this->getPosition().x, 2) + pow(safeY - this->getPosition().z, 2)));
		}
	    }
	}
    }
  if (!safeX && !safeY)
    return (false);
  this->_Xobj = safeX;
  this->_Yobj = safeY;
  return (true);
}

void		Bomberman::IA::update(const gdl::GameClock &gClock, gdl::Input &)
{
  Bomberman::PlayerView		*playerView = static_cast<Bomberman::PlayerView *>(this->_view);
  std::list<Bomberman::Dir>	dirList;

  this->_score++;
  if (this->_safe)
    this->_safe--;
  playerView->getModel().update(gClock);
  playerView->getModel().set_anim_speed("run", static_cast<float>(this->_speed) / 5);

  if (detectDangerZone())
    {
      this->_typeObj = Bomberman::SURVIVE;
      if (findSafePlace())
	this->makeMoveDecision(dirList);
    }
  else
    {
      if (detectPowerUp())
	{
	  this->_typeObj = Bomberman::GETBONUS;
	  this->makeMoveDecision(dirList);
	}
      else
	{
	  this->_typeObj = Bomberman::DBLOCK;
	  destroyBlock();
	  if (this->near(this->getPosition().x, this->getPosition().z, Bomberman::BLOCK))
	    this->placeBomb(gClock);
	  else
	    {
	      if (this->_typeObj == Bomberman::GETBONUS && this->verifObj())
		{
		  this->placeBomb(gClock);
		  this->_typeObj = Bomberman::SURVIVE;
		  if (findSafePlace())
		    this->makeMoveDecision(dirList);
		}
	      this->makeMoveDecision(dirList);
	    }
	}
    }
  this->translateTo(playerView, dirList);
}

std::string	Bomberman::IA::getName(void) const
{
  return ("IA");
}
