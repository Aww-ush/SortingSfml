#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <algorithm> // For shuffle
#include <random>
using namespace sf;
using namespace std;

class Field
{
private:
    vector<int> m_points;

public:
    void fill(const unsigned number_of_points)
    {
        // Creating the points
        for (unsigned i = 0; i < number_of_points; ++i)
        {
            m_points.push_back(i+50);
        }
        // Shuffling it
        std::random_device rd;
        std::mt19937 g(rd());

        // Shuffle the elements randomly
        std::shuffle(m_points.begin(), m_points.end(), g);
    }

    // bubble sort
    void BubbleSort()
    {
        for (size_t i = m_points.size() - 1; i > 0; --i)
        {
            bool swapped = false;
            for (size_t pos = 0; pos < i; ++pos)
            {
                if (m_points[pos] < m_points[pos + 1])
                {
                    swap(m_points[pos], m_points[pos + 1]);
                    swapped = true;
                }
            }
            if (swapped)
                break;
        }
    }

    void show_points(RenderWindow &App)
    {
        RectangleShape rectangle(Vector2f(1, 178));
        rectangle.setFillColor(Color(129, 154, 120));
        for (size_t i = 0; i < m_points.size(); i++)
        {
            rectangle.setPosition(i, m_points[i]);
            App.draw(rectangle);
        }
    }
};

int main()
{
    RenderWindow App(VideoMode(800, 600), "Bubble Sort");
    Event ev;
    Field fieldContext;
    fieldContext.fill(800);

    // Let's start the app
    while (App.isOpen())
    {
        // Verifying events
        while (App.pollEvent(ev))
        {
            // Window closed
            if (ev.type == Event::Closed)
                App.close();
        }
        fieldContext.BubbleSort();
        // Clearing screen
        App.clear(Color(255, 247, 244));
        fieldContext.show_points(App);

        // Displaying
        App.display();
    }
    return 0;
}