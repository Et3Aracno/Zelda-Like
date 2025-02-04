#include "Map.h"
Map::Map(RenderWindow& w) : window(w),cMap(false){

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
	if (!txtPf.loadFromFile("Assets/porte close.png")) {
		cout << "Erreur de chargement de la porte fermer" << endl;
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
	if (!txtPp_vie.loadFromFile("Assets/pp_vie.png")) {
		cout << "Erreur de chargement du pp vie" << endl;
	}
	if (!txtPp_dmg.loadFromFile("Assets/pp_dmg.png")) {
		cout << "Erreur de chargement du pp dmg" << endl;
	}
	if (!txtSd.loadFromFile("Assets/sol donjon.png")) {
		cout << "Erreur de chargement du sol du donjon" << endl;
	}
	if (!txtMais.loadFromFile("Assets/Maison.png")) {
		cout << "Erreur de chargement des maisons du hub" << endl;
	}
	
}
void Map::initSprt() {
	sprtArbre.setTexture(txtArbre);
	sprtPnj.setTexture(txtPnj);
	sprtTombe.setTexture(txtTombe);
	sprtTour.setTexture(txtTour);
	sprtKeyB.setTexture(txtKeyB);
	sprtP.setTexture(txtP);
	sprtPf.setTexture(txtP);
	sprtSext.setTexture(txtSext);
	sprtChemin.setTexture(txtChemin);
	sprtTpG.setTexture(txtTpG);
	sprtTpD.setTexture(txtTpD);
	sprtMu.setTexture(txtMu);
	sprtPp_dmg.setTexture(txtPp_dmg);
	sprtPp_vie.setTexture(txtPp_vie);
	sprtMais.setTexture(txtMais);
}
void Map::initF() {
	if (!fI.loadFromFile("Assets/huggo/Huggo.otf")) {
		cout << endl << "Impossible de charger la fonte" << endl;
	}
}
void Map::initT() {
	interactTp.setFont(fI);
	interactTp.setString("E");
	interactTp.setCharacterSize(15);
	interactTp.setFillColor(Color::Black);
	interactTp.setStyle(Text::Bold);

	inetractPnj.setFont(fI);
	inetractPnj.setString("!");
	inetractPnj.setCharacterSize(20);
	inetractPnj.setFillColor(Color::Red);
	inetractPnj.setStyle(Text::Bold);
}
void Map::initall(){
	initTxt();
	initSprt(); 
	initF();
	initT();
}
void Map::initM(string fileM) {
	vSol.clear();
	vMur.clear();
	vPnj.clear();
	vTp.clear();
	vM.clear();
	ifstream file(fileM);
	if (!file.is_open()) {
		cout << endl << "Impossible de lire le fichier txt" << fileM << endl;
	}
	string line;
	while (getline(file, line)) {
		vM.push_back(line);
	}
	file.close();
	cMap = true;
}
void Map::DrawM(Player& p, View& v, string& currentMap) {
	try {
		if (vM[0].empty()) {
			throw runtime_error("le fichier texte est vide");
		}
	}
	catch (const exception& e){
		cout << "Problème détecter : " << e.what() << endl;
	}
	//clear les vecteurs si la map à changer
	if (cMap == true) {
		//vSol.clear();
		//vMur.clear();
		//vPnj.clear();
		//vTp.clear();

		//cout << vSol.size();

		float Width = static_cast<float>(window.getSize().x) / vM[0].size();
		float Height = static_cast<float>(window.getSize().y) / vM.size();

		for (int i = 0; i < vM.size(); i++) {
			for (int j = 0; j < vM[0].size(); j++) {
				cout << vM[i][j];
				switch (vM[i][j])
				{
				case '#':
				{//arbre hub
					auto solext = make_unique<RectangleShape>(Vector2f(67, 54));
					solext->setPosition(Vector2f(67 * j, 54 * i));
					solext->setTexture(&txtSext);
					solext->setPosition(j * Width, i * Height);
					vSol.emplace_back(move(solext));

					auto arbre = make_unique<RectangleShape>(Vector2f(67, 54));
					arbre->setPosition(Vector2f(67 * j, 54 * i));
					arbre->setTexture(&txtArbre);
					arbre->setPosition(j * Width, i * Height);
					vMur.emplace_back(move(arbre));
					break;
				}
				case ';':
				{//herbe hub
					auto solext = make_unique<RectangleShape>(Vector2f(67, 54));
					solext->setPosition(Vector2f(67 * j, 54 * i));
					solext->setTexture(&txtSext);
					solext->setPosition(j * Width, i * Height);
					vSol.emplace_back(move(solext));
					break;
				}
				case '/':
				{//chemin hub
					auto Chemin = make_unique<RectangleShape>(Vector2f(67, 54));
					Chemin->setPosition(Vector2f(67 * j, 54 * i));
					Chemin->setTexture(&txtChemin);
					Chemin->setPosition(j * Width, i * Height);
					vSol.emplace_back(move(Chemin));
					break;
				}
				case 'T':
				{//tombe hub
					auto solext = make_unique<RectangleShape>(Vector2f(67, 54));
					solext->setPosition(Vector2f(67 * j, 54 * i));
					solext->setTexture(&txtSext);
					solext->setPosition(j * Width, i * Height);
					vSol.emplace_back(move(solext));

					auto Tombe = make_unique<RectangleShape>(Vector2f(67, 54));
					Tombe->setPosition(Vector2f(67 * j, 54 * i));
					Tombe->setTexture(&txtTombe);
					Tombe->setPosition(j * Width, i * Height);
					vMur.emplace_back(move(Tombe));
					break;
				}
				case 'm':
				{//tombe hub
					auto solext = make_unique<RectangleShape>(Vector2f(67, 54));
					solext->setPosition(Vector2f(67 * j, 54 * i));
					solext->setTexture(&txtSext);
					solext->setPosition(j * Width, i * Height);
					vSol.emplace_back(move(solext));

					auto maison = make_unique<RectangleShape>(Vector2f(100, 100));
					maison->setPosition(Vector2f(67 * j, 54 * i));
					maison->setTexture(&txtMais);
					maison->setPosition(j * Width, i * Height);
					vMur.emplace_back(move(maison));
					break;
				}
				case 'M':
				{//Pnj hub
					auto solext = make_unique<RectangleShape>(Vector2f(67, 54));
					solext->setPosition(Vector2f(67 * j, 54 * i));
					solext->setTexture(&txtSext);
					solext->setPosition(j * Width, i * Height);
					vSol.emplace_back(move(solext));

					
					auto Pnj = make_unique<RectangleShape>(Vector2f(67, 54));
					Pnj->setPosition(Vector2f(67 * j, 54 * i));
					Pnj->setTexture(&txtPnj);
					Pnj->setPosition(j * Width, i * Height);
					vPnj.emplace_back(move(Pnj));
					break;
				}

				

				case 'D':
				{ //tp droit
					auto solext = make_unique<RectangleShape>(Vector2f(67, 54));
					solext->setPosition(Vector2f(67 * j, 54 * i));
					solext->setTexture(&txtSext);
					solext->setPosition(j* Width, i* Height);
					vSol.emplace_back(move(solext));


					auto tpD = make_unique<RectangleShape>(Vector2f(67, 54));
					tpD->setPosition(Vector2f(67 * j, 54 * i));
					tpD->setTexture(&txtTpD);
					tpD->setPosition(j * Width, i * Height);
					vTp.emplace_back(move(tpD));
					break;
				}
				case 'G':
				{//tp gauche
					auto solext = make_unique<RectangleShape>(Vector2f(67, 54));
					solext->setPosition(Vector2f(67 * j, 54 * i));
					solext->setTexture(&txtSext);
					solext->setPosition(j * Width, i * Height);
					vSol.emplace_back(move(solext));


					auto tpG = make_unique<RectangleShape>(Vector2f(67, 54));
					tpG->setPosition(Vector2f(67 * j, 54 * i));
					tpG->setTexture(&txtTpG);
					tpG->setPosition(j* Width, i* Height);
					vTp.emplace_back(move(tpG));
					break;


				}
				case'd':
				{//popo dmg
					auto soldj = make_unique<RectangleShape>(Vector2f(67, 56));
					soldj->setPosition(Vector2f(67 * j, 56 * i));
					soldj->setTexture(&txtSd);
					soldj->setPosition(j * 67, i * 56);
					vSol.emplace_back(move(soldj));


					auto pp_dmg = make_unique<RectangleShape>(Vector2f(67, 54));
					pp_dmg->setPosition(Vector2f(67 * j, 54 * i));
					pp_dmg->setTexture(&txtPp_dmg);
					pp_dmg->setPosition(j * Width, i * Height);
					vTp.emplace_back(move(pp_dmg));
					break;


				}
				case'V':
				{//popo vie
				auto soldj = make_unique<RectangleShape>(Vector2f(67, 56));
				soldj->setPosition(Vector2f(67 * j, 56 * i));
				soldj->setTexture(&txtSd);
				soldj->setPosition(j * 67, i * 56);
				vSol.emplace_back(move(soldj));


				auto pp_vie = make_unique<RectangleShape>(Vector2f(67, 54));
				pp_vie->setPosition(Vector2f(67 * j, 54 * i));
				pp_vie->setTexture(&txtPp_vie);
				pp_vie->setPosition(j * Width, i * Height);
				vTp.emplace_back(move(pp_vie));//changer le vecteur pour les popo
				break;


				}
				case 'h':
				{ //mur donjon

					auto MurD = make_unique<RectangleShape>(Vector2f(67, 56));
					MurD->setPosition(Vector2f(67 * j, 56 * i));
					MurD->setTexture(&txtMu);
					MurD->setPosition(j * 67, i * 56);
					vMur.emplace_back(move(MurD));
					break;
				}
				case 'U':
				{ //porte donjon
					auto porte = make_unique<RectangleShape>(Vector2f(67, 56));
					porte->setPosition(Vector2f(67 * j, 56 * i));
					porte->setTexture(&txtPf);
					porte->setPosition(j * 67, i * 56);
					dD.emplace_back(move(porte));
					break;


				}
				case 'K':
				{ //clef donjon
					auto soldj = make_unique<RectangleShape>(Vector2f(67, 56));
					soldj->setPosition(Vector2f(67 * j, 56 * i));
					soldj->setTexture(&txtSd);
					soldj->setPosition(j * 67, i * 56);
					vSol.emplace_back(move(soldj));

					auto Key = make_unique<RectangleShape>(Vector2f(67, 56));
					Key->setPosition(Vector2f(67 * j, 56 * i));
					Key->setTexture(&txtKeyB);
					Key->setPosition(j * 67, i * 56);
					vKey.emplace_back(move(Key));
					break;


				}
				case 'B':
				{ //sol donjon
					auto soldj = make_unique<RectangleShape>(Vector2f(67, 56));
					soldj->setPosition(Vector2f(67 * j, 56 * i));
					soldj->setTexture(&txtSd);
					soldj->setPosition(j * 67, i * 56);
					vSol.emplace_back(move(soldj));
					break;


				}
				case ' ':
				{ //vide donjon
					auto vide = make_unique<RectangleShape>(Vector2f(67, 56));
					vide->setFillColor(Color::Red);
					vide->setPosition(Vector2f(67 * j, 56 * i));
				vMur.emplace_back(move(vide));
					break;


				}
				case 'P':
				{
					//joueur
					if(currentMap =="Assets/hub.txt"){ 
						auto solext = make_unique<RectangleShape>(Vector2f(67, 54));
						solext->setPosition(Vector2f(67 * j, 54 * i));
						solext->setTexture(&txtSext);
						solext->setPosition(j * Width, i * Height);
						vSol.emplace_back(move(solext));
						p.getSprite().setScale(2.f, 2.f);
					}
					else if (currentMap == "Assets/donjon.txt") {
						auto soldj = make_unique<RectangleShape>(Vector2f(67, 56));
						soldj->setPosition(Vector2f(67 * j, 56 * i));
						soldj->setTexture(&txtSd);
						soldj->setPosition(j * 67, i * 56);
						vSol.emplace_back(move(soldj));
						p.getSprite().setScale(2.f, 2.f);
					}
					

					p.setPos(Vector2f(j* Width, i* Height));
					p.getSprite().setPosition(p.getPos());
					break;
				}
				default: { //vide donjon
					auto vide = make_unique<RectangleShape>(Vector2f(67, 56));
					vide->setFillColor(Color::Red);
					vide->setPosition(Vector2f(67 * j, 56 * i));
					vMur.emplace_back(move(vide));
					break;


				}
				}
			}
			cout << endl;
		}
		cMap = false;
	}
updatemap(v, p);
	
}
void Map::coliM(Player& p) {
	for (auto& mur : vMur) {
		if (p.getSprite().getGlobalBounds().intersects(mur->getGlobalBounds())) {

			if (p.getPos().x > mur->getPosition().x) { //coli mur gauche
				p.setPos(Vector2f(p.getPos().x + 3, p.getPos().y));

			}

			if (p.getPos().x < mur->getPosition().x) {//coli mur droit
				p.setPos(Vector2f(p.getPos().x - 3, p.getPos().y));

			}
			if (p.getPos().y > mur->getPosition().y) {//coli mur du bas
				p.setPos(Vector2f(p.getPos().x, p.getPos().y + 3));

			}
			if (p.getPos().y < mur->getPosition().y) {//coli mur haut
				p.setPos(Vector2f(p.getPos().x, p.getPos().y - 3));

			}

			
		}
	}
	
}
void Map::coliKey(Player& p){
	for (auto& key : vKey) {
		if (p.getSprite().getGlobalBounds().intersects(key->getGlobalBounds())) {
			Keyrecup = true;
		}
		
	}

}
void Map::coliD(Player& p) {
		for (auto& portef : dD) {
			if (Keyrecup != true) {
				if (p.getSprite().getGlobalBounds().intersects(portef->getGlobalBounds())) {

					if (p.getPos().x > portef->getPosition().x) { //coli porte gauche
						p.setPos(Vector2f(p.getPos().x + 3, p.getPos().y));

					}

					if (p.getPos().x < portef->getPosition().x) {//coli porte droit
						p.setPos(Vector2f(p.getPos().x - 3, p.getPos().y));

					}
					if (p.getPos().y > portef->getPosition().y) {//coli porte du bas
						p.setPos(Vector2f(p.getPos().x, p.getPos().y + 3));

					}
					if (p.getPos().y < portef->getPosition().y) {//coli porte haut
						p.setPos(Vector2f(p.getPos().x, p.getPos().y - 3));

					}


				}
			}
			else if (Keyrecup == true) {
				portef->setTexture(&txtP);
			}
		}

}
void Map::tpTxt(Player& p) {
	for (auto& tp : vTp) {
		if (tp->getGlobalBounds().intersects(p.getSprite().getGlobalBounds())) {
			interactTp.setPosition(vTp[0]->getPosition().x+ vTp[0]->getSize().x-7, vTp[0]->getPosition().y-10+ vTp[0]->getSize().y/2);
			window.draw(interactTp);
			
		}

	}

}
void Map::pnjTxt(Player& p) {
	for (auto& pnj : vPnj) {
			inetractPnj.setPosition(vPnj[0]->getPosition().x+30, vPnj[0]->getPosition().y-30);
			interactTp.setPosition(vPnj[0]->getPosition().x + 30 , vPnj[0]->getPosition().y);
		if (p.getSprite().getGlobalBounds().intersects(pnj->getGlobalBounds())) {

			if (p.getPos().x > pnj->getPosition().x) {
				p.setPos(Vector2f(p.getPos().x + 3, p.getPos().y));

			}

			if (p.getPos().x < pnj->getPosition().x) {
				p.setPos(Vector2f(p.getPos().x - 3, p.getPos().y));

			}
			if (p.getPos().y > pnj->getPosition().y) {
				p.setPos(Vector2f(p.getPos().x, p.getPos().y + 3));

			}
			if (p.getPos().y < pnj->getPosition().y) {
				p.setPos(Vector2f(p.getPos().x, p.getPos().y - 3));

			}
			
			

			window.draw(interactTp);
		}
		if (iPNJ != true) {
		window.draw(inetractPnj);
		}
		
	}

}
void Map::updatemap(View& v, Player& p) {
	coliKey(p);
	coliD(p);
	for (auto& sol : vSol) {
		window.draw(*sol);
	}

	for (auto& mur : vMur) {
		window.draw(*mur);

	}
	for (auto& pnj : vPnj) {
		window.draw(*pnj);
	}

	for (auto& tp : vTp) {
		window.draw(*tp);
	}
	for (auto& porte : dD) {
		window.draw(*porte);
	}
	if(Keyrecup!= true){
		for (auto& key : vKey) {
			window.draw(*key);
		}
	}
	
	tpTxt(p);
	pnjTxt(p);
	coliM(p);

	p.draw(window, v);
}
void Map::eDonj(Player& p, View& v, string& currentMap) {
	for (auto& tp : vTp) {
		if (tp->getGlobalBounds().intersects(p.getSprite().getGlobalBounds()) and Keyboard::isKeyPressed(Keyboard::E)) {
			if (currentMap != "Assets/donjon.txt") {
				currentMap = "Assets/donjon.txt";
				initM(currentMap);

			}
		}
	}

	//si on a pas utilisé le tp alors la map actuel reste la meme 
	if (currentMap != "Assets/hub.txt" and currentMap != "Assets/donjon.txt") {
		currentMap = "Assets/hub.txt";
		initM(currentMap);
	}
}