#ifndef Q
#define Q
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<time.h>

typedef struct Proc
    {

        int id;

        int temps;

        int prio;

        struct Proc* next;

     }Processus;

typedef struct List
    {

        struct Proc* first;

    }List_chaine;

typedef struct stockage
    {
        char* nom;
        float tmga;
    }stock;

int* initialise(int a, int b);

void melanger(int* tableau, int taille);

List_chaine* construct();

void add_head(List_chaine* liste, int id,int temps,int prio);

void add_tail(List_chaine* liste, int id,int temps,int prio);

void getListe(List_chaine* liste);

void suprimmeFisrt(List_chaine* liste);

void suprimmeID(List_chaine* liste,int id);

void trieID(List_chaine* liste);

void trieTEMPS(List_chaine *liste);

float fifo (List_chaine *liste);

float sjf (List_chaine *liste);

float prio (List_chaine *liste);

float rr (List_chaine* liste, int lng);

#endif
