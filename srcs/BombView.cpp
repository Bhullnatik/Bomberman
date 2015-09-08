//
// BombView.cpp for bomberman in /home/chazal_l//Ydrasaal/PROJECT/Bomberman/Bomberman
//
// Made by leo chazal
// Login   <chazal_l@epitech.net>
//
// Started on  Fri May 24 13:45:18 2013 leo chazal
// Last update Tue Jun  4 17:22:39 2013 leo chazal
//

#include	"BombView.hh"
#include	<ModelException.hpp>
#include	<iostream>

Bomberman::BombView::BombView()
{
  this->initialize();
}

Bomberman::BombView::~BombView()
{

}

gdl::Model&	 Bomberman::BombView::getModel()
{
  return (this->_model);
}

void		Bomberman::BombView::initialize(void)
{
  try {
    this->_model = gdl::Model::load(MODE_BOMBS);
  } catch (const gdl::ModelException *e) {
    std::cerr << "Error while loading model : " << e->what() << std::endl;
  }
}

void		Bomberman::BombView::draw(const AModel *)
{
  glPushMatrix();

  this->moveTo(this->_pos);
  glScalef(0.6f, 0.6f, 0.6f);
  this->_model.draw();

  glPopMatrix();
}

void		Bomberman::BombView::runAnim(const std::string &anim)
{
  if (this->_model.anim_is_ended(anim))
    this->_model.play(anim);
}

void		Bomberman::BombView::stopAnim(const std::string &anim)
{
  if (!this->_model.anim_is_ended(anim))
    this->_model.stop_animation(anim);
}

void		Bomberman::BombView::moveTo(Vector3f pos)
{
  glTranslatef(pos.x + 100, pos.y + 75, pos.z + 100);
}
