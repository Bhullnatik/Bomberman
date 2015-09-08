//
// Sound.hh for Sound in /home/hoarau_s/Projets/Bomberman/tmp/includes
//
// Made by stephen hoarau
// Login   <hoarau_s@epitech.net>
//
// Started on  Tue May 28 17:22:23 2013 stephen hoarau
// Last update Sun Jun  9 17:02:30 2013 jimmy mayoukou
//

#pragma		once

#include	"bomberman.hh"
#include	"Data.hpp"
#include	<string>
#include	"FMOD/fmod.hpp"

namespace	Bomberman
{
  class				Sound
  {
  private:
    FMOD::System		*_system;
    FMOD::Sound			*_soundPack[SOUND_NUMBER];
    FMOD::Channel		*_mainChannel;
    FMOD::Channel		*_secChannel;
    int				_currentTrack;

  private:
    Sound();
    ~Sound();

    void			loadTracks(void);

  public:
    static Bomberman::Sound	*getInstance(void);
    void			playSound(Bomberman::Type);
    void			playTrack(Bomberman::Type);
    void			stopTrack(void);
    void			mute(void);
  };
};
