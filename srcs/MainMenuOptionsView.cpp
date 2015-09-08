//
// MenuOptionsView.cpp for  in /home/hoarau_s/Projets/Bomberman/Bomberman/srcs
//
// Made by stephen hoarau
// Login   <hoarau_s@epitech.net>
//
// Started on  Thu Jun  6 15:21:30 2013 stephen hoarau
// Last update Thu Jun  6 16:39:43 2013 stephen hoarau
//

#include	"MainMenuOptionsView.hh"
#include	"MainMenuOptions.hh"

Bomberman::MainMenuOptionsView::MainMenuOptionsView()
{
  this->initialize();
}

void		Bomberman::MainMenuOptionsView::initialize()
{

}

void		Bomberman::MainMenuOptionsView::draw(const AModel *inst)
{
  const	Bomberman::MainMenuOptions 	*menu = dynamic_cast<const Bomberman::MainMenuOptions *>(inst);
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
  text.draw("Options", 300, 50, 40);
  text.draw("   Retour", 0, 20, 20);
}
