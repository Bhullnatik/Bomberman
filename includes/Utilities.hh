//
// Utilities.hh for Bomberman in /home/mayouk_j/CPP/Bomberman
//
// Made by jimmy mayoukou
// Login   <mayouk_j@epitech.net>
//
// Started on  Sun Jun  9 00:22:24 2013 jimmy mayoukou
// Last update Sun Jun  9 01:24:06 2013 jimmy mayoukou
//

#pragma		once

class		Utilities
{
public:
  static bool		checkExtension(const std::string &, const std::string &);
  static std::string	cleanExtension(const std::string &);
  static std::string	getTimestamp();
};

