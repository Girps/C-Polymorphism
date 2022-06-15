#include <stdio.h>
#include <stdlib.h>
#include "mammal.h"
#define CLEAR while((getchar()) != '\n');
#define MAX 50
/*
    Author: Jesse Jimenez
    Date: 6/14/2022
    Purpose: Implement a polymorphic structure in C
*/


int main()
{
    printf("Select animal: (1)dog (2)cat (3)horse (4)pig\n");
    struct Mammal* arrayPtrs[5];
    struct Dog* dptr;
    struct Cat* cptr;
    struct Horse* hptr;
    struct Pig* pptr;
    struct Mammal *ptr;
    void (*func)() = 0;
    for(int i = 0; i < 5; ++i)
    {
        int c = 0;
        scanf("%s",&c);
        c = c - '0';
        CLEAR;
        switch(c)
        {
        // Dog
        case(1):
            dptr = (struct Dog*)malloc(sizeof(struct Dog));
            *dptr = INITDG;
            dptr->construct(dptr);
            arrayPtrs[i] = (struct Mammal*)dptr;
            break;
        // Cat
        case(2):
            cptr = (struct Cat*)malloc(sizeof(struct Cat));
            *cptr = INITCT;
            cptr->constructor(cptr);
            arrayPtrs[i] = (struct Mammal*)cptr;
            break;
        // Horse
        case(3):
            hptr = (struct Horse*)malloc(sizeof(struct Horse));
            *hptr = INITHE;
            hptr->constructor(hptr);
            arrayPtrs[i] = (struct Mammal*)hptr;
            break;
        // Pig
        case(4):
            pptr = (struct Pig*)malloc(sizeof(struct Pig));
            *pptr = INITPG;
            pptr->constructor(pptr);
            arrayPtrs[i] = (struct Mammal*)pptr;
            break;
        // Mammal
        default:
             ptr = (struct Mammal*)malloc(sizeof(struct Mammal));
            *ptr = INITMM;
            ptr->constructor(ptr);
            arrayPtrs[i] = ptr;
            break;
        }
    }

    // Print polymorphic function
    for(int i =0; i < 5; ++i)
        {
            (*arrayPtrs[i]).vptr->speak(); // call function
        }

    // destruct each and free them
    for(int i =0; i < 5; ++i)
        {
            func = (*arrayPtrs[i]).vptr->speak;
            if(dogspeak == func)
                {
                    // up cast to dog calls its destructor
                    destruct_Dog((struct Dog* )arrayPtrs[i]);
                    free(arrayPtrs[i]);
                }
            else if(catspeak == func)
                {
                    destruct_Cat((struct Cat* )arrayPtrs[i]);
                    free(arrayPtrs[i]);
                }
            else if(horsespeak == func)
                {
                    destruct_Horse((struct Horse* )arrayPtrs[i]);
                    free(arrayPtrs[i]);
                }
            else if(pigspeak == func)
                {
                    destruct_Pig((struct Pig* )arrayPtrs[i]);
                    free(arrayPtrs[i]);
                }
            else
                {
                    destruct_Mammal((struct Mammal* )arrayPtrs[i]);
                    free(arrayPtrs[i]);
                }

        }

    return 0;
}
