/*

	DEV CLERMONT cette classe est utilisé pour faire cecia cakakakal sqkjdklqjkdj lq jdkql


*/

#pragma once
#include <winsock.h>
#include <stdio.h>

class rs232
{
private:
	HANDLE hcom;
	

public:
	rs232();
	void inithandle();


	// Méthode qui permet d'envoyer une trame camera
	// trame : un tableau do'cteter
	// taille : taille du tableau 
	void sendtrame(char* trame,int taille);
	void getTrameHaut(char trame[]);
	void getTrameBas(char trame[]);
	void getTrameGauche(char trame[]);
	void getTrameDroite(char trame[]);
	void getTrameZoom(char trame[]);
	void getTrameDezoom(char trame[]);
	void getTrameCentre(char trame[]);
	void getTrameStart(char trame[]);
	void getTrameOff(char trame[]);
	

};

