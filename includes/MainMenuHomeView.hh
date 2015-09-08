//
// MenuHomeView.hh for Menu in /home/hoarau_s/Projets/Bomberman/Bomberman/srcs
//
// Made by stephen hoarau
// Login   <hoarau_s@epitech.net>
//
// Started on  Thu Jun  6 15:12:37 2013 stephen hoarau
// Last update Fri Jun  7 22:57:56 2013 leo chazal
//

#pragma		once

#include	<Model.hpp>
#include	<Image.hpp>
#include	"AModel.hpp"
#include	"AView.hpp"

namespace	Bomberman
{
  class		MainMenuHomeView : public Bomberman::AView
  {
  public:
    MainMenuHomeView();
    virtual ~MainMenuHomeView() {}

    void	initialize();
    void        draw(const AModel *);
  };
}
