#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<stdbool.h>
#include"librery.h"

float promedio(float a[][6], int b, int k){
    int i;
    float promedio=0.0;
    for(i = 0; i<b; i++)
        promedio += a[i][k];
    promedio = promedio/b;
    return promedio;
}

float varianza(float a[][6], int b, int k, float c){
    int i;
    float varianza=0.0;
    for(i = 0; i<b; i++)
        varianza += (a[i][k]-c)*(a[i][k]-c);
    varianza = sqrt(varianza/b);
    return varianza;
}

float evaluacion(float x, float a, float b, float c){
    float evaluado=0;
    evaluado = a*exp(-1*((b-x)/c)*((b-x)/c));
//    evaluado = y - a*exp(-1*((b-x)/c)*((b-x)/c));
//    evaluado = evaluado*evaluado;
    return evaluado;
}

int contarLineas(){
    FILE *archivo;
    int count = 0;
    char c;
    archivo=fopen("source.txt","r");
    for (c = getc(archivo); c != EOF; c = getc(archivo)){
        if (c == '\n')
        count ++;
    }
    fclose(archivo);
    return count;
}

int validar(float a[], float b[], int c){
    int i, comprobacion=0;
    for(i=0;i<c;i++){
        if(b[i]/a[i] > 0.001)
            comprobacion+=1;
    }
    return comprobacion;
}