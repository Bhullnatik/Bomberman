//
// Background.hh for Bomberman in /home/magrin_j/Project/Bomberman
//
// Made by Jérémy Magrin
// Login   <magrin_j@epitech.net>
//
// Started on  Fri Jun  7 17:11:05 2013 Jérémy Magrin
// Last update Sun Jun  9 21:51:23 2013 leo chazal
//

#pragma		once

#include	<Image.hpp>

namespace		Bomberman
{
  class			Drawable
  {
  private:
    gdl::Image		_drawables[11];

  public:
    static Drawable	*getInstance(void);
    static void		pushOrthoMatrix(float, float);
    static void		popOrthoMatrix(void);
    static void		drawAt(float, float, float, float,
			       gdl::Image &);
    void		drawBg(size_t);

  private:
    Drawable();
    ~Drawable();

    void		initialize(void);
  };
}
