#include<SFML/Graphics.hpp>
#include<iostream>
using namespace std;
using namespace sf;
int show_main_menu(RenderWindow& window)
{
	//draw buttons
	RectangleShape start(Vector2f(300., 130.));
	RectangleShape exit(Vector2f(200., 130.));
	RectangleShape how_to_play(Vector2f(500., 130.));
	RectangleShape name(Vector2f(1120., 160.));
	
	//color of buttons
	start.setFillColor(Color(255,0,0,0));
	exit.setFillColor(Color(255,0,0,0));
	name.setFillColor(Color(255,0,0,0));
	how_to_play.setFillColor(Color(255,0,0,0));


	
	start.setPosition(Vector2f(530, 300));
	how_to_play.setPosition(Vector2f(350., 450));
	exit.setPosition(Vector2f(566, 600));
	name.setPosition(Vector2f(150, 100));
	
	
	start.setOrigin(Vector2f(50., 50.));
	exit.setOrigin(Vector2f(50., 50.));
	name.setOrigin(Vector2f(50., 50.));
	how_to_play.setOrigin(Vector2f(50., 50.));
	
	//text to be inserted inside buttons
	Font font;
	font.loadFromFile("font.ttf");
	
	if (!font.loadFromFile("font.ttf"))
		cout << "Failed to load font";
	Text name_("MEMORY ARC", font, 200);
	Text start_("START", font, 150);
	Text exit_("EXIT", font, 150);
	Text how_to_play_("HOW TO PLAY", font, 150);

	//color of font
	
	name_.setFillColor(Color::White);
	start_.setFillColor(Color::White);
	exit_.setFillColor(Color::White);
	how_to_play_.setFillColor(Color::White);
	
	//location of text

	name_.setPosition(Vector2f(name.getPosition().x + 80, name.getPosition().y - 100));
	start_.setPosition(Vector2f(start.getPosition().x - 35, start.getPosition().y - 85));
	exit_.setPosition(Vector2f(exit.getPosition().x - 25, exit.getPosition().y - 75));
	how_to_play_.setPosition(Vector2f(how_to_play.getPosition().x - 25, how_to_play.getPosition().y - 75));
	
	//cursor
	Cursor defaultCursor, handCursor;
	defaultCursor.loadFromSystem(Cursor::Arrow);
	handCursor.loadFromSystem(Cursor::Hand);

	//background
	Texture background;
	background.loadFromFile("background.jpg");
	Sprite backg(background);
	backg.setScale(
		static_cast<float>(window.getSize().x) / background.getSize().x,
		static_cast<float>(window.getSize().y) / background.getSize().y);

	

	while (window.isOpen())
	{
		Vector2f mousepos = window.mapPixelToCoords(Mouse::getPosition(window));
		Event menu;
		while (window.pollEvent(menu))
		{
			if (Event::Closed)
				window.close();
			if (Event::MouseButtonPressed)
			{
				if (menu.mouseButton.button == Mouse::Left)
				{
					if (start.getGlobalBounds().contains(mousepos))
						return 1;

					else if(how_to_play.getGlobalBounds().contains(mousepos))
						return 2;
					else if (exit.getGlobalBounds().contains(mousepos))
						return 3;
						
					
						
				}
			}
			if (Event::MouseButtonReleased)
			{
				if (start.getGlobalBounds().contains(mousepos) || exit.getGlobalBounds().contains(mousepos) ||how_to_play.getGlobalBounds().contains(mousepos))
				{
					window.setMouseCursor(handCursor);
					if (!handCursor.loadFromSystem(Cursor::Hand))
						cout << "Failed to load Hand Cursor" << endl;
				}
				else
				{
					window.setMouseCursor(defaultCursor);
					if (!handCursor.loadFromSystem(Cursor::Hand))
						cout << "Failed to load Hand Cursor" << endl;
				}
			}
	
		}
		window.clear();
		window.draw(backg);
		window.draw(start);
		window.draw(exit);
		window.draw(name);
		window.draw(name_);
		window.draw(start_);
		window.draw(exit_);
		window.draw(how_to_play);
		window.draw(how_to_play_);
		window.display();

	}
	return false;
}

