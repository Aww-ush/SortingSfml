#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
int main()
{
    // create the window
    //create a button 
    // create a area where the button is if the mouse is pressed in the area then the button is pressed
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "My window");
    sf::RectangleShape rectangle(sf::Vector2f(120.f, 50.f));
    rectangle.setPosition(10.f, 50.f);
    rectangle.move(5.f, 5.f);
    rectangle.setRotation(45.f);
    rectangle.rotate(10.f);
    sf::CircleShape shape(50.f);
    sf::Texture texture;
    sf::Sprite sprite;
    sprite.setTexture(texture);
    if (!texture.loadFromFile("image.png"))
    {
        cout << "error loading texture" << endl;
    }
    // transforming the entity
    window.setVerticalSyncEnabled(true);
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        window.draw(rectangle);

        // end the current frame
        window.display();
    }

    return 0;
}