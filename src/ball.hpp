
#pragma once
/********************************************/
//
//              CopyRight Moatasem Elsayed
//
/********************************************/
/*
author : Moatasem Elsayed
date :Wed May  1 03:42:21 PM EEST 2024
brief:
*/
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

namespace game {
using namespace sf;
class ball : public sf::Drawable {

public:
  int player1_score = 0;
  int pc_score = 0;
  ball(int x, int y);
  ~ball();
  void draw(RenderTarget &target, RenderStates states) const override;
  void update();
  sf::FloatRect get_bounding_box() const noexcept {
    return m_sprite.getGlobalBounds();
  }
  // Implement the helper functions
  void move_up() noexcept;
  void move_down() noexcept;
  void move_left() noexcept;
  void move_right() noexcept;
  // Helper functions to get the position of the sprite
  float x() const noexcept { return m_sprite.getPosition().x; }

  float y() const noexcept { return m_sprite.getPosition().y; }

private:
  sf::Texture m_texture;
  sf::Sprite m_sprite;
  sf::Vector2f m_velocity;
};
} // namespace game
