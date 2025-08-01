#include<SFML/Graphics.hpp>
#include<iostream>
using namespace std;
using namespace sf;
int select_difficulty(RenderWindow& window)
{
	RectangleShape selectbox(Vector2f(800, 100));
	RectangleShape easy(Vector2f(270, 80));
	RectangleShape medium(Vector2f(400, 80));
	RectangleShape hard(Vector2f(200, 80));
	
	selectbox.setPosition(212., 100.);
	easy.setPosition(582., 350.);
	medium.setPosition(512., 450.);
	hard.setPosition(612., 550.);

	selectbox.setFillColor(Color(255,0,0,0));
	easy.setFillColor(Color(255, 0, 0, 0));
	medium.setFillColor(Color(255, 0, 0, 0));
	hard.setFillColor(Color(255, 0, 0, 0));

	selectbox.setOrigin(100., 50.);
	easy.setOrigin(100., 50.);
	medium.setOrigin(100., 50.);
	hard.setOrigin(100., 50.);
	//background
	Texture background;
	background.loadFromFile("background.jpg");
	Sprite backg(background);
	backg.setScale(
		static_cast<float>(window.getSize().x) / background.getSize().x,
		static_cast<float>(window.getSize().y) / background.getSize().y
	);
	//font 
	Font font;
	font.loadFromFile("font.ttf");
	if(!font.loadFromFile("font.ttf"))
		cout<<"Failed to load Font";
	
	Text easy_("BEGINNER",font,90);
	Text medium_("INTERMEDIATE",font,90);
	Text hard_("EXPERT",font,90);
	Text selectbox_("SELECT THE DIFFICULTY",font,120);

	selectbox_.setPosition(selectbox.getPosition().x, selectbox.getPosition().y-70);
	easy_.setPosition(easy.getPosition().x-100, easy.getPosition().y-70);
	medium_.setPosition(medium.getPosition().x-85, medium.getPosition().y-70);
	hard_.setPosition(hard.getPosition().x-90, hard.getPosition().y-70);
	//cursor
	Cursor defaultCursor, handCursor;
	defaultCursor.loadFromSystem(Cursor::Arrow);
	handCursor.loadFromSystem(Cursor::Hand);
	while (window.isOpen())
	{
		Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.MouseButtonPressed)
			{
				if (evnt.mouseButton.button == Mouse::Left)
				{
					Vector2f mousepos = window.mapPixelToCoords(Mouse::getPosition(window));
					if (easy.getGlobalBounds().contains(mousepos))
						return 1;
					else if (medium.getGlobalBounds().contains(mousepos))
						return 2;
					else if (hard.getGlobalBounds().contains(mousepos))
						return 3;
				}
			}
			if (evnt.MouseButtonReleased)
			{
				Vector2f mousepos = window.mapPixelToCoords(Mouse::getPosition(window));
				if (easy.getGlobalBounds().contains(mousepos) || medium.getGlobalBounds().contains(mousepos) || hard.getGlobalBounds().contains(mousepos))
					window.setMouseCursor(handCursor);
				else
					window.setMouseCursor(defaultCursor);
			}
			if (evnt.type == Event::KeyPressed)
			{
				if (Keyboard::Key::Escape)
					return 4;
			}

		}
		window.clear();
		window.draw(backg);
		window.draw(easy);
		window.draw(medium);
		window.draw(hard);
		window.draw(selectbox);
		window.draw(easy_);
		window.draw(medium_);
		window.draw(hard_);
		window.draw(selectbox_);
		window.display();
	}
	return 0;
}
