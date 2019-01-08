/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** main
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#define MAX_NOM 14

typedef struct {
    long ino;
    char nom[MAX_NOM+1];
}Ent_rep;

typedef struct {
    int fd;
    Ent_rep e;
}REP;
int main (void){
REP *ouvrir_rep(char *nomrep);
Ent_rep *lire_rep(REP *fdr);
void fermer_rep(REP *fdr);

char *nom;
struct stat sttamp;
int stat(const char *, struct stat *);
printf("%s\n", sttamp.st_dev);
}


