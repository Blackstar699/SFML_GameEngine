#include "GameObject.h"

//Rectangle Constructor
GameObject::GameObject( sf::Vector2f _position, sf::Vector2f _size, sf::Color _color ) {
    shape = new sf::RectangleShape(_size);
    shape->setOrigin(_size.x / 2, _size.y / 2);
    shape->setPosition(_position);
    shape->setFillColor(_color);
    
    position = _position;
    size = _size;
    color = _color;
    speed = 100;
    direction = {0,0};
}

//Circle Constructor
GameObject::GameObject( sf::Vector2f _position, float _size, sf::Color _color ) {
    shape = new sf::CircleShape(_size);
    shape->setOrigin(_size, _size);
    shape->setPosition(_position);
    shape->setFillColor(_color);
    
    position = _position;
    size = {_size, _size};
    color = _color;
    speed = 200;
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
    //shape->setOrigin(size.x / 2, size.y / 2);
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

sf::FloatRect GameObject::getBounds() {
    return shape->getGlobalBounds();
}

//////////////////////////
/// COLLISIONS METHODS ///
//////////////////////////

bool GameObject::checkCollisions( GameObject& goOther ) {
    sf::FloatRect shapeBounds = shape->getGlobalBounds();
    sf::FloatRect otherBounds = goOther.getBounds();
    sf::Vector2f p1 = {shapeBounds.left, shapeBounds.top};
    sf::Vector2f p2 = {shapeBounds.left + shapeBounds.width, shapeBounds.top};
    sf::Vector2f p3 = {shapeBounds.left, shapeBounds.top + shapeBounds.height};
    sf::Vector2f p4 = {shapeBounds.left + shapeBounds.width, shapeBounds.top + shapeBounds.height};
    
    if(shapeBounds.intersects(otherBounds) || (otherBounds.contains(p1) || otherBounds.contains(p2) || otherBounds.contains(p3) || otherBounds.contains(p4))){
        collision = true;
        if(!inCollision){
            this->onCollisionEnter(goOther);
        }
    } else {
        collision = false;
        if(inCollision){
            this->onCollisionExit();
        }
    }
    
    if(collision || inCollision){
        //std::cout << "collision: " << collision << std::endl;
    }
    
    return collision;
}

void GameObject::onCollisionEnter(GameObject& goOther) {
    inCollision = true;
    std::cout << "inCollision -----> true" << std::endl;
    
    sf::FloatRect shapeBounds = shape->getGlobalBounds();
    sf::FloatRect otherBounds = goOther.getBounds();
    sf::Vector2f directions = this->getDirection();
    sf::Vector2f p1 = {shapeBounds.left, shapeBounds.top};
    sf::Vector2f p2 = {shapeBounds.left + shapeBounds.width, shapeBounds.top};
    sf::Vector2f p3 = {shapeBounds.left, shapeBounds.top + shapeBounds.height};
    sf::Vector2f p4 = {shapeBounds.left + shapeBounds.width, shapeBounds.top + shapeBounds.height};
    
    if(otherBounds.contains(p1) && otherBounds.contains(p2) && !otherBounds.contains(p3) && !otherBounds.contains(p4)){
        this->setDirection({directions.x, -directions.y});
    } else if(!otherBounds.contains(p1) && !otherBounds.contains(p2) && otherBounds.contains(p3) && otherBounds.contains(p4)){
        this->setDirection({directions.x, -directions.y});
    } else if(otherBounds.contains(p1) && !otherBounds.contains(p2) && otherBounds.contains(p3) && !otherBounds.contains(p4)){
        this->setDirection({-directions.x, directions.y});
    } else if(!otherBounds.contains(p1) && otherBounds.contains(p2) && !otherBounds.contains(p3) && otherBounds.contains(p4)){
        this->setDirection({-directions.x, directions.y});
    }
}

void GameObject::onCollisionStay() {

}

void GameObject::onCollisionExit() {
    inCollision = false;
    std::cout << "inCollision -----> false" << std::endl;
}

/////////////////////
/// OTHER METHODS ///
/////////////////////

//Draw Shape
void GameObject::draw( sf::RenderWindow& window ) {
    window.draw(*shape);
    sf::FloatRect rectgb = shape->getGlobalBounds();
    sf::RectangleShape rect({rectgb.width, rectgb.height});
    rect.setPosition({rectgb.left, rectgb.top});
    rect.setOutlineThickness(1);
    rect.setFillColor(sf::Color::Transparent);
    rect.setOutlineColor(sf::Color::White);
    window.draw(rect);
}

//Rotate Shape
void GameObject::rotate( float _angle ) {
    float rotation = shape->getRotation();
    shape->setRotation(rotation+_angle);
}

//Move Shape
void GameObject::move( float deltaTime ) {
    sf::Vector2f newPosition;
    newPosition.x = getPosition().x + direction.x * deltaTime * speed;
    newPosition.y = getPosition().y + direction.y * deltaTime * speed;
    setPosition(newPosition);
}
