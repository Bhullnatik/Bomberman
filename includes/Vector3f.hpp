//
// Vector3F.hpp for tuto Bomber in /home/mayouk_j/CPP/Bomberman/libgdl_gl-2012.4
//
// Made by jimmy mayoukou
// Login   <mayouk_j@epitech.net>
//
// Started on  Sun May  5 17:18:01 2013 jimmy mayoukou
// Last update Wed May  8 03:49:17 2013 jimmy mayoukou
//

#pragma		once

struct		Vector3f
{
  float		x;
  float		y;
  float		z;

  Vector3f(void) : x(0.0f), y(0.0f), z(0.0f) {}
  Vector3f(float x, float y, float z) : x(x), y(y), z(z) {}

  Vector3f(const Vector3f &copy)
  {
    *this = copy;
  }

  ~Vector3f() {}

  Vector3f	&operator=(const Vector3f &copy)
  {
    this->x = copy.x;
    this->y = copy.y;
    this->z = copy.z;
    return (*this);
  }
};
