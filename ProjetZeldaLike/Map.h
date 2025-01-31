#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <thread>
#include <vector>
#include<fstream>
#include<sstream>
#include "Player.h"
#include<SFML/Audio.hpp>

using namespace std;
using namespace sf;



class Map{

public:
	Map(RenderWindow& w);
	void initTxt();
	void initSprt();
	void initM(string);
	void DrawM();
	void initall();
	void updatemap();



	RenderWindow& window;//ajouter ça dans le game pour appeler la window et commencer la boucle de jeux  Map map; /*map.initM(); while (map.window) {}*/
	Texture txtArbre, txtSext, txtTour, txtPnj, txtTombe, txtChemin, txtMu, txtS, txtP, txtKeyB, txtTpG,txtTpD;
	Sprite sprtMu, sprtS, sprtP, sprtKeyB, sprtArbre, sprtSext, sprtPnj, sprtTombe, sprtChemin, sprtTour,sprtTpG,sprtTpD;
	vector<string>vM;
	vector<RectangleShape>vMur;
	vector<RectangleShape>vSol;
	vector<RectangleShape>vPorte;
	vector< RectangleShape>vTp;
	
	
};
