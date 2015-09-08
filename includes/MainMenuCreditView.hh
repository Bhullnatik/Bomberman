//
// MainMenuCreditView.hh for Bomberman in /home/magrin_j/Project/Bomberman
//
// Made by Jérémy Magrin
// Login   <magrin_j@epitech.net>
//
// Started on  Sun Jun  9 14:06:05 2013 Jérémy Magrin
// Last update Sun Jun  9 14:55:56 2013 Jérémy Magrin
//

#pragma		once

#include	"AModel.hpp"
#include	"MyText.hh"
#include	"AView.hpp"
#include	"Drawable.hh"
#include	"Img.hh"

namespace	Bomberman
{
  class		MainMenuCreditView : public Bomberman::AView
  {
  public:
    gdl::Image		_background;
    Bomberman::Img	_mayoukj;
    Bomberman::Img	_chazall;
    Bomberman::Img	_magrinj;
    Bomberman::Img	_hoaraus;
    Bomberman::Img	_kapousc;

  private:

  public:
    MainMenuCreditView();
    ~MainMenuCreditView();

  public:
    void		initialize(void);
    void		draw(const AModel *);
  };
}
