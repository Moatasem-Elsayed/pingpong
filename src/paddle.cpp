
/********************************************/
//
//              CopyRight Moatasem Elsayed
//
/********************************************/
/*
author : Moatasem Elsayed
date :Tue Apr 30 11:33:27 PM EEST 2024
brief:
*/
#include "paddle.hpp"

namespace game {

paddle::paddle(int x, int y) {
  m_texture.loadFromFile("paddle.png");
  m_sprite.setTexture(m_texture);
  m_sprite.setPosition(x, y);
  m_velocity = {game::paddle_speed, 0.0f};
}

paddle::~paddle() {}

void paddle::draw(RenderTarget &target, RenderStates states) const {

  target.draw(m_sprite);
}

void paddle::update() {

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
    // Left arrow key pressed - move to the left
    // Unless the paddle has gone past the left hand side
    if (x() >= 0)
      m_velocity.x = -game::paddle_speed;
    else
      m_velocity.x = 0;
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
    // Similarly for the right arrow
    if (x() <= game::windowWidth - 80)
      m_velocity.x = game::paddle_speed;
    else
      m_velocity.x = 0;
  } else {
    // Some other key pressed, or no key at all
    m_velocity.x = 0;
  }
  m_sprite.move(m_velocity);
}
} // namespace game
