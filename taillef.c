/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** taillef
*/

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

int stat(char *, struct stat *);
void balayer_rep(char*, void (*fnc)(char *));

void taillef (char *nom)
{
    struct stat sttamp;
    if  (stat(nom, &sttamp) == -1){
        exit(84);
    }
    if((sttamp.st_mode & __S_IFMT))
    balayer_rep(nom, taillef);
    printf("%8ld %s\n", sttamp.st_size, nom);
}

int main (int argc, char **argv)
{
    if (argc == 1){
        taillef(".");
    }
    else{
        while (argc-- > 0){
            taillef(*++argv);
    
        }
    return (0);
    }
}