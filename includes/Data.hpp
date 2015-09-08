//
// Data.hh for bomberman in /home/chazal_l//Ydrasaal/PROJECT/Bomberman/Bomberman
//
// Made by leo chazal
// Login   <chazal_l@epitech.net>
//
// Started on  Sat Jun  1 11:24:55 2013 leo chazal
// Last update Sun Jun  9 18:17:42 2013 leo chazal
//

#pragma		once

#include	<cstdlib>
#include	<Color.hpp>
#include	<Input.hpp>
#include	<Model.hpp>
#include	<ModelException.hpp>
#include	"APlayer.hh"
#include	"Player.hh"

typedef gdl::Keys::Key	key_array[KEY_NUMBER];

namespace	Bomberman
{
  enum		KeyID
    {
      KEY_UP = 0,
      KEY_DOWN = 1,
      KEY_LEFT = 2,
      KEY_RIGHT = 3,
      KEY_BOMB = 4
    };

  enum          Type
    {
      T_METAL = 0,
      T_ICE = 1,
      T_CURSE = 2,
      T_SKY = 3,
      T_SAND = 4,
      T_MAIN = 5,
      T_MENU = 6,
      T_WIN = 7,
      T_LOSS = 8,
      T_CREDIT = 9,
      T_DEATH = 10,
      T_BOMB = 11,
      T_EXPLODE = 12,
      T_BONUS = 13,
      T_MALUS = 14
    };

  class		Data
  {
  private:
    gdl::Keys::Key	_p1[KEY_NUMBER];
    gdl::Keys::Key	_p2[KEY_NUMBER];
    gdl::Color		_playerColors[NB_PLAYER_COLOR];
    gdl::Color		_iaColors[NB_IA_COLOR];
    gdl::Keys::Key	_menu;
    gdl::Model		_bombModel;
    gdl::Model		_playerModel;
    Type		_levelType;

  private:
    Data()
      : _menu(gdl::Keys::Escape), _levelType(T_METAL)
    {
      this->_p1[KEY_UP] = gdl::Keys::Up;
      this->_p1[KEY_DOWN] = gdl::Keys::Down;
      this->_p1[KEY_LEFT] = gdl::Keys::Left;
      this->_p1[KEY_RIGHT] = gdl::Keys::Right;
      this->_p1[KEY_BOMB] = gdl::Keys::Space;
      this->_p2[KEY_UP] = gdl::Keys::Z;
      this->_p2[KEY_DOWN] = gdl::Keys::S;
      this->_p2[KEY_LEFT] = gdl::Keys::Q;
      this->_p2[KEY_RIGHT] = gdl::Keys::D;
      this->_p2[KEY_BOMB] = gdl::Keys::LShift;
      this->loadModels();
      this->initColors();
    }

    ~Data();

    void	loadModels()
    {
      try {
      	this->_bombModel = gdl::Model::load(MODE_BOMBS);
      	this->_bombModel.cut_animation(this->_bombModel, "Take 001", 1, 1, "idle");
      	this->_bombModel.cut_animation(this->_bombModel, "Take 001", 1, 40, "grow");
      	this->_playerModel = gdl::Model::load(MODE_BOMBERMAN);
      	this->_playerModel.cut_animation(this->_playerModel, "Take 001", 0, 0, "idle");
      	this->_playerModel.cut_animation(this->_playerModel, "Take 001", 0, 30, "start");
      	this->_playerModel.cut_animation(this->_playerModel, "Take 001", 35, 53, "run");
      	this->_playerModel.cut_animation(this->_playerModel, "Take 001", 57, 120, "end");
      } catch (const gdl::ModelException *e) {
      	std::cerr << "Error while loading model : " << e->what() << std::endl;
      }
    }

    void	initColors()
    {
      this->_playerColors[0] = gdl::Color(0.0f, 0.0f, 255.0f);
      this->_playerColors[1] = gdl::Color(255.0f, 0.0f, 0.0f);
      this->_iaColors[0] = gdl::Color(255.0f, 255.0f, 255.0f);
      this->_iaColors[1] = gdl::Color(0.0f, 0.0f, 0.0f);
      this->_iaColors[2] = gdl::Color(0.0f, 255.0f, 0.0f);
      this->_iaColors[3] = gdl::Color(0.0f, 255.0f, 213.0f);
      this->_iaColors[4] = gdl::Color(255.0f, 0.0f, 179.0f);
      this->_iaColors[5] = gdl::Color(255.0f, 255.0f, 0.0f);
    }

  public:
    static Data		*getInstance(void)
    {
      static Data	*instance = new Data();

      return (instance);
    }

    const key_array	&getP1Keys(void) const
    {
      return (this->_p1);
    }

    const key_array	&getP2Keys(void) const
    {
      return (this->_p2);
    }

    gdl::Keys::Key	getMenuKey(void) const
    {
      return (this->_menu);
    }

    void	setP1Key(KeyID key, gdl::Keys::Key input)
    {
      this->_p1[key] = input;
    }

    void	setP2Key(KeyID key, gdl::Keys::Key input)
    {
      this->_p2[key] = input;
    }

    gdl::Model	getBombModel(void)
    {
      return (this->_bombModel);
    }

    gdl::Model	getPlayerModel(void)
    {
      return (this->_playerModel);
    }

    void	setLevelType(void)
    {
      this->_levelType = (Bomberman::Type) (rand() % LEVEL_NUMBER);
    }

    Bomberman::Type	getLevelType(void) const
    {
      return (this->_levelType);
    }

    const gdl::Color	&getPlayerColor(const Bomberman::APlayer *player)
    {
      if (dynamic_cast<const Bomberman::Player *>(player))
	return (this->_playerColors[player->getId() % NB_PLAYER_COLOR]);
      else
	return (this->_iaColors[player->getId() % NB_IA_COLOR]);
    }
  };
}
