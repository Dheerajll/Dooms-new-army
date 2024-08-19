#pragma once
#include<SFML/Graphics.hpp>
#include"Enemy.h"
#include"Bullet.h"
class Player
{
	sf::Texture texture;
	std::vector<Bullet>bullets;
	float bulletspeed = 1.0f;
	float playerspeed = 1.0f;
	sf::Vector2i size; 
	float firerate;
	float maxfirerate;
public:
	sf::Sprite sprite;

public:
	Player();
	~Player();
	void initialize();
	void load();
	void update(Enemy& enemy,double,sf::Vector2i&);
	void draw(sf::RenderWindow&);
};

