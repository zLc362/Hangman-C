//
// Created by zLc on 17/12/2021.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void change(int wrong,char *hang){
    if(wrong==1)
        hang[0]='O';
    else
    if(wrong==2)
        hang[3]='|';
    else
    if(wrong==3)
        hang[1]='\\';
    else
    if(wrong==4)
        hang[2]='/';
    else
    if(wrong==5)
        hang[4]='/';
    else
    if(wrong==6)
        hang[5]='\\';
}
void Print(char hang[]){
    printf("\t||==========|   \n"
           "\t||          |    \n"
           "\t||          |    \n"
           "\t||        %c %c %c   \n"
           "\t||          %c    \n"
           "\t||         %c %c   \n"
           "\t||            \n"
           "\t||              \n"
           "\t=====================\n",hang[1],hang[0],hang[2],hang[3],hang[4],hang[5]);
}
int main() {
    int wrong=0,chk,guess,wordL,GC=0;   //GC e brojac na probani bukvi
    char Word[20],Current_guessed_word[20],GL[40],hang[]={' ', ' ', ' ', ' ', ' ', ' ', ' '}; //GL e niza na probani bukvi
    printf("Vnesete zbor\n");
    scanf("%s",&Word);
    system("cls");
    wordL= strlen(Word);
    for(int i=0;i<=wordL;i++) {
        Current_guessed_word[i] = '_';
    }
    Current_guessed_word[wordL]='\0';
    while (wrong<6) {
        chk=1;
        guess = getchar();
        if(guess!=10){          //10 e ascii kod za \n, pa go ignorirame
            GL[GC]=guess;
            GL[GC+1]=' ';
            GL[GC+2]='\0';
            GC+=2;
            system("cls");
            for (int i = 0; i < wordL; i++) {               //sekoja bukva od zborot
                if (((int)Word[i]) == guess){               //dali se isti ascii kodovite
                    Current_guessed_word[i] = (char)guess;
                    chk=0;                                  //chk e za ako ima gresna bukva vneseno
                }
            }
            if(chk){
                wrong++;
            }
            change(wrong,hang);
            printf("\tProbani bukvi se:\t%s\n\tZborot e:\t\t%s\n\tZborot ima %d bukvi.\n\n", GL, Current_guessed_word,wordL);
            if((strcmp(Word, Current_guessed_word)) == 0) {
                break;
            }
            Print(hang);
        }
    }
    system("cls");
    printf("\tProbani bukvi se:\t%s\n\tZborot e:\t\t%s\n\tZborot ima %d bukvi.\n\n", GL, Current_guessed_word,wordL);
    if(wrong<6){
        printf(" _    _  _____  _   _ \n"
               "| |  | ||_   _|| \\ | |\n"
               "| |  | |  | |  |  \\| |\n"
               "| |/\\| |  | |  | . ` |\n"
               "\\  /\\  / _| |_ | |\\  |\n"
               " \\/  \\/  \\___/ \\_| \\_/\n\n");
    }
    if(wrong==6){
        printf(" _      _____  _____  _____ \n"
               "| |    |  _  |/  ___||  ___|\n"
               "| |    | | | |\\ `--. | |__  \n"
               "| |    | | | | `--. \\|  __| \n"
               "| |____\\ \\_/ //\\__/ /| |___ \n"
               "\\_____/ \\___/ \\____/ \\____/ \n\n");}
    Print(hang);
    printf("Tocniot zbor e:\n%s\n", Word);
    getchar();getchar();
    return 0;
}