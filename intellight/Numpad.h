//
// Created by maxim on 06/12/2023.
//

#ifndef BECPPOBJETSCONNECTES_NUMPAD_H
#define BECPPOBJETSCONNECTES_NUMPAD_H

#include <Arduino.h>
#include "SoftwareSerial.h"

/* Les numpads sont des claviers tactiles capacitifs fonctionnant en UART.
 * Comme l'ESP8266 n'a qu'un seul UART et que ce dernier est utilisé par la connexion en USB,
 * Nous utilisons la librairie SoftwareSerial pour créer à partir de 2 pins d'IO des UART émulés.
 * De cette manière, on peut implémenter nos numpads en UART.
*/

class Numpad {
private:
    /* Attributs */
    uint8_t data; // Contient la donnée lue depuis le numpad. Elle n'est pas formattée de manière lisible par un humain.
    SoftwareSerial * mySerial; // Pointeur vers l'UART émulé pour le numpad

    short * code; // Tableau de nombres contenant le code tapé sur le numpad
    short nbDigits, nbEtoiles; // Nombre de digits dans le code, nombre d'étoiles tapées d'affilée


    /* Méthodes */
    void updateData(); // Permet d'effectuer une lecture sur le numpad et de mettre à jour data.


public:
    /* Constructeurs */
    Numpad(); // Constructeur par défaut, ne sera à priori jamais utilisé.
    Numpad(SoftwareSerial * s); // Constructeur permettant de créer un numpad avec un UART associé

    /* Méthodes */
    // Getters
    uint8_t getData(); // Permet d'obtenir l'attribut data de manière non lisible par un humain.
    char getTouche(); // Permet d'obtenir de manière lisible par un humain la touche sur laquelle l'utilisateur a appuyé.
    short getCode() const; // Permet d'obtenir de manière lisible par un humain une suite de 4 digits tapés sur le numpad.
    SoftwareSerial * getSerial(); // Permet d'accéder à l'UART associé au numpad
    short getNbDigits() const; // Permet d'accéder au nombre de digits dans le code
    short getNbEtoiles() const; // Permet d'accéder au nombre d'étoiles tapées d'affilée

    // Autres méthodes
    void addDigitToCode(char digit); // Ajout d'un digit dans le code
    void resetNbEtoiles(); // Remise à zéro du nombre d'étoiles tapées
    void incrNbEtoiles(); // Incrémentation du nombre d'étoiles tapées
    void resetCode(); // Remise à zéro du code

    // Destructeurs
    ~Numpad(); // Destructeur par défaut pour le moment -- A MODIFIER POUR SUPPRIMER L'UART
};


#endif //BECPPOBJETSCONNECTES_NUMPAD_H
