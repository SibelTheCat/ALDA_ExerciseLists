
#include "list.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    
    struct light *firstLightPointer = NULL; //Pointer der auf ein light struct zeigt
    struct light **firstLight = &firstLightPointer; //die Adresse des Pointers der auf ein light struct zeigt. -> brauche ich, damit ich die Adresse in den Funktionen ändern kann.
    
    
    
    char whatToDo = 'a';
    char whatLight = 'b';
    int position;

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    while (whatToDo != 'x'){
        
        printf("m: ");
        scanf(" %c", &whatToDo);
        
        switch (whatToDo) {
                
            case 'a':
                while (whatLight != '0')
                {printf("l: ");
                scanf(" %c", &whatLight); //whitespace before %c  otherwise it will skip the input
                    if(whatLight == '0'){
                        break;
                    }
                    insertAtBeginning(whatLight, firstLight);
                }
                print(firstLight);
                whatLight = 'b'; // variable whatLight geändert von 0 weg
                break;

            
                
            case 'e':
                while (whatLight != '0')
                {printf("l: ");
                scanf(" %c", &whatLight);
                    if(whatLight == '0'){
                        break;
                    }
                    insertAtEnd(whatLight, firstLight);
                }
                print(firstLight);
                whatLight = 'b'; // variable whatLight geändert von 0 weg 
                break;
                
            case 'i':
                printf("l: ");
                scanf("%d", &position);
                printf("l: ");
                scanf(" %c", &whatLight);
                insertLight(whatLight, position, firstLight);
    
                print(firstLight);
                
                break;
                
            case 'l':
                printf("l: ");
                scanf("%d", &position);
                
                delateLight(position, firstLight);
    
                print(firstLight);
                
                break;
                
            case 'u':
               
                reverse(firstLight);
                print(firstLight);
                
                break;
                
            case 'x':
                break;
    
            default:
                printf("This code does not exist: please only use: a, e, i, l, u. Use x if you want to exit the programm.\n");
                break;
        }
    }
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    
    
//    char a = 'a';
//    char b = 'b';
//    char c = 'c';
//    char d = 'd';
//    char e = 'e';
//    char f = 'f';
//    char g = 'g';
//
    
//    insertAtBeginning(a, firstLight);
//    insertAtBeginning(b, firstLight);
//    insertAtBeginning(c, firstLight);
//    insertAtEnd(d, firstLight);
//    insertAtEnd(e, firstLight);
//    insertAtEnd(f, firstLight);
//    
//    print(firstLight);
//    printf("\n");
//    insertLight(g, 8, firstLight);
//    print(firstLight);
//    
//    printf("\n");
//    
//    delateLight(12, firstLight);
//    print(firstLight);
//    
//    printf("\n");
//    
   // reverse(firstLight);
   // print(firstLight);
    
    return 0;
}






