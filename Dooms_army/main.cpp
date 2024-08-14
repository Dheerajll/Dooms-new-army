#include<iostream>
#include<SFML/Graphics.hpp>



int main() {
	//----------Initialize-------
	sf::ContextSettings settings;
	settings.antialiasingLevel = 10;
	sf::RenderWindow window(sf::VideoMode(800, 600),"Dooms army",sf::Style::Default,settings);
	sf::Texture playertexture;
	sf::Sprite playersprite;
	if (playertexture.loadFromFile("Assets/player/texture/playerright.png")) {
		std::cout << "Player loaded" << std::endl;
		playersprite.setTexture(playertexture);
		playersprite.setScale(sf::Vector2f(0.75,0.75));
		playersprite.setTextureRect(sf::IntRect(0, 0, 95, 155));
		playersprite.setOrigin(sf::Vector2f(95 / 2, 155 / 2));
		playersprite.setPosition(sf::Vector2f(400, 300));

	}
	std::vector<sf::RectangleShape>bullets;
	float bulletspeed = 0.005;
	//----------Initialize-----
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}


		}
		//-------UPDATE-------
			sf::Vector2f position = playersprite.getPosition();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			playersprite.setPosition(position + sf::Vector2f(0,-1));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			playersprite.setPosition(position + sf::Vector2f(-1, 0));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			playersprite.setPosition(position + sf::Vector2f(0, 1));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			playersprite.setPosition(position + sf::Vector2f(1, 0));
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			bullets.push_back(sf::RectangleShape(sf::Vector2f(50,25)));
			int i = bullets.size() - 1;
			bullets[i].setPosition(playersprite.getPosition());
		}
		for (size_t i = 0; i < bullets.size(); i++)
		{
			sf::Vector2f bulletdirection;
			bulletdirection = sf::Vector2f(800, 600) - bullets[i].getPosition();
			bullets[i].setPosition(bullets[i].getPosition()+bulletdirection*bulletspeed);
		}
		//-------UPDATE-------
		// 
		//-------DRAW
		window.clear(sf::Color::Black);

		window.draw(playersprite);
		for (size_t i = 0; i < bullets.size(); i++)
		{
			window.draw(bullets[i]);
		}
		window.display();
		//-------DRAW
	}



	return 0;
}