//
// Player.cpp for bomberman in /home/chazal_l//Ydrasaal/PROJECT/Bomberman/Bomberman
//
// Made by leo chazal
// Login   <chazal_l@epitech.net>
//
// Started on  Mon May 13 13:23:27 2013 leo chazal
// Last update Sun Jun  9 21:44:28 2013 leo chazal
//

#include	<iostream>
#include	"Data.hpp"
#include	"Player.hh"
#include	"Save.hh"
#include	"KeyHandler.hh"
#include	"Sound.hh"

Bomberman::Player::Player(const Bomberman::Save::Player &save, Bomberman::Map &map, std::list<Bomberman::Bomb *> &bombs, const gdl::Keys::Key (&keys)[KEY_NUMBER]) : APlayer(save, map, bombs), _keys(keys)
{
}

Bomberman::Player::Player(size_t id, Bomberman::Map &map, std::list<Bomberman::Bomb *> &bombs,
			  const gdl::Keys::Key (&keys)[KEY_NUMBER], const Vector3f &pos) : APlayer(id, map, bombs, pos), _keys(keys)
{
}

Bomberman::Player::~Player()
{
}

void		Bomberman::Player::draw()
{
  this->_view->draw(this);
}

void		Bomberman::Player::update(const gdl::GameClock &gameClock, gdl::Input &input)
{
  Bomberman::PlayerView		*playerView = static_cast<Bomberman::PlayerView *>(this->_view);
  std::list<Bomberman::Dir>	listDir;

  this->_score += 1;
  if (this->_safe)
    this->_safe--;
  playerView->getModel().update(gameClock);
  playerView->getModel().set_anim_speed("run", static_cast<float>(this->_speed) / 5);
  if (input.isKeyDown(this->_keys[KEY_RIGHT]))
    listDir.push_back(Bomberman::RIGHT);
  if (input.isKeyDown(this->_keys[KEY_LEFT]))
    listDir.push_back(Bomberman::LEFT);
  if (input.isKeyDown(this->_keys[KEY_UP]))
    listDir.push_back(Bomberman::UP);
  if (input.isKeyDown(this->_keys[KEY_DOWN]))
    listDir.push_back(Bomberman::DOWN);
  this->translateTo(playerView, listDir);
  if (input.isKeyDown(this->_keys[KEY_BOMB]))
    this->placeBomb(gameClock);
}

std::string     Bomberman::Player::getName(void) const
{
  return ("Player");
}
