#include<SFML/Graphics.hpp>
#include<iostream>
using namespace sf;
using namespace std;
bool show_instruction_screen(RenderWindow& window)
{   // shapes
	RectangleShape instruction_box(Vector2f(1212, 712));
	CircleShape close_instruction_screen(50.f);

	instruction_box.setOrigin(256, 256);
	//position
	instruction_box.setPosition(290, 260);
	close_instruction_screen.setPosition(1170, -30);
    
	instruction_box.setFillColor(Color::Transparent);
	close_instruction_screen.setFillColor(Color::Transparent);

	//cursor
	Cursor defaultCursor, handCursor;
	defaultCursor.loadFromSystem(Cursor::Arrow);
	handCursor.loadFromSystem(Cursor::Hand);
	window.setMouseCursor(defaultCursor);
	
	//Text
	Font font;
	if(!font.loadFromFile("font.ttf"))
		cout<<"Failed to load font";
	Text explain("\t\t\t\t\tWELCOME TO MEMORY ARC\n\nA game developed to challenge your visual memory.\nThe rules are simple, during each level several boxes\nwill get highlighted randomly and you have to repeat\nthe pattern by clicking the boxes.After every round\nthe game will become more challenging by highlighting \nmore number of boxes and increasing the speed.\n\t\t\t\t\t\t\t GOOD LUCK",font,65);
	Text close("BACK", font, 60);

	explain.setPosition(instruction_box.getPosition().x-250, instruction_box.getPosition().y-240);
	close.setPosition(close_instruction_screen.getPosition().x-5, close_instruction_screen.getPosition().y+20);
	Texture background;
	if (!background.loadFromFile("background.jpg"))
		cout << "failed to load background";
	Sprite backg(background);
	backg.setScale(
		static_cast<float>(window.getSize().x) / background.getSize().x,
		static_cast<float>(window.getSize().y) / background.getSize().y
	);

	while (window.isOpen())
	{
		Event instruction;
		while (window.pollEvent(instruction))
		{
			if (instruction.type == Event::Closed)
				window.close();
			if (instruction.type == Event::MouseButtonPressed)
			{
				Vector2f mousepos = window.mapPixelToCoords(Mouse::getPosition(window));
				if (close_instruction_screen.getGlobalBounds().contains(mousepos))
				{
					return false;
				}
			}
			if (instruction.MouseButtonReleased)
			{
				Vector2f mousepos = window.mapPixelToCoords(Mouse::getPosition(window));
				if (close_instruction_screen.getGlobalBounds().contains(mousepos))
					window.setMouseCursor(handCursor);
				else
					window.setMouseCursor(defaultCursor);
				
			}
			if (instruction.type == Event::KeyPressed)
			{
				if (Keyboard::Key::Escape)
					return false;

			}
		}
		window.clear();
		window.draw(backg);
		window.draw(instruction_box);
		window.draw(close_instruction_screen);
		window.draw(explain);
		window.draw(close);
		window.display();
    }
}