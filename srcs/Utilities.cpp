//
// Utilities.cpp for Bomberman in /home/mayouk_j/CPP/Bomberman
//
// Made by jimmy mayoukou
// Login   <mayouk_j@epitech.net>
//
// Started on  Sun Jun  9 00:22:19 2013 jimmy mayoukou
// Last update Sun Jun  9 01:24:30 2013 jimmy mayoukou
//

#include	<ctime>
#include	<sstream>
#include	"Utilities.hh"

bool		Utilities::checkExtension(const std::string &filename,
					  const std::string &extension)
{
  if (filename.rfind(extension) == std::string::npos)
    return (false);
  return (true);
}

std::string	Utilities::cleanExtension(const std::string &filename)
{
  return (filename.substr(0, filename.find('.')));
}

std::string		Utilities::getTimestamp()
{
  std::ostringstream	ss;
  time_t		timet = time(NULL);
  struct tm		*info = localtime(&timet);

  ss << 1900 + info->tm_year << (1 + info->tm_mon < 10 ? "0" : "");
  ss << 1 + info->tm_mon << info->tm_mday;
  ss << "-" << info->tm_hour << info->tm_min;
  return (ss.str());
}
