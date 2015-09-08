//
// PlayerView.cpp for bomberman in /home/chazal_l//Ydrasaal/PROJECT/Bomberman/Bomberman
//
// Made by leo chazal
// Login   <chazal_l@epitech.net>
//
// Started on  Wed May 15 18:09:28 2013 leo chazal
// Last update Sun Jun  9 19:05:05 2013 leo chazal
//

#include	<iostream>
#include	<ModelException.hpp>
#include	"APlayer.hh"
#include	"Data.hpp"
#include	"PlayerView.hh"

Bomberman::PlayerView::PlayerView()
{
  this->initialize();
}

Bomberman::PlayerView::~PlayerView()
{

}

void		Bomberman::PlayerView::setModelColor(const gdl::Color &color)
{
  this->_model.set_default_model_color(color);
}

gdl::Model&	 		Bomberman::PlayerView::getModel()
{
  return (this->_model);
}

void				Bomberman::PlayerView::initialize(void)
{
  try {
    this->_model = gdl::Model::load(MODE_BOMBERMAN);
  } catch (const gdl::ModelException *e) {
    std::cerr << "Error while loading model : " << e->what() << std::endl;
  }
}

void				Bomberman::PlayerView::moveTo(float x, float y, float z)
{
  glTranslatef(x, y, z);
}

void				Bomberman::PlayerView::rotateTo(float angle)
{
  glRotatef(angle, 0.0f, 1.0f, 0.0f);
}

#include <iostream>

bool				Bomberman::PlayerView::animIsEnded(const std::string &anim) const
{
  return (this->_model.anim_is_ended(anim));
}

void				Bomberman::PlayerView::runAnim(const std::string &anim)
{
  if (this->_model.anim_is_ended(anim))
    this->_model.play(anim);
}

void				Bomberman::PlayerView::stopAnim(const std::string &anim)
{
  if (!this->_model.anim_is_ended(anim))
    this->_model.stop_animation(anim);
}

void				Bomberman::PlayerView::draw(const AModel *model)
{
  const Bomberman::APlayer	*player = dynamic_cast<const Bomberman::APlayer *>(model);

  if (player->getSafeTime() % 2)
    return;
  glPushMatrix();

  this->moveTo(player->getPosition().x, 0, player->getPosition().z);
  glScalef(0.60f, 0.60f, 0.60f);
  this->rotateTo(player->getAngle());

  this->setModelColor(Bomberman::Data::getInstance()->getPlayerColor(player));

  this->_model.draw();

  glPopMatrix();
}

const Vector3f			&Bomberman::PlayerView::getPosition(void) const
{
  return (this->_pos);
}
