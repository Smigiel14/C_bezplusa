#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

size_t pn_str_len(const char *str) {
    int i = 0;

    if (str == NULL) {
        return 0;  
    }
    while (str[i] != '\0'){
        i++;
    }
    return i;
}

char* pn_str_dup(const char *str){
    if (str == NULL){
        return NULL;
    }

    char* new = malloc(pn_str_len(str)+1);
    size_t i;
    for (i = 0; str[i] != '\0'; i++){
        new[i] = str[i];
    }
    new[i] ='\0';
    return new;
}

bool pn_str_cmp(const char *str1, const char *str2){
    size_t i = 0;
    while (str1[i] != '\0' && str2[i] != '\0'){
        if (str1[i] != str2[i]){
            return false;
            i++;
        }
        return str1[i] == str2[i];
    }
}

size_t pn_str_count(const char *str, char ch){
    size_t i;
    size_t counter = 0;
    for (i = 0; pn_str_len(str) > i; i++){
        if (str[i] == ch){
            counter++;
        }
    } return counter;
}
// duze od 65 do 90 male od 97 do 122
void pn_str_capitalize(char *str){
    size_t i = 0;
    if (str[i] >= 97 && str[i] <= 122 && str != NULL){
    str[i] = str[i] - 32;
    }
}

void pn_str_trim(char *str) {
    size_t len = pn_str_len(str);
    while (len > 0 && str[len - 1] == ' ') {
        str[len - 1] = '\0';
        len--;
    }

    size_t poczatek = 0;
    while (str[poczatek] == ' ') {
        poczatek++;
    }

    if (poczatek > 0) {
        size_t i = 0;
        while (str[poczatek + i] != '\0') {
            str[i] = str[poczatek + i];
            i++;
        }
        str[i] = '\0';  
    }
}

void pn_str_rev(char *str){
    size_t len = pn_str_len(str);
    if (len == 0) 
    return;
    for (size_t i = 0; i < len / 2; i++){
        char temp = str[i];
        str[i] = str[len-1-i];
        str[len-1] = str[i];
        str[len - 1 - i] = temp;
    }
}

int main() {

    char text[] = "jakis tekst  ";
    char kopia[] = "tekst kopia";
    char literka = 'a';
    size_t length = pn_str_len(text);  
    pn_str_dup(kopia);
    char* copy = pn_str_dup(kopia);

    pn_str_count(text, literka);

    char dlugosc[] = "jak dlugi jest ten tekst";
    printf("Dlugos tekstu: %zu\n", pn_str_len(dlugosc));
    printf("Kopia: %s\n", copy);
    if (pn_str_cmp(text, kopia)) {
        printf("text == kopia\n");
    } else {
        printf("text != kopia\n");
    }

    char wzor[] = "Karolina";
    printf(" Ilość wystapien litery a w Karolina: %zu\n",pn_str_count(wzor, literka));


    char male[] = "malelitery";
    pn_str_capitalize(male);
    printf(" Po capitalize: %s\n", male);

    char trim[] = "        blabla     ";
    pn_str_trim(trim);
    printf(" Po trim: %s\n", trim);

    char reverse[] = "odwrocenie";
    pn_str_rev(reverse);
    printf("odwrocony jakis tekst %s\n", reverse);
    
    free(copy);
    
    return 0;
}