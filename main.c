#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include"librery.h"
//float reiniciar(float a[][2], int rango, int posicion)
int main(int argc, char *argv[])
{
    srand(time(NULL));
    srand48(time(NULL));
    int DATOS = contarLineas(), num=2, valida;
    int i,j,k,error,iteracion=0,population=5000,seed=10;
    float xy_original[DATOS][3],xy[DATOS][2];
    float ab[population][3*num],semilla[seed][3*num];
    float resultado[2][population];
    float aux=0, evalua=0;
    float average[3*num],std_dev[3*num];
//Inicializar los valores de X y Y ***leer de los valores de un archivo
    FILE *data;
    data=fopen("source.txt","r");
    for(i=0;i<DATOS;i++)
        fscanf(data,"%f %f %f",&xy[i][0] ,&xy[i][1] ,&xy[i][2]);
    fclose(data);

// Generar la poblacion con valores random
     for(i=0;i<population;i++){
        for(j=0;j<(3*num);j++){
            ab[i][j] = (rand() % 25)-10;
        }
    }

/*    for(error=0;error<10;error++){

        for(i=0;i<DATOS;i++){
            xy[i][0] = xy_original[i][0] + xy_original[i][2]*(2*drand48()-1);
            xy[i][1] = xy_original[i][1] + xy_original[i][2]*(2*drand48()-1);
    //        printf("%f | %f \n", xy[i][0], xy[i][1]);
        }*/


    // Inicio de la evaluacion de la poblacion hasta que la condiciòn se cumpla
        do{
    // Evaluacion de los elementos de la poblaciòn de con la funciòn objetivo
            for(i = 0; i<population; i++){            
                resultado[0][i] = 0;
                for(j = 0; j<DATOS; j++){
                    evalua=0;
                    for(k=0; k<num; k++)
                        evalua += evaluacion(xy[j][0],ab[i][(3*k)],ab[i][(3*k)+1],ab[i][(3*k)+2]);
                    resultado[0][i] += (xy[j][1]-evalua)*(xy[j][1]-evalua);
                    resultado[1][i] = resultado[0][i];
                }
            }
    // Ordenar las resultados
    /*        printf("\n************************************************\n");
            printf("Resultado de la iteracion %d\n",iteracion);
            printf("************************************************\n");*/
            for(i=1; i<population; i++){
                for(j=0; j<population-1; j++){
                    if(resultado[0][j] > resultado[0][j+1]){
                        aux = resultado[0][j];
                        resultado[0][j] = resultado[0][j+1];
                        resultado[0][j+1] = aux;
                    }
                }
            }
    // obtener las posiciones de los elementos mejor evaluados (semillas) para generar a la siguiente generacion
            for(i=0; i<seed; i++){
                for(j=0; j<population; j++){
                    if(resultado[0][i] == resultado[1][j]){
                        for(k=0; k<3*num; k++){
                            semilla[i][k] = ab[j][k];
    //                       printf("%d -- %d *** %f -- %f -- %f -- %f -- %f -- %f\n",i+1,j+1,semilla[i][0],semilla[i][1],semilla[i][2],semilla[i][3],semilla[i][4],semilla[i][5]);
                        }
                    }
                }
            }

    // calculos de los promedio y desviaciones estandar de las poblaciones para validar la condicion
            for(i=0;i<3*num;i++)
                average[i]=promedio(ab,population,i);
    //        for(i=0;i<3*num;i++)
    //            printf("El promedio de -%d es: %f\n",i+1,average[i]);

            for(i=0;i<3*num;i++)
                std_dev[i]=varianza(ab,population,i,average[i]);
    //        for(i=0;i<3*num;i++)
    //            printf("La varianza de -%d es: %f\n",i+1,std_dev[i]);

    // generaciòn de la nueva poblacion apartir de las semillas
            for(i=0;i<seed;i++){
                for(j=0;j<3*num;j++)
                    ab[i*(population/seed)][j]=semilla[i][j];
            }
            for(i=0;i<seed;i++){
                for(j=1;j<(population/seed);j++){
                    for(k=0;k<3*num;k++)
                        ab[j+i*(population/seed)][k]=semilla[i][k]+std_dev[k]*(2*drand48()-1);
                }
            }
            for(i=0;i<3*num;i++){
                average[i]=sqrt(average[i]*average[i]);
                std_dev[i]=sqrt(std_dev[i]*std_dev[i]);
            }
    //valiadacion de la iteracion y evaluacion de la condicion
            iteracion +=1;
            valida = validar(average, std_dev,3*num);
        }while(valida > 1);
        printf("************************************************\n");
        printf("resultado de evaluar pob %d y tardo %d iteraciones\n", error+1, iteracion+1);
        printf("%f | %f | %f | %f | %f | %f\n", ab[0][0], ab[0][1], ab[0][2], ab[0][3], ab[0][4], ab[0][5]);
//    }
}
