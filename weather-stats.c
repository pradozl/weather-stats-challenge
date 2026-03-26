#include <stdio.h>
#include <stdlib.h>

int main(){

    // Variáveis

    int cidades, dias, cidade_maior,
        dia_maior, cidade_menor, dia_menor;
    float **temperaturas, *media_cidades, soma_total = 0,
            media_geral, maior_temp, menor_temp;

    // Obter quantia de Cidades/Dias
    
    printf("Informe a quantidade de cidades: ");
    scanf("%d", &cidades);

    printf("Informe a quantidade de dias: ");
    scanf("%d", &dias);

    // Matriz dinâmica

    temperaturas = (float **)malloc(cidades * sizeof(float *));
    for(int i = 0; i < cidades; i++){
        temperaturas[i] = (float *)malloc(dias * sizeof(float));
    }

    // Obter temperaturas

    media_cidades = (float *)malloc(cidades * sizeof(float));

    for(int i = 0; i < cidades; i++){
        printf("\nCidade %d:\n", i + 1);
            for(int j = 0; j < dias; j++){
                printf(" Dia %d - Temperatura máxima: ", j + 1);
                scanf("%f", &temperaturas[i][j]);
            }
    }

    // Maior temperatura / Menor temperatura 

    maior_temp = menor_temp = temperaturas[0][0];
    cidade_maior = cidade_menor = 1;
    dia_maior = dia_menor = 1;

    // Processar dados

    for(int i = 0; i < cidades; i++){
        float soma = 0;
        for(int j = 0; j < dias; j++){
            float temp = temperaturas[i][j];
            soma +=  temp;
            soma_total += temp;

            if(temp > maior_temp){
                maior_temp = temp;
                cidade_maior = i + 1;
                dia_maior = j + 1;
            }
            if(temp < menor_temp){
                menor_temp = temp;
                cidade_menor = i + 1;
                dia_menor = j + 1;
            }
        }
        media_cidades[i] = soma / dias;
    }

    // Média geral

    media_geral = soma_total / (cidades + dias);

    // Exibir médias por cidade

    printf("\nTemperatura media semanal por cidade:\n");
    for(int i = 0; i < cidades; i++){
        printf("Cidade %d: %.2f\n", i + 1, media_cidades[i]);
    }

    // Exibir Maior / Menor temperatura

    printf("\nMaior temperatura registrada: %.2f (Cidade %d, Dia %d)\n", maior_temp, cidade_maior, dia_maior);
    printf("Menor temperatura registrada: %.2f (Cidade %d, Dia %d)\n", menor_temp, cidade_menor, dia_menor);

    // Exibir cidades com média acima da geral
    
    printf("\nMedia geral das temperaturas: %.2f\n", media_geral);
    printf("Cidades com media acima da media geral:\n");
    for(int i = 0; i < cidades; i++){
        if(media_cidades[i] > media_geral){
            printf("Cidade %d (%.2f)\n", i + 1, media_cidades[i]);
        }
    }
    return 0;
}