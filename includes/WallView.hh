//
// WallView.hh for bomberman in /home/chazal_l//Ydrasaal/PROJECT/Bomberman/Bomberman
//
// Made by leo chazal
// Login   <chazal_l@epitech.net>
//
// Started on  Thu May 16 16:54:01 2013 leo chazal
// Last update Fri Jun  7 15:41:11 2013 leo chazal
//

#pragma         once

#include        "AView.hpp"
#include        <Image.hpp>

namespace       Bomberman
{
  class         WallView : public AView
  {
  private:
    gdl::Image  _texture[LEVEL_NUMBER];

  private:
    WallView();
    ~WallView();

  public:
    static WallView	*getInstance(void);
    void                initialize(void);
    void                draw(const AModel *);
  };
}
