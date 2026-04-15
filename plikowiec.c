#include <stdio.h>
#include <string.h>


void file_hello(const char *filename){
    FILE *fp = fopen(filename, "w");
    fprintf(fp, "Hello world");
    fclose(fp);
}

void file_print(const char *filename){
    FILE *fp = fopen(filename, "r");
    
    char myString[100];
    while(fgets(myString, 100, fp)){
    printf("%s", myString);
    }
    fclose(fp);
}

void file_append(const char *filename, const char *data){
    FILE *fp = fopen(filename, "a");
    fprintf(fp, "%s", data);
    fclose(fp);
}

void file_remove(const char *filename){
    remove(filename);
}

int main(){
   
   file_hello("content.txt");
    char option;
    char data[256];

    do{
    printf("wybierz opcje\n (1) odczyt pliku\n (2) dopisz do pliku\n (3) wyjscie\n");
    scanf("%c", &option);

    if(option == '1'){
        file_print("content.txt");
        printf("\n");
    }
    else if(option == '2'){
        printf("Podaj dane do dodania do pliku:\n");
        scanf("%s", data);
        file_append("content.txt", data);
    }

    }while(option != '3');
    file_remove("content.txt");
    return 0;

}
