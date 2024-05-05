#include "GameLogic.hpp"
#include "Constants.hpp"

GameLogic::GameLogic(Application* app) : application(app)
{
    block.GetBlockSprites().clear();
    block.SetBlocks();

    sf::Vector2f pPosition = sf::Vector2f(application->GetSize().x, application->GetSize().y);
    paddle.SetPaddlePosition(pPosition);

    sf::Vector2f bPosition = sf::Vector2f(paddle.GetPaddlePosition().x + paddle.GetPaddleRect().width / 2.f, paddle.GetPaddlePosition().y - 15.f);
    ball.SetBallPosition(bPosition);
}

GameLogic::~GameLogic()
{
    delete application;
}

void GameLogic::DrawGame()
{
    application->GetRenderWindow().clear();

    background.DrawBackground(application->GetRenderWindow());
    ball.DrawBall(application->GetRenderWindow());
    paddle.DrawPaddle(application->GetRenderWindow());
    block.DrawBlock(application->GetRenderWindow());

    application->GetRenderWindow().display();
}

void GameLogic::StartGame()
{
    srand(time(0));
    ball.SetBallDirection(sf::Vector2f(5.f, -5.f));

    while (application->IsOpen())
    {
        paddle.SetPaddleSpeed(0.f);

        HandleWindowEvents();

        if (continueGame)
        {
            paddle.UpdatePaddle(application->GetSize().x);

            ball.SetBallPosition(sf::Vector2f(ball.GetBallPosition().x + ball.GetBallDirection().x, ball.GetBallPosition().y));

            for (auto i = block.GetBlockSprites().begin(); i != block.GetBlockSprites().end(); i++)
            {
                if (sf::FloatRect(ball.GetBallPosition().x + 3.f, ball.GetBallPosition().y + 3.f, 6.f, 6.f).intersects(i->getGlobalBounds()))
                {
                    i = block.GetBlockSprites().erase(i);
                    ++score;

                    ball.SetBallDirection(sf::Vector2f(-ball.GetBallDirection().x, ball.GetBallDirection().y));
                }
            }

            ball.SetBallPosition(sf::Vector2f(ball.GetBallPosition().x, ball.GetBallPosition().y + ball.GetBallDirection().y));

            for (auto i = block.GetBlockSprites().begin(); i != block.GetBlockSprites().end(); i++)
            {
                if (sf::FloatRect(ball.GetBallPosition().x + 3.f, ball.GetBallPosition().y + 3.f, 6.f, 6.f).intersects(i->getGlobalBounds()))
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


            if (ball.GetBallPosition().y > application->GetSize().y)
            {
                sound.GetLoseSound();
                RestartGame();
            }

            if (sf::FloatRect(ball.GetBallPosition().x, ball.GetBallPosition().y, 12.f, 12.f).intersects(paddle.GetPaddleRect()))
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

        ball.SetBallPosition(ball.GetBallPosition());
        DrawGame();

        if (score == (Constants::BLOCKS_COUNT.x * Constants::BLOCKS_COUNT.y))
        {
            sound.GetWinSound();
            RestartGame();
        }
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

    sf::Vector2f bPosition = sf::Vector2f(paddle.GetPaddlePosition().x + paddle.GetPaddleRect().width / 2.f, paddle.GetPaddlePosition().y - 15.f);
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
        }
    }
}