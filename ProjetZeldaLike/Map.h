#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <thread>
#include <vector>
#include<fstream>
#include<sstream>
using namespace std;
using namespace sf;



class Map{
protected:
	string fileM;
	
public:
	void initTxt();
	void initM();
	void DrawM();
	void initArbre();
	void initSext();
	void initTour();
	void initPnj();
	void initTombe();
	void initChemin();
	void initJ();
	void initMu();
	void initS();
	void initP();
	void initKey();
	void initall();


	RenderWindow* window;//ajouter ça dans le game pour appeler la window et commencer la boucle de jeux  Map map; /*map.initM(); while (map.window) {}*/
	Texture txtArbre,txtSext,txtTour,txtPnj,txtTombe,txtChemin,txtJ, txtMu, txtS,txtP, txtKey;
	Sprite sprtJ, sprtMu, sprtS, sprtP, sprtKey,sprtArbre,sprtSext,sprtPnj,sprtTomb,sprtChemin;
	vector<string>vM;
	vector<RectangleShape>vMur;
	vector<RectangleShape>vSol;
	vector<RectangleShape>vPorte;

	
};
