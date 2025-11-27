#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct sala {
char nome[50];          
 struct sala *esquerda;  
struct sala *direita;   
} Sala;
Sala* criarSala(const char *nome) {
Sala *nova = (Sala*)malloc(sizeof(Sala));

if (nova == NULL) {
printf("Erro ao alocar memória!\n");
exit(1);
}

strcpy(nova->nome, nome);
nova->esquerda = NULL;
nova->direita = NULL;
return nova;
}
void explorarSalas(Sala *atual) {
while (atual != NULL) {
printf("\n----------------------------------\n");
printf("Você está em: %s\n", atual->nome);

if (atual->esquerda == NULL && atual->direita == NULL) {
printf("\n❗ Fim do caminho! Esta sala não possui outras rotas.\n");
printf("----------------------------------\n");
return;
}
printf("\nEscolha para onde deseja ir:\n");
if (atual->esquerda != NULL)
printf(" (e) Ir para %s\n", atual->esquerda->nome);
if (atual->direita != NULL)
printf(" (d) Ir para %s\n", atual->direita->nome);
printf(" (s) Sair da exploração\n");
printf("Sua escolha: ");
char opc;
scanf(" %c", &opc);
if (opc == 'e' || opc == 'E') {
if (atual->esquerda != NULL) {
atual = atual->esquerda;
} else {
printf("❌ Não há sala à esquerda!\n");
}
}
else if (opc == 'd' || opc == 'D') {
if (atual->direita != NULL) {
atual = atual->direita;
} else {
printf("❌ Não há sala à direita!\n");
}
}
else if (opc == 's' || opc == 'S') {
printf("\nSaindo da exploração...\n");
return;
}
else {
printf("Opção inválida! Tente novamente.\n");
}
}
}

int main() {

// --------- Criando as salas ----------
Sala *hall = criarSala("Hall de Entrada");
Sala *salaEstar = criarSala("Sala de Estar");
Sala *cozinha = criarSala("Cozinha");
Sala *biblioteca = criarSala("Biblioteca");
Sala *jardim = criarSala("Jardim");
Sala *porao = criarSala("Porão");

hall->esquerda = salaEstar;
hall->direita = cozinha;

salaEstar->esquerda = biblioteca;
salaEstar->direita = jardim;

cozinha->direita = porao;

// --------- Início do jogo ----------
printf("=====================================\n");
printf("   DETECTIVE QUEST - MANSÃO ENIGMA\n");
printf("=====================================\n");
printf("\nBem-vindo(a) à Mansão! Vamos explorar.\n");

explorarSalas(hall);

printf("\nObrigado por jogar Detective Quest!\n");

return 0;
}
