#pragma once
#include<SFML/Graphics.hpp>
class Math
{
public:
	static sf::Vector2f Normalize(sf::Vector2f);
	static bool checkCollision(sf::FloatRect, sf::FloatRect);
};

