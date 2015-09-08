//
// main.cpp for Bomberman in /home/mayouk_j/CPP/Bomberman
//
// Made by jimmy mayoukou
// Login   <mayouk_j@epitech.net>
//
// Started on  Wed May  8 02:30:24 2013 jimmy mayoukou
// Last update Sun Jun  9 20:25:22 2013 leo chazal
//

#include		<cstdlib>
#include		"Game.hh"

int			main()
{
  Bomberman::Game	game;

  if (!getenv("DISPLAY"))
    return (EXIT_FAILURE);
  game.run();
  return (EXIT_SUCCESS);
}
