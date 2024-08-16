#include<SFML/Graphics.hpp>

#include"Player.h"
#include"Enemy.h"
int main() {
	//----------Initialize-------
	sf::ContextSettings settings;
	settings.antialiasingLevel = 10;
	sf::RenderWindow window(sf::VideoMode(800, 600),"Dooms army",sf::Style::Default,settings);
	window.setFramerateLimit(240);

	Player player;
	Enemy enemy;
	player.initialize();
	enemy.initialize();


	enemy.load();
	player.load();
	
	//----------Initialize-----
	sf::Clock clock;
	while (window.isOpen()) {
		sf::Time time = clock.restart();
		float deltatime = time.asMilliseconds();
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		//-------UPDATE-------
		enemy.update(deltatime);
		player.update(enemy,deltatime);

		//-------UPDATE-------
		// 
		//-------DRAW
		window.clear(sf::Color::Black);
		player.draw(window);
		enemy.draw(window);
		window.display();
		//-------DRAW
	}
	return 0;
}