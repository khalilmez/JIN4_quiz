#include <gtest/gtest.h>
#include "Game.h"
#include "Menu.h"
#include "Screen.h"
#include "UpdateStrategy.h"
#include "EventHandler.h"
#include "Text.h"
#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
#include "ImGuiWindow.h"
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

	auto sprite = std::make_unique<Sprite>(4, 5, "spriteTest", "resources/stripes.png", sf::Color());
	/*Test sur la classe Sprite */
	EXPECT_EQ("spriteTest", sprite->getName());
	EXPECT_EQ(4, sprite->getX());
	EXPECT_EQ(5, sprite->getY());
}
TEST(TestClassImGuiWindow, TestImGuiWindow) {
	
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


}

TEST(TestLevel1, TestLevel) {
	Game game;
	game.init();

}

