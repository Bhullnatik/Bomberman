//
// Geometrics.hh for bomberman in /home/chazal_l//Ydrasaal/PROJECT/Bomberman/Bomberman
//
// Made by leo chazal
// Login   <chazal_l@epitech.net>
//
// Started on  Tue Jun  4 14:21:05 2013 leo chazal
// Last update Fri Jun  7 18:40:16 2013 leo chazal
//

#pragma		once

#include        "Image.hpp"
#include	"Vector3f.hpp"

namespace	Bomberman
{
  class		Geometrics
  {
  public:
    static void	cube(gdl::Image &, const Vector3f &,
		     size_t width = TILE_SIZE,
		     size_t height = TILE_SIZE,
		     size_t depth = TILE_SIZE);
    static void	pyramid(gdl::Image &, const Vector3f &);

  private:
    Geometrics();
    ~Geometrics();
  };
}
