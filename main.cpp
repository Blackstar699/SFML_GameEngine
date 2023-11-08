#include "class/GameObject.h"

int main( int argc, char **argv ) {
    
    //Création d'une fenêtre
    const sf::Vector2i window_size(700, 800);
    sf::RenderWindow window(sf::VideoMode(window_size.x, window_size.y), "SFML", sf::Style::Close);
    window.setFramerateLimit(120);
    
    //Objects Declaration
    GameObject rect({200, 200}, {100, 50}, sf::Color::Red);
    GameObject circle({100, 100}, 50, sf::Color::Green);
    
    //GameLoop
    while ( window.isOpen() ) {
        //EVENT
        sf::Event o_event{};
        while ( window.pollEvent(o_event) ) {
            if ( o_event.type == sf::Event::KeyPressed ) {
                rect.setRotation(45);
            }
            
            
            if ( o_event.type == sf::Event::Closed )
                window.close();
        }
        
        //UPDATE
        
        //DRAW
        window.clear();
        
        rect.draw(window);
        circle.draw(window);
        
        window.display();
    }
    
    return EXIT_SUCCESS;
}
