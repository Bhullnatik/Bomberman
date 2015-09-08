//
// Save.cpp for Bomberman in /home/mayouk_j/CPP/Bomberman
//
// Made by jimmy mayoukou
// Login   <mayouk_j@epitech.net>
//
// Started on  Sat Jun  1 12:10:10 2013 jimmy mayoukou
// Last update Sun Jun  9 17:10:59 2013 jimmy mayoukou
//

#include	<fstream>
#include	<stdexcept>
#include	"Engine.hh"
#include	"Player.hh"
#include	"Save.hh"

void			Bomberman::Save::save(const Bomberman::Engine *engine, const std::string &filename)
{
  std::ofstream		stream((SAVE_PATH + filename).c_str());

  if (!stream)
    throw std::runtime_error("Bomberman: Cannot save to file " + filename);
  stream.write(KEY_SAVE, KEY_SAVE_LEN);
  engine->serialize(stream);
  stream.close();
}

Bomberman::Engine	*Bomberman::Save::load(const std::string &filename, Bomberman::Game *game)
{
  std::ifstream		stream(filename.c_str());
  Engine		*engine = NULL;
  char			key[KEY_SAVE_LEN];

  if (!stream)
    throw std::runtime_error("Bomberman: Cannot load from file " + filename);
  stream.read(key, KEY_SAVE_LEN);
  if (std::string(key) != KEY_SAVE)
    throw std::runtime_error("Bomberman: invalid save file " + filename);
  engine = new Engine(game, stream);
  stream.close();
  return (engine);
}

Bomberman::Save::Player::Player()
{
}

Bomberman::Save::Player::Player(const Bomberman::APlayer *player)
{
  this->pos = player->getPosition();
  this->id = player->getId();
  this->bombNbr = player->getBombNumber();
  this->bombPwr = player->getBombPower();
  this->speed = player->getSpeed();
  this->angle = player->getAngle();
  this->safe = player->getSafeTime();
  this->score = player->getScore();
  this->isHuman = dynamic_cast<const Bomberman::Player *>(player);
}

Bomberman::Save::Bomb::Bomb()
{
}

Bomberman::Save::Bomb::Bomb(const Bomberman::Bomb *bomb)
{
  this->power = bomb->getPower();
  this->posX = bomb->getX();
  this->posY = bomb->getY();
  this->tick = bomb->getTicks();
  this->id = bomb->getId();
}
