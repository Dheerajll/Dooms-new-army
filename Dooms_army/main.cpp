#include<iostream>
#include<SFML/Graphics.hpp>

int main() {
	//------INITIALIZE-----
	sf::RenderWindow window(sf::VideoMode(800, 600), "Dooms army");
	sf::CircleShape triangle(50.0f, 3);
	triangle.setFillColor(sf::Color::Red);
	triangle.setPosition(sf::Vector2f(100, 100));
	//triangle.setOrigin(25.0f);

	//------GAME LOOP
	while (window.isOpen()) {

		//------UPDATE
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}


		}

		window.clear(sf::Color::Black);
		//------DRAW
		window.draw(triangle);

		window.display();
	}
	return 0;
}