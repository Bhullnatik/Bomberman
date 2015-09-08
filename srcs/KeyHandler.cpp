//
// KeyHandler.cpp for bomberman in /home/chazal_l//Ydrasaal/PROJECT/Bomberman/Bomberman
//
// Made by leo chazal
// Login   <chazal_l@epitech.net>
//
// Started on  Wed Jun  5 19:10:15 2013 leo chazal
// Last update Sun Jun  9 21:02:59 2013 jimmy mayoukou
//

#include	<map>
#include	"KeyHandler.hh"

bool		KeyHandler::handle(gdl::Input &input, const gdl::Keys::Key &key)
{
  static std::map<gdl::Keys::Key, bool>	mapPressed;

  if (!mapPressed[key])
    {
      if (input.isKeyDown(key))
	{
	  mapPressed[key] = true;
	  return (true);
	}
    }
  else
    if (!input.isKeyDown(key))
      mapPressed[key] = false;
  return (false);
}

bool		KeyHandler::handle(gdl::Input &input, const gdl::Mouse::Button &button)
{
  static std::map<gdl::Mouse::Button, bool>	buttonPressed;

  if (!buttonPressed[button])
    {
      if (input.isMouseButtonDown(button))
	{
	  buttonPressed[button] = true;
	  return (true);
	}
    }
  else
    if (!input.isMouseButtonDown(button))
      buttonPressed[button] = false;
  return (false);
}
