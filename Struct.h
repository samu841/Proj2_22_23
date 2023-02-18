//
// Created by samu on 2/2023.
//
#ifndef PROJ2_22_23_STRUCT_H
#define PROJ2_22_23_STRUCT_H

typedef struct Player {
    char name[50];
    char surname[50];
    char birthdate[10];
    char nationality[50];
    char team[50];
    int id;
}PLAYERS;

typedef struct Coach {
    char name[50];
    char surname[50];
    char birthdate[10];
    char nationality[50];
    char team[50];
    int id;
}COACH;

typedef struct Team {
    char name[50];
    char surname[50];
    char birthdate[10];
    char nationality[50];
    char team[50];
    int id;
}TEAMS;


#endif //PROJ2_22_23_STRUCT_H
