#include <bits/stdc++.h>
#define size_att 17 //numero total de atributos de cada instância.
#define size_inst 101 //numero total de instâncias.
#define size_data 85850 //numero total de dados testados.
#define sigma 10
//DECLARAÇÃO DE VARIÁVEIS
char name[101][100]; //matriz de atributos.
int data[101][17]; //nome dos animais.
int pepemoreno[5050];
float matriz[101][101];
int matriz2[101][101];

//DECLARAÇÃO DE FUNÇÕES
void read_file(); //leitura de dados e construção de tabela
void compare(); //compara a distancia euclidiana entre dois pontos
double distance_e(int a, int b); //função auxiliar para o calculo da distancia euclidiana
void zera_diagonal(); //zera diagonal
void matriz_diagonal(); //constroi matriz diagonal

int main(){
  double teste=exp(0.5);
  read_file();
  compare();
//      for(int i=0;i<101;++i){
//        for(int j=0;j<101;++j){
//            printf("%d",matriz[i][j]);
//        }
//        printf("\n");
//    }
  //matriz_diagonal();

  return 0;
}

void read_file(){
    //--------LEITURA DE zoo.data
    FILE *arquivo;
    int k=0;
    arquivo = fopen("lista_de_animais.in" ,"r+");
    while(fscanf(arquivo, "%s", name[k])!=EOF){
        for(int j=0;j<17;++j){
            fscanf(arquivo, "%d ", &data[k][j]);
        }
        ++k;
    }
    fclose(arquivo);
    //---------FIM LEITURA DE ARQUIVO
    //printf("%s \n", name[100]);
    //for(int i=0; i<17;++i){
        //printf("%d ", data[100][i]);
    //}
}

void compare(){
    int n_iteracoes = size_inst*(size_inst-1)/2;
    double temp;
    for(int i=0;i<101;++i){
        for(int j=0;j<101;++j){
            matriz[i][j] = exp(distance_e(i,j)/(2*pow(sigma,2)));
//           printf("%f", matriz[i][j]);
        }
//       printf("\n");
    }
    zera_diagonal();

}

double distance_e(int a, int b){
    float soma = 0;
    for (int i=0; i<size_att;++i){
        soma = soma + pow(data[a][i] - data[b][i],2);
//        printf("%f\n", soma);
    }
    return sqrt(soma);
}

void zera_diagonal(){
    for(int i=0;i<101;++i){
        matriz [i][i] = 0;
    }
}

void matriz_diagonal(){
    int somaLinha = 0;
    for(int i=0;i<101;++i){
        for(int j=0;j<101;++j){
            if (i!=j) matriz2[i][j] = 0;
        }
    }
    for(int i=0;i<101;++i){
        somaLinha = 0;
        for(int j=0;j<101;++j){
            somaLinha += matriz[i][j];
        }
        matriz2[i][i] = somaLinha;
    }

 //   for(int i=0;i<101;++i){
 //       for(int j=0;j<101;++j){
 //           printf("%d",matriz2[i][j]);
 //       }
 //       printf("\n");
 //   }
}