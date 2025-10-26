#include "world.h"

void Inputs::update(const std::optional<sf::Event>& event)
{
	// XXX : could also use sf::Keyboard::isKeyPressed instead
	if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
	{
		if (keyPressed->scancode == sf::Keyboard::Scancode::Up)
			up = true;
		if (keyPressed->scancode == sf::Keyboard::Scancode::Down)
			down = true;
		if (keyPressed->scancode == sf::Keyboard::Scancode::Left)
			left = true;
		if (keyPressed->scancode == sf::Keyboard::Scancode::Right)
			right = true;
	}
	else if (const auto* keyReleased = event->getIf<sf::Event::KeyReleased>())
	{
		if (keyReleased->scancode == sf::Keyboard::Scancode::Up)
			up = false;
		if (keyReleased->scancode == sf::Keyboard::Scancode::Down)
			down = false;
		if (keyReleased->scancode == sf::Keyboard::Scancode::Left)
			left = false;
		if (keyReleased->scancode == sf::Keyboard::Scancode::Right)
			right = false;
	}
}

void World::update()
{
	for (auto& element : overlays) {
		element->update(*this);
	}
	for (auto& element : entities) {
		element->update(*this);
	}
	for (auto& element : backgrounds) {
		element->update(*this);
	}
}

void World::render(const sf::RenderTarget& target, double alpha) const
{
	for (auto& element : overlays) {
		element->render(target, alpha);
	}
	for (auto& element : entities) {
		element->render(target, alpha);
	}
	for (auto& element : backgrounds) {
		element->render(target, alpha);
	}
}

void World::build()
{
}