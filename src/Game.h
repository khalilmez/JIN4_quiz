#pragma once
#include <map>
#include <memory>
#include <vector>

class Screen;

class Game {

public:

	/* Initialise le jeu.
	Tous les niveaux et les menus du jeu sont
	construits dans cette méthode.
	*/
	void init();

	/* Permet de récupérer les menu associé à l'indentifiant
	id dans Game::menus.
	*/
	Screen* getMenu(int id) const;

	/* Permet de récupérer le niveau courant
	(Game::levels[Game::currentLevel]).
	*/
	Screen* getCurrentLevel() const;

	/* Ajoute un menu au jeu.
	* Utilisé dans la méthode Game::init().
	*/
	void addMenu(std::unique_ptr<Screen> menu);

	/* Ajoute un niveau au jeu.
	* Utilisé dans la méthode Game::init().
	*/
	void addLevel(std::unique_ptr<Screen> level);

	/* Incrémente l'indice du niveau courant.
	Permet de passer au niveau suivant.
	*/
	void nextLevel();

private:

	/* Les menus du jeu.
	Les menus sont des écrans comme les
	niveaux.
	*/
	std::map<int, std::unique_ptr<Screen>> menus;

	/* Les niveaux du jeu.
	Les niveaux sont des écrans.
	Les niveaux sont rangés dans levels
	par ordre de succession.
	Ainsi, levels[0] correspond au premier niveau, levels[1] au deuxième,
	et ainsi de suite.
	*/
	std::vector<std::unique_ptr<Screen>> levels;

	/* L'indice du niveau courrant dans levels.
	*/
	int currentLevel;

};
