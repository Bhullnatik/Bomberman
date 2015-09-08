//
// FireView.hh for bomberman in /home/chazal_l//Ydrasaal/PROJECT/Bomberman/Bomberman
//
// Made by leo chazal
// Login   <chazal_l@epitech.net>
//
// Started on  Mon May 27 19:22:11 2013 leo chazal
// Last update Mon May 27 19:30:16 2013 leo chazal
//

#pragma		once

#include	"AView.hpp"
#include	<Image.hpp>

namespace	Bomberman
{
  class		FireView : public AView
  {
  private:
    gdl::Image	_texture;

  private:
    FireView();
    ~FireView();

  public:
    static FireView	*getInstance(void);
    void		initialize(void);
    void		draw(const AModel *);
  };
}
