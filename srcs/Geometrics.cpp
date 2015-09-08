//
// Geometrics.cpp for bomberman in /home/chazal_l//Ydrasaal/PROJECT/Bomberman/Bomberman
//
// Made by leo chazal
// Login   <chazal_l@epitech.net>
//
// Started on  Tue Jun  4 14:20:20 2013 leo chazal
// Last update Fri Jun  7 18:41:46 2013 leo chazal
//

#include        <OpenGL/gl.h>
#include        <OpenGL/glu.h>

#include	"bomberman.hh"
#include	"Geometrics.hh"

Bomberman::Geometrics::Geometrics()
{

}

Bomberman::Geometrics::~Geometrics()
{

}

void		Bomberman::Geometrics::cube(gdl::Image &texture,
					    const Vector3f &coo,
					    size_t width, size_t height, size_t depth)
{
  texture.bind();

  glBegin(GL_QUADS);

  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(coo.x, coo.y + height, coo.z);
  glTexCoord2f(0.0f, 1.0f);
  glVertex3f(coo.x, coo.y, coo.z);
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f(coo.x + width, coo.y, coo.z);
  glTexCoord2f(1.0f, 0.0f);
  glVertex3f(coo.x + width, coo.y + height, coo.z);

  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(coo.x, coo.y + height, coo.z + depth);
  glTexCoord2f(0.0f, 1.0f);
  glVertex3f(coo.x, coo.y, coo.z + depth);
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f(coo.x, coo.y, coo.z);
  glTexCoord2f(1.0f, 0.0f);
  glVertex3f(coo.x, coo.y + height, coo.z);

  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(coo.x + width, coo.y + height, coo.z + depth);
  glTexCoord2f(0.0f, 1.0f);
  glVertex3f(coo.x + width, coo.y, coo.z + depth);
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f(coo.x + width, coo.y, coo.z);
  glTexCoord2f(1.0f, 0.0f);
  glVertex3f(coo.x + width, coo.y + height, coo.z);

  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(coo.x, coo.y + height, coo.z + depth);
  glTexCoord2f(0.0f, 1.0f);
  glVertex3f(coo.x, coo.y, coo.z + depth);
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f(coo.x + width, coo.y, coo.z + depth);
  glTexCoord2f(1.0f, 0.0f);
  glVertex3f(coo.x + width, coo.y + height, coo.z + depth);

  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(coo.x, coo.y + height, coo.z);
  glTexCoord2f(0.0f, 1.0f);
  glVertex3f(coo.x, coo.y + height, coo.z + depth);
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f(coo.x + width, coo.y + height, coo.z + depth);
  glTexCoord2f(1.0f, 0.0f);
  glVertex3f(coo.x + width, coo.y + height, coo.z);

  glEnd();
}

void		Bomberman::Geometrics::pyramid(gdl::Image &texture,
					       const Vector3f &coo)
{
  texture.bind();

  glBegin(GL_TRIANGLES);

  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(coo.x + TILE_SIZE / 2, coo.y + TILE_SIZE, coo.z + TILE_SIZE / 2);
  glTexCoord2f(0.0f, 1.0f);
  glVertex3f(coo.x, coo.y, coo.z);
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f(coo.x + TILE_SIZE, coo.y, coo.z);

  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(coo.x + TILE_SIZE / 2, coo.y + TILE_SIZE, coo.z + TILE_SIZE / 2);
  glTexCoord2f(0.0f, 1.0f);
  glVertex3f(coo.x, coo.y, coo.z + TILE_SIZE);
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f(coo.x + TILE_SIZE, coo.y, coo.z + TILE_SIZE);

  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(coo.x + TILE_SIZE / 2, coo.y + TILE_SIZE, coo.z + TILE_SIZE / 2);
  glTexCoord2f(0.0f, 1.0f);
  glVertex3f(coo.x, coo.y, coo.z);
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f(coo.x, coo.y, coo.z + TILE_SIZE);

  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(coo.x + TILE_SIZE / 2, coo.y + TILE_SIZE, coo.z + TILE_SIZE / 2);
  glTexCoord2f(0.0f, 1.0f);
  glVertex3f(coo.x + TILE_SIZE, coo.y, coo.z);
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f(coo.x + TILE_SIZE, coo.y, coo.z + TILE_SIZE);

  glEnd();
}
