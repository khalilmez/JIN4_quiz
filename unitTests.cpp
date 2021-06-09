#include <gtest/gtest.h>
#include "Game.h"
#include "Menu.h"
#include "Screen.h"
#include "UpdateStrategy.h"
#include "EventHandler.h"
#include "Text.h"
#include <iostream>
#include "Level1EventHandler.h"
#include "Level1UpdateStrategy.h"
#include "Level2EventHandler.h"
#include "Level2UpdateStrategy.h"
#include "Circle.h"
#include "Rectangle.h"
#include "ImGuiWindowBuilder.h"
#include "ImGuiWindow.h"
#include "WinLoseEventHandler.h"
#include "WinLoseUpdateStrategy.h"
#include "Sprite.h"

using namespace std;

#define WIDTH 640
#define HEIGHT 480
TEST(TestClassCircle, TestCircle) {

	auto circle = std::make_unique<Circle>(30, 80, "Circle", 50, sf::Color::Magenta);
	/*Test sur la classe Circle */
	EXPECT_EQ("Circle", circle->getName());
	EXPECT_EQ(30, circle->getX());
	EXPECT_EQ(80, circle->getY());
	EXPECT_EQ(50, circle->getRadius());
	EXPECT_EQ(sf::Color::Magenta, circle->getColor());
	EXPECT_EQ(true, circle->contains(35, 85));
	EXPECT_EQ(false, circle->contains(10, 85));

}

TEST(TestClassRectangle, TestRectangle) {

	auto rectangle = std::make_unique<Rectangle>(10, 20, "RectangleTest", 100, 150, sf::Color::Black);
	/*Test sur la classe Rectangle */
	EXPECT_EQ("RectangleTest", rectangle->getName());
	EXPECT_EQ(10, rectangle->getX());
	EXPECT_EQ(20, rectangle->getY());
	EXPECT_EQ(150, rectangle->getHeight());
	EXPECT_EQ(100, rectangle->getWidth());
	EXPECT_EQ(sf::Color::Black, rectangle->getColor());
	EXPECT_EQ(true, rectangle->contains(35, 85));
	EXPECT_EQ(true, rectangle->contains(10, 85));
	EXPECT_EQ(false, rectangle->contains(130, 85));

}

TEST(TestClassSprite, SpriteTest) {

	auto sprite = std::make_unique<Sprite>(4, 5, "spriteTest", "resources/stripes.png");
	/*Test sur la classe Sprite */
	EXPECT_EQ("spriteTest", sprite->getName());
	EXPECT_EQ(4, sprite->getX());
	EXPECT_EQ(5, sprite->getY());
}
TEST(TestClassImGuiWindow, TestImGuiWindow) {
	ImGuiWindowBuilder builder;

	/*Test de la classe qui va gérer le ImGui au sein de notre jeu */
	ImGuiWindow imgui = builder.withTitle("ImguiTest")->withContent("TestContent")->withInputInt("TestInt")->build();
	
	EXPECT_EQ("ImguiTest", imgui.getTitle());
	EXPECT_EQ("TestContent", imgui.getContent());
	EXPECT_EQ("TestInt", imgui.getTitleInt());
	EXPECT_EQ(true, imgui.hasInt());
	EXPECT_EQ(false, imgui.hasFloat());
}
TEST(TestClassText, TestText) {

	sf::Font font;
	auto text = std::make_unique<Text>(7, 8, "TextTest", "Formez un Rectangle.", font, 53, sf::Color(200, 200, 200), sf::Text::Bold);
	/*Test sur la classe Text */
	EXPECT_EQ("TextTest", text->getName());
	EXPECT_EQ(7, text->getX());
	EXPECT_EQ(8, text->getY());
	/*EXPECT_EQ(sf::Color(200, 200, 200), text->getColor());
	EXPECT_EQ("Formez un Rectangle.", text->getContent()); */
}

TEST(TestScreenClass, TestScreen) {
	Game game;
	game.init();
	auto winScreen = std::make_unique<Screen>(
		&game,
		std::move(std::make_unique<WinLoseEventHandler>()),
		std::move(std::make_unique<WinLoseUpdateStrategy>()),
		sf::Color()
		);

	winScreen->addElement(std::move(std::make_unique<Sprite>(0, 0, "background", "resources/stripes.png")));
	winScreen->addElement(std::move(std::make_unique<Sprite>(160, 10, "text", "resources/win.png")));
	winScreen->addElement(std::move(std::make_unique<Sprite>(260, 280, "button", "resources/next.png")));

	EXPECT_EQ(3, winScreen->getNumberOfElements());
	EXPECT_EQ("button", winScreen->getElement(2)->getName());
	EXPECT_EQ("text", winScreen->getElement(1)->getName());

	EXPECT_EQ(0, winScreen->getElement(0)->getX());
	EXPECT_EQ(0, winScreen->getElement(0)->getY());

	EXPECT_EQ(false, winScreen->isCompleted());

	winScreen->setCompleted(true);
	EXPECT_EQ(true, winScreen->isCompleted());

	EXPECT_EQ(false, winScreen->isFailed());

	winScreen->setFailed(true);
	EXPECT_EQ(true, winScreen->isFailed());

}

TEST(TestLevel1, TestLevel) {
	Game game;
	game.init();
	auto level1 = std::make_unique<Screen>(
		&game,
		std::move(std::make_unique<Level1EventHandler>()),
		std::move(std::make_unique<Level1UpdateStrategy>()),
		sf::Color()
		);

	sf::Font font;
	if (!font.loadFromFile("resources/Bernadette.ttf")) {
		std::cout << "Impossible de charger la police d'écriture." << std::endl;
	}

	sf::RenderWindow window;
	level1->addElement(std::move(std::make_unique<Text>(10, 10, "goal", "Trouvez la forme avec le plus de faces.", font, 53, sf::Color(200, 200, 200), sf::Text::Bold)));
	level1->addElement(std::move(std::make_unique<Circle>(30, 80, "Circle", 50, sf::Color::Magenta)));
	level1->addElement(std::move(std::make_unique<Rectangle>(WIDTH - 100, 100, "Rectangle", 50, 100, sf::Color::Yellow)));
	level1->addElement(std::move(std::make_unique<Circle>(WIDTH - 100, 280, "Triangle", 50, sf::Color::Red, 3)));
	level1->addElement(std::move(std::make_unique<Circle>(30, 280, "Octogone", 50, sf::Color::Red, 8)));

	EXPECT_EQ(5, level1->getNumberOfElements());

	EXPECT_EQ("Circle", level1->getElement(1)->getName());
	EXPECT_EQ("Octogone", level1->getElement(4)->getName());

}

