#include "Map.h"
Map::Map(RenderWindow& w) : window(w) {

};
void Map::initTxt() {
	if (!txtArbre.loadFromFile("Assets/arbre.png")) {
		cout << "Erreur de chargement de l'arbre" << endl;
	}
	if (!txtPnj.loadFromFile("Assets/mob.png")) {
		cout << "Erreur de chargement du PNJ" << endl;
	}
	if (!txtTombe.loadFromFile("Assets/tombe pnj.png")) {
		cout << "Erreur de chargement de la tombe" << endl;
	}
	if (!txtTour.loadFromFile("Assets/Tower 1.png")) {
		cout << "Erreur de chargement de la Tower" << endl;
	}
	if (!txtKeyB.loadFromFile("Assets/Golden Key.png")) {
		cout << "Erreur de chargement de la Golden Key" << endl;
	}
	if (!txtP.loadFromFile("Assets/porte open.png")) {
		cout << "Erreur de chargement de la porte open" << endl;
	}
	if (!txtSext.loadFromFile("Assets/sol ext (2).png")) {
		cout << "Erreur de chargement du sol ext" << endl;
	}
	if (!txtChemin.loadFromFile("Assets/chemin (2).png")) {
		cout << "Erreur de chargement du chemin" << endl;
	}
	if (!txtTpG.loadFromFile("Assets/tp gauche.png")) {
		cout << "Erreur de chargement du tp gauche" << endl;
	}
	if (!txtTpD.loadFromFile("Assets/tp droite.png")) {
		cout << "Erreur de chargement du tp droit" << endl;
	}
	if (!txtMu.loadFromFile("Assets/mur.png")) {
		cout << "Erreur de chargement du mur" << endl;
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
void Map::initF() {
	if (!fI.loadFromFile("Assets/huggo/Huggo.otf")) {
		cout << endl << "Impossible de charger la fonte" << endl;
	}
}
void Map::initT() {
	interact.setFont(fI);
	interact.setString("E");
	interact.setCharacterSize(15);
	interact.setFillColor(Color::Black);
	interact.setStyle(Text::Bold);

}

void Map::initall(){
	initTxt();
	initSprt(); 
	initF();
	initT();
}
void Map::initM(string fileM) {
	initall();
	ifstream file(fileM);
	if (!file.is_open()) {
		cout << endl << "Impossible de lire le fichier txt" << fileM << endl;
	}
	string line;
	while (getline(file, line)) {
		vM.push_back(line);
	}
}
void Map::DrawM(Player& p) {
	float Width = static_cast<float>(window.getSize().x) / vM[0].size();
	float Height = static_cast<float>(window.getSize().y) / vM.size();
	for (size_t i = 0; i < vM.size(); i++) {
		for (size_t j = 0; j < vM[0].size(); j++) {
			switch (vM[i][j])
			{
			case '#':
			{
				RectangleShape solext(Vector2f(67, 54));
				solext.setPosition(Vector2f(67 * j, 54 * i));
				solext.setTexture(&txtSext);
				solext.setPosition(j * Width, i * Height);
				vSol.push_back(solext);
				RectangleShape arbre(Vector2f(67, 54));
				arbre.setPosition(Vector2f(67 * j, 54 * i));
				arbre.setTexture(&txtArbre);
				arbre.setPosition(j * Width, i * Height);
				vMur.push_back(arbre);
				break;
			}
			case ';':
			{
				RectangleShape solext(Vector2f(67, 54));
				solext.setPosition(Vector2f(67 * j, 54 * i));
				solext.setTexture(&txtSext);
				solext.setPosition(j * Width, i * Height);
				vSol.push_back(solext);
				break;
			}
			case '/':
			{
				RectangleShape Chemin(Vector2f(67, 54));
				Chemin.setPosition(Vector2f(67 * j, 54 * i));
				Chemin.setTexture(&txtChemin);
				Chemin.setPosition(j * Width, i * Height);
				vSol.push_back(Chemin);
				break;
			}
			case 'T':
			{
				RectangleShape solext(Vector2f(67, 54));
				solext.setPosition(Vector2f(67 * j, 54 * i));
				solext.setTexture(&txtSext);
				solext.setPosition(j * Width, i * Height);
				vSol.push_back(solext);
				RectangleShape Tombe(Vector2f(67, 54));
				Tombe.setPosition(Vector2f(67 * j, 54 * i));
				Tombe.setTexture(&txtTombe);
				Tombe.setPosition(j * Width, i * Height);
				vMur.push_back(Tombe);
				break;
			}
			case 'M':
			{
				RectangleShape solext(Vector2f(67, 54));
				solext.setPosition(Vector2f(67 * j, 54 * i));
				solext.setTexture(&txtSext);
				solext.setPosition(j * Width, i * Height);
				vSol.push_back(solext);
				RectangleShape Pnj(Vector2f(67, 54));
				Pnj.setPosition(Vector2f(67 * j, 54 * i));
				Pnj.setTexture(&txtPnj);
				Pnj.setPosition(j * Width, i * Height);
				vPnj.push_back(Pnj);
				break;
			}

			case'§':
			{
				RectangleShape solext(Vector2f(67, 54));
				solext.setPosition(Vector2f(67 * j, 54 * i));
				solext.setTexture(&txtSext);
				solext.setPosition(j * Width, i * Height);
				vSol.push_back(solext);
				RectangleShape Tour(Vector2f(67, 54));
				Tour.setPosition(Vector2f(67 * j, 54 * i));
				Tour.setTexture(&txtTour);
				Tour.setPosition(j * Width, i * Height);
				vMur.push_back(Tour);
				break;
			}

			case'D':
			{
				RectangleShape solext(Vector2f(67, 54));
				solext.setPosition(Vector2f(67 * j, 54 * i));
				solext.setTexture(&txtSext);
				solext.setPosition(j * Width, i * Height);
				vSol.push_back(solext);
				RectangleShape tpD(Vector2f(67, 54));
				tpD.setPosition(Vector2f(67 * j, 54 * i));
				tpD.setTexture(&txtTpD);
				tpD.setPosition(j * Width, i * Height);
				vTp.push_back(tpD);
				break;
			}
			case'G':
			{
				RectangleShape solext(Vector2f(67, 54));
				solext.setPosition(Vector2f(67 * j, 54 * i));
				solext.setTexture(&txtSext);
				solext.setPosition(j * Width, i * Height);
				vSol.push_back(solext);
				RectangleShape tpG(Vector2f(67, 54));
				tpG.setPosition(Vector2f(67 * j, 54 * i));
				tpG.setTexture(&txtTpG);
				tpG.setPosition(j * Width, i * Height);
				vTp.push_back(tpG);
				break;
			}
			case'P':
			{
				RectangleShape solext(Vector2f(67, 54));
				solext.setPosition(Vector2f(67 * j, 54 * i));
				solext.setTexture(&txtSext);
				solext.setPosition(j * Width, i * Height);
				vSol.push_back(solext);
				p.setPos(Vector2f(j * Width, i * Height));
				break;
			}
			default:
				break;
			}
		}
	}
}
void Map::coliM(Player& p) {
	for (auto& mur : vMur) {
		if (p.getSprite().getGlobalBounds().intersects(mur.getGlobalBounds())) {
			
		}
	}
	
}
void Map::tpTxt(Player& p) {
	for (auto& tp : vTp) {
		if (tp.getGlobalBounds().intersects(p.getSprite().getGlobalBounds())) {
			interact.setPosition(vTp[0].getPosition().x+ vTp[0].getSize().x-7, vTp[0].getPosition().y-10+ vTp[0].getSize().y/2);
			window.draw(interact);
			cout << endl << "ok coli tp"<<endl;
		}
		else if(!tp.getGlobalBounds().intersects(p.getSprite().getGlobalBounds()))
		{
			cout << endl << "ne touche pas" << endl;
		}

	}

}
void Map::pnjTxt(Player& p) {


}
void Map::updatemap(View& v, Player& p) {

	for (auto& sol : vSol) {
		window.draw(sol);
	}

	for (auto& mur : vMur) {
		window.draw(mur);

	}

	for (auto& tp : vTp) {
		window.draw(tp);
	}
	

	p.draw(window, v);
}
