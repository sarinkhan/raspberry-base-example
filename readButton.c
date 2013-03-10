/*
* Code sous licence GNU GPL
* This code is provided "as-is", and under the GNU GPL2 licence.
* Ce programme sert à lire un bouton poussoir connecte a un GPIO
* du raspberry Pi selon le montage suivant decrit dans le lien ci dessous:
* http://forum.pcinpact.com/topic/165594-raspberry-pi-fabriquons-des-trucs/page__p__2746825#entry2746825
*
*/
#include <wiringPi.h>
#include <stdio.h>

int main(void)
{
	int switchPin=0;               //On indique la broche sur laquelle on lit le bouton

	if(wiringPiSetup()==-1)
	{
		return 0;
	}
	pinMode(switchPin,INPUT);     //Cette broche est configurée en mode lecture
	int button=0;                 //La valeur lue du bouton est initialisée à 0
	while(1)
	{

		button=digitalRead(switchPin);//ici on récupère l'etat du bouton

		if(button==0)             //Si on appuie sur le bouton
		{
			printf("Appui sur le bouton!\n");//on indique qu'on a detecte un appui sur le bouton
			while(button==0)//tant que le bouton n'est pas relache
            		{
                		delay(20);                    //on attend un petit peu
                		button=digitalRead(switchPin);//avant de relire la valeur
            		}
		}
		delay(20);//dans tous les cas, on attend un peu avant la prochaine lecture.
	}
 	return 0;
}
