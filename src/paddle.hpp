
#pragma once
/********************************************/
//
//              CopyRight Moatasem Elsayed
//
/********************************************/
/*
author : Moatasem Elsayed
date :Tue Apr 30 11:33:26 PM EEST 2024
brief:
*/
#include "common.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
namespace game {
using namespace sf;
class paddle : public sf::Drawable {

public:
  paddle(int x, int y);
  ~paddle();
  void draw(RenderTarget &target, RenderStates states) const override;
  virtual void update();
  sf::FloatRect get_bounding_box() const noexcept {
    return m_sprite.getGlobalBounds();
  }
  // Helper functions to get the position of the sprite
  float x() const noexcept { return m_sprite.getPosition().x; }

  float y() const noexcept { return m_sprite.getPosition().y; }

protected:
  sf::Texture m_texture;
  sf::Sprite m_sprite;
  sf::Vector2f m_velocity;
};

class pc_paddle : public paddle {
public:
  pc_paddle(int x, int y) : paddle(x, y) {
    m_velocity = {game::pc_paddle_speed, 0.0f};
  }
  virtual void update() override {
    if (m_sprite.getPosition().x < 0 ||
        m_sprite.getPosition().x > game::windowWidth - 80) {
      m_velocity.x = -m_velocity.x;
    }
    m_sprite.move(m_velocity);
  };
};
} // namespace game
