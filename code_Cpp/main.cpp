// ServeurVS.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#pragma hdrstop
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "serveur.h"
#include <winsock.h>
#include "rs232.h"

using namespace std;

int main()
{	
	rs232 liaison;
	liaison.inithandle();
	char trame[9];
	char data[100] = "";
	char reponse[5] = { 'M','E','R','C', 'I' };
	char message, finDeChaine;

	do {
		
		serveur myServeur;
		if (myServeur.liaison() == false)

		{
			cout << "erreur lors de la liaison" << endl;
		}
		else
		{
			cout << "la liaison c'est bien etablie" << endl;
		}

		//cout << "debut de boucle" << endl;


		if (myServeur.listenClient() == false)
		{
			cout << "erreur lors du listen" << endl;
		}
		else
		{
			cout << "le listen c'est bien etablie" << endl;
		}
		//cout << "apres serv" << endl;

		if (myServeur.recup(data, 2) == true)
		{

			message = data[0];
			finDeChaine = data[1];

			if (finDeChaine != '!') 
			{
				cout << "caractere de fin de chaine incorrect" << endl;
			}

			
			if (message == 'h') 
			{

				cout << "le message envoye est : " << message << endl;
				myServeur.sendMessage(reponse, 5);


				liaison.getTrameHaut(trame);
				//liaison.inithandle();
				liaison.sendtrame(trame,9);

				
				
			}
			
			else if (message == 'b')
			{
				cout << "le message envoye est : " << message << endl;
				myServeur.sendMessage(reponse, 5);
				
				liaison.getTrameBas(trame);
				//liaison.inithandle();
				liaison.sendtrame(trame,9);

				
				
			}

			else if (message == 'a')
			{
				cout << "le message envoye est : " << message << endl;
				myServeur.sendMessage(reponse, 5);

				liaison.getTrameStart(trame);
				//liaison.inithandle();
				liaison.sendtrame(trame, 6);


			}

			else if (message == 'e')
			{
				cout << "le message envoye est : " << message << endl;
				myServeur.sendMessage(reponse, 5);

				liaison.getTrameOff(trame);
				//liaison.inithandle();
				liaison.sendtrame(trame, 6);

				

			}

			else if (message == 'c')
			{
				cout << "le message envoye est : " << message << endl;
				myServeur.sendMessage(reponse, 5);

				liaison.getTrameCentre(trame);
				//liaison.inithandle();
				liaison.sendtrame(trame,5);

				
			}

			else if (message == 'g')
			{
				cout << "le message envoye est : " << message << endl;
				myServeur.sendMessage(reponse, 5);
				
				liaison.getTrameGauche(trame);
				//liaison.inithandle();
				liaison.sendtrame(trame,9);
			}

			else if (message == 'd')
			{
				cout << "le message envoye est : " << message << endl;
				myServeur.sendMessage(reponse, 5);
				
				liaison.getTrameDroite(trame);
				//liaison.inithandle();
				liaison.sendtrame(trame,9);
			}

			else if (message == '+')
			{
				cout << "le message envoye est : " << message << endl;
				myServeur.sendMessage(reponse, 5);
				
				liaison.getTrameZoom(trame);
				//liaison.inithandle();
				liaison.sendtrame(trame,6);
			}

			else if (message == '-')
			{
				cout << "le message envoye est : " << message << endl;
				myServeur.sendMessage(reponse, 5);
				
				liaison.getTrameDezoom(trame);
				//liaison.inithandle();
				liaison.sendtrame(trame,6);
			}

			else if (message == 'y')
			{
				cout << "le message envoye est : " << message << endl;
				myServeur.sendMessage(reponse, 5);
			
				for (int i = 0; i < 3; i++)
				{
					liaison.getTrameGauche(trame);
					liaison.sendtrame(trame, 9);

					Sleep(3000);

					liaison.getTrameDroite(trame);
					liaison.sendtrame(trame, 9);

					Sleep(3000);
				}
					


			}

			else if (message == ';')
			{
				cout << "fermeture de la liaison" << endl;
				myServeur.sendMessage(reponse, 5);
				myServeur.close();
				
				
			}
			else
			{
				cout << "La commande envoye n existe pas" << endl;
			}
		}
		else
		{
			cout << "ERROR impossible de lire le mssage recu" << endl;
		}
		myServeur.close();
		
	
	} while (message != ';');

	
		

	return 0;
}



// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
