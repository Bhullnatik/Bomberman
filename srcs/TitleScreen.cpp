//
// TitleScreen.cpp for bomberman in /home/chazal_l//Ydrasaal/PROJECT/Bomberman/Bomberman
//
// Made by leo chazal
// Login   <chazal_l@epitech.net>
//
// Started on  Sat Jun  8 07:07:26 2013 leo chazal
// Last update Sun Jun  9 14:42:03 2013 jimmy mayoukou
//

#include	"TitleScreen.hh"
#include	"bomberman.hh"
#include	"Drawable.hh"
#include	"KeyHandler.hh"
#include	"Sound.hh"

Bomberman::TitleScreen::TitleScreen(Bomberman::Game *main)
  : Bomberman::AModel(NULL), _main(main)
{
  this->initialize();
}

Bomberman::TitleScreen::~TitleScreen()
{
}

void	Bomberman::TitleScreen::initialize(void)
{
  this->_texture = gdl::Image::load(TITLE_BG);
  this->_wording = gdl::Image::load(TITLE_WORD);
}

void		Bomberman::TitleScreen::update(const gdl::GameClock &, gdl::Input &input)
{
  static size_t	tick = 0;

  Bomberman::Sound::getInstance()->playTrack(Bomberman::T_MAIN);
  tick++;
  if (tick >= 50)
    {
      this->_wordUp = !this->_wordUp;
      tick = 0;
    }
  if (KeyHandler::handle(input, gdl::Keys::Return))
    this->_main->popCurrentView();
}

void	Bomberman::TitleScreen::draw(void)
{
  Bomberman::Drawable::pushOrthoMatrix(1, 1);
  Bomberman::Drawable::drawAt(0, 0, 1, 1, this->_texture);
  if (this->_wordUp)
    Bomberman::Drawable::drawAt(0.129, 0.37, 0.357, 0.434, this->_wording);
  Bomberman::Drawable::popOrthoMatrix();
}
