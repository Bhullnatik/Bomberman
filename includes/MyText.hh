//
// MyText.hh for MyText in /home/hoarau_s/Projets/Bomberman/tmp/includes
//
// Made by stephen hoarau
// Login   <hoarau_s@epitech.net>
//
// Started on  Mon May 27 16:26:07 2013 stephen hoarau
// Last update Sun Jun  2 01:55:44 2013 Jérémy Magrin
//

# pragma	once

#include	"Text.hpp"

namespace	Bomberman
{

  class		MyText
  {
  public:
    MyText();
    ~MyText();
    void	setColor(unsigned char, unsigned char, unsigned char, unsigned char o = 255);
    void	draw(std::string, int, int, int);
    void	setFont(std::string);

  private:
    gdl::Text _text;
  };

};
