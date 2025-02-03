#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <thread>
#include <vector>
#include<fstream>
#include<sstream>
#include "Player.h"
#include<SFML/Audio.hpp>
#include "enemyChaser.h"
#include "enemyPatrol.h"

using namespace std;
using namespace sf;



class Map {
private:
	bool cMap;
public:


	Map(RenderWindow& w);
	bool bTp = false;
	Clock clock;
	float deltaTime = clock.restart().asMicroseconds();
	void initTxt();
	void initSprt();
	void initM(string);
	void initF();
	void initT();
	void DrawM(Player&, View& v, string& currentMap);
	void initall();
	void updatemap(View& v, Player& p);
	void coliM(Player& p);
	void tpTxt(Player& p);
	void pnjTxt(Player& p);
	void eDonj(Player& p, View& v, string &currentMap);

	RenderWindow& window;//ajouter ça dans le game pour appeler la window et commencer la boucle de jeux  Map map; /*map.initM(); while (map.window) {}*/
	Texture txtArbre, txtSext, txtTour, txtPnj, txtTombe, txtChemin, txtMu, txtS, txtP, txtKeyB, txtTpG, txtTpD,txtPp_dmg, txtPp_vie,txtSd;
	Sprite sprtMu, sprtS, sprtP, sprtKeyB, sprtArbre, sprtSext, sprtPnj, sprtTombe, sprtChemin, sprtTour, sprtTpG, sprtTpD,sprtPp_dmg,sprtPp_vie,sprtSd;
	Font fI;
	Text interactTp,inetractPnj;
	vector <string>vM;
	vector<unique_ptr<RectangleShape>>vMur;
	vector<unique_ptr<RectangleShape>>vSol;
	vector<unique_ptr<RectangleShape>>vPorte;
	vector<unique_ptr<RectangleShape>>vTp;
	vector <unique_ptr<Chaser>>vC;
	vector <unique_ptr<Patroler>>vP;
	vector <unique_ptr<Player>>vE;
	vector <unique_ptr<RectangleShape>>vPnj;
};
