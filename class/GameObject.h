#ifndef SFML_GAMEENGINE_GAMEOBJECT_H
#define SFML_GAMEENGINE_GAMEOBJECT_H

#include <SFML/Graphics.hpp>

class GameObject {
private:
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Color color;
    
public:
    //Constructeur
    
    void setPosition(sf::Vector2f _position);
    sf::Vector2f returnPosition();
    void setSize(sf::Vector2f _size);
    sf::Vector2f returnSize();
    void setColor(sf::Color _color);
    sf::Color returnColor();
};

#endif
