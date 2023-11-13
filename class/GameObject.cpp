#include "GameObject.h"

//Rectangle Constructor
GameObject::GameObject( sf::Vector2f _position, sf::Vector2f _size, sf::Color _color ) {
    shape = new sf::RectangleShape(_size);
    shape->setPosition(_position);
    shape->setFillColor(_color);
    
    position = _position;
    size = _size;
    color = _color;
    direction = {0,0};
}

//Circle Constructor
GameObject::GameObject( sf::Vector2f _position, float _size, sf::Color _color ) {
    shape = new sf::CircleShape(_size);
    shape->setPosition(_position);
    shape->setFillColor(_color);
    
    position = _position;
    size = {_size, _size};
    color = _color;
    direction = {0,0};
}

///////////////////
/// SET METHODS ///
///////////////////

//Set Color
void GameObject::setColor( sf::Color _color ) {
    color = _color;
    shape->setFillColor(color);
}

//Set Position
void GameObject::setPosition( sf::Vector2f _position ) {
    position = _position;
    shape->setPosition(position);
}

//Set Rotation
void GameObject::setRotation( float _angle ) {
    shape->setOrigin(size.x / 2, size.y / 2);
    shape->setRotation(_angle);
}

//Set Direction
void GameObject::setDirection( sf::Vector2f _direction ) {
    direction = _direction;
}

///////////////////
/// GET METHODS ///
///////////////////

//Get Color
sf::Color GameObject::getColor() {
    return color;
}

//Get Position
sf::Vector2f GameObject::getPosition() {
    return position;
}

//Get Size
sf::Vector2f GameObject::getSize() {
    return size;
}

//Get Direction
sf::Vector2f GameObject::getDirection() {
    return direction;
}

/////////////////////
/// OTHER METHODS ///
/////////////////////

//Draw Shape
void GameObject::draw( sf::RenderWindow& window ) {
    window.draw(*shape);
}

//Rotate Shape
void GameObject::rotate( float _angle ) {
    float rotation = shape->getRotation();
    shape->setOrigin(size.x / 2, size.y / 2);
    shape->setRotation(rotation+_angle);
}

//Move Shape
void GameObject::move( float deltaTime ) {
    sf::Vector2f newPosition;
    newPosition.x = getPosition().x + direction.x * deltaTime * speed;
    newPosition.y = getPosition().y + direction.y * deltaTime * speed;
    setPosition(newPosition);
}

//////////////////////////
/// COLLISIONS METHODS ///
//////////////////////////

//bool checkCollision( const sf::)

bool GameObject::checkCollisions( GameObject& goOther ) {
    std::vector<sf::Vector2f> points;
    for(int i = 0; i > shape->getPointCount(); i++){
        points.push_back(shape->getPoint(i));
    }
    
    for( auto& point : points ){
        std::cout << "x: " << point.x << ", y: " << point.y << std::endl;
    }
    
    for( auto& point : points ) {
        if(point.x >= goOther.getPosition().x && point.x <= goOther.getPosition().x + goOther.getSize().x &&
        point.y >= goOther.getPosition().y && point.y <= goOther.getPosition().y + goOther.getSize().y){
            collision = true;
            break;
        }
    }
    
    return collision;
}

void GameObject::onCollisionEnter() {

}

void GameObject::onCollisionStay() {

}

void GameObject::onCollisionExit() {

}
