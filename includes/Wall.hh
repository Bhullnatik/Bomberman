//
// Wall.hh for bomberman in /home/chazal_l//Ydrasaal/PROJECT/Bomberman/Bomberman
//
// Made by leo chazal
// Login   <chazal_l@epitech.net>
//
// Started on  Thu May 16 16:51:17 2013 leo chazal
// Last update Wed May 29 20:05:34 2013 leo chazal
//

#pragma         once

#include        "AElement.hpp"

namespace               Bomberman
{
  class                 Wall : public Bomberman::AElement
  {
  private:
    Wall();
    ~Wall();

  public:
    static Wall        *getInstance(void);
    void                draw();
    void                update(const gdl::GameClock &, gdl::Input &);
    void		onFire(void);
  };
}
