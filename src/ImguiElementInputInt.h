#pragma once
#include <string>
class ImguiElementInputInt {
	/*Cette classe représente un élement de la window
	* ImGui represantant un input de type Float
	*/
public:
	explicit ImguiElementInputInt(std::string const& title, int expected);

	/*Cette fonction retourne la "reference" de result
	* pour qu'elle soit rempli après avec ImGui
	*/
	int& getRefInt();

	/*Cette fonction retourne la valeur de l'input
	*/
	int getInput() const;

	/*Retourne le titre de l'input Float
	*/
	std::string getTitle() const;

	/*Cette fonction vérifie si la valeur de l'inpur est
	* égale à la valeur attendue
	*/
	bool verify() const;

	/*Pour modifier le Titre*/
	void setTitle(std::string const& newTitle);

private:
	/*La valeur ou on stocke l'input*/
	int input= 0;

	/*La valeur exceptée pour gagner*/
	int expected = -9999;

	/*Titre de l'input*/
	std::string title;
};