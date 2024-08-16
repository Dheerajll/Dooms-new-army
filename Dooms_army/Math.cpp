#include "Math.h"
#include<cmath>
sf::Vector2f Math::Normalize(sf::Vector2f bulletdirection)
{
    sf::Vector2f normal;
    float magnitude = std::sqrt(bulletdirection.x * bulletdirection.x + bulletdirection.y * bulletdirection.y);
    normal = sf::Vector2f(bulletdirection.x / magnitude, bulletdirection.y / magnitude);
    return normal ;
}

bool Math::checkCollision(sf::FloatRect rect1, sf::FloatRect rect2)
{
    if (rect1.intersects(rect2)) {
        return true;
   }
}
