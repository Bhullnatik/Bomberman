//
// Block.hh for Bomberman in /home/magrin_j/Project/Bomberman/Local/Dev
//
// Made by magrin_j
// Login   <magrin_j@epitech.net>
//
// Started on  Mon May 13 10:58:15 2013 magrin_j
// Last update Wed May 29 19:47:29 2013 leo chazal
//

#pragma		once

#include	"AElement.hpp"

namespace		Bomberman
{
  class			Block : public Bomberman::AElement
  {
  public:
    static Block	*getInstance(void);
    void		draw(void);
    void		update(const gdl::GameClock &, gdl::Input &);
    void		onFire(void);

  private:
    Block();
    ~Block();
  };
}
