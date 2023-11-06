#include "GameObject.h"

void GameObject::setPosition(sf::Vector2f _position) {
    position = _position;
}

sf::Vector2f GameObject::returnPosition() {
    return position;
}

void GameObject::setSize(sf::Vector2f _size) {
    size = _size;
}

sf::Vector2f GameObject::returnSize() {
    return size;
}

void GameObject::setColor(sf::Color _color) {
    color = _color;
}

sf::Color GameObject::returnColor() {
    return color;
}
