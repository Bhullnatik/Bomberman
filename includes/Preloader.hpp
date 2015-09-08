//
// Loader.hpp for bomberman in /home/chazal_l//Ydrasaal/PROJECT/Bomberman/Bomberman
//
// Made by leo chazal
// Login   <chazal_l@epitech.net>
//
// Started on  Sun Jun  9 20:11:16 2013 leo chazal
// Last update Sun Jun  9 22:12:13 2013 leo chazal
//

#pragma		once

#include        <OpenGL/gl.h>
#include        <OpenGL/glu.h>
#include	<cstdlib>
#include	<Window.hpp>
#include        "Data.hpp"
#include        "BlockView.hh"
#include        "Block.hh"
#include        "BonusView.hh"
#include        "FireView.hh"
#include        "MapView.hh"
#include        "TileView.hh"
#include        "WallView.hh"
#include        "Wall.hh"

namespace	Bomberman
{
  class		Preloader
  {
  public:
    Preloader(gdl::Window &win)
    {
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      this->draw(win);
      for (int i = 50; i > 0; i--)
	win.display();
      this->load();
    }

    ~Preloader() {};

  private:
    Preloader();

    void	draw(gdl::Window &)
    {
      gdl::Image	bg = gdl::Image::load(BG_PRELOAD);
      Bomberman::Drawable::pushOrthoMatrix(1, 1);
      Bomberman::Drawable::drawAt(0, 0, 1, 1, bg);
      Bomberman::Drawable::popOrthoMatrix();
    }

    void	load(void)
    {
      Bomberman::Data::getInstance();
      Bomberman::Block::getInstance();
      Bomberman::BlockView::getInstance();
      Bomberman::BonusView::getInstance();
      Bomberman::FireView::getInstance();
      Bomberman::MapView::getInstance();
      Bomberman::Sound::getInstance();
      Bomberman::TileView::getInstance();
      Bomberman::Wall::getInstance();
      Bomberman::WallView::getInstance();
    }
  };
}
