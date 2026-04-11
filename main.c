#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Declaração antecipada da função
int gerador_de_senhas_fortes();

int main(){
int opcao;
    printf("====== MENU ======\n");
    printf("1. Gerar senha forte\n");
    printf("2. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    getchar(); 

   switch (opcao)
   {
     case 1:
       gerador_de_senhas_fortes();
        break;
     case 2:
       printf("Saindo do programa...\n");
        return 0;
        break;
     default:
       printf("Opção inválida. Tente Novamente\n");
       getchar();
    }
   

    return 0;
}












// um programa que gera senhas aleatórias seguindo critérios de segurança definidos pelo usuário.
int gerador_de_senhas_fortes(){
  int posicao = 0;
  int nivel_seguranca = 0;
  char senha[33];
  char incluir_maiusculas[10], incluir_minusculas[10], incluir_numeros[10], incluir_simbolos[10];
  int comprimento;
   // selecionar opções, sele quer sair ou gerar senha
  
  


 while (1)
 {
    
    


   // precisa exibir pro usuario os criterios disponiveis para a senha
   printf("Bem vindo\n");
   printf("-----------------------------------\n");
   printf("Gerenciador de senhas fortes\n");
   printf("-----------------------------------\n");
 
   printf("Deseja incluir letras maiusculas?(s/n): ");
   fgets(incluir_maiusculas, sizeof(incluir_maiusculas), stdin);
   incluir_maiusculas[strcspn(incluir_maiusculas, "\n")] = '\0'; 

   printf("Deseja incluir letras minusculas?(s/n): ");
   fgets(incluir_minusculas, sizeof(incluir_minusculas), stdin);
   incluir_minusculas[strcspn(incluir_minusculas, "\n")] = '\0';

   printf("Deseja incluir numeros?(s/n): ");
   fgets(incluir_numeros, sizeof(incluir_numeros), stdin);
   incluir_numeros[strcspn(incluir_numeros, "\n")] = '\0';

   printf("Deseja incluir simbolos?(s/n): "); 
   fgets(incluir_simbolos, sizeof(incluir_simbolos), stdin);
   incluir_simbolos[strcspn(incluir_simbolos, "\n")] = '\0';
   // precisa validar se pelo menos um criterio foi selecionado, ou seja, 0 = foi escolhido, 1 = nao foi escolhido, se foi escolhido, gerar senha
   if (strcmp(incluir_maiusculas, "s") != 0 && strcmp(incluir_minusculas, "s") != 0 && strcmp(incluir_numeros, "s") != 0 && strcmp(incluir_simbolos, "s") != 0) {
        printf("Erro: Você deve selecionar pelo menos um critério para a senha.\n");
        return 1;
      }
    char buffer[10];
    printf("Qual será o comprimento da senha?(8-32): ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &comprimento);
    getchar(); 
  
    if(comprimento < 8 || comprimento > 32){
      printf("Comprimento inválido, Usando 12 caracteres.\n");
      comprimento = 12;
    }


   // Inicializar gerador aleatório(time(NULL) retorna o tempo atual em segundos 
   srand(time(NULL));



   char maiusculas[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   char minusculas[] = "abcdefghijklmnopqrstuvwxyz";
   char numeros[] = "0123456789";
   char simbolos[] = "!@#$%^&*()";

   // o pool de caracteres possiveis para a senha que depois será sorteado um caractere do pool para cada posição da senha(aleatorio com rand())
   char pool[100] = "";
   // se 'incluir_maiusculas' for igual a 's', ou seja, o char 's' estiver armazenado em 'incluir_maiusculas', retorna 0(true) e concatena(strcat) as letras M em pool
            if(strcmp(incluir_maiusculas, "s") == 0) {
               strcat(pool, maiusculas);
            }

            if(strcmp(incluir_minusculas, "s") == 0) {
              strcat(pool, minusculas);
            }
           
            if(strcmp(incluir_numeros, "s") == 0) {
              strcat(pool, numeros);
            }

            if(strcmp(incluir_simbolos, "s") == 0) {
              strcat(pool, simbolos);
            }
 

    // o pool escolhido será apenas comprimento pelo strlen que o resto da divisão de um numero aleatorio do rand() será igual a posição da letra do pool escolhido
    /*int indice = rand() % strlen(pool); 
    char letra = pool[indice]; 
     */  

    if(strcmp(incluir_maiusculas, "s") == 0) {
     int idx = rand() % strlen(maiusculas);
     senha[posicao++] = maiusculas[idx];
    }

    if(strcmp(incluir_minusculas, "s") == 0) {
     int idx = rand() % strlen(minusculas);
     senha[posicao++] = minusculas[idx];
    }

    if(strcmp(incluir_numeros, "s") == 0) {
     int idx = rand() % strlen(numeros);
     senha[posicao++] = numeros[idx];
    }

    if(strcmp(incluir_simbolos, "s") == 0) {
     int idx = rand() % strlen(simbolos);
     senha[posicao++] = simbolos[idx];
    }

   // Completar o resto da senha com caracteres aleatórios do pool
     while(posicao < comprimento) {
       int idx = rand() % strlen(pool);
       senha[posicao++] = pool[idx];
      }

   // embaralhador da senha

     for(int i = 0; i < comprimento; i++) {
      int j = rand() % comprimento;
      char temp = senha[i];
      senha[i] = senha[j];
      senha[j] = temp;
     }




   // Adicionar o terminador de string
    senha[comprimento] = '\0';
    if(strlen(senha) >= 8) {
     nivel_seguranca++;
    }
   // (strpbrk)vai procurar pelo primeiro caractere da string que contenha com o cojunto de caracteres(ex:maiusculas)
    if(strpbrk(senha, maiusculas) != NULL) {
      nivel_seguranca++;
    }
   if(strpbrk(senha, minusculas) != NULL) {
      nivel_seguranca++;
   }
   if(strpbrk(senha, numeros) != NULL) {
      nivel_seguranca++;
    }
   if(strpbrk(senha, simbolos) != NULL) {
      nivel_seguranca++;
    }
 



   printf("Senha gerada: %s\n", senha);
   printf("Nivel de segurança: %d/5\n", nivel_seguranca);
   printf("-----------------------------------\n");
   printf("Deseja gerar outra senha?(s/n): ");
   char opcao;
   scanf("%c", &opcao);
   getchar();
   if(opcao != 's') {
     printf("Saindo do gerador de senhas...\n");
     break;
    }
   
   
 } 
    return 0;
}



