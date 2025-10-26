#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <Dwmapi.h>
#include <chrono>
#include "world.h"

#pragma comment (lib, "Dwmapi.lib")

using Clock = std::chrono::high_resolution_clock;

sf::RenderWindow getWindow()
{
	sf::RenderWindow window(sf::VideoMode({ 1920u, 1080u }), "Transparent Window");
	window.setFramerateLimit(60);

	MARGINS margins;
	margins.cxLeftWidth = -1;

	// Transparent window
	SetWindowLong(window.getNativeHandle(), GWL_STYLE, WS_POPUP | WS_VISIBLE);
	DwmExtendFrameIntoClientArea(window.getNativeHandle(), &margins);
	return window;
}

int main()
{
	sf::RenderWindow window = getWindow();
	const double MS_PER_UPDATE = 1.0 / 60.0;

	World world;
	Clock::time_point previous = Clock::now();
	double lag = 0.0;

	while (window.isOpen())
	{
		Clock::time_point current = Clock::now();
		std::chrono::duration<double> elapsed = current - previous;
        previous = current;
		lag += elapsed.count();

		while (const std::optional<sf::Event> event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
			{
				window.close();
			}
		}
		world.inputs.update(window);

        while (lag >= MS_PER_UPDATE)
        {
            world.update();
            lag -= MS_PER_UPDATE;
        }
        
		double alpha = lag / MS_PER_UPDATE;
		window.clear(sf::Color::Transparent);
		world.render(window, alpha);
		window.display();
	}

	return 0;
}