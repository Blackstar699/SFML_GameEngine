#include <SFML/Graphics.hpp>
#include "iostream"

class GameObject {
private:
    sf::Vector2f position;
    sf::Vector2f direction;
    sf::Vector2f size;
    sf::Color color;
    sf::Shape *shape;
    float speed;
    bool collision = false;
    bool inCollision = false;

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
    
    sf::FloatRect getBounds();
    
    //Collisions Methods
    bool checkCollisions( GameObject& goOther );
    
    virtual void onCollisionEnter(GameObject& goOther);
    
    virtual void onCollisionStay();
    
    virtual void onCollisionExit();
    
    //Other Methods
    void draw( sf::RenderWindow& window );
    
    void rotate( float _angle );
    
    void move( float deltaTime );
};
