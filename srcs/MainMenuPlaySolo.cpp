//
// MenuPlay.cpp for MenuPlay in /home/hoarau_s/Projets/Bomberman/Bomberman/srcs
//
// Made by stephen hoarau
// Login   <hoarau_s@epitech.net>
//
// Started on  Thu Jun  6 15:53:39 2013 stephen hoarau
// Last update Sun Jun  9 22:09:44 2013 stephen hoarau
//

#include	<stdexcept>
#include	<unistd.h>
#include	"Sound.hh"
#include	"MainMenuCredit.hh"
#include	"MainMenuPlaySolo.hh"
#include	"MainMenuPlaySoloView.hh"
#include	"MainMenuLoadGame.hh"
#include	"Data.hpp"
#include	"KeyHandler.hh"
#include	"Utilities.hh"
#include	"Error.hh"

Bomberman::MainMenuPlaySolo::MainMenuPlaySolo(Bomberman::Game *game) : Bomberman::AModel(new Bomberman::MainMenuPlaySoloView())
{
  this->_text.setFont("./assets/fonts/bm.ttf");
  this->_pos = 0;
  this->_player = 1;
  this->_game = game;
  this->_idx = 0;
  this->_ia = 0;
  try {
    this->init_map_choices();
  } catch (std::exception &e) {
  }
  this->_selected = "";
  this->_width = this->_game->getWindow().getWidth();
  this->_height = this->_game->getWindow().getHeight();
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

Bomberman::MainMenuPlaySolo::~MainMenuPlaySolo()
{

}

void		Bomberman::MainMenuPlaySolo::draw()
{
  this->_view->draw(this);
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
  glPopMatrix();
  glPopAttrib();
}

void		Bomberman::MainMenuPlaySolo::update(const gdl::GameClock &, gdl::Input &input)
{
  Bomberman::Sound::getInstance()->playTrack(Bomberman::T_MENU);
  this->_width = this->_game->getWindow().getWidth();
  this->_height = this->_game->getWindow().getHeight();
  if (KeyHandler::handle(input, gdl::Keys::Escape))
    this->_game->getWindow().close();
  if (KeyHandler::handle(input, gdl::Mouse::Left))
    {
      int		x = input.getMousePositionX();
      int		y = input.getMousePositionY();

      manageNbrPlayers(x, y);
      manageSelectMap(x, y);
      if ((x >= getRealPosX(100) && x < getRealPosX(360)) &&
  	       (y >= getRealPosY(535) && y <= getRealPosY(555)))
  	this->startNewGame();
      if ((x >= getRealPosX(30) && x <= getRealPosX(200)))
  	{
  	  int		tmp = 335;
  	  int		i = 0;

  	  while (tmp <= 435)
  	    {
  	      if (y >= getRealPosY(tmp) && y <= getRealPosY(tmp + 10))
  		getSelected(i);
  	      tmp += 20;
  	      i++;
  	    }
  	}
      if ((x >= getRealPosX(405) && x <= getRealPosX(650)) &&
	  (y >= getRealPosY(535) && y <= getRealPosY(556)))
	this->_game->setCurrentView(new Bomberman::MainMenuLoadGame(this->_game));
      if ((x >= getRealPosX(690) && x <= getRealPosX(790)) &&
	  (y >= getRealPosY(24) && y <= getRealPosY(43)))
	this->_game->setCurrentView(new Bomberman::MainMenuCredit(this->_game));
    }
  this->getInputKeyboard(input);
}

void	Bomberman::MainMenuPlaySolo::startNewGame()
{
  if (((this->_player > 0 && this->_ia >= 1) || (this->_player > 1)) && this->_selected.length())
    {
      std::string    tmp = "assets/maps/";

      if (this->_selected != "Aleatoire")
	{
	  tmp.append(this->_selected);
	  tmp.append(MAP_EXTENSION);
	}
      else
	tmp = "Aleatoire";
      try {
	this->_game->newGame(tmp, this->_ia, this->_player);
      } catch (std::exception &e) {
	this->_game->setCurrentView(new Bomberman::Error(this->_game, e.what()));
      }
    }
}

void	Bomberman::MainMenuPlaySolo::manageSelectMap(int x, int y)
{
  if ((x >= getRealPosX(50) && x <= getRealPosX(60)) &&
      (y >= getRealPosY(300) && y <= getRealPosY(305)) && this->_idx > 0)
    this->_idx--;
  if ((x >= getRealPosX(50) && x <= getRealPosX(65)) &&
      (y >= getRealPosY(470) && y <= getRealPosY(480)) && this->checkNext())
    this->_idx++;
  if ((x >= getRealPosX(500) && x <= getRealPosX(680)) &&
      (y >= getRealPosY(265) && y <= getRealPosY(280)))
    this->_selected = "Aleatoire";
}

void	Bomberman::MainMenuPlaySolo::manageNbrPlayers(int x, int y)
{
  if ((x >= getRealPosX(285) && x <= getRealPosX(295)) &&
      (y >= getRealPosY(235) && y <= getRealPosY(245)) && this->_player > 1)
    this->_player--;
  else if ((x >= getRealPosX(355) && x <= getRealPosX(370)) &&
	   (y >= getRealPosY(235) && y <= getRealPosY(250)) && this->_player < 2)
    this->_player++;
  if ((x >= getRealPosX(200) && x <= getRealPosX(210)) &&
      (y >= getRealPosY(213) && y <= getRealPosY(218)) && this->_ia > 0)
    this->_ia--;
  else if ((x >= getRealPosX(268) && x <= getRealPosX(280)) &&
	   (y >= getRealPosY(213) && y <= getRealPosY(218)) && this->_ia < 100)
    this->_ia++;
}

bool	Bomberman::MainMenuPlaySolo::checkNext()
{
  int	i = 0;
  std::list<std::string>::iterator it = this->_choices.begin();

  while (i != this->_idx + 6)
    {
      if (it == this->_choices.end())
	return (false);
      i++;
      it++;
    }
  if (it == this->_choices.end())
    return (false);
  return (true);
}

int	Bomberman::MainMenuPlaySolo::getRealPosX(float x)
{
  return (x * (this->_width / 800.));
}

int	Bomberman::MainMenuPlaySolo::getRealPosY(float y)
{
  return (y * (this->_height / 600));
}

void	Bomberman::MainMenuPlaySolo::init_map_choices()
{
  DIR		*dir;
  struct dirent	*maps;

  dir = opendir("./assets/maps/");
  if (!dir)
    throw std::ios_base::failure("Cannot opendir maps");
  while ((maps = readdir(dir)))
    {
      if (maps->d_type == DT_REG && Utilities::checkExtension(maps->d_name, MAP_EXTENSION))
	this->_choices.push_front(Utilities::cleanExtension(maps->d_name));
    }
}

std::string		Bomberman::MainMenuPlaySolo::getSelected(int mouse)
{
  std::list<std::string>::iterator it = this->_choices.begin();
  int		i = 0;

  if (it == this->_choices.end())
    return ("");
  while (i != this->_idx + mouse)
    {
      i++;
      it++;
      if (it == this->_choices.end())
	return ("");
    }
  this->_selected = *it;
  return (*it);
}

void		Bomberman::MainMenuPlaySolo::getInputKeyboard(gdl::Input &input)
{
  if (KeyHandler::handle(input, gdl::Keys::Up))
    this->_pos = 0;
  if (KeyHandler::handle(input, gdl::Keys::Down))
    this->_pos = 1;
  if (KeyHandler::handle(input, gdl::Keys::Left))
    {
      if (!this->_pos && this->_ia > 0)
	this->_ia--;
      else if (this->_pos && this->_player > 1)
	this->_player--;
    }
  if (KeyHandler::handle(input, gdl::Keys::Right))
    {
      if (!this->_pos && this->_ia < 100)
	this->_ia++;
      else if (this->_pos && this->_player < 2)
	this->_player++;
    }
}

void		Bomberman::MainMenuPlaySolo::map_choices()
{
}

Bomberman::MyText	Bomberman::MainMenuPlaySolo::getText() const
{
  return (this->_text);
}

int		Bomberman::MainMenuPlaySolo::getNbrPlayers() const
{
  return (this->_player);
}

std::string	Bomberman::MainMenuPlaySolo::getSelection() const
{
  return (this->_selected);
}

std::list<std::string>	Bomberman::MainMenuPlaySolo::getList() const
{
  return (this->_choices);
}

int		Bomberman::MainMenuPlaySolo::getIdx() const
{
  return (this->_idx);
}

int		Bomberman::MainMenuPlaySolo::getNbrIA() const
{
  return (this->_ia);
}

int		Bomberman::MainMenuPlaySolo::getPos() const
{
  return (this->_pos);
}
