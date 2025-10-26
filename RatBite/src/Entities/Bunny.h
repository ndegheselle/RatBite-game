#pragma once
#include "../World.h"

class Bunny : Entity
{
public:
	void update(const World& world);
	void render(const sf::RenderTarget& target, double alpha) const;
};