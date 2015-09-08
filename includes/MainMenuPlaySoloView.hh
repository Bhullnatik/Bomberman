//
// MenuPlaySoloView.hh for  in /home/hoarau_s/Projets/Bomberman/Bomberman/srcs
//
// Made by stephen hoarau
// Login   <hoarau_s@epitech.net>
//
// Started on  Thu Jun  6 15:18:22 2013 stephen hoarau
// Last update Thu Jun  6 17:44:35 2013 stephen hoarau
//

# pragma once

#include	<Model.hpp>
#include	<Image.hpp>
#include	"AModel.hpp"
#include	"MyText.hh"
#include	"AView.hpp"

namespace	Bomberman
{
  class		MainMenuPlaySoloView : public Bomberman::AView
  {
  public:
    gdl::Image		_background;

  private:
    void	map_choices(Bomberman::MyText, std::list<std::string>, int);

  public:
    MainMenuPlaySoloView();
    virtual ~MainMenuPlaySoloView() {}

    void	initialize();
    void        draw(const AModel *);

  };
}
