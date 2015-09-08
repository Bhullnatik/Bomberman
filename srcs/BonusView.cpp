//
// BonusView.cpp for Bomberman in /home/chazal_l//Ydrasaal/PROJECT/Bomberman/Bomberman
//
// Made by leo chazal
// Login   <chazal_l@epitech.net>
//
// Started on  Wed May 22 21:39:55 2013 leo chazal
// Last update Fri Jun  7 21:11:48 2013 leo chazal
//

#include	<OpenGL/gl.h>
#include	<OpenGL/glu.h>
#include	"bomberman.hh"
#include	"Bonus.hh"
#include	"BonusView.hh"
#include	"Geometrics.hh"

Bomberman::BonusView::BonusView(void)
{
  this->initialize();
}

Bomberman::BonusView::~BonusView(void)
{

}

Bomberman::BonusView	*Bomberman::BonusView::getInstance(void)
{
  static BonusView	*instance = new BonusView();

  return (instance);
}

void			Bomberman::BonusView::initialize(void)
{
  this->_texture[B_BOMB] = gdl::Image::load(TEXT_B_BOMB);
  this->_texture[M_BOMB] = gdl::Image::load(TEXT_M_BOMB);
  this->_texture[B_POWER] = gdl::Image::load(TEXT_B_POWER);
  this->_texture[M_POWER] = gdl::Image::load(TEXT_M_POWER);
  this->_texture[B_SPEED] = gdl::Image::load(TEXT_B_SPEED);
  this->_texture[M_SPEED] = gdl::Image::load(TEXT_M_SPEED);
  this->_texture[INVINC] = gdl::Image::load(TEXT_B_INVINC);
  this->setType(0);
}

void				Bomberman::BonusView::draw(const AModel *model)
{
  const Bomberman::Bonus	*bonus = dynamic_cast<const Bomberman::Bonus *>(model);
  float				add = TILE_SIZE / 2.0f;

  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glTranslatef(this->_pos.x + add, this->_pos.y, this->_pos.z + add);
  glScalef(0.8f, 0.8f, 0.8f);
  glRotatef(this->_rotate, 0.0f, 1.0f, 0.0f);
  glTranslatef(-(this->_pos.x + add), -this->_pos.y, -(this->_pos.z + add));
  Bomberman::Geometrics::cube(this->_texture[bonus->getBonus()], this->_pos);
  glPopMatrix();
}

void		Bomberman::BonusView::setType(size_t id)
{
  this->_type = id;
}

void		Bomberman::BonusView::setRotation(float rotate)
{
  this->_rotate = rotate;
}
