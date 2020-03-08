/*
    author: Jules Gammad
*/
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>


//defining a State struct
struct State {
    struct State *last;
    struct State *next;
    char stateName;
    int nodeCount;
};


//function changes the next and last state of the currentState defined by the user
void changeState(struct State *states[], char userInput, struct State *currentState, int whichState);

//prints all the array pointers that are not already deleted
void print(struct State *states[]);

//checks to see if there is an unreachable state
void garbage(struct State *current, struct State *last, struct State *next, struct State *rootNode);

//resets the nodeCount of each state
void reset(struct State *states[]);

//deletes states that are unreachable and are not already deleted
void delete (struct State *states[], struct State *currentState, char userInput);
   

int main(int argc, char * argv[])
{
    //declare struct States
    static struct State A,B,C,D,E,F,G,H;
    //make an struct array pointer to the states
    static struct State *states[8];
    
    //set the pointers to specified states
    states[0] = &A;
    states[1] = &B;
    states[2] = &C;
    states[3] = &D;
    states[4] = &E;
    states[5] = &F;
    states[6] = &G;
    states[7] = &H;
    
 
    //intialize struct linkedlist according to given specifications
    A.last = &D; A.next = &E; A.stateName = 'A', A.nodeCount = 0;
    B.last = &G; B.next = &D; B.stateName = 'B', B.nodeCount = 0;
    C.last = &A; C.next = &E; C.stateName = 'C', C.nodeCount = 0;
    D.last = &D; D.next = &H; D.stateName = 'D', D.nodeCount = 0;
    E.last = &F; E.next = &G; E.stateName = 'E', E.nodeCount = 0;
    F.last = &C; F.next = &B; F.stateName = 'F', F.nodeCount = 0;
    G.last = &B; G.next = &A; G.stateName = 'G', G.nodeCount = 0;
    H.last = &C; H.next = &F; H.stateName = 'H', H.nodeCount = 0;
    
    
    //initialize currentState pointer
    struct State *currentState;
    currentState = states[2];
    
    //prints starting state
    printf("%c\n",currentState->stateName);
    
    //user variables and for loop counter declaration
    char userInput[5];
    int i;
    
    //loops the program where typing 000 terminates the program
    while (userInput[0] != '0' || userInput[1] != '0' || userInput[2] != '0' ) {
        
        //stndin
        fgets(userInput,100,stdin);
        
        //switch-case statement that will output results according the char type commands
        switch(userInput[0]) {
            
            case '0':
		if (currentState->last != null) {
                	currentState = currentState->last;
                	printf("%c\n",currentState->stateName);
		}else {
			printf("Last state unavailable.\n");
		}
                break;
                
            case '1':
		if (currentState->next != null) {
                	currentState = currentState->next;
                	printf("%c\n",currentState->stateName);
		}else {
			printf("Next state unavailable.\n");
		}
                break;
                
            case 'c':
                if (userInput[2] == '0') {
                    changeState(states,userInput[4],currentState, 0);
                }
                if (userInput[2] == '1') {
                    changeState(states,userInput[4],currentState, 1);
                }
                break;
                
            case 'p':
                print(states);
                break;
                
            case 'g':
                reset(states);
                garbage(currentState,currentState->last,currentState->next,currentState);
                
                int garbageState = 0;
                
                for (i = 0; i < 8; i++) {
                    if (states[i] != NULL) {
                        if (states[i]->nodeCount == 0) {
                            printf("Garbage: %c\n", states[i]->stateName);
                            garbageState = 1;
                        }
                    }
                }
                
                if(garbageState == 0) 
                    printf("No garbage.\n");
                break;
            
            case 'd':
                reset(states);
                garbage(currentState,currentState->last,currentState->next,currentState);
                delete(states, currentState, userInput[2]);
            
        }
        
    }
    return 0;
}

/* FUNCTION DEFINITIONS BELOW*/

//function changes the next and last state of the currentState defined by the user
void changeState(struct State *states[], char userInput, struct State *currentState, int whichState) {
    int i;
    for (i = 0; i < 8; i++) {
        
        if (states[i]->stateName == userInput && whichState == 0) {
            currentState->last = states[i];
        }
        if (states[i]->stateName == userInput && whichState == 1) {
            currentState->next = states[i];
        }
            
    }
}

//prints all the array pointers that are not already deleted
void print(struct State *states[]) {
    int i;
    for (i = 0; i < 8; i++) {
        if (states[i] != NULL) {
            printf("%c  %c  %c\n",states[i]->stateName,states[i]->last->stateName,states[i]->next->stateName);
        }
    }
}

//checks to see if there is an unreachable state
void garbage(struct State *current, struct State *last, struct State *next, struct State *rootNode) {
    struct State *previous = current;
    current->nodeCount++;
    
    if (current != last || current != next) {
    
        if(previous != last && last != rootNode && last-> nodeCount == 0) {
            garbage(last,last->last, last->next,rootNode);
        }
        
        if(previous != next && next != rootNode && next->nodeCount == 0) {
            garbage(next, next->last,next->next,rootNode);
        }
    
    }
}

//resets the nodeCount of each state
void reset(struct State *states[]) {
    int i;
    for (i = 0; i<8; i++) {
        if (states[i] != NULL)
        states[i]->nodeCount = 0;
    }
    
}

//deletes states that are unreachable and are not already deleted
void delete (struct State *states[], struct State *currentState, char userInput) {
    int i;
    int garbageState = 0;

    for (i = 0; i < 8; i++) {
        if (states[i] != NULL) {
            if (states[i]->nodeCount == 0) 
                garbageState = 1;
        }
    }
    
    if (userInput == NULL) {
        if (garbageState == 0) {
            printf("No states deleted.\n");
        }else {
            for (i = 0; i < 8; i++) {
                if (states[i] != NULL) {
                    if (states[i]->nodeCount == 0) {
                        printf("Deleted: %c\n", states[i]->stateName);
                        states[i]->next = NULL;
                        states[i]->last = NULL;
                        states[i] = NULL;
                    }
                }
            }
        }
    }else {
        for (i = 0; i < 8; i++) {
            if (states[i] != NULL) {
                if (states[i]->stateName == userInput && states[i]->nodeCount == 0) {
                    printf("Deleted.\n");
                    states[i]->next = NULL;
                    states[i]->last = NULL;
                    states[i] = NULL;
                }
                else if (states[i]->stateName == userInput) {
                    printf("Not deleted.\n");
                }
            }
        }
    }
}


