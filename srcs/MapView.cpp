//
// MapView.cpp for bomberman in /home/chazal_l//Ydrasaal/PROJECT/Bomberman/Bomberman
//
// Made by leo chazal
// Login   <chazal_l@epitech.net>
//
// Started on  Wed May 15 17:13:45 2013 leo chazal
// Last update Sat Jun  8 09:29:36 2013 leo chazal
//

#include        <OpenGL/gl.h>
#include        <OpenGL/glu.h>

#include	"Map.hh"
#include	"MapView.hh"
#include	"BlockView.hh"

#include	<iostream>

Bomberman::MapView::MapView()
{

}

Bomberman::MapView::~MapView()
{

}

Bomberman::MapView	*Bomberman::MapView::getInstance(void)
{
  static MapView	*instance = new MapView();

  return (instance);
}

void			Bomberman::MapView::initialize(void)
{

}

void			Bomberman::MapView::draw(const AModel *model)
{
  const Bomberman::Map		*map = dynamic_cast<const Bomberman::Map *>(model);
  std::vector<Bomberman::Tile>	tiles = map->getLevel();


  for (std::vector<Bomberman::Tile>::iterator it = tiles.begin();
       it != tiles.end(); it++)
    (*it).draw();
}
