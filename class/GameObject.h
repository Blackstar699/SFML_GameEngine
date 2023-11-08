#include <SFML/Graphics.hpp>

class GameObject {
private:
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Color color;
    sf::Shape *shape;

public:
    //Class Constructors
    GameObject( sf::Vector2f _position, sf::Vector2f _size, sf::Color _color );   //rectangle
    GameObject( sf::Vector2f _position, float _size, sf::Color _color );          //circle
    
    void setPosition( sf::Vector2f _position );
    
    sf::Vector2f getPosition();
    
    void setSize( sf::Vector2f _size );
    
    sf::Vector2f getSize();
    
    void setColor( sf::Color _color );
    
    sf::Color getColor();
    
    void setRotation( float rotation );
    
    void draw( sf::RenderWindow &window );
};
