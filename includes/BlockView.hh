//
// BlockView.hh for bomberman in /home/chazal_l//Ydrasaal/PROJECT/Bomberman/Bomberman
//
// Made by leo chazal
// Login   <chazal_l@epitech.net>
//
// Started on  Wed May 15 19:41:19 2013 leo chazal
// Last update Fri Jun  7 16:00:50 2013 leo chazal
//

#pragma		once

#include	"AView.hpp"
#include	<Image.hpp>

namespace	Bomberman
{
  class		BlockView : public AView
  {
  private:
    gdl::Image	_texture[LEVEL_NUMBER];

  private:
    BlockView();
    ~BlockView();

  public:
    static BlockView	*getInstance(void);
    void		initialize(void);
    void		draw(const AModel *);
  };
}
