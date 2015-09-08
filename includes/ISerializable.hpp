//
// ISerializable.hpp for Bomberman in /home/mayouk_j/CPP/Bomberman
//
// Made by jimmy mayoukou
// Login   <mayouk_j@epitech.net>
//
// Started on  Sat Jun  1 11:31:21 2013 jimmy mayoukou
// Last update Tue Jun  4 15:53:05 2013 jimmy mayoukou
//

#pragma		once

#include	<iostream>

class		ISerializable
{
public:
  ISerializable() {}
  virtual ~ISerializable() {}
  virtual void	serialize(std::ostream &) const = 0;
};
