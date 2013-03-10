Ces codes sources servent à prendre en main et programmer
des actions simples exploitant les GPIO du Raspberry Pi.

Pour l'instant il y a des exemples de codes permettant
de faire clignotter une LED, de lire un bouton poussoir, 
et de combiner les deux pour pouvoir changer l'état de
la LED si l'on appuie sur le bouton poussoir.

Dans tous les cas, les tutoriels et schémas de montages
sont disponibles au lien suivant :
http://forum.pcinpact.com/topic/165594-raspberry-pi-fabriquons-des-trucs/

Les codes se compilent en utilisant l'option
-lwiringPi
(en pratique, ça fera "gcc source.c -o executable -lwiringPi")