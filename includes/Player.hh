//
// Player.hh for bomberman in /home/chazal_l//Ydrasaal/PROJECT/Bomberman/Bomberman
//
// Made by leo chazal
// Login   <chazal_l@epitech.net>
//
// Started on  Mon May 13 13:12:30 2013 leo chazal
// Last update Sun Jun  9 19:50:29 2013 leo chazal
//

#pragma		once

#include	<GameClock.hpp>
#include	<Input.hpp>
#include	"APlayer.hh"
#include	"Save.hh"

namespace	Bomberman
{
  class		Player : public Bomberman::APlayer
  {
  private:
    const gdl::Keys::Key		*_keys;

  public:
    Player(const Bomberman::Save::Player &, Bomberman::Map &, std::list<Bomberman::Bomb *> &,
	   const gdl::Keys::Key (&)[KEY_NUMBER]);
    Player(size_t, Bomberman::Map &, std::list<Bomberman::Bomb *> &,
	   const gdl::Keys::Key (&)[KEY_NUMBER], const Vector3f &);
    ~Player();
    void	draw(void);
    void	update(const gdl::GameClock &, gdl::Input &);
    std::string	getName(void) const;
  };
}
