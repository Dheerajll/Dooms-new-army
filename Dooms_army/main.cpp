#include<SFML/Graphics.hpp>

#include"Player.h"
#include"Enemy.h"
#include"FrameRate.h"
int main() {
	sf::ContextSettings settings;
	settings.antialiasingLevel = 10;
	sf::RenderWindow window(sf::VideoMode(800, 600),"Dooms army",sf::Style::Default,settings);
	window.setFramerateLimit(240);
	Player player;
	Enemy enemy;
	FrameRate frame;

	//----------Initialize-------

	frame.initialize();
	player.initialize();
	enemy.initialize();

	frame.load();
	enemy.load();
	player.load();
	
	//----------Initialize-----
	sf::Clock clock;
	while (window.isOpen()) {
		sf::Time time = clock.restart();
		double deltatime = time.asMicroseconds()/1000;
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		//-------UPDATE-------
		sf::Vector2i mouseposition = sf::Mouse::getPosition(window);
		enemy.update(deltatime);
		player.update(enemy,deltatime,mouseposition);
		frame.update(deltatime);

		//-------UPDATE-------
		// 
		// 
		// 
		// 
		// 
		//-------DRAW
		window.clear(sf::Color::Black);
		player.draw(window);
		enemy.draw(window);
		frame.draw(window);
		window.display();
		//-------DRAW
	}
	return 0;
}