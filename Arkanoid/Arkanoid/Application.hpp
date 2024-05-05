#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Application
{
private:
    sf::RenderWindow window;
    sf::Vector2f windowSize;

public:
    Application();
    ~Application();

    void Close();
    void Start();

    bool IsOpen();
    bool PollEvent(sf::Event& event);

    const sf::Vector2f& GetSize();

    sf::RenderWindow& GetRenderWindow();
};