#include <stdio.h>

typedef struct {
    int hora;
    int minutos;
    int segundos;
} hora;

typedef struct {
    int dia;
    int mes;
    int ano;
} data;

typedef struct {
    data cdata;
    hora chora;
    char cdesc[200];
} compromisso;

int main(void) {

    return 0;
}