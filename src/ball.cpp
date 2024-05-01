
/********************************************/
//
//              CopyRight Moatasem Elsayed
//
/********************************************/
/*
author : Moatasem Elsayed
date :Wed May  1 03:42:22 PM EEST 2024
brief:
*/
#include "ball.hpp"
#include "common.hpp"
#include <iostream>

namespace game {
ball::ball(int x, int y) {
  m_texture.loadFromFile("ball.png");
  m_sprite.setTexture(m_texture);
  m_sprite.setPosition(x, y);
  m_velocity = {game::ballspeed, game::ballspeed};
  //   m_sprite.setOrigin(x, y);
}

ball::~ball() {}

void ball::draw(RenderTarget &target, RenderStates states) const {
  target.draw(m_sprite);
}

void ball::move_up() noexcept { m_velocity.y = -game::ballspeed; }

void ball::move_down() noexcept { m_velocity.y = game::ballspeed; }

void ball::move_left() noexcept { m_velocity.x = -game::ballspeed; }

void ball::move_right() noexcept { m_velocity.x = game::ballspeed; }

void ball::update() {
  if (m_sprite.getPosition().y < 0) {
    player1_score++;
    std::cout << "player1:" << player1_score << std::endl;
    std::cout << "pc:" << pc_score << std::endl;
  }
  if (m_sprite.getPosition().y > game::windowHeight) {
    pc_score++;
    std::cout << "player1:" << player1_score << std::endl;
    std::cout << "pc:" << pc_score << std::endl;
  }
  if (m_sprite.getPosition().x < 0 ||
      m_sprite.getPosition().x > game::windowWidth) {
    m_velocity.x = -m_velocity.x;
  }
  if (m_sprite.getPosition().y < 0 ||
      m_sprite.getPosition().y > game::windowHeight) {
    m_velocity.y = -m_velocity.y;
  }
  m_sprite.move(m_velocity);
}
} // namespace game
