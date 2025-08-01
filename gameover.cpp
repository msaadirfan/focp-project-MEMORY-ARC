#include<SFML/Graphics.hpp>
#include<iostream>
using namespace sf;
using namespace std;

int show_game_over(RenderWindow& window)
{
    RectangleShape game_over(Vector2f(1000, 400));
    RectangleShape play_again(Vector2f(300, 100));
    RectangleShape rtrn_to_menu(Vector2f(300, 100));

    game_over.setOrigin(500, 200);
    play_again.setOrigin(150, 50);
    rtrn_to_menu.setOrigin(150, 50);

    game_over.setFillColor(Color::Transparent);
    play_again.setFillColor(Color::Transparent);
    rtrn_to_menu.setFillColor(Color::Transparent);

    game_over.setPosition(650, 200);
    play_again.setPosition(650, 500);
    rtrn_to_menu.setPosition(650, 650);

    // Load font
    Font font;
    if (!font.loadFromFile("font.ttf"))
        cout << "Failed to load font";

    Text game_over_text("GAME OVER", font, 200);
    Text play_again_text("PLAY AGAIN", font, 80);
    Text rtrn_to_menu_text("MAIN MENU", font, 80);

    game_over_text.setFillColor(Color::White);
    play_again_text.setFillColor(Color::White);
    rtrn_to_menu_text.setFillColor(Color::White);

    game_over_text.setPosition(game_over.getPosition().x-350, game_over.getPosition().y-100);
    play_again_text.setPosition(play_again.getPosition().x - 140, play_again.getPosition().y - 60);
    rtrn_to_menu_text.setPosition(rtrn_to_menu.getPosition().x - 140, rtrn_to_menu.getPosition().y-60);

    // Load background
    Texture background;
    if (!background.loadFromFile("background.jpg"))
        cout << "Failed to load background";

    Sprite backg(background);
    backg.setScale(
        static_cast<float>(window.getSize().x) / background.getSize().x,
        static_cast<float>(window.getSize().y) / background.getSize().y
    );

    while (window.isOpen())
    {
        Vector2f mousepos = window.mapPixelToCoords(Mouse::getPosition(window)); 
        Event status;

        while (window.pollEvent(status))
        {
            if (status.type == Event::Closed)
            {
                window.close();
                return 2;
            }
            if (Event::MouseButtonPressed && status.mouseButton.button == Mouse::Left)
                {
                //if (status.mouseButton.button == Mouse::Left)
                {
                    if (play_again.getGlobalBounds().contains(mousepos))
                        return 1;
                    else if (rtrn_to_menu.getGlobalBounds().contains(mousepos))
                        return 2;
                }
                }
            }
        

        window.clear();
        window.draw(backg);
        window.draw(game_over);
        window.draw(play_again);
        window.draw(rtrn_to_menu);
        window.draw(game_over_text);
        window.draw(play_again_text);
        window.draw(rtrn_to_menu_text);
        window.display();
    }
    return 2;
}
