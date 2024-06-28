#pragma once
#include <list>
#include "Application.hpp"
#include "Ball.hpp"
#include "Backgroud.hpp"
#include "Paddle.hpp"
#include "Block.hpp"
#include "Sound.hpp"
#include "Menu.hpp"

class GameLogic
{
private:
    Application* application;
    Menu menu;
    Ball ball;
    Backgroud background;
    Paddle paddle;
    Block block;
    Sound sound;

    int score = 0;

    bool continueGame = false;
    bool gamePause = false;
    bool mainMenuCall = true;

public:
    GameLogic(Application* app);
    ~GameLogic();

    void CallMainMenu();
    void DrawGame();
    void StartGame();
    void UpdateGame();
    void RestartGame();
    void HandleWindowEvents();
};