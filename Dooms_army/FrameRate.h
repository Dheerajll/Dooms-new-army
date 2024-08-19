#pragma once
#include<SFML/Graphics.hpp>
class FrameRate
{
	sf::Text text;
	sf::Font font;
	int time;
public:
	

public:
	void initialize();
	void load();
	void update(double);
	void draw(sf::RenderWindow&);
};

