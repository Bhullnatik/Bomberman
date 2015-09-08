//
// MainMenuLoadGameView.cpp for  in /home/hoarau_s/Projets/Bomberman/Bomberman/includes
//
// Made by stephen hoarau
// Login   <hoarau_s@epitech.net>
//
// Started on  Thu Jun  6 17:46:25 2013 stephen hoarau
// Last update Sat Jun  8 20:29:56 2013 leo chazal
//

#include	"MainMenuLoadGame.hh"
#include	"MainMenuLoadGameView.hh"
#include	"MyText.hh"
#include	"Drawable.hh"

Bomberman::MainMenuLoadGameView::MainMenuLoadGameView()
{

}

void		Bomberman::MainMenuLoadGameView::initialize()
{

}

#include <iostream>

void		Bomberman::MainMenuLoadGameView::draw(const AModel *inst)
{
  const	Bomberman::MainMenuLoadGame	*menu = dynamic_cast<const Bomberman::MainMenuLoadGame *>(inst);
  Bomberman::MyText		text;

  Bomberman::Drawable::getInstance()->drawBg(6);

  text = menu->getText();
  // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  // glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  // glMatrixMode(GL_MODELVIEW);
  // glPushMatrix();
  // glMatrixMode(GL_PROJECTION);
  // glPushMatrix();
  // glPushAttrib(GL_COLOR_BUFFER_BIT | GL_CURRENT_BIT   | GL_ENABLE_BIT  |
  // 	       GL_TEXTURE_BIT      | GL_TRANSFORM_BIT | GL_VIEWPORT_BIT);
  // glDisable(GL_ALPHA_TEST);
  // glDisable(GL_DEPTH_TEST);
  // glDisable(GL_LIGHTING);

  text.draw("Charger une partie", 145, 70, 40);
  text.draw("   Retour", 0, 20, 20);
  text.draw("Selection de la", 5, 260, 20);
  text.draw("sauvegarde :", 5, 290, 20);
  if (menu->getSelection() != "")
    text.draw(menu->getSelection(), 180, 290, 20);
  text.draw("-", 50, 320, 20);
  text.draw("+", 50, 490, 20);
  text.draw("Lancer la partie", 240, 550, 30);
  this->saves_choices(text, menu->getList(), menu->getIdx());
}

void		Bomberman::MainMenuLoadGameView::saves_choices(Bomberman::MyText text, std::list<std::string> choices, int idx)
{
  int				i = 0;
  int				x = 30;
  int				y = 350;
  std::list<std::string>::const_iterator it = choices.begin();

  while (i < idx)
    {
      i++;
      it++;
    }
  i = 0;
  while (i != 6 && it != choices.end())
    {
      text.draw(*it, x, y, 15);
      y += 20;
      i++;
      it++;
    }
}
