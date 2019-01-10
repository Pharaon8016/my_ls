/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** main
*/
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <pwd.h>
#include "my.h"
struct stat repertoire;
DIR *dir;
struct dirent *rep;
struct passwd *passwd;



void afficher_permissions(char *name){

    stat(name, &repertoire);
    ((repertoire.st_mode & __S_IFDIR) != 0) ? my_putstr("d") : my_putstr("-");
    ((repertoire.st_mode & S_IRUSR) != 0) ? my_putstr("r") : my_putstr("-");
    ((repertoire.st_mode & S_IWUSR) != 0) ? my_putstr("w") : my_putstr("-");
    ((repertoire.st_mode & S_IXUSR) != 0) ? my_putstr("x") : my_putstr("-");
    ((repertoire.st_mode & S_IRGRP) != 0) ? my_putstr("r") : my_putstr("-");
    ((repertoire.st_mode & S_IWGRP) != 0) ? my_putstr("w") : my_putstr("-");
    ((repertoire.st_mode & S_IXGRP) != 0) ? my_putstr("x") : my_putstr("-");
    ((repertoire.st_mode & S_IROTH) != 0) ? my_putstr("r") : my_putstr("-");
    ((repertoire.st_mode & S_IWOTH) != 0) ? my_putstr("w") : my_putstr("-");
    ((repertoire.st_mode & S_IXOTH) != 0) ? my_putstr("x") : my_putstr("-");

}
void display_result()
{
    if (rep->d_name[0] != '.'){
        afficher_permissions(rep->d_name);
        my_putstr("  ");
        my_put_nbr(repertoire.st_nlink);
        my_putstr("  ");
        my_putstr(passwd->pw_name);
        my_putstr("  ");
        my_putstr(rep->d_name);
        my_put_nbr(repertoire.st_size);
        my_putchar('\n');
    }

}

int my_ls()
{
    if ((dir = opendir(".")) == NULL){
        return(84);
    }
    while ((rep = readdir(dir))){
        passwd = getpwuid(repertoire.st_uid);
        display_result();
    }
    return (0);
}

int main (int argc, char **argv)
{
    my_ls();
}

