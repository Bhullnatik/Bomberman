//
// ErrorView.hh for Bomberman in /home/magrin_j/Project/Bomberman
//
// Made by Jérémy Magrin
// Login   <magrin_j@epitech.net>
//
// Started on  Sun Jun  9 15:44:53 2013 Jérémy Magrin
// Last update Sun Jun  9 16:33:56 2013 Jérémy Magrin
//

#pragma		once

#include        "AModel.hpp"
#include        "MyText.hh"
#include        "AView.hpp"
#include        "Drawable.hh"
#include	<string>
#include	<list>

namespace	Bomberman
{
  class		ErrorView : public Bomberman::AView
  {
  public:
    gdl::Image		_background;

  public:
    ErrorView();
    ~ErrorView();

  public:
    void		initialize(void);
    void		draw(const AModel *);
  };
}
