//
// Engine.cpp for bomberman in /home/chazal_l//Ydrasaal/PROJECT/Bomberman/Bomberman
//
// Made by leo chazal
// Login   <chazal_l@epitech.net>
//
// Started on  Fri May 10 19:47:24 2013 leo chazal
// Last update Sun Jun  9 22:24:07 2013 Jérémy Magrin
//

#include	<iostream>
#include	<stdexcept>
#include	"Data.hpp"
#include	"Engine.hh"
#include	"IA.hh"
#include	"Player.hh"
#include	"Save.hh"
#include	"Sound.hh"
#include	"Game.hh"
#include	"EndGameScreen.hh"
#include	"Drawable.hh"
#include	"KeyHandler.hh"
#include	"MyText.hh"
#include	"Utilities.hh"
#include	"Error.hh"
#include	"bomberman.hh"

Bomberman::Engine::Engine(Bomberman::Game *main, size_t pNumber)
  : AModel(NULL), _map(pNumber), _war(this->_map), _main(main), _hasKeys(false), _paused(false)
{

}

Bomberman::Engine::Engine(Bomberman::Game *main, const std::string &pname)
  : AModel(NULL), _map(pname), _war(this->_map), _main(main), _hasKeys(false), _paused(false)
{

}

Bomberman::Engine::Engine(Bomberman::Game *main, std::ifstream &stream)
  : AModel(NULL), _war(this->_map), _main(main), _hasKeys(false), _paused(false)
{
  size_t	nb(0);

  stream.read((char *) &nb, sizeof(nb));
  for (size_t it = 0; it < nb; ++it)
    {
      Bomberman::Save::Player	savePlayer;

      stream.read((char *) &savePlayer, sizeof(savePlayer));
      if (!stream)
	throw std::runtime_error("Bomberman: invalid save file");
      this->createPlayer(savePlayer);
    }
  if (!stream)
    throw std::runtime_error("Bomberman: invalid save file");
  stream.read((char *) &nb, sizeof(nb));
  for (size_t it = 0; it < nb; ++it)
    {
      Bomberman::Save::Bomb	saveBomb;

      stream.read((char *) &saveBomb, sizeof(saveBomb));
      if (!stream)
	throw std::runtime_error("Bomberman: invalid save file");
      this->_war.getBombs().push_back(new Bomberman::Bomb(saveBomb));
    }
  if (!stream)
    throw std::runtime_error("Bomberman: invalid save file");
  this->_map = Bomberman::Map(stream);
  for (std::list<Bomberman::Bomb *>::iterator it = this->_war.getBombs().begin();
       it != this->_war.getBombs().end(); ++it)
    this->_map.setTileContent((*it)->getX() / TILE_SIZE, (*it)->getY() / TILE_SIZE, (*it));
  this->validPosPlayer();
}

Bomberman::Engine::~Engine()
{
}

size_t	Bomberman::Engine::getSizeXMap() const
{
  return (this->_map.getSizeX());
}

size_t	Bomberman::Engine::getSizeYMap() const
{
  return (this->_map.getSizeY());
}

const std::list<Vector3f>	Bomberman::Engine::getPlayerList() const
{
  std::list<Vector3f>		posPlayerList;

  for (std::list<Bomberman::APlayer *>::const_iterator it = this->_player.begin();
       it != this->_player.end(); ++it)
    if (dynamic_cast<Bomberman::Player *>((*it)) != NULL)
      posPlayerList.push_back((*it)->getPosition());
  return (posPlayerList);
}

void	Bomberman::Engine::draw(void)
{
  Bomberman::Drawable::getInstance()->drawBg(Bomberman::Data::getInstance()->getLevelType());
  this->_map.draw();
  this->_war.draw();
  for (std::list<Bomberman::APlayer *>::iterator it = this->_player.begin();
       it != this->_player.end(); ++it)
    (*it)->draw();
  if (this->_paused)
    this->drawPause();
}

void	Bomberman::Engine::initialize(size_t nbIAs, size_t nbPlayers)
{
  if (nbPlayers > 0)
    {
      this->createPlayer(true);
      if (nbPlayers > 1)
	this->createPlayer(true);
    }
  for (size_t it = 0; it < nbIAs; ++it)
    this->createPlayer(false);
  Bomberman::Data::getInstance()->setLevelType();
}

