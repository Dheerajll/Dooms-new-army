#include<iostream>
#include<SFML/Graphics.hpp>

int main() {
	//------INITIALIZE-----
	sf::RenderWindow window(sf::VideoMode(800, 600), "Dooms army");
	//------LOAD
	sf::Texture playertexture;
	sf::Sprite playersprite;
	if (playertexture.loadFromFile("Assets/player/texture/playerright.png")) {
		std::cout << "Player image loaded" << std::endl;
		playersprite.setTexture(playertexture);
		playersprite.setTextureRect(sf::IntRect(0,0,95, 155));
		playersprite.setScale(sf::Vector2f(0.75, 0.75));
	}
	else {
		std::cout << "Player image not loaded" << std::endl;

	}
	//------GAME LOOP
	while (window.isOpen()) {
			int Xindex =0, Yindex=0;//Initially the sprite will be setted to no booster one every other time 
			playersprite.setTextureRect(sf::IntRect(Xindex * 95, Yindex * 155, 95, 155));

		//------UPDATE
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}


		}
			sf::Vector2f position = playersprite.getPosition();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			playersprite.setPosition(position + sf::Vector2f(0.75, 0));
			playersprite.setScale(0.75, 0.75);
			
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			Xindex = 0;//this makes the booster appear only when flying up
			Yindex = 1;
			playersprite.setPosition(position + sf::Vector2f(0, -0.5));
			playersprite.setTextureRect(sf::IntRect(Xindex * 95, Yindex * 155, 95, 155));
			
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			playersprite.setPosition(position + sf::Vector2f(-0.75, 0));
			playersprite.setScale(-0.75,0.75);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			playersprite.setPosition(position + sf::Vector2f(0, 0.75));
		}
		//------UPDATE
		window.clear(sf::Color::Black);
		//------DRAW
		window.draw(playersprite);

		window.display();
	}
	return 0;
} 