#include "class/GameObject.h"

int main() {
    //Window Setup
    const sf::Vector2i window_size(700, 800);
    sf::RenderWindow window(sf::VideoMode(window_size.x, window_size.y), "SFML", sf::Style::Close);
    window.setFramerateLimit(120);
    
    //GameObjects Declarations
    GameObject cannon({350, 600 }, {50, 100 }, sf::Color::Red);
    GameObject circle({ 350, 600 }, 10, sf::Color::Green);
    GameObject rect({200,100}, {100,50}, sf::Color::Blue);
    
    //Variables Declarations
    sf::Clock clock;
    sf::Time time;
    sf::Vector2f direction{0, 0};
    float deltaTime = 0, angle;
    
    
    ///GameLoop Start
    while (window.isOpen()) {
        //EVENTS
        sf::Event o_event{};
        while (window.pollEvent(o_event)) {
            if (o_event.type == sf::Event::KeyPressed) {
                if (o_event.key.code == sf::Keyboard::R) {
                    circle.setPosition({350, 600});
                    circle.setDirection({0,0});
                    direction.x = direction.y = 0;
                }
                if (o_event.key.code == sf::Keyboard::Z) {
                    cannon.setDirection({cannon.getDirection().x, -1 });
                    cannon.move(deltaTime);
                }
                if (o_event.key.code == sf::Keyboard::Q) {
                    cannon.setDirection({-1, cannon.getDirection().y });
                    cannon.move(deltaTime);
                }
                if (o_event.key.code == sf::Keyboard::S) {
                    cannon.setDirection({cannon.getDirection().x, 1 });
                    cannon.move(deltaTime);
                }
                if (o_event.key.code == sf::Keyboard::D) {
                    cannon.setDirection({1, cannon.getDirection().y });
                    cannon.move(deltaTime);
                }
            }
            
            if (o_event.type == sf::Event::KeyReleased) {
                if (o_event.key.code == sf::Keyboard::Z || o_event.key.code == sf::Keyboard::S) {
                    cannon.setDirection({cannon.getDirection().x, 0 });
                }
                if (o_event.key.code == sf::Keyboard::Q || o_event.key.code == sf::Keyboard::D) {
                    cannon.setDirection({0, cannon.getDirection().y });
                }
            }
            
            if (o_event.type == sf::Event::MouseMoved) {
                sf::Vector2i mouse = sf::Mouse::getPosition(window);
                angle = -atan2(mouse.x - cannon.getPosition().x, mouse.y - cannon.getPosition().y) * 180 / 3.14159;
                if (angle > -115 && angle <= 0) {
                    angle = -115;
                }
                if (angle < 115 && angle >= 0) {
                    angle = 115;
                }
                cannon.setRotation(angle);
                //std::cout << "angle: " << angle << std::endl;
            }
            
            if (o_event.type == sf::Event::MouseButtonPressed) {
                if (o_event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mouse = sf::Mouse::getPosition(window);
                    direction.x = float(mouse.x) - cannon.getPosition().x;
                    direction.y = float(mouse.y) - cannon.getPosition().y;
                    float norme = std::sqrt(direction.x * direction.x + direction.y * direction.y);
                    direction = direction / norme;
                    std::cout << "xSet: " << direction.x << ", ySet: " << direction.y << std::endl;
                }
            }
            
            if (o_event.type == sf::Event::Closed) {
                window.close();
            }
        }
        
        //UPDATE
        if ( circle.getPosition().x - circle.getSize().x <= 0 || circle.getPosition().x + circle.getSize().x >= float(window_size.x) ) {
            direction.x = -direction.x;
        }
        if ( circle.getPosition().y - circle.getSize().y <= 0 ) {
            direction.y = -direction.y;
        }
        
        circle.setDirection({direction.x, direction.y});
        
        circle.checkCollisions(rect);
        
        circle.move(deltaTime);
        
        if ( circle.getPosition().y + circle.getSize().y > float(window_size.y) ) {
            circle.setPosition({350, 600});
            circle.setDirection({0,0});
            direction.x = direction.y = 0;
        }
        
        time = clock.restart();
        deltaTime = time.asSeconds();
        
        //DRAW
        window.clear();
        
        /* GRILLE
        float d = 50;
        for(int i = 0; i < window_size.y / d; i++){
            sf::RectangleShape line({float(window_size.x), 1});
            line.setPosition({0, float(i) * d});
            line.setFillColor(sf::Color::White);
            window.draw(line);
        }
        for(int i = 0; i < window_size.x / d; i++){
            sf::RectangleShape line({1, float(window_size.y)});
            line.setPosition({float(i) * d, 0});
            line.setFillColor(sf::Color::White);
            window.draw(line);
        }*/
        
        cannon.draw(window);
        circle.draw(window);
        rect.draw(window);
        
        window.display();
    }
    ///GameLoop End
    
    return EXIT_SUCCESS;
}
