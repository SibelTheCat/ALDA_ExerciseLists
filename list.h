//
//  list.h
//  ALDA_ExerciseLists
//
//  Created by Michael Strommer on 26.04.21.
//

#ifndef list_h
#define list_h

#include <stdio.h>

struct light{
    char color;
    struct light *next;
};
void insertAtBeginning(char inputLight, struct light ** firstLight );
void insertAtEnd(char inputLight, struct light ** firstLight );
void insertLight(char inputLight, int position, struct light ** firstLight );
void delateLight(int position, struct light ** firstLight );
void print (struct light **firstLight);
void reverse(struct light ** firstLight );


    
    



#endif /* list_h */
