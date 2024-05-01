#include "ball.hpp"
#include "common.hpp"
#include "paddle.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <string>
// Determine whether two entities overlap
bool is_interacting(const game::paddle &e1, const game::ball &e2) {
  auto box1 = e1.get_bounding_box();
  auto box2 = e2.get_bounding_box();
  return box1.intersects(box2);
}

// Resolve potential collision between the ball and the paddle
void handle_collision(game::ball &b, const game::paddle &p) {
  if (is_interacting(p, b)) {
    // Make the ball bounce upwards
    b.move_up();

    // Make the new direction depend on where the collision occurs on the paddle
    // If the collision is on the left of the paddle, make the ball bounce to
    // the left
    if (b.x() < p.x())
      b.move_left();
    else
      b.move_right();
  }
}
void handle_collision2(game::ball &b, const game::paddle &p) {
  if (is_interacting(p, b)) {
    // Make the ball bounce upwards
    b.move_down();

    // Make the new direction depend on where the collision occurs on the paddle
    // If the collision is on the left of the paddle, make the ball bounce to
    // the left
    if (b.x() < p.x())
      b.move_left();
    else
      b.move_right();
  }
}

int main() {
  sf::RenderWindow window(sf::VideoMode(game::windowWidth, game::windowHeight),
                          "moatasem");
  sf::RectangleShape m_rect(
      sf::Vector2f(game::windowWidth, game::windowHeight));
  game::paddle paddle(0, (game::windowHeight - 20));
  game::pc_paddle paddle2(0, (20));
  game::ball ball(game::windowWidth / 2, game::windowHeight / 2);
  window.setFramerateLimit(60);
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::EventType::Closed) {
        window.close();
      }
    }
    window.clear();
    m_rect.setFillColor(sf::Color(139, 69, 19));
    m_rect.setPosition(0, 0);
    paddle.update();
    paddle2.update();
    ball.update();
    handle_collision(ball, paddle);
    handle_collision2(ball, paddle2);

    sf::Font font;
    font.loadFromFile("atop-font/Atop-R99O3.ttf");
    std::string value("moatasem\n");
    value += std::to_string(ball.player1_score);
    std::string pcvalue("PC\n");
    pcvalue += std::to_string(ball.pc_score);

    sf::Text text(value.c_str(), font, 30);
    sf::Text text2(pcvalue.c_str(), font, 30);
    text.setPosition(10, game::windowHeight / 2);
    text2.setPosition(game::windowWidth - 50, game::windowHeight / 2);
    // window.draw(m_rect);
    window.draw(paddle);
    window.draw(paddle2);
    window.draw(ball);
    window.draw(text);
    window.draw(text2);
    window.display();
  }

  return 0;
}