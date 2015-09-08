//
// Img.hh for Img in /home/magrin_j/Project/Bomberman
//
// Made by Jérémy Magrin
// Login   <magrin_j@epitech.net>
//
// Started on  Sun Jun  2 15:09:42 2013 Jérémy Magrin
// Last update Thu Jun  6 18:34:15 2013 Jérémy Magrin
//

#pragma		once

#include	<string>
#include	<Image.hpp>
#include	"Vector3f.hpp"

namespace		Bomberman
{
  class			Img
  {
  private:
    Vector3f		_pos;
    gdl::Image		_texture;
    float		_width;
    float		_height;

  public:
    unsigned int			getWidth(void) const;
    unsigned int			getHeight(void) const;
    void				setPosition(Vector3f);
    void				setPosition(float, float, float);
    void				setSize(float, float);
    void				setWidth(float);
    void				setHeight(float);

  public:
    void				load(const std::string &);
    void				draw(void);

  public:
    Img();
    ~Img();
  };
}
