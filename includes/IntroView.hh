//
// IntroView.hh for IntroView in /home/magrin_j/Project/Bomberman
//
// Made by Jérémy Magrin
// Login   <magrin_j@epitech.net>
//
// Started on  Sat Jun  1 16:36:36 2013 Jérémy Magrin
// Last update Sat Jun  8 11:41:49 2013 leo chazal
//

#pragma		once

#include	<Image.hpp>
#include	<AModel.hpp>
#include	"Img.hh"

namespace		Bomberman
{
  class			IntroView : public Bomberman::AView
  {
  private:
    gdl::Image		_image;
    gdl::Image		_title;
    gdl::Image		_bomb;
    gdl::Image		_fire;
    gdl::Image		_box;

  public:
    IntroView();
    ~IntroView();

    void			draw(const Bomberman::AModel *);

  private:
    void			initialize(void);
  };
}
