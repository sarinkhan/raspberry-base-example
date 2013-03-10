/*
* Code sous licence GNU GPL
* This code is provided "as-is", and under the GNU GPL2 licence.
* Ce programme sert a lire un bouton poussoir connecte a un GPIO
* du raspberry Pi et a changer l'etat d'une LED branchee sur un
* autre GPIO. Un appui allume la LED, un autre l'eteint. Le tutoriel
* et le schema sont disponibles sur le lien suivant :
* http://forum.pcinpact.com/topic/165594-raspberry-pi-fabriquons-des-trucs/page__p__2746825#entry2746825
*
*/
#include <wiringPi.h>
#include <stdio.h>

int main(void)
{
	int ledPin =7;          //La LED est connectee sur la broche 7 du Pi
	int switchPin=0;        //Le bouton poussoir est lu par la broche 0

	if(wiringPiSetup()==-1)
	{
		return 0;
	}

	pinMode(ledPin,OUTPUT);     //La broche de la LED est definie comme sortie
	pinMode(switchPin,INPUT);   //la broche du bouton poussoir est definie comme entree
	int ledState=0;             //Par defaut la led est eteinte

	int button=0;

	while(1)
	{

		button=digitalRead(switchPin);  //Lecture du bouton poussoir
		if(button==0)                   //si on appuie sur le bouton
		{
			if(ledState==0)             //si la led est eteinte,
			{
				ledState=1;             //on l'allume
			}
			else                        //sinon, si la led est allumee
			{
				ledState=0;             //on l'eteint
			}
			digitalWrite(ledPin,ledState);//modification effective de l'etat de la LED
			printf("Un appui sur le bouton a ete effectue!\n");
			while(button==0)//boucle permettant de considerer un appui long comme un seul appui
            {
                delay(20);  //on attend 20ms
                button=digitalRead(switchPin);//et on lit a nouveau la valeur
            }//cette boucle se repete jusqu'a ce que l'utilisateur lache le bouton.
		}
		delay(20);//on attend 20ms dans tous les cas

	}


 	return 0;
}