void	Bomberman::Engine::update(const gdl::GameClock &clock, gdl::Input &input)
{
  Bomberman::Sound::getInstance()->playTrack(Bomberman::Data::getInstance()->getLevelType());
  if (KeyHandler::handle(input, gdl::Keys::Return))
    this->_paused = !this->_paused;
  if (this->_paused)
    {
      this->pause(input);
      return;
    }
  this->_map.update(clock, input);
  this->_war.update(clock, input);
  bool	isThereStillPlayer = false;

  for (std::list<Bomberman::APlayer *>::iterator it = this->_player.begin();
       it != this->_player.end();)
    {
      if (!(*it)->isAlive(this->_war.getFire()))
	{
	  Bomberman::Sound::getInstance()->playSound(T_DEATH);
	  this->_main->addHighScore("Toto", (*it)->getScore());
	  delete (*it);
	  it = this->_player.erase(it);
	  continue;
	}
      isThereStillPlayer = (isThereStillPlayer ? true
			    : (dynamic_cast<Bomberman::Player *>((*it))) != NULL);
      (*it)->update(clock, input);
      it++;
    }
  if (this->_player.size() <= 1 || !isThereStillPlayer)
    this->endGame(isThereStillPlayer);
}

void	Bomberman::Engine::endGame(bool player)
{
  this->_main->popCurrentView();
  this->_main->setCurrentView(new Bomberman::EndGameScreen(this->_main, this->_player, player));
  delete (this);
}

void		Bomberman::Engine::validPosPlayer(void) const
{
  for (std::list<Bomberman::APlayer *>::const_iterator it = this->_player.begin();
       it != this->_player.end(); it++)
    {
      if ((*it) && (((*it)->getPosition().x > ((this->_map.getSizeX() - 2) * TILE_SIZE) + TILE_SIZE - (PLAYER_SIZE / 2)) ||
		    ((*it)->getPosition().x < TILE_SIZE + (PLAYER_SIZE / 2)) ||
		    ((*it)->getPosition().z > ((this->_map.getSizeY() - 2) * TILE_SIZE) + TILE_SIZE - (PLAYER_SIZE / 2)) ||
		    ((*it)->getPosition().z < TILE_SIZE + (PLAYER_SIZE / 2))))
	throw std::runtime_error("Bomberman : Invalid player position");
    }
}

Vector3f	Bomberman::Engine::getPlayerSpawn(void)
{
  Bomberman::AElement   *nearby[5] = {NULL, NULL, NULL, NULL, NULL};
  Vector3f		coord, base, pos;
  size_t       		i = 0;

  base.x = -1.0f;
  base.y = -1.0f;
  base.z = -1.0f;
  while (i < (this->_map.getSizeX() - 2) * (this->_map.getSizeY() - 2))
    {
      coord.x = (rand() % (this->_map.getSizeX() - 2)) + 1;
      coord.z = (rand() % (this->_map.getSizeY() - 2)) + 1;
      nearby[0] = this->_map.getTile(coord.x, coord.z).getItem();
      nearby[1] = this->_map.getTile(coord.x + 1, coord.z).getItem();
      nearby[2] = this->_map.getTile(coord.x - 1, coord.z).getItem();
      nearby[3] = this->_map.getTile(coord.x, coord.z + 1).getItem();
      nearby[4] = this->_map.getTile(coord.x, coord.z - 1).getItem();
      if (((!nearby[0] || (nearby[0] && nearby[0]->getType() == Bomberman::BLOCK)) &&
	   (!nearby[1] || (nearby[1] && nearby[1]->getType() == Bomberman::BLOCK)) &&
	   (!nearby[3] || (nearby[3] && nearby[3]->getType() == Bomberman::BLOCK))) ||
	  ((!nearby[0] || (nearby[0] && nearby[0]->getType() == Bomberman::BLOCK)) &&
	   (!nearby[2] || (nearby[2] && nearby[2]->getType() == Bomberman::BLOCK)) &&
	   (!nearby[3] || (nearby[3] && nearby[3]->getType() == Bomberman::BLOCK))) ||
	  ((!nearby[0] || (nearby[0] && nearby[0]->getType() == Bomberman::BLOCK)) &&
	   (!nearby[4] || (nearby[4] && nearby[4]->getType() == Bomberman::BLOCK)) &&
	   (!nearby[1] || (nearby[1] && nearby[1]->getType() == Bomberman::BLOCK))) ||
	  ((!nearby[0] || (nearby[0] && nearby[0]->getType() == Bomberman::BLOCK)) &&
	   (!nearby[2] || (nearby[2] && nearby[2]->getType() == Bomberman::BLOCK)) &&
	   (!nearby[4] || (nearby[4] && nearby[4]->getType() == Bomberman::BLOCK))) ||
	  ((!nearby[0] || (nearby[0] && nearby[0]->getType() == Bomberman::BLOCK)) &&
	   (!nearby[1] || (nearby[1] && nearby[1]->getType() == Bomberman::BLOCK)) &&
	   (!nearby[2] || (nearby[2] && nearby[2]->getType() == Bomberman::BLOCK)) &&
	   (!nearby[3] || (nearby[3] && nearby[3]->getType() == Bomberman::BLOCK)) &&
	   (!nearby[4] || (nearby[4] && nearby[4]->getType() == Bomberman::BLOCK))))
	{
	  if (nearby[0] && nearby[0]->getType() == Bomberman::BLOCK)
	    this->_map.removeItem(coord.x, coord.z);
	  if (nearby[1] && nearby[1]->getType() == Bomberman::BLOCK)
	    this->_map.removeItem(coord.x + 1, coord.z);
	  if (nearby[2] && nearby[2]->getType() == Bomberman::BLOCK)
	    this->_map.removeItem(coord.x - 1, coord.z);
	  if (nearby[3] && nearby[3]->getType() == Bomberman::BLOCK)
	    this->_map.removeItem(coord.x, coord.z + 1);
	  if (nearby[4] && nearby[4]->getType() == Bomberman::BLOCK)
	    this->_map.removeItem(coord.x, coord.z - 1);
	  pos.x = (coord.x * TILE_SIZE) + (TILE_SIZE / 2);
	  pos.z = (coord.z * TILE_SIZE) + (TILE_SIZE / 2);
	  if (this->_player.size() == 0)
	    return (pos);
	  for (std::list<Bomberman::APlayer *>::const_iterator it = this->_player.begin();
	       it != this->_player.end(); it++)
	    if (pos.x != (*it)->getPosition().x || pos.z != (*it)->getPosition().z)
	      return (pos);
	}
      i++;
    }
  return (base);
}

