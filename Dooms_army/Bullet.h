#pragma once
#include<SFML/Graphics.hpp>

class Bullet
{
	sf::RectangleShape bullet;
	sf::Vector2f bulletdirection;
	float speed;
public:
	Bullet();
	~Bullet();
	void initialize(const sf::Vector2f& position, sf::Vector2f target, float speed);
	void update(double deltatime);
	void draw(sf::RenderWindow& window);
	inline const sf::FloatRect& GETbound() { return bullet.getGlobalBounds(); }
};