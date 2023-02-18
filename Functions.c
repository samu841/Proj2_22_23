//
// Created by samu on 2/2023.
//
#include "Main.h"

//Global variables
PLAYERS players[MAX_PLAYERS];
COACH coach[MAX_COACH];

void insertPlayer(){
    int i=0;
    char key = 'Y';
    for (i = 0; i < MAX_PLAYERS; i++) {
        if (toupper(key)!='N') {
            printf(" First Name: ");
            gets(players[i].name);
            printf("Last Name: ");
            gets(players[i].surname);
            printf("Date of Birth(dd-mm-yyyy): ");
            gets(players[i].birthdate);
            printf("Nationality: ");
            gets(players[i].nationality);
            printf("Team: ");
            /*if(fgets(players[i].team, i, stdin)==NULL){
                printf("\nTeam is mandatory\n");
                printf("Team: ");
                fgets(players[i].team, i, stdin);
            }*/
            gets(players[i].team);
            printf("Federation Number: ");
            scanf(" %i", &players[i].id);
            printf("Continue?(Y/N)");
            fseek(stdin, 0, SEEK_END);
            gets(&key);
        }else{writePlayers();
        }
    }
    writePlayers();
}
void writePlayers(){
    FILE* fp;
    //allow the user to define the name of the file
    char fileName[80];
    printf("File name? ");
    scanf("%s", fileName);
    fp = fopen(strcat(fileName, ".txt"),"w");
    if(fp==NULL){
        printf("Error opening the file");
        exit(1);
    }
    int i;
    for(i=0; i<MAX_PLAYERS; i++){
        fprintf(fp, "%s %25s %25s %25s %25s %i\n"
                ,players[i].name ,players[i].surname ,players[i].birthdate ,players[i].nationality ,players[i].team ,players[i].id );
    }
    fclose(fp);
    menu();
}

void insertCoach(){
    int i=0;
    char key = 'Y';
    for (i = 0; i < MAX_COACH; i++) {
        if (toupper(key)!='N') {
            printf("First Name: ");
            gets(coach[i].name);
            printf("Last Name: ");
            gets(coach[i].surname);
            printf("Date of Birth(dd-mm-yyyy):");
            gets(coach[i].birthdate);
            printf("Nationality:");
            gets(coach[i].nationality);
            printf("Team:");
            gets(coach[i].team);
            printf("Federation Number: ");
            scanf(" %i", &coach[i].id);
            getchar();
            printf("Continue?(Y/N)");
            gets(&key);
        }else{writeCoach();
        }
    }
    writePlayers();
}
void writeCoach(){
    FILE* fp;
    //allow the user to define the name of the file
    char fileName[80];
    printf("File name? ");
    scanf("%s", fileName);
    fp = fopen(strcat(fileName, ".txt"),"w");
    if(fp==NULL){
        printf("Error opening the file");
        exit(1);
    }
    int i;
    for(i=0; i<MAX_COACH; i++){
        fprintf(fp, "%s %25s %25s %25s %25s %i\n"
                ,coach[i].name ,coach[i].surname ,coach[i].birthdate ,coach[i].nationality ,coach[i].team ,coach[i].id );
    }
    fclose(fp);
    menu();
}

void menuI(){
    char key;
    printf("1-Palyers\n2-Teams\n3-Coaches:");
    gets(&key);
    switch (key) {
        case '1':insertPlayer();break;
        case '3':insertCoach();break;
        default:
            printf("Wrong selection\n"); menuI(); break;
    }

}
void menu(){
    char key;
    printf("Select menu:\nInsert(I)\nDelete(D)\nList(L):");
    gets(&key);
    switch (toupper(key)) {
        case 'I': menuI();break;
        default:
            printf("Wrong selection\n"); menu(); break;
    }
}