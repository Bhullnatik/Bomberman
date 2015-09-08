//
// PlayerView.hh for bomberman in /home/chazal_l//Ydrasaal/PROJECT/Bomberman/Bomberman
//
// Made by leo chazal
// Login   <chazal_l@epitech.net>
//
// Started on  Wed May 15 18:01:51 2013 leo chazal
// Last update Wed Jun  5 15:34:03 2013 Jérémy Magrin
//

#pragma		once

#include	<Model.hpp>
#include	"AModel.hpp"
#include	"Vector3f.hpp"
#include	"Color.hpp"

namespace	Bomberman
{
  class		PlayerView : public AView
  {
  private:
    gdl::Model		_model;

  public:
    PlayerView();
    ~PlayerView();

  public:
    void			setModelColor(const gdl::Color &color);
    gdl::Model&			getModel();
    void			setLookAt(float);
    void			initialize(void);
    void			moveTo(float, float, float);
    void			rotateTo(float);
    bool			animIsEnded(const std::string &anim) const;
    void			runAnim(const std::string &);
    void			stopAnim(const std::string &);
    void			draw(const AModel *);
    const Vector3f		&getPosition(void) const;
  };
}
