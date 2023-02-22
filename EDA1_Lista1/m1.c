/**
 *
 * Esse código, do jeito que está, resulta em 63% em "Wrong Answer".
 *
 **/

#include <stdio.h>

/* Para facilitar. */
#define LINHA "~~~~~~~~~~~\n"
#define GALHO "---"
#define LENHADOR " L "
#define TRONCO_MACHUCADO_ESQUERDA '>'
#define TRONCO_MACHUCADO_DIREITA '<'

/* Limites. */
#define COLUNAS 11
#define TRONCO_LINHAS 5
#define COMANDOS 2000

/* Como o jogo vai ser lido. */
struct Setup
{

  /* Quais comandos seão rodados. */
  //char comandos[COMANDOS];

  /* Comando a ser rodado. */
  char comando; // 'N' para nada. 'T' para o lenhador trocar de lado. 'B' para bater no tronco.

  /* Iterator para testar se é o primeira tela e não rodar nenhum comando. */
  short int comando_i;

} setup;

/* Informações do tronco. */
struct Tronco
{

  /* A quantidade de linhas do tronco. */
  int linhas;

  /* A quantidade de galhos do tronco. */
  int galhos;

} tronco;

/* Nosso grande lenhador. */
struct Lenhador
{

  /* O lado em que o lenhador está. */
  char lado; // 'D' para direita. 'E' para esquerda.

  /* Status do lenhador. */
  int vivo; // '0' para morto. '1' para vivo.

} lenhador;

/* Um galho do tronco. */
struct Galho
{

  /* O lado em que o galho está. */
  char lado; // 'D' para direita, 'E' para esquerda.

  /* Em qual linha do tronco o galho está. */
  int linha; // Sempre menor que a quantidade de 'galhos'.

};

struct Tela
{

  /* A quantidade de linhas do tronco. */
  int linhas;

  /* Linha do tronco para imprimir. */
  char tronco_esquerda;
  char tronco_direita;

  /* Linha para o galho esquerdo. */
  char galho_esquerdo;

  /* Linha para o galho direito. */
  char galho_direito;

  /* Se a linha-base está danificada. */
  int danificado_esquerda; // 0 para nada. 1 para danificado. 2 remove a linha.
  int danificado_direita; // 0 para nada. 1 para danificado. 2 remove a linha.

} tela;

int main ()
{

  // -- Pegar input e definir iniciais.
  setup.comando   = 'N';
  setup.comando_i = -1;

  tela.danificado_esquerda = 0;
  tela.danificado_direita  = 0;

  scanf("%d\n", &tronco.linhas);
  tela.linhas = (int) tronco.linhas;

  scanf("%d\n", &tronco.galhos);

  struct Galho galhos[tronco.galhos];

  for (int i = 0; i < tronco.galhos; ++i)
    scanf("%c %d\n", &galhos[i].lado, &galhos[i].linha);

  scanf("%c\n", &lenhador.lado);

  //printf("Comandos [%s]\n", setup.comandos);
  //printf("Lado do Lenhador: [%c]\n", lenhador.lado);

  // -- Começar o calculo.
  while (tela.linhas >= 1 && setup.comando != '\0' && setup.comando != '\n')
  {

    //printf("[%c]\n", setup.comando);

    // Agir no comando.
    if (setup.comando == 'T')
    {

      if (lenhador.lado == 'D')
        lenhador.lado = 'E';
      else
        lenhador.lado = 'D';

      for (int i = 0; i <= tronco.galhos; ++i)
        if (galhos[i].lado == lenhador.lado && (galhos[i].linha == 1 || galhos[i].linha == 2))
        {

          printf("**beep**\n");
          return 0;

        };

    }
    else if (setup.comando == 'B')
    {

      if (lenhador.lado == 'D')
      {

        if (tela.danificado_direita)
        {

            --tela.linhas;
            tela.danificado_esquerda = 0;
            tela.danificado_direita = 0;

            for (int i = 0; i <= tronco.galhos; ++i)
              --galhos[i].linha;

        } else
          ++tela.danificado_direita;

      } else {

        if (tela.danificado_esquerda)
        {
          --tela.linhas;
          tela.danificado_esquerda = 0;
          tela.danificado_direita = 0;

          for (int i = 0; i <= tronco.galhos; ++i)
            --galhos[i].linha;
        } else
          ++tela.danificado_esquerda;

      }

      // Verificar se o lenhador está morto.
      for (int i = 0; i <= tronco.galhos; ++i)
      {

        if (lenhador.lado == galhos[i].lado && galhos[i].linha == 2)
        {

          printf("**morreu**\n");
          return 0;

        }

      }

    } else {

      if (++setup.comando_i)
      {
        printf("**beep**\n");
        return 0;
      }

    }

    // Printar a próxima fodendo tela.
    {
      printf(LINHA);

      for (int j = TRONCO_LINHAS; j >= 1; --j)
      {

        if ((int)j > tela.linhas)
        {

          if (j <= 2)
            printf("  L\n");
          else
            printf("\n");

        } else {

          tela.galho_direito = tela.galho_esquerdo = ' ';
          tela.tronco_esquerda = tela.tronco_direita = '|';

          for (int i = 0; i <= tronco.galhos; ++i)
          {

            if (galhos[i].linha <= TRONCO_LINHAS && galhos[i].linha == j)
            {

              if (galhos[i].lado == 'E')
                tela.galho_esquerdo = '-';
              else
                tela.galho_direito = '-';

            }

          }

          if (j <= 2)
          {

            if (j == 1)
            {
              if (tela.danificado_direita)
                tela.tronco_direita = TRONCO_MACHUCADO_DIREITA;
              if (tela.danificado_esquerda)
                tela.tronco_esquerda = TRONCO_MACHUCADO_ESQUERDA;
            }

            if (lenhador.lado == 'E')
              printf(" %s%c|%c%c%c%c \n", LENHADOR, tela.tronco_esquerda, tela.tronco_direita, tela.galho_direito, tela.galho_direito, tela.galho_direito);
            else
              printf(" %c%c%c%c|%c%s \n", tela.galho_esquerdo, tela.galho_esquerdo, tela.galho_esquerdo, tela.tronco_esquerda, tela.tronco_direita, LENHADOR);

          } else {

            printf(" %c%c%c%c|%c%c%c%c \n", tela.galho_esquerdo, tela.galho_esquerdo, tela.galho_esquerdo, tela.tronco_esquerda, tela.tronco_direita, tela.galho_direito, tela.galho_direito, tela.galho_direito);

          }

        }

        //printf("[%c]\n", tela.galho_esquerdo);

      }
      printf(LINHA);
    }

    // Para pegar o próxímo comando.
    scanf("%c", &setup.comando);

  }

}
