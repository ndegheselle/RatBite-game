#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <Dwmapi.h>

#pragma comment (lib, "Dwmapi.lib")

int main()
{
	sf::RenderWindow window(sf::VideoMode({ 1920u, 1080u }), "Transparent Window");
	window.setFramerateLimit(60);

	MARGINS margins;
	margins.cxLeftWidth = -1;

	// Transparent window
	SetWindowLong(window.getNativeHandle(), GWL_STYLE, WS_POPUP | WS_VISIBLE);
	DwmExtendFrameIntoClientArea(window.getNativeHandle(), &margins);

	//CircleShape for DemoContent
	sf::CircleShape shape(360.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
			{
				window.close();
			}
			else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
			{
				if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
					window.close();
			}
		}

		window.clear(sf::Color::Transparent);
		window.draw(shape);
		window.display();
	}

	return 0;
}