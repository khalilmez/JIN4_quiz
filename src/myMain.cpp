#include "myMain.h"
#include <iostream>
#include "imgui.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

#include "imgui-SFML.h"

using namespace std;
#define Width 640
#define Height 480
int myMain()
{
    sf::RenderWindow window(sf::VideoMode(Width, Height), "Quiz");
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);

    sf::Text question;
    sf::Font font;
    if (!font.loadFromFile("resources/Bernadette.ttf")) {
        cout << "Error"<<endl;
    }

    question.setFont(font);

    question.setString("Quel est la forme qui a le plus de cotés ?");
    cout << "¯\_( ͡° ͜ʖ ͡°)_/¯"<<endl;
    question.setCharacterSize(32); 
    question.setStyle(sf::Text::Bold);
    question.setFillColor(sf::Color::White);
    sf::FloatRect textRect = question.getLocalBounds();
    question.setOrigin(textRect.left + textRect.width / 2.0f,
        textRect.top + textRect.height / 2.0f);
    question.setPosition(sf::Vector2f(Width / 2.0f, 20.f));

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    static char rep[128] = "";

    sf::Clock deltaClock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            
            ImGui::SFML::ProcessEvent(event);

            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        ImGui::SFML::Update(window, deltaClock.restart());

        ImGui::Begin("Reponse :");
        ImGui::InputTextWithHint("Reponse", "Votre reponse", rep, IM_ARRAYSIZE(rep));
        ImGui::Button("Save");
        ImGui::End();

        window.clear();

        ImGui::SFML::Render(window);
        window.draw(question);
        window.display();
    }

    ImGui::SFML::Shutdown();


	return 0;
}