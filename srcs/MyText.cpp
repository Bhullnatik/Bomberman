//
// Text.cpp for Text in /home/hoarau_s/Projets/Bomberman/tmp/includes
//
// Made by stephen hoarau
// Login   <hoarau_s@epitech.net>
//
// Started on  Mon May 27 16:30:19 2013 stephen hoarau
// Last update Sun Jun  2 01:53:45 2013 Jérémy Magrin
//

#include	<Color.hpp>
#include	"MyText.hh"

Bomberman::MyText::MyText()
{
}

Bomberman::MyText::~MyText()
{

}

void		Bomberman::MyText::setColor(unsigned char r, unsigned char g, unsigned char b, unsigned char o)
{
  this->_text.setColor(gdl::Color(r, g, b, o));
}

void		Bomberman::MyText::draw(std::string str, int x, int y, int size)
{
  this->_text.setText(str.c_str());
  this->_text.setSize(size);
  this->_text.setPosition(x, y);
  this->_text.draw();
}

void		Bomberman::MyText::setFont(std::string font)
{
  this->_text.setFont(font);
}
