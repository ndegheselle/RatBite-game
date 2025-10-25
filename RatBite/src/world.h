#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

class Inputs {
public:
	bool key_up;
	bool key_down;
	bool key_left;
	bool key_right;

	void update(const std::optional<sf::Event>& event);
};

class World;

class Entity
{
public:
	virtual void update(const World& world) = 0;
	virtual void render(const sf::RenderTarget& target, double alpha) const = 0;
};

class World {
public:
	Inputs inputs;

	std::vector<Entity*> overlays;
	std::vector<Entity*> entities;
	std::vector<Entity*> backgrounds;

	/// <summary>
	/// Build the base world objects
	/// </summary>
	void build();

	void update();
	void render(const sf::RenderTarget& target, double alpha) const;
};


