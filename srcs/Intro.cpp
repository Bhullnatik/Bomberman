//
// Intro.cpp for Bomberman in /home/magrin_j/Project/Bomberman
//
// Made by Jérémy Magrin
// Login   <magrin_j@epitech.net>
//
// Started on  Sat Jun  1 16:18:47 2013 Jérémy Magrin
// Last update Sun Jun  9 14:09:50 2013 jimmy mayoukou
//

#include	"KeyHandler.hh"
#include	"Intro.hh"
#include	"IntroView.hh"
#include	"Sound.hh"

#include	<iostream>

Bomberman::Intro::Intro(Bomberman::Game *main)
  : Bomberman::AModel(new Bomberman::IntroView()),
    _ticks(0), _main(main)
{
  this->initialize();
}

Bomberman::Intro::~Intro()
{

}

void	Bomberman::Intro::initialize(void)
{
  this->_state.push_front(BInfo(.75, .45, 25));
  this->_state.push_front(BInfo(.4, .65, 60));
  this->_state.push_front(BInfo(.9, .2, 95));
  this->_state.push_front(BInfo(.1, .5, 110));
  this->_state.push_front(BInfo(.6, .6, 125));
  this->_state.push_front(BInfo(.25, .2, 140));
  this->_state.push_front(BInfo(0, .65, 155));
  this->_state.push_front(BInfo(.5, .1, 170));
  this->_state.push_front(BInfo(.4, .3, 185));
}

void			Bomberman::Intro::draw(void)
{
  this->_view->draw(this);
}

void			Bomberman::Intro::update(const gdl::GameClock &, gdl::Input &input)
{
  ++this->_ticks;
  if (this->_ticks == 200)
    Bomberman::Sound::getInstance()->playSound(Bomberman::T_EXPLODE);
  if (this->_ticks >= 250 || KeyHandler::handle(input, gdl::Keys::Return))
    this->_main->popCurrentView();
  for (std::list<Bomberman::BInfo>::iterator it = this->_state.begin();
       it != this->_state.end(); it++)
    {
      if (!(*it).lit && (*it).count < this->_ticks)
	{
	  (*it).lit = true;
	  Bomberman::Sound::getInstance()->playSound(Bomberman::T_BOMB);
	}
    }
}

size_t		Bomberman::Intro::getTicks(void) const
{
  return (this->_ticks);
}

const std::list<Bomberman::BInfo>	&Bomberman::Intro::getState(void) const
{
  return (this->_state);
}
