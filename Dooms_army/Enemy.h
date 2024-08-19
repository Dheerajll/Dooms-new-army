#pragma once
#include<SFML/Graphics.hpp>
class Enemy
{
	sf::Texture texture;
	sf::Vector2i size;
	float enemyspeed = 1.0f;
	sf::Text Healthtext;
	sf::Font font;
public:
	int health;
	sf::Sprite sprite;

public:
	void changeHP(int hp);
	void initialize();
	void load();
	void update(double);
	void draw(sf::RenderWindow&);
};
