#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


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
    int chk,guess,wordL,wordnum;   //GC e brojac na probani bukvi
    char Current_guessed_word[20],GL[40]; //GL e niza na probani bukvi
    char Words[15][20]={"krokodil",
                        "marmalad",
                        "lamba",
                        "laptop",
                        "elka",
                        "lampion",
                        "gluvce",
                        "tastatura",
                        "monitor",
                        "krevet",
                        "casa",
                        "harija",
                        "slika",
                        "racka",
                        "stol"};
    srand(time(NULL));
    while(1){
    int GC=0,wrong=0;
    char hang[]={' ', ' ', ' ', ' ', ' ', ' ', ' '};
    GL[0]='\0';
    wordnum=rand()%15;
    wordL= strlen(Words[wordnum]);
    for(int i=0;i<=wordL;i++) {
        Current_guessed_word[i] = '_';
    }
    Current_guessed_word[wordL]='\0';
    printf("\tProbani bukvi se:\t%s\n\tZborot e:\t\t%s\n\t"
           "Zborot ima %d bukvi.\n\n", GL, Current_guessed_word,wordL);
        Print(hang);
    while (wrong<6) {
        chk=1;
        guess = getchar();
        if(guess!=10){          //10 e ascii kod za \n, pa go ignorirame
            GL[GC]=(char)guess;
            GL[GC+1]=' ';
            GL[GC+2]='\0';
            GC+=2;
            system("cls");              //go brise terminal na windows
            for (int i = 0; i < wordL; i++) {               //sekoja bukva od zborot
                if (((int)Words[wordnum][i]) == guess){               //dali se isti ascii kodovite
                    Current_guessed_word[i] = (char)guess;
                    chk=0;                                  //chk e za ako ima gresna bukva vneseno
                }
            }
            if(chk){            //ako ima gresna bukva,chk ostanuva 1
                wrong++;
            }
            change(wrong,hang);
            printf("\tProbani bukvi se:\t%s\n\tZborot e:\t\t%s\n\t"
                   "Zborot ima %d bukvi.\n\n", GL, Current_guessed_word,wordL);
            if((strcmp(Words[wordnum], Current_guessed_word)) == 0) {
                break;
            }
            Print(hang);
        }
    }
    system("cls");
    printf("\tProbani bukvi se:\t%s\n\tZborot e:\t\t%s\n\t"
           "Zborot ima %d bukvi.\n\n", GL, Current_guessed_word,wordL);
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
    printf("Tocniot zbor e:\n%s\n\n"
           "Vnesete '0' za da zavrse igrata, stisnete ENTER za da prodolzite\n", Words[wordnum]);
    getchar();
    if(getchar()=='0')
        break;
    system("cls");
    }
    return 0;
}