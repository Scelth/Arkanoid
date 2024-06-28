#include "GameLogic.hpp"
#include "Constants.hpp"

GameLogic::GameLogic(Application* app) : application(app)
{
    block.GetBlockSprites().clear();
    block.SetBlocks();

    sf::Vector2f pPosition = sf::Vector2f(application->GetSize().x, application->GetSize().y);
    paddle.SetPaddlePosition(pPosition);

    sf::Vector2f bPosition = sf::Vector2f(paddle.GetObjectPosition().x + paddle.GetObjectRect().width / 2.f, paddle.GetObjectPosition().y - 15.f);
    ball.SetBallPosition(bPosition);
}

GameLogic::~GameLogic()
{
    delete application;
}

void GameLogic::CallMainMenu()
{
    while (mainMenuCall)
    {
        menu.MainMenuDraw(application->GetRenderWindow());

        sf::Event event;
        while (application->PollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                application->Close();
            }

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::Up)
                {
                    menu.MainMenuMove(event);
                }

                if (event.key.code == sf::Keyboard::Enter)
                {
                    if (menu.GetMenuSelected() == 0)
                    {
                        mainMenuCall = false;

                        while (application->IsOpen())
                        {
                            StartGame();
                        }
                    }

                    else
                    {
                        mainMenuCall = false;
                        application->Close();
                    }
                }

            }
        }
    }
}

void GameLogic::DrawGame()
{
    application->GetRenderWindow().clear();

    background.Draw(application->GetRenderWindow());
    ball.Draw(application->GetRenderWindow());
    paddle.Draw(application->GetRenderWindow());
    block.Draw(application->GetRenderWindow());

    application->GetRenderWindow().display();
}

void GameLogic::StartGame()
{
    srand(time(0));
    ball.SetBallDirection(sf::Vector2f(5.f, -5.f));

    while (application->IsOpen())
    {
        UpdateGame();
    }
}

void GameLogic::UpdateGame()
{
    paddle.SetPaddleSpeed(0.f);

    HandleWindowEvents();

    if (continueGame)
    {
        paddle.UpdatePaddle(application->GetSize().x);

        ball.SetBallPosition(sf::Vector2f(ball.GetObjectPosition().x + ball.GetBallDirection().x, ball.GetObjectPosition().y));

        for (auto i = block.GetBlockSprites().begin(); i != block.GetBlockSprites().end(); i++)
        {
            if (sf::FloatRect(ball.GetObjectPosition().x + 3.f, ball.GetObjectPosition().y + 3.f, 6.f, 6.f).intersects(i->getGlobalBounds()))
            {
                i = block.GetBlockSprites().erase(i);
                ++score;

                ball.SetBallDirection(sf::Vector2f(-ball.GetBallDirection().x, ball.GetBallDirection().y));
            }
        }

        ball.SetBallPosition(sf::Vector2f(ball.GetObjectPosition().x, ball.GetObjectPosition().y + ball.GetBallDirection().y));

        for (auto i = block.GetBlockSprites().begin(); i != block.GetBlockSprites().end(); i++)
        {
            if (sf::FloatRect(ball.GetObjectPosition().x + 3.f, ball.GetObjectPosition().y + 3.f, 6.f, 6.f).intersects(i->getGlobalBounds()))
            {
                i = block.GetBlockSprites().erase(i);
                ++score;

                ball.SetBallDirection(sf::Vector2f(ball.GetBallDirection().x, -ball.GetBallDirection().y));

                if (ball.GetBallDirection().x == 0.f)
                {
                    ball.SetBallDirection(sf::Vector2f(rand() / 2.f, ball.GetBallDirection().y));
                }
            }
        }

        ball.UpdateBall(application->GetSize());

        if (sf::FloatRect(ball.GetObjectPosition().x, ball.GetObjectPosition().y, 12.f, 12.f).intersects(paddle.GetObjectRect()))
        {
            if (paddle.GetPaddleSpeed() != 0.f)
            {
                ball.SetBallDirection(sf::Vector2f(-6.f, 0.f));
            }

            else
            {
                ball.SetBallDirection(sf::Vector2f(ball.GetBallDirection().x, -(rand() % 4 + 2.f)));

                if (ball.GetBallDirection().x == 0.f)
                {
                    ball.SetBallDirection(sf::Vector2f(rand() / 2.f, ball.GetBallDirection().y));
                }
            }
        }
    }

    ball.SetBallPosition(ball.GetObjectPosition());

    if (!gamePause)
    {
        DrawGame();
    }

    if (ball.GetObjectPosition().y > application->GetSize().y)
    {
        gamePause = true;
        sound.GetLoseSound();
        menu.GameOverMenuDraw(application->GetRenderWindow());
    }

    if (score == (Constants::BLOCKS_COUNT.x * Constants::BLOCKS_COUNT.y))
    {
        gamePause = true;
        sound.GetWinSound();
        menu.GameOverMenuDraw(application->GetRenderWindow());
    }
}

void GameLogic::RestartGame()
{
    continueGame = false;
    score = 0;

    sf::Vector2f pPosition = sf::Vector2f(application->GetSize().x, application->GetSize().y);
    paddle.SetPaddlePosition(pPosition);

    block.GetBlockSprites().clear();
    block.SetBlocks();

    sf::Vector2f bPosition = sf::Vector2f(paddle.GetObjectPosition().x + paddle.GetObjectRect().width / 2.f, paddle.GetObjectPosition().y - 15.f);
    ball.SetBallPosition(bPosition);
}

void GameLogic::HandleWindowEvents()
{
    sf::Event event;
    while (application->PollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            application->Close();
        }

        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Space)
            {
                continueGame = true;
            }

            if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::Up)
            {
                menu.GameOverMenuMove(event);
            }

            if (event.key.code == sf::Keyboard::Enter)
            {
                if (menu.GetGameOverSelected() == 0)
                {
                    gamePause = false;
                    RestartGame();
                }

                else
                {
                    application->Close();
                }
            }
        }
    }
}