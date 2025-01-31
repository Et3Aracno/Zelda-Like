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

public:


	Map(RenderWindow& w);

	Clock clock;
	float deltaTime = clock.restart().asMicroseconds();
	void initTxt();
	void initSprt();
	void initM(string);
	void DrawM(Player&);
	void initall();
	void updatemap(View& v, Player& p);
	void coliM(Player& p);



	RenderWindow& window;//ajouter ça dans le game pour appeler la window et commencer la boucle de jeux  Map map; /*map.initM(); while (map.window) {}*/
	Texture txtArbre, txtSext, txtTour, txtPnj, txtTombe, txtChemin, txtMu, txtS, txtP, txtKeyB, txtTpG, txtTpD;
	Sprite sprtMu, sprtS, sprtP, sprtKeyB, sprtArbre, sprtSext, sprtPnj, sprtTombe, sprtChemin, sprtTour, sprtTpG, sprtTpD;
	vector<string>vM;
	vector<RectangleShape>vMur;
	vector<RectangleShape>vSol;
	vector<RectangleShape>vPorte;
	vector< RectangleShape>vTp;
	vector<Chaser>vC;
	vector<Patroler>vP;
	vector<enemy>vE;

};
