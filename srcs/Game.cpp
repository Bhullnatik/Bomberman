//
// Game.cpp for Bomberman in /home/mayouk_j/CPP/Bomberman/includes
//
// Made by jimmy mayoukou
// Login   <mayouk_j@epitech.net>
//
// Started on  Wed May  8 04:30:00 2013 jimmy mayoukou
// Last update Sun Jun  9 22:02:25 2013 leo chazal
//

#include	<OpenGL/gl.h>
#include	<OpenGL/glu.h>
#include	<algorithm>
#include	<cstdlib>
#include	<iostream>
#include	"Drawable.hh"
#include	"Intro.hh"
#include	"Game.hh"
#include	"KeyHandler.hh"
#include	"MainMenuHome.hh"
#include	"MainMenuPlaySolo.hh"
#include	"TitleScreen.hh"
#include	"Preloader.hpp"

void	Bomberman::Game::initialize(void)
{
  this->window_.create();
  this->_cam.initialize(this->window_);
  try {
    Bomberman::Preloader        loader(this->window_);

  } catch (gdl::ModelException *e) {
    // CACA
    this->window_.close();
  }
  srand(time(NULL));
  this->_timeStamp = 0;
  try {
    this->loadHighscore();
  } catch (std::exception &e) {

  }
  this->_views.push(new Bomberman::MainMenuPlaySolo(this));
  this->_views.push(new Bomberman::TitleScreen(this));
  this->_views.push(new Bomberman::Intro(this));
}

void	Bomberman::Game::update(void)
{
  if (!this->window_.getHeight() || !this->addTick())
    return ;
  if (KeyHandler::handle(this->input_, gdl::Keys::M))
    Bomberman::Sound::getInstance()->mute();
  this->_cam.update(this->gameClock_, this->input_, this->window_);
  if (!this->_views.empty())
    {
      this->_views.top()->update(this->gameClock_, this->input_);
      this->_views.top()->setCameraMode(this->_cam, this->window_);
    }
}

void	Bomberman::Game::draw(void)
{
  if (!this->window_.getHeight())
    return ;
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  if (!this->_views.empty())
    this->_views.top()->draw();
  this->window_.display();
}

void	Bomberman::Game::unload(void)
{
  try {
    this->saveHighScore();
  } catch (std::exception &e) {

  }
  while (this->_views.empty())
    {
      delete (this->_views.top());
      this->_views.pop();
    }
}

void	Bomberman::Game::addHighScore(const std::string &name, size_t score)
{
  this->_highScore.push_back(std::pair<std::string, size_t>(name, score));
}

const std::list<std::pair<std::string, size_t> > &Bomberman::Game::getHighScores() const
{
  return (this->_highScore);
}

void	Bomberman::Game::setCurrentView(AModel *view)
{
  this->_views.push(view);
}

void	Bomberman::Game::popCurrentView()
{
  this->_views.pop();
}

void		Bomberman::Game::newGame(const std::string &map,
					 size_t nbIAs, size_t nbPlayers)
{
  Engine	*game = NULL;

  if (!(map.length()) || map == "Aleatoire")
    game = new Engine(this, nbIAs + nbPlayers);
  else
    game = new Engine(this, map);
  game->initialize(nbIAs, nbPlayers);

  this->_cam.setSizeMap(game->getSizeXMap(), game->getSizeYMap());
  this->_cam.setPlayers(game->getPlayerList());
  Bomberman::Data::getInstance()->setLevelType();
  this->setCurrentView(game);
}

void		Bomberman::Game::newGame(const std::string &save)
{
  Engine	*game = NULL;

  game = Bomberman::Save::load(save, this);
  this->_cam.setSizeMap(game->getSizeXMap(), game->getSizeYMap());
  this->_cam.setPlayers(game->getPlayerList());
  Bomberman::Data::getInstance()->setLevelType();
  this->setCurrentView(game);
}

const gdl::Window	&Bomberman::Game::getWindow() const
{
  return (this->window_);
}

gdl::Window		&Bomberman::Game::getWindow()
{
  return (this->window_);
}

bool	Bomberman::Game::addTick()
{
  this->_timeStamp += this->gameClock_.getElapsedTime();
  if (this->_timeStamp < GAME_DELAY)
    return (false);
  this->_timeStamp = 0;
  return (true);
}

void		Bomberman::Game::loadHighscore()
{
  std::ifstream	stream(SCORE_FILE);
  std::string	line;

  if (!stream)
    throw std::ios_base::failure("Cannot load highScores");
  while (getline(stream, line))
    {
      std::istringstream	ss(line);
      std::string		name;
      size_t			score;

      ss >> name;
      ss >> score;
      this->_highScore.push_back(std::pair<std::string, size_t>(name, score));
    }
}

static bool	compScore(const std::pair<std::string, size_t> &score1,
			  const std::pair<std::string, size_t> &score2)
{
  return (score1.second >= score2.second);
}

void		Bomberman::Game::saveHighScore()
{
  std::ofstream	stream(SCORE_FILE);

  if (!stream)
    throw std::ios_base::failure("Cannot save highScores");
  this->_highScore.sort(compScore);
  if (this->_highScore.size() > 10)
    this->_highScore.resize(10);
  for (std::list<std::pair<std::string, size_t> >::iterator it = this->_highScore.begin();
       it != this->_highScore.end() && std::distance(this->_highScore.begin(), it) <= 10; ++it)
    stream << (*it).first << " " << (*it).second << std::endl;
}
