#include <vector>
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
using namespace std;

enum class ButtonType
{
    Rectangle,
    Circle,
    Triangle
};

class Button
{
protected:
    vector<float> area;
    bool isPressed;
    string color;
    string text;

public:
    virtual sf::Shape GetShape() = 0;  
    void SetArea(vector<float> dimensions);
    vector<float> GetArea();
    void SetPressed(bool pressed);
    bool GetPressed();
    void SetColor(string newColor);
    string GetColor();
    void SetText(string newText);
    string GetText();
    virtual void Click() = 0; // Pure virtual function for Click action
};
void Button::SetArea(vector<float> dimensions)
{
    area = dimensions;
}

vector<float> Button::GetArea()
{
    return area;
}

void Button::SetPressed(bool pressed)
{
    isPressed = pressed;
}

bool Button::GetPressed()
{
    return isPressed;
}

void Button::SetColor(string newColor)
{
    color = newColor;
}

string Button::GetColor()
{
    return color;
}

void Button::SetText(string newText)
{
    text = newText;
}

string Button::GetText()
{
    return text;
}

// set shape for the button