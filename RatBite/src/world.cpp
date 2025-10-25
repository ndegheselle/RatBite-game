#include "world.h"

void Inputs::update(const std::optional<sf::Event>& event)
{
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