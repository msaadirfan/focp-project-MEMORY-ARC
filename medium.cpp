#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include<chrono>
#include<thread>
#include<cstdlib>
#include<ctime>
using namespace std;
using namespace sf;
bool medium_level(RenderWindow& window)
{
    srand(time(0));
    // create boxes
    RectangleShape box1(Vector2f(170, 170));
    RectangleShape box2(Vector2f(170, 170));
    RectangleShape box3(Vector2f(170, 170));
    RectangleShape box4(Vector2f(170, 170));
    RectangleShape box5(Vector2f(170, 170));
    RectangleShape box6(Vector2f(170, 170));
    RectangleShape level(Vector2f(130, 50));
    // set initial box colors
    box1.setFillColor(Color::White);
    box2.setFillColor(Color::White);
    box3.setFillColor(Color::White);
    box4.setFillColor(Color::White);
    box5.setFillColor(Color::White);
    box6.setFillColor(Color::White);
    level.setFillColor(Color(255, 0, 0, 0));

    // set positions of boxes
    box1.setPosition(451.f, 246.0f);
    box2.setPosition(631.f, 246.0f);
    box3.setPosition(451.f, 426.0f);
    box4.setPosition(631.f, 426.f);
    box5.setPosition(811.f, 246.f);
    box6.setPosition(811.f, 426.f);
    level.setPosition(70.f, 70.f);

    // set origins of boxes
    box3.setOrigin(50.f, 50.f);
    box1.setOrigin(50.f, 50.f);
    box4.setOrigin(50.f, 50.f);
    box2.setOrigin(50.f, 50.f);
    box5.setOrigin(50.f, 50.f);
    box6.setOrigin(50.f, 50.f);
    level.setOrigin(50.f, 50.f);


    // score variables
    int level_number = 1; //round number
    int highlight_per_round = 2; //controls how many times boxes are highlighted in each round

    //font for round
    Font font;
    font.loadFromFile("font.ttf");
    if (!font.loadFromFile("font.ttf"))
        cout << "Failed to load font";
    Text level_;
    level_.setFillColor(Color::White);
    level_.setFont(font);// Ensure font is set
    level_.setCharacterSize(50);
    level_.setPosition(level.getPosition().x - 40, level.getPosition().y - 55);  // Set position
    level_.setString("LEVEL: " + to_string(level_number));
    //background
    Texture background;
    background.loadFromFile("background.jpg");
    if (!background.loadFromFile("background.jpg"))
    {
        cout << "error loading background image" << endl;
        return 0;
    }

    //sprite for background
    Sprite backg(background);

    //scaling the background to fit the window
    backg.setScale(
        static_cast<float>(window.getSize().x) / background.getSize().x,
        static_cast<float>(window.getSize().y) / background.getSize().y
    );
    //speed per round
    int millisecond = 450;

    //cursor
    Cursor defaultCursor, handCursor;
    defaultCursor.loadFromSystem(Cursor::Arrow);
    if (!defaultCursor.loadFromSystem(Cursor::Arrow))
        cout << "Failed to load default cursor" << endl;
    handCursor.loadFromSystem(Cursor::Hand);
    if (!handCursor.loadFromSystem(Cursor::Hand))
        cout << "Failed to load Hand cursor" << endl;

    //paino sound for boxes
    Music piano_sound;
    piano_sound.setVolume(100);
    if (!piano_sound.openFromFile("piano_sound.wav"))
        cout << "Failed loading the piano sound for the boxes";

    //text to show "correct"
    Text correct_text;
    correct_text.setFont(font);
    correct_text.setCharacterSize(70);
    correct_text.setFillColor(Color::Green);
    correct_text.setPosition(565, 50); // Adjust position as needed
    correct_text.setString("Correct!");


    //your turn box
    RectangleShape your_turn_box(Vector2f(300, 100));
    your_turn_box.setFillColor(Color::Transparent); // Semi-transparent black
    your_turn_box.setPosition(500, 600); // Centered


    Text your_turn_text;
    your_turn_text.setFont(font);
    your_turn_text.setString("Your Turn");
    your_turn_text.setCharacterSize(90);
    your_turn_text.setFillColor(Color::White);
    FloatRect textBounds = your_turn_text.getLocalBounds();
    your_turn_text.setPosition(
        your_turn_box.getPosition().x + (your_turn_box.getSize().x - textBounds.width) / 2,
        your_turn_box.getPosition().y + (your_turn_box.getSize().y - textBounds.height) / 2 - 10
    );



    while (window.isOpen()) {
        cout << "ROUND: " << level_number << endl;
        int user[100];int cpu[100];
        // random pattern generation

        for (int i = 0; i < 100; i++)
            cpu[i] = rand() % 6 + 1;

        for (int j = 0; j < highlight_per_round; j++) {


            // set the corresponding box to black based on random choice
            if (cpu[j] == 1)
            {
                piano_sound.play();
                box1.setFillColor(Color::Black);
            }
            else if (cpu[j] == 2)
            {
                piano_sound.play();
                box2.setFillColor(Color::Black);
            }
            else if (cpu[j] == 3)
            {
                piano_sound.play();
                box3.setFillColor(Color::Black);
            }
            else if (cpu[j] == 4)
            {
                piano_sound.play();
                box4.setFillColor(Color::Black);
            }
            else if (cpu[j] == 5)
            {
                piano_sound.play();
                box5.setFillColor(Color::Black);
            }
            else if (cpu[j] == 6)
            {
                piano_sound.play();
                box6.setFillColor(Color::Black);
            }
            // render the window with the highlighted box
            window.clear();
            window.draw(backg);
            window.draw(box1);
            window.draw(box2);
            window.draw(box3);
            window.draw(box4);
            window.draw(box5);
            window.draw(box6);
            window.draw(level);
            window.draw(level_);
            window.display();

            // pause to show the highlight
           this_thread::sleep_for(chrono::milliseconds(millisecond));

            // reset all boxes to white
            box1.setFillColor(Color::White);
            box2.setFillColor(Color::White);
            box3.setFillColor(Color::White);
            box4.setFillColor(Color::White);
            box5.setFillColor(Color::White);
            box6.setFillColor(Color::White);

            // render the reset boxes
            window.clear();
            window.draw(backg);
            window.draw(box1);
            window.draw(box2);
            window.draw(box3);
            window.draw(box4);
            window.draw(box5);
            window.draw(box6);
            window.draw(level);
            window.draw(level_);
            window.display();



            window.setMouseCursor(defaultCursor);
            // Pause before the next highlight
          this_thread::sleep_for(chrono::milliseconds(millisecond));

        }
        cout << "Repeat the Pattern! " << endl;


        // Check if the user has made a selection

        int   userentries = 0;//checks if the clicked the required number of boxes
        Event userinput;
        int counter = 0;//counter to store in user array

        while ((userentries < highlight_per_round) && window.isOpen()) {
            Event userEvnt;
            while (window.pollEvent(userEvnt)) {

                if (userEvnt.type == Event::MouseButtonPressed) {
                    if (userEvnt.mouseButton.button == Mouse::Left) {
                        // Check mouse position and update the corresponding box
                        Vector2f mousepos = window.mapPixelToCoords(Mouse::getPosition(window));
                        if (box1.getGlobalBounds().contains(mousepos))
                        {
                            user[counter] = 1;
                            counter++;
                            userentries++;
                            piano_sound.play();
                            box1.setFillColor(Color::Black);

                        }
                        else if (box2.getGlobalBounds().contains(mousepos))
                        {

                            user[counter] = 2;
                            counter++;
                            userentries++;
                            piano_sound.play();
                            box2.setFillColor(Color::Black);

                        }
                        else if (box3.getGlobalBounds().contains(mousepos))
                        {

                            user[counter] = 3;
                            counter++;
                            userentries++;
                            piano_sound.play();
                            box3.setFillColor(Color::Black);

                        }
                        else if (box4.getGlobalBounds().contains(mousepos))
                        {

                            user[counter] = 4;
                            counter++;
                            userentries++;
                            piano_sound.play();
                            box4.setFillColor(Color::Black);

                        }
                        else if (box5.getGlobalBounds().contains(mousepos))
                        {
                            user[counter] = 5;
                            counter++;
                            userentries++;
                            piano_sound.play();
                            box5.setFillColor(Color::Black);
                        }
                        else if (box6.getGlobalBounds().contains(mousepos))
                        {
                            user[counter] = 6;
                            counter++;
                            userentries++;
                            piano_sound.play();
                            box6.setFillColor(Color::Black);
                        }
                        window.clear();
                        window.draw(backg);
                        window.draw(box1);
                        window.draw(box2);
                        window.draw(box3);
                        window.draw(box4);
                        window.draw(box5);
                        window.draw(box6);
                        window.draw(level);
                        window.draw(level_);
                        window.draw(your_turn_box);
                        window.draw(your_turn_text);
                        window.display();

                    }
                }
                if (Event::MouseButtonReleased)
                {
                    Vector2f mousepos = window.mapPixelToCoords(Mouse::getPosition(window));
                    if (box1.getGlobalBounds().contains(mousepos) || box2.getGlobalBounds().contains(mousepos) || box3.getGlobalBounds().contains(mousepos) || box4.getGlobalBounds().contains(mousepos) || box5.getGlobalBounds().contains(mousepos) || box6.getGlobalBounds().contains(mousepos))
                        window.setMouseCursor(handCursor);
                    else
                        window.setMouseCursor(defaultCursor);
                }
            }
            this_thread::sleep_for(chrono::milliseconds(160));

            box1.setFillColor(Color::White);
            box2.setFillColor(Color::White);
            box3.setFillColor(Color::White);
            box4.setFillColor(Color::White);
            box5.setFillColor(Color::White);
            box6.setFillColor(Color::White);

            window.clear();
            window.draw(backg);
            window.draw(box1);
            window.draw(box2);
            window.draw(box3);
            window.draw(box4);
            window.draw(box5);
            window.draw(box6);
            window.draw(level);
            window.draw(level_);
            window.draw(your_turn_box);
            window.draw(your_turn_text);
            window.display();

        }


        // Draw the boxes and wait for user input
        window.clear();
        window.draw(backg);
        window.draw(box1);
        window.draw(box2);
        window.draw(box3);
        window.draw(box4);
        window.draw(box5);
        window.draw(box6);
        window.draw(level);
        window.draw(level_);
        window.draw(your_turn_box);
        window.draw(your_turn_text);
        window.display();

        //checks if user entered the correct pattern
        bool iscorrect = true;
        for (int i = 0;i < highlight_per_round;i++)
        {
            if (user[i] != cpu[i])
            {
                iscorrect = false;
                break;
            }
        }
        if (iscorrect) {
            cout << "Correct!" << endl;
            level_number++;
            level_.setString("LEVEL: " + to_string(level_number));

            // Display "Correct" text
            window.clear();
            window.draw(backg);
            window.draw(box1);
            window.draw(box2);
            window.draw(box3);
            window.draw(box4);
            window.draw(box5);
            window.draw(box6);
            window.draw(level);
            window.draw(level_);
            window.draw(correct_text);
            window.display();

           this_thread::sleep_for(chrono::milliseconds(800)); // Pause to show "Correct"
        }
        else {
            cout << "Incorrect!" << endl;
            cout << "Try again! " << endl;
            break;
        }
        // difficulty control
        highlight_per_round++;
        millisecond -= 20;
        cout << endl;
        if (!iscorrect)
            break;
    }


    return false;
}
