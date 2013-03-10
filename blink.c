/*
* Code sous licence GNU GPL
* This code is provided "as-is", and under the GNU GPL2 licence.
* Ce programme sert à faire clignoter une LED connectee a un GPIO
* du raspberry Pi selon le montage suivant decrit dans le lien ci dessous:
* http://forum.pcinpact.com/topic/165594-raspberry-pi-fabriquons-des-trucs/page__view__findpost__p__2746544
*/
#include <wiringPi.h>
#include <stdio.h>

int main(void)
{
	int pin =7;                 //Nous definissions la broche GPIO qui commande la LED
	if(wiringPiSetup()==-1)
	{
		return 0;
	}

	pinMode(pin,OUTPUT);        //Cette broche est definie en mode sortie
	while(1)                    //Nous faisons une boucle infinie. Pour arreter le programme il faut faire ctrl+c
	{
		digitalWrite(pin,1);    //Nous definissions la valeur de la broche a 1, ce qui allume la LED
		delay(500);             //On attend 500ms, soit 1/2 seconde
		digitalWrite(pin,0);    //Nous definissions la valeur de la broche a 0, eteignant la LED
		delay(500);             //On attend encore 500ms
	}
 	return 0;
}
