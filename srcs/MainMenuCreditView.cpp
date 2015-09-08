//
// MainMenuCreditView.cpp for Bomberman in /home/magrin_j/Project/Bomberman
//
// Made by Jérémy Magrin
// Login   <magrin_j@epitech.net>
//
// Started on  Sun Jun  9 14:06:31 2013 Jérémy Magrin
// Last update Sun Jun  9 15:13:43 2013 Jérémy Magrin
//

#include	"MainMenuCredit.hh"
#include	"MainMenuCreditView.hh"

Bomberman::MainMenuCreditView::MainMenuCreditView()
{

}

Bomberman::MainMenuCreditView::~MainMenuCreditView()
{

}

void			Bomberman::MainMenuCreditView::initialize(void)
{
  this->_mayoukj.load(CREDITS_MAYOUKJ);
  this->_chazall.load(CREDITS_CHAZALL);
  this->_magrinj.load(CREDITS_MAGRINJ);
  this->_hoaraus.load(CREDITS_HOARAUS);
  this->_kapousc.load(CREDITS_KAPOUSC);
}

void			Bomberman::MainMenuCreditView::draw(const AModel *inst)
{
  const	Bomberman::MainMenuCredit	*menu = dynamic_cast<const Bomberman::MainMenuCredit *>(inst);
  Bomberman::MyText			text;

  Bomberman::Drawable::getInstance()->drawBg(7);

  text = menu->getText();
  text.draw("   Retour", 0, 20, 20);
  text.draw("Credits", 135, 70, 40);
  this->_mayoukj.setPosition(70, 140, 0);
  this->_mayoukj.draw();
  text.draw("mayouk_j", 90, 335, 20);
  this->_chazall.setPosition(320, 140, 0);
  this->_chazall.draw();
  text.draw("chazal_l", 350, 335, 20);
  this->_magrinj.setPosition(570, 140, 0);
  this->_magrinj.draw();
  text.draw("magrin_j", 600, 335, 20);
  this->_hoaraus.setPosition(190, 370, 0);
  this->_hoaraus.draw();
  text.draw("hoarau_s", 220, 570, 20);
  this->_kapousc.setPosition(450, 370, 0);
  this->_kapousc.draw();
  text.draw("kapous_c", 480, 570, 20);
}
