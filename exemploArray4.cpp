#include <stdio.h>
#include <windows.h>
#define LINHAS  24
#define COLUNAS 14

void gotoxy(short col, short row);
void desenhaTela(short altura, short largura, short x, short y, char letra[LINHAS][COLUNAS]);
 void desenharLinha(short linha, short largura,short x, short y, char conteudo[LINHAS][COLUNAS]);

main() {
   char tela[LINHAS][COLUNAS] = {{201,205,187},
                                 {186, 32, 186},
                                 {204,205,185},
                                 {200,205, 188}};
  
  desenhaTela( 10, 20, 30, 25, tela );
  
 }
 
 void desenharLinha(short linha, short largura,short x, short y, char conteudo[LINHAS][COLUNAS]) {
 	  int i = 0;
 	  gotoxy( x, y ); // muita conascença
 	  printf("%c",conteudo[linha][0]);
      for(i = 0; i < largura; i++  ) {
		printf("%c",conteudo[linha][1]);
      }
      printf("%c",conteudo[linha][2]);
 }
 
void desenhaTela(short altura, short largura, short x, short y, char letra[LINHAS][COLUNAS]) {
	  int i;

	  desenharLinha(0,largura, x, y++, letra); 	// primeira linha
      desenharLinha(1,largura, x, y++, letra);  // segunda linha
      desenharLinha(2 ,largura,x, y++, letra); // separador do cabeçalho

	  // recheio
	  for(i = 0; i < altura; i++  ) {
     	 desenharLinha(1,largura, x, y++, letra);  // segunda linha
      }
      desenharLinha(2 ,largura, x, y++, letra); // separador do cabeçalho
      desenharLinha(1,largura, x, y++, letra);  // penultima linha
      desenharLinha(3,largura, x, y++, letra);  // ultima linha
}

void gotoxy(short x, short y) {
 COORD pos ={x,y};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
