/*
* Code sous licence GNU GPL
* This code is provided "as-is", and under the GNU GPL2 licence.
* Ce programme sert à lire un bouton poussoir connecte a un GPIO
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
	int ledPin =7;
	int switchPin=0;

	if(wiringPiSetup()==-1)
	{
		return 0;
	}

	pinMode(ledPin,OUTPUT);
	pinMode(switchPin,INPUT);
	int ledState=0;

	int button=0;

	while(1)
	{

		button=digitalRead(switchPin);
		if(button==0)
		{
			if(ledState==0)
			{
				ledState=1;
			}
			else
			{
				ledState=0;
			}
			digitalWrite(ledPin,ledState);
			printf("button pressed!\n");
			while(button==0)
            {
                button=digitalRead(switchPin);
                delay(20);
            }
		}
		delay(20);

	}


 	return 0;
}
