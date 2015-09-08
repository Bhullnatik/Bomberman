//
// MainMenuLoadGameView.hh for  in /home/hoarau_s/Projets/Bomberman/Bomberman/includes
//
// Made by stephen hoarau
// Login   <hoarau_s@epitech.net>
//
// Started on  Thu Jun  6 17:43:06 2013 stephen hoarau
// Last update Thu Jun  6 17:43:41 2013 stephen hoarau
//

# pragma once

#include	<Model.hpp>
#include	<Image.hpp>
#include	"AModel.hpp"
#include	"MyText.hh"
#include	"AView.hpp"

namespace	Bomberman
{
  class		MainMenuLoadGameView : public Bomberman::AView
  {
  public:
    gdl::Image		_background;

  private:
    void	saves_choices(Bomberman::MyText, std::list<std::string>, int);

  public:
    MainMenuLoadGameView();
    virtual ~MainMenuLoadGameView() {}

    void	initialize();
    void        draw(const AModel *);

  };
}
