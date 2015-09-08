//
// Modele.hh for Bomberman in /home/mayouk_j/CPP/Bomberman
//
// Made by jimmy mayoukou
// Login   <mayouk_j@epitech.net>
//
// Started on  Wed May  8 03:40:54 2013 jimmy mayoukou
// Last update Sat Jun  8 09:42:22 2013 leo chazal
//

#pragma		once

#include	"bomberman.hh"
#include	"AView.hpp"
#include	<GameClock.hpp>
#include	<Input.hpp>
#include	"Camera.hh"

namespace		Bomberman
{
  class			AModel
  {
  protected:
    Bomberman::AView	*_view;

  public:
    AModel(Bomberman::AView *view)
      : _view(view)
    {

    }

    virtual ~AModel() {}

    virtual void	draw(void) = 0;
    virtual void	update(const gdl::GameClock &, gdl::Input &) = 0;

    void		initialize(void)
    {
      this->_view->initialize();
    }

    Bomberman::AView	*getView(void) const
    {
      return (this->_view);
    }

    virtual void	setCameraMode(Bomberman::Camera &, const gdl::Window &)
    {

    }

  private:
    AModel();
    AModel(const AModel &);
    AModel		&operator=(const AModel &);
  };
}
