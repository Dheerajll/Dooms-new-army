#include "Bullet.h"
#include"Math.h"
Bullet::Bullet() : speed(0)
{
}

Bullet::~Bullet()
{

}

void Bullet::initialize(const sf::Vector2f& position, sf::Vector2f target, float speed)
{
	this->speed = speed;
	bullet.setSize(sf::Vector2f(30, 15));
	bullet.setPosition(position);
	bulletdirection = Math::Normalize(target-position); 
}

void Bullet::update(double deltatime)
{
	bullet.setPosition(bullet.getPosition() + bulletdirection * (float)deltatime * speed);
}

void Bullet::draw(sf::RenderWindow& window)
{
	window.draw(bullet);
}
