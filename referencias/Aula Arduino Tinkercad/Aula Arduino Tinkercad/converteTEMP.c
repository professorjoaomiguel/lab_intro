//Programação Básica
//Prof. João Miguel

/* Faça um algoritmo que receba como
   entrada uma determinada temperatura
   em graus Celsius e mostre a temperatura
   em Fahrenheit.
      Fahrenheit = (9/5)*(Celsius) + 32
*/

//Bibliotecas
#include<stdio.h>
#include<stdlib.h>

//Função Principal
int main(void){
	//Declaração das Variáveis]
	float tempC,tempF;
	//Entrada
	printf("\nInforme a temperatura em oC:");
	scanf("%f",&tempC);
	//Processamento
	tempF = (9.0/5.0) * tempC + 32;
	//Saída
	printf("A temp %.1foC equivale a %.1foF",tempC,tempF);
	//Fechamento da Função Principal
	return 0;
}