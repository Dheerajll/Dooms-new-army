#pragma once
#include<SFML/Graphics.hpp>
#include"Enemy.h"
class Player
{
	sf::Texture texture;
	std::vector<sf::RectangleShape>bullets;
	float bulletspeed = 1.0f;
	float playerspeed = 1.0f;
	sf::Vector2i size; 
public:
	sf::Sprite sprite;

public:
	void initialize();
	void load();
	void update(Enemy& enemy,float);
	void draw(sf::RenderWindow&);
};

