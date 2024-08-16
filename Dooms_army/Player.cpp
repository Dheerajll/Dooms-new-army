
#include "Player.h"
#include<iostream>
#include "Math.h"
void Player::initialize()
{
	size = sf::Vector2i(95, 155);
}

void Player::load()
{
	if (texture.loadFromFile("Assets/player/texture/playerright.png")) {
		std::cout << "Player loaded" << std::endl;
		sprite.setTexture(texture);
		sprite.setScale(sf::Vector2f(0.75, 0.75));
		sprite.setTextureRect(sf::IntRect(0, 0, size.x, size.y));
		sprite.setOrigin(sf::Vector2f(size.x / 2, size.x / 2));
		sprite.setPosition(sf::Vector2f(100, 100));

	}
}

void Player::update(Enemy& enemy,float deltatime)
{
	sf::Vector2f position = sprite.getPosition();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		sprite.setPosition(position + sf::Vector2f(0, -1)*playerspeed*deltatime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		sprite.setPosition(position + sf::Vector2f(-1, 0) * playerspeed * deltatime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		sprite.setPosition(position + sf::Vector2f(0, 1) * playerspeed * deltatime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		sprite.setPosition(position + sf::Vector2f(1, 0) * playerspeed * deltatime);
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		bullets.push_back(sf::RectangleShape(sf::Vector2f(30, 15)));
		int i = bullets.size() - 1;
		bullets[i].setPosition(sprite.getPosition());
	}
	for (size_t i = 0; i < bullets.size(); i++)
	{
		sf::Vector2f bulletdirection;
		bulletdirection =enemy.sprite.getPosition() - bullets[i].getPosition();
		bullets[i].setPosition(bullets[i].getPosition() + Math::Normalize(bulletdirection) * bulletspeed*deltatime);
	if (Math::checkCollision(sprite.getGlobalBounds(), enemy.sprite.getGlobalBounds())) {
		std::cout << "Collision!!";
		
	}
}
	}

void Player::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	for (size_t i = 0; i < bullets.size(); i++)
	{
		window.draw(bullets[i]);
	}
}
