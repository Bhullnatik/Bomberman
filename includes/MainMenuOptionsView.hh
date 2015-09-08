//
// MenuOptionsView.hh for  in /home/hoarau_s/Projets/Bomberman/Bomberman/srcs
//
// Made by stephen hoarau
// Login   <hoarau_s@epitech.net>
//
// Started on  Thu Jun  6 15:20:14 2013 stephen hoarau
// Last update Thu Jun  6 17:09:18 2013 stephen hoarau
//

# pragma once

#include	<Model.hpp>
#include	<Image.hpp>
#include	"AModel.hpp"
#include	"AView.hpp"

namespace	Bomberman
{
  class		MainMenuOptionsView : public Bomberman::AView
  {
  public:
    gdl::Image		_background;

  public:
    MainMenuOptionsView();
    virtual ~MainMenuOptionsView() {}

    void	initialize();
    void        draw(const AModel *);

  };
}
