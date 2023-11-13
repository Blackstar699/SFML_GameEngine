#include <SFML/Graphics.hpp>
#include "iostream"

class GameObject {
private:
    sf::Vector2f position;
    sf::Vector2f direction;
    sf::Vector2f size;
    sf::Color color;
    sf::Shape *shape;
    float speed = 300;
    bool collision = false;

public:
    //Class Constructors
    GameObject( sf::Vector2f _position, sf::Vector2f _size, sf::Color _color );   //rectangle
    GameObject( sf::Vector2f _position, float _size, sf::Color _color );          //circle
    
    //Set Methods
    void setColor( sf::Color _color );
    
    void setPosition( sf::Vector2f _position );
    
    void setRotation( float _angle );
    
    void setDirection( sf::Vector2f _direction );
    
    //Get Methods
    sf::Color getColor();
    
    sf::Vector2f getPosition();
    
    sf::Vector2f getSize();
    
    sf::Vector2f getDirection();
    
    //Other Methods
    void draw( sf::RenderWindow& window );
    
    void rotate( float _angle );
    
    void move( float deltaTime );
    
    //Collisions Methods
    bool checkCollisions( GameObject& goOther );
    /*sf::Vector2F GetPosition() { return body.getPosition(); }
    sf::Vector2f GetHalfSize() { return body.getSize()/ 2.0f; }*/
    
    virtual void onCollisionEnter();
    
    virtual void onCollisionStay();
    
    virtual void onCollisionExit();
};
