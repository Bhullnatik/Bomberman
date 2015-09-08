//
// KeyHandler.hpp for bomberman in /home/chazal_l//Ydrasaal/PROJECT/Bomberman/Bomberman
//
// Made by leo chazal
// Login   <chazal_l@epitech.net>
//
// Started on  Tue Jun  4 18:33:53 2013 leo chazal
// Last update Sun Jun  9 20:44:59 2013 jimmy mayoukou
//

#pragma		once

#include	<Input.hpp>
#include	"bomberman.hh"

class		KeyHandler
{
public:
  static bool	handle(gdl::Input &, const gdl::Keys::Key &);
  static bool	handle(gdl::Input &, const gdl::Mouse::Button &);

private:
  KeyHandler();
  ~KeyHandler();
};
