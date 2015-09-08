//
// MenuHomeView.cpp for  in /home/hoarau_s/Projets/Bomberman/Bomberman/srcs
//
// Made by stephen hoarau
// Login   <hoarau_s@epitech.net>
//
// Started on  Thu Jun  6 15:06:03 2013 stephen hoarau
// Last update Fri Jun  7 22:59:43 2013 leo chazal
//

#include	"MainMenuHomeView.hh"
#include	"MainMenuHome.hh"

Bomberman::MainMenuHomeView::MainMenuHomeView()
{
  this->initialize();
}

void		Bomberman::MainMenuHomeView::initialize()
{

}

void		Bomberman::MainMenuHomeView::draw(const AModel *inst)
{
  const	Bomberman::MainMenuHome	*menu = dynamic_cast<const Bomberman::MainMenuHome *>(inst);
  Bomberman::MyText		text;

  text = menu->getText();
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glPushAttrib(GL_COLOR_BUFFER_BIT | GL_CURRENT_BIT   | GL_ENABLE_BIT  |
  	       GL_TEXTURE_BIT      | GL_TRANSFORM_BIT | GL_VIEWPORT_BIT);
  glDisable(GL_ALPHA_TEST);
  glDisable(GL_DEPTH_TEST);
  glDisable(GL_LIGHTING);
  text.setColor(0, 0, 0, 160);
  text.draw("Play", 320, 240, 50);
  text.draw("Options", 350, 550, 20);
}
