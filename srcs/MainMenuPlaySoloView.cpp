//
// MenuPlaySoloView.cpp for PlaySolo in /home/hoarau_s/Projets/Bomberman/Bomberman/srcs
//
// Made by stephen hoarau
// Login   <hoarau_s@epitech.net>
//
// Started on  Thu Jun  6 15:15:44 2013 stephen hoarau
// Last update Sun Jun  9 14:30:15 2013 Jérémy Magrin
//

#include	"MainMenuPlaySoloView.hh"
#include	"MainMenuPlaySolo.hh"
#include	"MyText.hh"
#include	"Drawable.hh"

Bomberman::MainMenuPlaySoloView::MainMenuPlaySoloView()
{

}

void		Bomberman::MainMenuPlaySoloView::initialize()
{

}

void		Bomberman::MainMenuPlaySoloView::draw(const AModel *inst)
{
  const	Bomberman::MainMenuPlaySolo	*menu = dynamic_cast<const Bomberman::MainMenuPlaySolo *>(inst);
  Bomberman::MyText		text;


  Bomberman::Drawable::getInstance()->drawBg(5);

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

  text.draw("Credits", 690, 20, 20);
  text.draw("Battle Lobby", 250, 60, 40);
  text.draw("Nombre d'IA:", 25, 200, 20);
  text.draw("-", 200, 200, 20);
  std::ostringstream os;
  os << menu->getNbrIA();
  text.draw(os.str(), 230, 200, 20);
  text.draw("+", 265, 200, 20);
  text.draw("Nombre de joueurs:", 25, 230, 20);
  text.draw("-", 285, 230, 20);

  std::ostringstream oss;
  oss << menu->getNbrPlayers();
  text.draw(oss.str(), 320, 230, 20);
  text.draw("+", 355, 230, 20);
  text.draw("Selection de la map:", 25, 260, 20);
  if (menu->getSelection() != "")
    text.draw(menu->getSelection(), 300, 260, 20);
  text.draw("-", 50, 290, 20);
  text.draw("+", 50, 460, 20);
  text.draw("Map Aleatoire", 500, 260, 20);
  text.draw("Nouvelle partie:", 100, 530, 25);
  text.draw("Charger Partie:", 400, 530, 25);
  this->map_choices(text, menu->getList(), menu->getIdx());

  // text.setColor(255, 0, 0);
  if (!menu->getPos())
    text.draw("o ", 5, 205, 10);
  if (menu->getPos())
    text.draw("o ", 5, 235, 10);
}

void		Bomberman::MainMenuPlaySoloView::map_choices(Bomberman::MyText text, std::list<std::string> choices, int idx)
{
  int				i = 0;
  int				x = 30;
  int				y = 330;
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

