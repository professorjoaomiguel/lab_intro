//Professor João Miguel - Programação Básica

/* Descrição
A locadora de carros SAI DA FRENTE está fazendo uma promoção e está alugando
carros no período junino por R$ 30,00 a diária. Além disso, a locadora cobra
R$ 0,01 por quilômetro rodado. Como é período de São João, a locadora quer 
fidelizar os clientes e está dando 10% de desconto no valor total do aluguel
de qualquer carro.
Formato de entrada
 - Quantos dias a pessoa ficou com o carro: [1; 30]
 - Quantos kilômetros ela rodou [1; 1000]
Formato de saída
 - O valor total que a pessoa deve pagar pelo aluguel do
   carro arredondado para duas casas decimais. */

#include <stdio.h>
#include <stdlib.h>
int main(void) {
    //Declaração das Variáveis
    int tempo;      //em dias
    int distancia;  //em kilometros
    float valor;    //em reais
    //Entrada
    scanf("%i",&tempo);
    scanf("%i",&distancia);
    //Processamento
    valor = (tempo * 30 + distancia * 0.01) * 0.9;
    //Saída
    printf("%.2f",valor);
    return 0;
}
