//
// Camera.cpp for Bomberman in /home/magrin_j/Project/Bomberman/Bomberman
//
// Made by magrin_j
// Login   <magrin_j@epitech.net>
//
// Started on  Mon May 20 17:10:02 2013 magrin_j
// Last update Sat Jun  8 18:57:14 2013 leo chazal
//

#include	<OpenGL/gl.h>
#include	<OpenGL/glu.h>
#include	<cmath>
#include	"Camera.hh"

Bomberman::Camera::Camera()
{
  this->_init = false;
}

Bomberman::Camera::~Camera()
{

}

void		Bomberman::Camera::setVectorPos(void)
{
  float		xPos;
  float		yPos;
  float		dist;

  xPos = static_cast<float>(((this->_sizeMapX) / 2.0f) * TILE_SIZE);
  yPos = static_cast<float>(((this->_sizeMapY) / 2.0f) * TILE_SIZE);
  dist = ((xPos > yPos) ? xPos : yPos) / tan(this->_fovy * M_PI / 180.0f);
  dist *= 2.8f;
  this->_eyePos = Vector3f(xPos, dist * 2.0f, sqrt(POW(dist) + POW(dist)) * 1.5f);
  this->_look = Vector3f(xPos, 0.0f, yPos);
  this->_upPos = Vector3f(0.0f, 1.0f, 0.0f);
}

void		Bomberman::Camera::setPlayers(const std::list<Vector3f> &players)
{
  this->_players = players;
  if (this->_sizeMapX > 20 || this->_sizeMapY > 20)
    this->findCenterPlayers();
  this->_init = false;
}

void		Bomberman::Camera::setSizeMap(size_t x, size_t y)
{
  this->_sizeMapX = x;
  this->_sizeMapY = y;
  this->setVectorPos();
}

void		Bomberman::Camera::findCenterPlayers(void)
{
  float		distPlayerCenter;
  float		distEye;
  Vector3f	max;

  this->_look = Vector3f(0.0f, 0.0f, 0.0f);
  for (std::list<Vector3f>::const_iterator it = this->_players.begin();
       it != this->_players.end(); it++)
    {
      this->_look.x += (*it).x + 1;
      this->_look.y += (*it).y + 1;
      this->_look.z += (*it).z + 1;
      if ((*it).x > max.x || (*it).z > max.z)
	max = (*it);
    }
  if (this->_players.size() > 0)
    {
      this->_look.x /= this->_players.size();
      this->_look.y /= this->_players.size();
      this->_look.z /= this->_players.size();
    }
  distPlayerCenter = sqrt(POW(max.x - this->_look.x) + POW(max.z - this->_look.z));
  if (distPlayerCenter < 600.0f)
    distPlayerCenter = 600.0f;
  distPlayerCenter *= 1.5f;
  distEye = distPlayerCenter / tan(this->_fovy);
  this->_eyePos.x = this->_look.x;
  this->_eyePos.y = distEye * 1.5f;
  this->_eyePos.z = distEye * 0.5f + this->_look.z;
}

void		Bomberman::Camera::initialize(const gdl::Window &window)
{
  if (this->_init)
    return ;
  this->_init = true;
  this->_sizeMapX = 0;
  this->_sizeMapY = 0;
  this->_fovy = 70.0f;
  this->setVectorPos();
  // glMatrixMode(GL_PROJECTION);
  // glLoadIdentity();
  // glViewport(0, 0, window.getWidth(), window.getHeight());
  gluPerspective(this->_fovy, window.getWidth() / window.getHeight(), 1.0f, 1000000.0f);
  gluLookAt(this->_eyePos.x, this->_eyePos.y, this->_eyePos.z,
	    this->_look.x, this->_look.y, this->_look.z,
	    this->_upPos.x, this->_upPos.y, this->_upPos.z);
  // glMatrixMode(GL_MODELVIEW);
  // glLoadIdentity();
  // glEnable(GL_DEPTH_TEST);
  // glDepthFunc(GL_LEQUAL);
}

void		Bomberman::Camera::resize(const gdl::Window &window)
{
  if (window.getWidth() < 500 || window.getHeight() < 500 ||
      this->_sizeMapX > 20 || this->_sizeMapY > 20)
    this->findCenterPlayers();
  else
    this->setVectorPos();
  glViewport(0, 0, window.getWidth(), window.getHeight());
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(this->_fovy, window.getWidth() / window.getHeight(), 1.0f, 1000000.0f);
}

void			Bomberman::Camera::update(const gdl::GameClock &, gdl::Input &,
						  const gdl::Window &window)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  this->resize(window);
  gluLookAt(this->_eyePos.x, this->_eyePos.y, this->_eyePos.z,
	    this->_look.x, this->_look.y, this->_look.z,
	    this->_upPos.x, this->_upPos.y, this->_upPos.z);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}
