#pragma once
#include<SFML/Graphics.hpp>
class Enemy
{
	sf::Texture texture;
	sf::Vector2i size;
	float enemyspeed = 1.0f;
public:
	sf::Sprite sprite;

public:
	void initialize();
	void load();
	void update(float);
	void draw(sf::RenderWindow&);
};
