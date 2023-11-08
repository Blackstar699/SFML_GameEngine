#include "GameObject.h"

//Rectangle Constructor
GameObject::GameObject( sf::Vector2f _position, sf::Vector2f _size, sf::Color _color ) {
    shape = new sf::RectangleShape(_size);
    shape->setPosition(_position);
    shape->setFillColor(_color);
}

//Circle Constructor
GameObject::GameObject( sf::Vector2f _position, float _size, sf::Color _color ) {
    shape = new sf::CircleShape(_size);
    shape->setPosition(_position);
    shape->setFillColor(_color);
}

void GameObject::setPosition( sf::Vector2f _position ) {
    position = _position;
    shape->setPosition(position);
}

sf::Vector2f GameObject::getPosition() {
    return position;
}

void GameObject::setSize( sf::Vector2f _size ) {
    size = _size;
}

sf::Vector2f GameObject::getSize() {
    return size;
}

void GameObject::setColor( sf::Color _color ) {
    color = _color;
    shape->setFillColor(color);
}

sf::Color GameObject::getColor() {
    return color;
}

void GameObject::draw( sf::RenderWindow &window ) {
    window.draw(*shape);
}

void GameObject::setRotation( float rotation ) {

}
