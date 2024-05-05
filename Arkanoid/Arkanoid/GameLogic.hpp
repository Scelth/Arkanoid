#pragma once
#include <list>
#include "Application.hpp"
#include "Ball.hpp"
#include "Backgroud.hpp"
#include "Paddle.hpp"
#include "Block.hpp"
#include "Sound.hpp"

class GameLogic
{
private:
    Application* application;
    Ball ball;
    Backgroud background;
    Paddle paddle;
    Block block;
    Sound sound;

    int score = 0;

    bool continueGame = false;

public:
    GameLogic(Application* app);
    ~GameLogic();

    void DrawGame();
    void StartGame();
    void RestartGame();
    void HandleWindowEvents();
};