#pragma once
#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Element.h"
#include "imgui-SFML.h"
#include <map>
#include "ImguiElementTitle.h"
#include "ImguiElementInputInt.h"
#include "ImguiElementInputFloat.h"

class ImGuiWindow : public Element {
	/*CLasse gérant la fenêtre ImGui*/
private :
	/*Liste des input de Type Int, Pour avoir
	plusieurs Input de type int, Il suffit d'ajouter 
	un element de type ImguiElementInputInt à ce vecteur*/
	std::vector<std::shared_ptr<ImguiElementInputInt>> widgetsInt;

	/*Liste des input de Type Float, Pour avoir
	plusieurs Input de type Float, Il suffit d'ajouter
	un element de type ImguiElementInputInt à ce vecteur*/
	std::vector<std::shared_ptr<ImguiElementInputFloat>> widgetsFloat;

	std::vector<std::shared_ptr<ImguiElementTitle>> widgetsTitle;

	sf::Clock deltaClock;
	std::string title;
	float width;
	float height;

public:

	explicit ImGuiWindow(std::string const& title);
	void init(sf::RenderWindow &window, std::string const &title, std::string const &content);

	void render(sf::RenderWindow &window) override;

	/*Ajouter un Nouveau Input Int*/
	void addInputInt(std::string const& title, int expectedValue);

	/*Ajouter un Nouveau Input Float*/
	void addInputFloat(std::string const& title, float expectedValue);
	std::string getTitle() const;

	/*Cette fonction va vérifier si tout les inputs on 
	la valeur souhaité, si c'est le cas elle retourne vrai
	sinon faux..*/
	bool verify() override;

	void setWidth(const float width);

	void setHeight(const float height);

};

