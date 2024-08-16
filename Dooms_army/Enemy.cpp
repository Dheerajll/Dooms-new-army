#include "Enemy.h"
#include<iostream>
void Enemy::initialize()
{
	size = sf::Vector2i(95, 155);
}

void Enemy::load()
{
	if (texture.loadFromFile("Assets/player/texture/playerright.png")) {
		std::cout << "Enemy loaded" << std::endl;
		sprite.setTexture(texture);
		sprite.setScale(sf::Vector2f(-0.75, 0.75));
		sprite.setTextureRect(sf::IntRect(0, 0, size.x, size.y));
		sprite.setOrigin(sf::Vector2f(size.x / 2, size.x / 2));
		sprite.setPosition(sf::Vector2f(400, 300));

	}
}

void Enemy::update(float deltatime)
{
	sf::Vector2f position = sprite.getPosition();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		sprite.setPosition(position + sf::Vector2f(0, -1) * enemyspeed * deltatime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		sprite.setPosition(position + sf::Vector2f(-1, 0) * enemyspeed * deltatime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		sprite.setPosition(position + sf::Vector2f(0, 1) * enemyspeed * deltatime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		sprite.setPosition(position + sf::Vector2f(1, 0) * enemyspeed * deltatime);
	}
}

void Enemy::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}