void		Bomberman::Engine::createPlayer(bool isHuman)
{
  Vector3f		pos;
  Bomberman::APlayer	*player = NULL;
  static size_t		id = 1;

  if (isHuman)
    {
      const key_array &keys = (this->_hasKeys ? Bomberman::Data::getInstance()->getP2Keys() :
	      Bomberman::Data::getInstance()->getP1Keys());
      pos = this->getPlayerSpawn();
      if (pos.x != -1 && pos.y != -1 && pos.z != -1)
	player = new Bomberman::Player(id, this->_map, this->_war.getBombs(),
				       keys, this->getPlayerSpawn());
      this->_hasKeys = true;
    }
  else
    {
      pos = this->getPlayerSpawn();
      if (pos.x != -1 && pos.y != -1 && pos.z != -1)
	player = new Bomberman::IA(id, this->_map, this->_war.getBombs(),
				   this->_player, this->getPlayerSpawn());
    }
  ++id;
  if (player != NULL)
    this->_player.push_back(player);
}

void			Bomberman::Engine::createPlayer(const Bomberman::Save::Player &save)
{
  Bomberman::APlayer	*player = NULL;

  if (save.isHuman)
    {
      const key_array &keys = (this->_hasKeys ? Bomberman::Data::getInstance()->getP2Keys() :
	      Bomberman::Data::getInstance()->getP1Keys());
      player = new Bomberman::Player(save, this->_map, this->_war.getBombs(), keys);
      this->_hasKeys = true;
    }
  else
    player = new Bomberman::IA(save, this->_map, this->_war.getBombs(), this->_player);
  this->_player.push_back(player);
}

void		Bomberman::Engine::serialize(std::ostream &stream) const
{
  size_t	size;

  size = this->_player.size();
  stream.write((char *) &size, sizeof(size));
  for (std::list<Bomberman::APlayer *>::const_iterator it = this->_player.begin();
       it != this->_player.end(); ++it)
    (*it)->serialize(stream);
  const std::list<Bomberman::Bomb *>	&bombs = this->_war.getBombs();
  size = bombs.size();
  stream.write((char *) &size, sizeof(size));
  for (std::list<Bomberman::Bomb *>::const_iterator it = bombs.begin();
       it != bombs.end(); ++it)
    (*it)->serialize(stream);
  this->_map.serialize(stream);
}

void	Bomberman::Engine::setCameraMode(Bomberman::Camera &cam, const gdl::Window &)
{
  cam.setPlayers(this->getPlayerList());
}

void	Bomberman::Engine::pause(gdl::Input &input)
{
  bool		saved = false;

  if (KeyHandler::handle(input, gdl::Keys::S) && !saved)
    {
      try {
	Bomberman::Save::save(this, "save_" + Utilities::getTimestamp() + SAVE_EXTENSION);
      } catch (std::exception &e) {
	this->_main->setCurrentView(new Bomberman::Error(this->_main, e.what()));
      }
      saved = true;
    }
}

void	Bomberman::Engine::drawPause()
{
  Bomberman::Drawable::getInstance()->drawBg(8);
}
