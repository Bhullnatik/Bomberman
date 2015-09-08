//
// AView.hh for Bomberman in /home/mayouk_j/CPP/Bomberman
//
// Made by jimmy mayoukou
// Login   <mayouk_j@epitech.net>
//
// Started on  Wed May  8 02:33:40 2013 jimmy mayoukou
// Last update Wed May 29 16:57:27 2013 leo chazal
//

#pragma		once

namespace	Bomberman
{
  class		AModel;
}

#include	"AModel.hpp"
#include	"Vector3f.hpp"

namespace	Bomberman
{
  class			AView
  {
  protected:
    Vector3f		_pos;

  public:
    AView() {}
    virtual ~AView() {}

    virtual void	initialize(void) = 0;
    virtual void	draw(const AModel *) = 0;

    void		setPosition(float x, float y, float z)
    {
      this->_pos.x = x;
      this->_pos.y = y;
      this->_pos.z = z;
    }

    const Vector3f	&getPosition(void) const
    {
      return (this->_pos);
    }
  };
}
