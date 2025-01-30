#include "Map.h"
void Map::initTxt() {
	if (!txtArbre.loadFromFile("arbre.png") or
		txtPnj.loadFromFile("PNJ.png") or
		txtTombe.loadFromFile("tombe.png") or
		txtTour.loadFromFile("Tower.png") or
		txtKeyB.loadFromFile("Golden Key") or
		txtP.loadFromFile("porte open.png") or
		txtSext.loadFromFile("sol ext.png") or
		txtChemin.loadFromFile("chemin.png") or
		txtTpG.loadFromFile("tp gauche.png") or
		txtTpD.loadFromFile("tp droite.png") or
		txtMu.loadFromFile("mur.png")) {
		cout << endl << "impossible de charger un asset" << endl;
	}
}
void Map::initSprt() {
	sprtArbre.setTexture(txtArbre);
	sprtPnj.setTexture(txtPnj);
	sprtTombe.setTexture(txtTombe);
	sprtTour.setTexture(txtTour);
	sprtKeyB.setTexture(txtKeyB);
	sprtP.setTexture(txtP);
	sprtSext.setTexture(txtSext);
	sprtChemin.setTexture(txtChemin);
	sprtTpG.setTexture(txtTpG);
	sprtTpD.setTexture(txtTpD);
	sprtMu.setTexture(txtMu);
}

void Map::initall(){
	initTxt();
	initSprt(); 
}
void Map::initM() {
	initall();
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
			case ';':
			{
				RectangleShape solext(Vector2f(80, 99));
				solext.setPosition(Vector2f(80 * j, 99 * i));
				solext.setTexture(&txtSext);
				solext.setPosition(j * Width, i * Height);
				vSol.push_back(solext);
				break;
			}
			case '/':
			{
				RectangleShape Chemin(Vector2f(80, 99));
				Chemin.setPosition(Vector2f(80 * j, 99 * i));
				Chemin.setTexture(&txtChemin);
				Chemin.setPosition(j * Width, i * Height);
				vSol.push_back(Chemin);
				break;
			}
			case 'T':
			{
				RectangleShape Tombe(Vector2f(80, 99));
				Tombe.setPosition(Vector2f(80 * j, 99 * i));
				Tombe.setTexture(&txtTombe);
				Tombe.setPosition(j * Width, i * Height);
				vMur.push_back(Tombe);
				break;
			}
			case 'M':
			{
				RectangleShape Pnj(Vector2f(80, 99));
				Pnj.setPosition(Vector2f(80 * j, 99 * i));
				Pnj.setTexture(&txtPnj);
				Pnj.setPosition(j * Width, i * Height);
				vMur.push_back(Pnj);
				break;
			}

			case'§':
			{
				RectangleShape Tour(Vector2f(80, 99));
				Tour.setPosition(Vector2f(80 * j, 99 * i));
				Tour.setTexture(&txtTour);
				Tour.setPosition(j * Width, i * Height);
				vMur.push_back(Tour);
				break;
			}

			case'D':
			{
				RectangleShape tpD(Vector2f(80, 99));
				tpD.setPosition(Vector2f(80 * j, 99 * i));
				tpD.setTexture(&txtTpD);
				tpD.setPosition(j * Width, i * Height);
				break;
			}
			case'G':
			{
				RectangleShape tpG(Vector2f(80, 99));
				tpG.setPosition(Vector2f(80 * j, 99 * i));
				tpG.setTexture(&txtTpG);
				tpG.setPosition(j * Width, i * Height);
				break;
			}
			default:
				break;
			}
		}
	}
}