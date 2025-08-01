#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

using namespace sf;
using namespace std;


int show_main_menu(RenderWindow& window);
bool hard_level(RenderWindow& window);
bool beginner_level(RenderWindow& window);
bool medium_level(RenderWindow& window);
int select_difficulty(RenderWindow& window);
bool show_instruction_screen(RenderWindow& window);
int show_game_over(RenderWindow& window);
int window_width = 1280;int window_height = 720;
int main()
{ 
    RenderWindow window(VideoMode(window_width, window_height), "My project", Style::Default);
   
    Music main_menu_music;
    if (!main_menu_music.openFromFile("main_menu_music.wav"))
        cout << "Music not loading";
    main_menu_music.setLoop(true);
    main_menu_music.play();

        while (window.isOpen()) {
            main_menu_music.setVolume(100);
            Event evnt;
            while (window.pollEvent(evnt)) {
                switch (evnt.type) {
                case Event::Closed:
                    window.close();
                    break;
                case Event::Resized:
                    cout << "New window width " << evnt.size.width
                        << " New window height " << evnt.size.height << endl;
                    break;
                    
                }
            }
            if (show_main_menu(window) == 3)
                return 0;
            else if (show_main_menu(window) == 2)
                if (!show_instruction_screen(window))
                    continue;


            if (select_difficulty(window) == 4)
                continue;
            int difficulty = select_difficulty(window);

            bool game_running = true;
        
            while (game_running && window.isOpen())
            {
               main_menu_music.setVolume(0);
                switch (difficulty)
                {
                case 1:
                    
                    game_running = beginner_level(window);
                    if (!(game_running))
                    {
                        main_menu_music.setVolume(100);
                        if (show_game_over(window) == 1)
                        {
                            game_running = true;
                            continue;
                        }
                        else if(show_game_over(window)==2)
                            game_running = false;
                            
                       
                    }
                    break;
                case 2:
                    game_running = medium_level(window);
                    if (!game_running)
                    {
                        main_menu_music.setVolume(100);
                        if (show_game_over(window) == 1)
                        {
                            game_running = true;
                            continue;
                        }
                        else if (show_game_over(window) == 2)
                            game_running = false;
                    }
                    break;
                case 3:
                    game_running = hard_level(window);
                    if (!game_running)
                    {
                        main_menu_music.setVolume(100);
                        if (show_game_over(window) == 1)
                        {
                            game_running = true;
                            continue;
                        }
                        else if (show_game_over(window) == 2)
                            game_running = false;
                    }
                    break;
                }
                if (!game_running)
                 break;
                
            }

        
        }
        return 0;
}
