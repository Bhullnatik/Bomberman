//
// BombView.hh for bomberman in /home/chazal_l//Ydrasaal/PROJECT/Bomberman/Bomberman
//
// Made by leo chazal
// Login   <chazal_l@epitech.net>
//
// Started on  Wed May 15 18:04:57 2013 leo chazal
// Last update Tue Jun  4 16:41:01 2013 leo chazal
//

#pragma		once

#include	<Model.hpp>
#include	"AModel.hpp"

namespace	Bomberman
{
  class		BombView : public AView
  {
  private:
    gdl::Model	_model;

  public:
    BombView();
    ~BombView();

    gdl::Model		&getModel();
    void		initialize(void);
    void		draw(const AModel *);
    void		runAnim(const std::string &);
    void		stopAnim(const std::string &);

  private:
    void		moveTo(Vector3f);
  };
}
