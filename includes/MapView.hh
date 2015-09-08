//
// MapView.hh for bomberman in /home/chazal_l//Ydrasaal/PROJECT/Bomberman/Bomberman
//
// Made by leo chazal
// Login   <chazal_l@epitech.net>
//
// Started on  Wed May 15 16:59:19 2013 leo chazal
// Last update Wed May 15 22:10:44 2013 leo chazal
//

#pragma		once

#include	"AView.hpp"

namespace	Bomberman
{
  class		MapView : public AView
  {
  private:
    MapView();
    ~MapView();

  public:
    static MapView	*getInstance(void);
    void		initialize(void);
    void		draw(const AModel *);
  };
}
