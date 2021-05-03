//
//  list.c
//  ALDA_ExerciseLists
//
//  Created by Michael Strommer on 26.04.21.
//

#include "list.h"
#include <memory.h>
#include <stdlib.h>

//Struct wurde in list.h deklariert

void insertAtBeginning(char inputLight, struct light ** firstLight ){
    //Speicherplatz für neuers Struct light wird allokiert, der Pointer newLight zeigt auf diesen neuen Speicherplatz
    
    struct light *newLight = (struct light *)malloc(sizeof(struct light));
    
    //Fall noch kein Light vorhanden ist, wird das allererste Licht erstellt
    if (*firstLight == NULL){
        newLight->color = inputLight;
        newLight->next = NULL;
        *firstLight=newLight;
    }
        //licht.next zeigt auf das Licht, das zuerst an der ersten Stelle war
        else {
            newLight->color = inputLight;
            newLight->next = *firstLight;//das gleiche wie (*newLight).next, ich greife also auf den Inhalt von newLight.next zu und schreibe dort die Adresse vom nächsten Licht rein.
            *firstLight = newLight;  //ich greife auf den Inhalt des Pointer, der auf die Adresse des ersten Lichtes zeigt zu und schreibe die Adresse des neuen ersten Lichtes rein.
        }
        
    }

void insertAtEnd(char inputLight, struct light ** firstLight ){
    
    struct light *newLight = (struct light *)malloc(sizeof(struct light));
    newLight->color = inputLight;
    newLight->next= NULL; //das es das letzte Licht ist, zeig es immer auf NULL
    
    if (*firstLight == NULL){ // falls es noch keine Lichter in der Lichterkette gibt
        *firstLight = newLight;
    }

        else {
            struct light *findMyPlace = *firstLight;
            while (findMyPlace->next != NULL){
                findMyPlace = findMyPlace->next;
            }
            findMyPlace->next = newLight;
        }
        
    }

void insertLight(char inputLight, int position, struct light ** firstLight ){
    struct light *newLight = (struct light *)malloc(sizeof(struct light));
    newLight->color = inputLight;
    
   
    
    if (*firstLight == NULL){
        newLight->next = NULL;
        *firstLight = newLight;
    }
        
    else{
        struct light *findMyPlace = *firstLight;
    
        for (int i = 1; i<position-1; i++){
        findMyPlace = findMyPlace->next;
            if (findMyPlace == NULL){
                printf("there is no position %i in this lightstring\n", position);
                return;
            }
    }
            newLight->next = findMyPlace->next;
            findMyPlace->next=newLight;
    }}

void delateLight(int position, struct light ** firstLight ){

    
    
    if (*firstLight == NULL){
        printf("no lights left");
    }
    
    else if ((*firstLight)->next == NULL){
        free(*firstLight);
        *firstLight = NULL;
        printf("That was the last light");
    }
  
    else{
        struct light *findMyPlace = *firstLight;
    
        for (int i = 1; i<position-1; i++){
            
        findMyPlace = findMyPlace->next;
            if (findMyPlace->next == NULL){
                printf("there is no position %i in this lightstring\n", position);
                return;
            }
        }
    
    struct light *safe =findMyPlace->next->next;
    free(findMyPlace->next);
    findMyPlace->next = safe;
 
    }}

void reverse(struct light ** firstLight ){
    
    if (*firstLight == NULL){
        printf("No lights to reverse\n");
    }
    
    else{
    struct light *findMyPlace = *firstLight;
    struct light *findMyPlaceNext = findMyPlace->next;
    
        
    while (findMyPlaceNext->next != NULL){
        struct light *safe = findMyPlaceNext->next;
        findMyPlaceNext->next = findMyPlace;
        findMyPlace= findMyPlaceNext;
        findMyPlaceNext = safe;
    }
        
        findMyPlaceNext->next = findMyPlace;
        (*firstLight)->next = NULL;
        *firstLight = findMyPlaceNext;

    }
    
}

void print (struct light **firstLight){
    if (*firstLight == NULL){
        printf("no lights left \n");
    }
        else{
        struct light *findMyPlace = *firstLight;
            printf("Lichterkette: ");
        while (findMyPlace->next != NULL){
            printf("%c - ", findMyPlace->color);
            findMyPlace = findMyPlace->next;
        }
            printf("%c \n", findMyPlace->color);
    }
}

