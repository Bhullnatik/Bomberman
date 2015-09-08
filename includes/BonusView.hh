//
// BonusView.hh for bomberman in /home/chazal_l//Ydrasaal/PROJECT/Bomberman/Bomberman
//
// Made by leo chazal
// Login   <chazal_l@epitech.net>
//
// Started on  Wed May 22 21:35:39 2013 leo chazal
// Last update Fri Jun  7 21:01:12 2013 leo chazal
//

#pragma		once

#include	"AView.hpp"
#include	<Image.hpp>
#include	<map>

namespace	Bomberman
{
  class		BonusView : public AView
  {
  private:
    gdl::Image	_texture[BONUS_NUMBER];
    size_t	_type;
    int		_rotate;

  private:
    BonusView();
    ~BonusView();

  public:
    static BonusView	*getInstance(void);
    void		initialize(void);
    void		draw(const AModel *);
    void		setType(size_t);
    void		setRotation(float rotate);
  };
}
