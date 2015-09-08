//
// MainMenuLoadGame.cpp for  in /home/hoarau_s/Projets/Bomberman/Bomberman/srcs
//
// Made by stephen hoarau
// Login   <hoarau_s@epitech.net>
//
// Started on  Thu Jun  6 17:29:02 2013 stephen hoarau
// Last update Sun Jun  9 20:55:33 2013 jimmy mayoukou
//

#include	<stdexcept>
#include	<unistd.h>
#include	"Sound.hh"
#include	"MainMenuLoadGame.hh"
#include	"MainMenuLoadGameView.hh"
#include	"Data.hpp"
#include	"KeyHandler.hh"
#include	"Utilities.hh"
#include	"Error.hh"

Bomberman::MainMenuLoadGame::MainMenuLoadGame(Bomberman::Game *game) : Bomberman:: AModel(new Bomberman::MainMenuLoadGameView())
{
  this->_text.setFont("./assets/fonts/bm.ttf");
  this->_game = game;
  this->_idx = 0;
  this->_selected = "";
  try {
    this->init_saves_choices();
  } catch (std::exception &e) {
  }
  this->_width = this->_game->getWindow().getWidth();
  this->_height = this->_game->getWindow().getHeight();
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

Bomberman::MainMenuLoadGame::~MainMenuLoadGame()
{

}

void		Bomberman::MainMenuLoadGame::draw()
{
  this->_view->draw(this);
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
  glPopMatrix();
  glPopAttrib();
}

void		Bomberman::MainMenuLoadGame::update(const gdl::GameClock &, gdl::Input &input)
{
  this->_width = this->_game->getWindow().getWidth();
  this->_height = this->_game->getWindow().getHeight();
  if (KeyHandler::handle(input, gdl::Mouse::Left))
    {
      int		x = input.getMousePositionX();
      int		y = input.getMousePositionY();

      manageSelectMap(x, y);
      if ((x >= getRealPosX(0) && x <= getRealPosX(90)) &&
  	  (y >= getRealPosY(20) && y <= getRealPosY(40)))
  	this->_game->popCurrentView();
      if ((x >= getRealPosX(30) && x <= getRealPosX(200)))
  	{
  	  int		tmp = 355;
  	  int		i = 0;

  	  while (tmp <= 455)
  	    {
  	      if (y >= getRealPosY(tmp) && y <= getRealPosY(tmp + 10))
  		this->getSelected(i);
  	      tmp += 20;
  	      i++;
  	    }
  	}
      if ((x >= getRealPosX(240) && x <= getRealPosX(560)) &&
	  (y >= getRealPosY(540) && y <= getRealPosY(580)))
	this->loadSave();
    }
}

void		Bomberman::MainMenuLoadGame::loadSave()
{
  std::string	path = "assets/saves/";

  if (this->_selected == "")
    return;
  this->_selected.append(SAVE_EXTENSION);
  path.append(this->_selected);
  this->_game->popCurrentView();
  try {
    this->_game->newGame(path);
  } catch (std::exception &e) {
    this->_game->setCurrentView(new Bomberman::Error(this->_game, e.what()));
  }
}

void		Bomberman::MainMenuLoadGame::manageSelectMap(int x, int y)
{
 if ((x >= getRealPosX(50) && x <= getRealPosX(60)) &&
      (y >= getRealPosY(330) && y <= getRealPosY(335)) && this->_idx > 0)
    this->_idx--;
  if ((x >= getRealPosX(50) && x <= getRealPosX(65)) &&
      (y >= getRealPosY(500) && y <= getRealPosY(510)) && this->checkNext())
    this->_idx++;
}

void		Bomberman::MainMenuLoadGame::init_saves_choices()
{
  DIR		*dir;
  struct dirent	*maps;

  dir = opendir("./assets/saves/");
  if (!dir)
    throw std::runtime_error("Cannot opendir saves");
  while ((maps = readdir(dir)))
    {
      if (maps->d_type == DT_REG && Utilities::checkExtension(maps->d_name, SAVE_EXTENSION))
	this->_choices.push_front(Utilities::cleanExtension(maps->d_name));
    }
}

int	Bomberman::MainMenuLoadGame::getRealPosX(float x)
{
  return (x * (this->_width / 800.));
}

int	Bomberman::MainMenuLoadGame::getRealPosY(float y)
{
  return (y * (this->_height / 600));
}

bool		Bomberman::MainMenuLoadGame::checkNext()
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

std::string	Bomberman::MainMenuLoadGame::getSelected(int mouse)
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

std::string	Bomberman::MainMenuLoadGame::getSelection() const
{
  return (this->_selected);
}

std::list<std::string>	Bomberman::MainMenuLoadGame::getList() const
{
  return (this->_choices);
}

int			Bomberman::MainMenuLoadGame::getIdx() const
{
  return (this->_idx);
}

Bomberman::MyText	Bomberman::MainMenuLoadGame::getText() const
{
  return (this->_text);
}
