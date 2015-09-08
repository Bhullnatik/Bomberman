//
// Sound.cpp<2> for Sound in /home/hoarau_s/Projets/Bomberman/tmp/includes
//
// Made by stephen hoarau
// Login   <hoarau_s@epitech.net>
//
// Started on  Tue May 28 17:35:02 2013 stephen hoarau
// Last update Sun Jun  9 18:28:29 2013 leo chazal
//

#include	"FMOD/fmod.hpp"
#include	"Sound.hh"

Bomberman::Sound::Sound()
  : _currentTrack(-1)
{
  FMOD::System_Create(&(this->_system));
  this->_system->setOutput(FMOD_OUTPUTTYPE_AUTODETECT);
  this->_system->init(32, FMOD_INIT_NORMAL, 0);
  this->loadTracks();
}

Bomberman::Sound::~Sound()
{
  this->_system->close();
  this->_system->release();
}

Bomberman::Sound	*Bomberman::Sound::getInstance(void)
{
  static Sound		*instance = new Sound();

  return (instance);
}

void		Bomberman::Sound::playSound(Bomberman::Type track)
{
  this->_system->playSound(FMOD_CHANNEL_FREE, this->_soundPack[track], false, &this->_secChannel);
  this->_system->update();
}

void		Bomberman::Sound::playTrack(Bomberman::Type track)
{
  if (this->_currentTrack == track)
    return ;
  this->stopTrack();
  this->_currentTrack = track;
  this->_system->playSound(FMOD_CHANNEL_FREE, this->_soundPack[track], false, &this->_mainChannel);
  this->_system->update();
}

void			Bomberman::Sound::stopTrack(void)
{
  if (this->_currentTrack == -1)
    return;
  this->_mainChannel->stop();
}

void			Bomberman::Sound::loadTracks()
{
  this->_system->createSound(TRACK_MAIN, FMOD_SOFTWARE, 0, &this->_soundPack[T_MAIN]);
  this->_soundPack[T_MAIN]->setMode(FMOD_LOOP_NORMAL);
  this->_system->createSound(TRACK_MENU, FMOD_SOFTWARE, 0, &this->_soundPack[T_MENU]);
  this->_soundPack[T_MENU]->setMode(FMOD_LOOP_NORMAL);
  this->_system->createSound(TRACK_METAL, FMOD_SOFTWARE, 0, &this->_soundPack[T_METAL]);
  this->_soundPack[T_METAL]->setMode(FMOD_LOOP_NORMAL);
  this->_system->createSound(TRACK_ICE, FMOD_SOFTWARE, 0, &this->_soundPack[T_ICE]);
  this->_soundPack[T_ICE]->setMode(FMOD_LOOP_NORMAL);
  this->_system->createSound(TRACK_DEATH, FMOD_SOFTWARE, 0, &this->_soundPack[T_CURSE]);
  this->_soundPack[T_CURSE]->setMode(FMOD_LOOP_NORMAL);
  this->_system->createSound(TRACK_SKY, FMOD_SOFTWARE, 0, &this->_soundPack[T_SKY]);
  this->_soundPack[T_SKY]->setMode(FMOD_LOOP_NORMAL);
  this->_system->createSound(TRACK_SAND, FMOD_SOFTWARE, 0, &this->_soundPack[T_SAND]);
  this->_soundPack[T_SAND]->setMode(FMOD_LOOP_NORMAL);
  this->_system->createSound(TRACK_CREDIT, FMOD_SOFTWARE, 0, &this->_soundPack[T_CREDIT]);
  this->_soundPack[T_CREDIT]->setMode(FMOD_LOOP_NORMAL);
  this->_system->createSound(FX_WIN, FMOD_SOFTWARE, 0, &this->_soundPack[T_WIN]);
  this->_system->createSound(FX_LOSS, FMOD_SOFTWARE, 0, &this->_soundPack[T_LOSS]);
  this->_system->createSound(FX_DEATH, FMOD_SOFTWARE, 0, &this->_soundPack[T_DEATH]);
  this->_system->createSound(FX_BOMB, FMOD_SOFTWARE, 0, &this->_soundPack[T_BOMB]);
  this->_system->createSound(FX_EXPLODE, FMOD_SOFTWARE, 0, &this->_soundPack[T_EXPLODE]);
  this->_system->createSound(FX_BONUS, FMOD_SOFTWARE, 0, &this->_soundPack[T_BONUS]);
  this->_system->createSound(FX_MALUS, FMOD_SOFTWARE, 0, &this->_soundPack[T_MALUS]);
}

void		Bomberman::Sound::mute()
{
  if (this->_currentTrack == -1)
    return ;
  bool pause;
  this->_mainChannel->getPaused(&pause);
  this->_mainChannel->setPaused(!pause);
}
