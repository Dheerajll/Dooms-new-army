#include "FrameRate.h"

void FrameRate::initialize()
{
	time = 0;
}

void FrameRate::load()
{
	if (font.loadFromFile("Assets/Fonts/abel-regular.ttf")) {
		text.setFont(font);
		
	}
}

void FrameRate::update(double deltatime)
{
	
	time += deltatime;
	if (time > 500) {
		int fps = int(1000 / deltatime);
		text.setString(std::to_string(fps));
		time = 0;
	}
}

void FrameRate::draw(sf::RenderWindow& window)
{
	window.draw(text);
}
