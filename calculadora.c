#include <stdio.h>
#include<stdlib.h>  

void decimalParaBinario()
{
    int restoDivisao[10], numero, i;  //variáveis
    
    printf("\nInsira um número para converter para binário: ");  //Pede o número ao usuário  
    scanf("%d", &numero); //Lê o número que deve ser convertido
    
    for (i = 0; numero > 0; i++) //Efetua o loop até o número ficar igual a zero
    {    
        restoDivisao[i] = numero % 2; //Guarda o valor do resto da divisão no array    
        numero = numero / 2; //O divide o número por dois e guarda apenas a parte inteira da divisão para ser utilizado no próximo loop   
    } 
    
    printf("O binário do número decimal inserido é ");
    
    for (i = i -1; i >= 0 ; i--) //Escreve na tela os valores do resto da divisão em ordem inversa    
    {    
        printf("%d", restoDivisao[i]);
    }   
}

void binarioParaDecimal()
{
    int resultado  = 0; // Resultdo em decimal
    int potencia = 1; // Peso da unidade
    int binario = 0; // Número binário informado pelo usuário
    int casaBinaria = 0; // Número que será multiplicado pelo peso da unidade
    
    printf("\nInsira um número em binário (0 e 1) para converter para decimal: "); //Pede o número ao usuário
    scanf("%d", &binario); //Lê o numero para converter 
  
    while (binario > 0) //Efetua o loop até o número ficar igual a zero
    {
        casaBinaria = binario % 10; // Pega o resto da divisão que representa a casaBinaria
        resultado += casaBinaria * potencia; // Multiplica casaBinaria pela potência já somando os resultados
        binario = binario / 10; // Divide o número inicial para cortar a casa binária
        potencia = potencia * 2; // dobra a potência
    }
    
     printf("O decimal do número binário inserido é: ");
     printf("%d", resultado); // Escreve na tela o resultado
}

int main()
{  
    int opcaoUsuario = 0;
    printf ("Calculadora de conversão de base:\n");
    
    do 
    {
        printf("\n\nEscolha a operação que a calculadora deve efetuar:\n"); //menu
        printf("1 - Decimal para Binário\n");
        printf("2 - Binário para Decimal\n");
        printf("0 - Sair\n");
        scanf("%d", &opcaoUsuario);
        
        if (opcaoUsuario < 0 || opcaoUsuario > 2)//se o usuário escolher uma opção que não tem no menu
            printf("Opção inválida!\n");
        else 
        {
            switch(opcaoUsuario)
            {
                case 1:
                    decimalParaBinario();
                    break;
                case 2:
                    binarioParaDecimal();
                    break;
            }
        }
    }
    while(opcaoUsuario != 0); // loop continua até usuário escolher a opção 0
    
    return 0;  
}
