#include "Map.h"
void Map::initTxt() {
	if (!txtArbre.loadFromFile("arbre.png")or
		txtPnj.loadFromFile("PNJ.png")or
		txtTombe.loadFromFile("tombe.png")or

}
void Map::initArbre(){
	sprtArbre.setTexture(txtArbre);
}
void Map::initSext(){
	txtSext.loadFromFile("");
}
void Map::initTour(){
	txtTour.loadFromFile("");
}
void Map::initChemin(){

}
void Map::initJ(){

}
void Map::initMu(){

}
void Map::initS(){

}
void Map::initP(){

}
void Map::initKey(){

}
void Map::initM() {
	window = new RenderWindow(VideoMode(1920, 1080), "Steam Purgator");
	ifstream file(fileM);
	if (!file.is_open()) {
		cout << endl << "Impossible de lire le fichier txt" << fileM << endl;
	}
	string line;
	while (getline(file, line)) {
		vM.push_back(line);
	}
}
void Map::DrawM() {
	float Width = static_cast<float>(window->getSize().x) / vM[0].size();
	float Height = static_cast<float>(window->getSize().y) / vM.size();
	for (size_t i = 0; i < vM.size(); i++) {
		for (size_t j = 0; j < vM[0].size(); j++) {
			switch (vM[i][j])
			{
			case '#':
			{
				RectangleShape arbre(Vector2f(80, 99));
				arbre.setPosition(Vector2f(80 * j, 99 * i));
				arbre.setTexture(&txtArbre);
				arbre.setPosition(j * Width, i * Height);
				vMur.push_back(arbre);
				break;
			}

			case'.':
			{
				RectangleShape sol(Vector2f(80, 99));
				sol.setPosition(Vector2f(80 * j, 99 * i));
				sol.setTexture(&txtS);
				sol.setPosition(j * Width, i * Height);
				vSol.push_back(sol);
				break;
			}

			case'D':
			{
				RectangleShape porte(Vector2f(80, 99));
				porte.setPosition(Vector2f(80 * j, 99 * i));
				porte.setTexture(&txtP);
				porte.setPosition(j * Width, i * Height);
				vPorte.push_back(porte);
				break;
			}
			default:
				break;
			}
		}
	}
}