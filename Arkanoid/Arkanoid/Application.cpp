#include <time.h>
#include "Application.hpp"
#include "GameLogic.hpp"
#include "Constants.hpp"

Application::Application()
{
    window.create(sf::VideoMode(Constants::SCREEN_SIZE.x, Constants::SCREEN_SIZE.y), Constants::GAME_NAME);
    window.setFramerateLimit(60);
    windowSize = Constants::SCREEN_SIZE;
}

Application::~Application() { }

bool Application::IsOpen()
{
    return window.isOpen();
}

bool Application::PollEvent(sf::Event& event)
{
    return window.pollEvent(event);
}

void Application::Close()
{
    window.close();
}

void Application::Start()
{
    GameLogic game(this);

    game.CallMainMenu();
}

sf::RenderWindow& Application::GetRenderWindow()
{
    return window;
}

const sf::Vector2f& Application::GetSize()
{
    return windowSize;
}