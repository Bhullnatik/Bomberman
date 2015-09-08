//
// EndGameScreen.cpp for bomberman in /home/chazal_l//Ydrasaal/PROJECT/Bomberman/Bomberman
//
// Made by leo chazal
// Login   <chazal_l@epitech.net>
//
// Started on  Sat Jun  8 10:08:34 2013 leo chazal
// Last update Sun Jun  9 20:48:31 2013 jimmy mayoukou
//

#include        "EndGameScreen.hh"
#include        "bomberman.hh"
#include        "Drawable.hh"
#include	"KeyHandler.hh"
#include	"Player.hh"
#include	"Sound.hh"
#include	"MyText.hh"
#include	<sstream>

Bomberman::EndGameScreen::EndGameScreen(Bomberman::Game *main,
					const std::list<Bomberman::APlayer *> &players, bool player)
  : Bomberman::AModel(NULL), _score(0)
{
  this->_main = main;
  this->_size = players.size();
  this->_human = player;
  if (this->_size)
    for (std::list<Bomberman::APlayer *>::const_iterator it = players.begin();
	 it != players.end(); it++)
      {
	if ((*it)->getScore() > this->_score)
	  this->_score = (*it)->getScore();
      }
  this->initialize();
}

Bomberman::EndGameScreen::~EndGameScreen()
{

}

void    Bomberman::EndGameScreen::initialize()
{
  this->_texture = gdl::Image::load(!this->_size ? END_DRAW : this->_human ? END_WINNER : END_LOSER);
  Bomberman::Sound::getInstance()->stopTrack();
  if (this->_size)
    Bomberman::Sound::getInstance()->playSound(this->_human ? T_WIN : T_LOSS);
}

void    Bomberman::EndGameScreen::update(const gdl::GameClock &, gdl::Input &input)
{
  if (KeyHandler::handle(input, gdl::Keys::Return))
    this->_main->popCurrentView();
}

void    Bomberman::EndGameScreen::draw(void)
{
  Bomberman::MyText	text;
  std::stringstream	ss;
  ss << this->_score;

  Bomberman::Drawable::pushOrthoMatrix(1, 1);
  Bomberman::Drawable::drawAt(0, 0, 1, 1, this->_texture);
  Bomberman::Drawable::popOrthoMatrix();
  text.setFont("assets/fonts/bm.ttf");
  !this->_size ?
    text.draw("It's a draw !", 150, 25, 40) :
    this->_human ?
    text.draw("Player Victory ! ", 180, 25, 50) :
    text.draw("You lost against the machine ! ", 40, 25, 35);
  text.draw(ss.str(), 300, 140, 50);
}
