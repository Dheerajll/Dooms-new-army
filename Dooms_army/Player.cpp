
#include "Player.h"
#include<iostream>
#include "Math.h"
#include"Bullet.h"
Player::Player()
{

}


Player::~Player()
{
}
void Player::initialize()
{
	size = sf::Vector2i(95, 155);
	firerate = 0;
	maxfirerate = 100;
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

void Player::update(Enemy& enemy,double deltatime, sf::Vector2i& mouse)
{
	firerate += deltatime;
	sf::Vector2f position = sprite.getPosition();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		sprite.setPosition(position + sf::Vector2f(0, -1)*playerspeed * (float)deltatime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		sprite.setPosition(position + sf::Vector2f(-1, 0) * playerspeed * (float)deltatime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		sprite.setPosition(position + sf::Vector2f(0, 1) * playerspeed * (float)deltatime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		sprite.setPosition(position + sf::Vector2f(1, 0) * playerspeed * (float)deltatime);
	}

	

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && firerate>=maxfirerate) {
			bullets.push_back(Bullet());
			int i = bullets.size() - 1;
			bullets[i].initialize(sprite.getPosition(), sf::Vector2f(mouse),1.0f);
			
			firerate = 0;
		}
		

	for (size_t i = 0; i < bullets.size(); i++)
	{
		//sf::Vector2f bulletdirection;
		//bulletdirection =sf::Vector2f(mouse)- bullets[i].getPosition();
		//bullets[i].setPosition(bullets[i].getPosition() + Math::Normalize(bulletdirection) * bulletspeed* (float)deltatime);
		bullets[i].update(deltatime);
		if (enemy.health > 0) {
			if (Math::checkCollision(bullets[i].GETbound(), enemy.sprite.getGlobalBounds())) {

				bullets.erase(bullets.begin() + i);
				enemy.changeHP(-10);
			}
		}
	}
}

void Player::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	for (size_t i = 0; i < bullets.size(); i++)
	{
		bullets[i].draw(window);
	}
}
