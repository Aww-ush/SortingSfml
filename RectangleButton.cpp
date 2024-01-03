#include "RectangleButton.h"

RectangleButton::RectangleButton()
{
    SetArea({120.f, 50.f}); // Default area
}

RectangleButton::RectangleButton(float length, float width)
{
    SetArea({length, width});
}

void RectangleButton::SetArea(std::vector<float> dimensions)
{
    if (dimensions.size() == 2)
    {
        area.push_back(dimensions[0]);
        area.push_back(dimensions[1]);
    }
    else
    {
        // Handle incorrect dimension input error
        std::cerr << "Invalid dimensions provided." << std::endl;
    }
}

sf::Shape RectangleButton::GetShape()
{
    sf::RectangleShape rectangle(area[0], area[1]); // Create rectangle shape with specified width and height
    rectangle.setPosition(10.f, 50.f);
    rectangle.move(5.f, 5.f);
    rectangle.setRotation(45.f);
    return rectangle;
}

// chage the color of the one in the bubble sort
// after you change the color then sort it
// then change the color back to the original color
// then sort the other one
// return the requirement to draw the button

