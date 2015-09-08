//
// Bonus.cpp for Bomberman in /home/magrin_j/Project/Bomberman/Bomberman
//
// Made by magrin_j
// Login   <magrin_j@epitech.net>
//
// Started on  Mon May 13 11:44:10 2013 magrin_j
// Last update Fri Jun  7 21:09:02 2013 leo chazal
//

#include		<OpenGL/gl.h>
#include		<OpenGL/glu.h>
#include		<cstdlib>
#include		"Bonus.hh"
#include		"BonusView.hh"

#include		<cstdlib>

Bomberman::Bonus::Bonus()
  : AElement(Bomberman::BonusView::getInstance(), Bomberman::BONUS, false)
{
  this->rollType();
  this->_rotate = 0;
}

Bomberman::Bonus::~Bonus()
{

}

void				Bomberman::Bonus::draw()
{
  this->_view->draw(this);
}

void				Bomberman::Bonus::update(const gdl::GameClock &clock, gdl::Input &)
{
  Bomberman::BonusView		*bonusView = static_cast<Bomberman::BonusView *>(this->_view);

  bonusView->setRotation(static_cast<int>(clock.getTotalGameTime() * 70.0f) % 360);
  this->_view->draw(this);
}

void				Bomberman::Bonus::rollType(void)
{
  this->_bonus = static_cast<Bomberman::TypeBonus>(rand() % BONUS_NUMBER);
  this->_isMalus = this->_bonus % 2;
}

bool				Bomberman::Bonus::isBonus(void)
{
  return (rand() % BONUS_CHANCE);
}

Bomberman::TypeBonus		Bomberman::Bonus::getBonus(void) const
{
  return (this->_bonus);
}

void				Bomberman::Bonus::onFire(void)
{
  delete (this);
}

bool				Bomberman::Bonus::isMalus(void) const
{
  return (this->_isMalus);
}
