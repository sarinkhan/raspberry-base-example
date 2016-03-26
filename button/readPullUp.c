#include <stdio.h>
#include <wiringPi.h>
int main(void)
{
int switchPin=0;
if(wiringPiSetup()==-1)
	  {return 0;}
//le port GPIO du bouton est configuré en lecture
pinMode(switchPin,INPUT);
int button=0;
while(1)
{
  //on lit la valeur de la broche GPIO
  button=digitalRead(switchPin);
  if(button==0)//Si un appui sur le bouton est détecté
  {
   //on affiche un message
   printf("button pressed!\n");
   //cette boucle permet de gerer un appui continu
   while(button==0)
	{
			//on relit la valeur à chaque fois
			button=digitalRead(switchPin);
			delay(20);//et on attend 20ms
	}
  }
  delay(20);//on attend 20ms entre chaque lecture.
}
  return 0;
}