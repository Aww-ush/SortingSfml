#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector> // Include the vector header

using namespace std;

const float THICKNESS = 50.f;

void FillVector(vector<float> &vec) // Pass vector by reference
{
    // fill the vector with random numbers
    for (int i = 0; i < 20; i++)
    {
        vec.push_back(rand() % 500 + 100);
    }
}

// Pass window by reference and vector by reference
void DrawRectangles(const vector<float> &vec, sf::RenderWindow &window)
{
    for (int i = 0; i < vec.size(); i++)
    {
        sf::RectangleShape rectangle(sf::Vector2f(THICKNESS, vec[i]));
        rectangle.setPosition(50.f + i * (THICKNESS + 10.f), 50.f); // Adjust position
        window.draw(rectangle);
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "My window");
    vector<float> vec;
    FillVector(vec);

    window.setVerticalSyncEnabled(true);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        DrawRectangles(vec, window);

        window.display();
    }

    return 0;
}
