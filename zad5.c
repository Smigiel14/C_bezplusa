#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
// enum{}
enum Operation {
    OP_LEN,
    OP_SQRT,
    OP_LOG10,
};

struct Calculation
{   
    char* str;
    enum Operation type;
};



size_t length(const char *str){
    return strlen(str);
}

double sqrt_len(const char *str){
    double result;
    result=sqrt(strlen(str));
    return result;
}

double log_10(const char *str){
    double result;
    result = log10(strlen(str));
    return result;
}

char* ASCII(int argc, char *argv[]){
    char *str = malloc(argc +1);
    
    
    int i = 1;
    while(i<argc){
        int code_ascii=atoi(argv[i]);
        str[i-1] = (char)code_ascii;
        i++;
    }
    str[i-1] = '\0';

    return str;
}

enum Operation parse_operation(const char *const str_oper) {
    if (strcmp(str_oper, "len") == 0)
        return OP_LEN;
    if (strcmp(str_oper, "sqrt") == 0)
        return OP_SQRT;
    if (strcmp(str_oper, "log10")== 0)
        return OP_LOG10;
    
}

double calc(const struct Calculation *const c)
{
    switch (c->type)
    {
        case OP_LEN:
           return length(c->str);
        case OP_SQRT:
           return sqrt_len(c->str);
        case OP_LOG10:
           return log_10(c->str);
    }
    return 0;
}



int main(int argc, char *argv[]){ 
    double result;
    char option[255];
    
    struct Calculation c;
    c.str = ASCII(argc, argv);
    printf("%s\n", c.str);

    do{
        printf("Podaj operację:");
        scanf("%s", option);

        if(strcmp(option,"len") ==0){
            c.type = OP_LEN;
        }

        if(strcmp(option,"sqrt") ==0){
            c.type = OP_SQRT;
        }

        if(strcmp(option,"log10") ==0){
            c.type = OP_LOG10;
        }

       result = calc(&c);
       printf("Wynik: %.4f\n", result);
    }while(strcmp(option,"bye") == 0);


    free(c.str);
    return 0;

}