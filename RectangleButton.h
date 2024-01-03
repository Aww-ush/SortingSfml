#include "Button.h"
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
class RectangleButton : public Button
{
private:
    /* data */
public:
    RectangleButton();
    RectangleButton(float length, float width);
    void SetArea(vector<float> dimensions) override;
    sf::Shape GetShape() override; 
};

