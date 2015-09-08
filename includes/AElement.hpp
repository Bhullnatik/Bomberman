//
// AElement.hpp for bomberman in /home/chazal_l//Ydrasaal/PROJECT/Bomberman/Bomberman
//
// Made by leo chazal
// Login   <chazal_l@epitech.net>
//
// Started on  Wed May 29 17:12:01 2013 leo chazal
// Last update Tue Jun  4 15:20:47 2013 leo chazal
//

#pragma		once

#include	"AModel.hpp"

namespace	Bomberman
{
  class		Map;
}

namespace	Bomberman
{
  class		AElement : public Bomberman::AModel
  {
  protected:
    Bomberman::Map	*_map;
    Bomberman::Element	_type;
    bool		_blocking;

  public:
    AElement(Bomberman::AView *view, Bomberman::Map *map, Bomberman::Element type, bool isBlock)
      : AModel(view), _map(map), _type(type), _blocking(isBlock)
    {

    }

    AElement(Bomberman::AView *view, Bomberman::Element type, bool isBlock)
      : AModel(view), _map(NULL), _type(type), _blocking(isBlock)
    {

    }

    virtual ~AElement() {}

    virtual void	onFire(void) = 0;

    bool	isBlocking(void) const
    {
      return (this->_blocking);
    }

    Bomberman::Element  getType(void) const
    {
      return (this->_type);
    }

  private:
    AElement();
    AElement(const AElement &);
    AElement	&operator=(const AElement &);
  };
}
