#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

class Inputs {
public:
	bool key_up;
	bool key_down;
	bool key_left;
	bool key_right;
};

class World {
public:
	Inputs inputs;

	std::vector<Entity> UI;
	std::vector<Entity> entities;
	std::vector<Entity> backgrounds;

	void update(const std::optional event);
};

class Entity
{
public:
	virtual void update(const World& world) = 0;
	virtual void render(const sf::RenderTarget& target, double alpha) const = 0;
};

