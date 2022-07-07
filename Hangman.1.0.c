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
    printf("||==========|   \n"
           "||          |    \n"
           "||          |    \n"
           "||          %c    \n"
           "||         %c %c    \n"
           "||          %c    \n"
           "||         %c %c   \n"
           "||              \n"
           "=====================\n",hang[0],hang[1],hang[2],hang[3],hang[4],hang[5]);
}
int main() {
    int wrong=0,chk=1,guess;
    char word[100],guessed[100],hang[]={' ',' ',' ',' ',' ',' ',' '};
    printf("Vnesete zbor\n");
    scanf("%s",&word);
    system("cls");
    for(int i=0;i<=strlen(word);i++){
        guessed[i]='_';
        if(i==strlen(word))
            guessed[i]='\0';
    }
    while (wrong<6) {
        chk=1;
        guess = getchar();
        if(guess!=10){
        system("cls");
        for (int i = 0; i < strlen(word); i++) {
            if (((int)word[i]) == guess){
                guessed[i] = (char)guess;
                chk=0;
                }
        }
        if(chk){
            wrong++;
        }
        change(wrong,hang);
            printf("%s\n",guessed);
        if((strcmp(word,guessed))==0) {
            printf(" _    _  _____  _   _ \n"
                   "| |  | ||_   _|| \\ | |\n"
                   "| |  | |  | |  |  \\| |\n"
                   "| |/\\| |  | |  | . ` |\n"
                   "\\  /\\  / _| |_ | |\\  |\n"
                   " \\/  \\/  \\___/ \\_| \\_/\n\n");
            break;
        }
        Print(hang);}
    }
    if((strcmp(word,guessed))!=0){
        system("cls");
        printf(" _      _____  _____  _____ \n"
               "| |    |  _  |/  ___||  ___|\n"
               "| |    | | | |\\ `--. | |__  \n"
               "| |    | | | | `--. \\|  __| \n"
               "| |____\\ \\_/ //\\__/ /| |___ \n"
               "\\_____/ \\___/ \\____/ \\____/ \n\n");}
    Print(hang);
    printf("The word was:\n%s\n",word);
    getchar();getchar();
    return 0;
}