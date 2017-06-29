#include <bits/stdc++.h>
#define size_att 17 //numero total de atributos de cada instancia
#define size_inst 101 //numero total de instancias
#define size_data 85850 //numero total de dados testados
#define sigma 10
//DECLARAÇÃO DE VARIÁVEIS
char name[101][100]; //matriz de atributos
int data[101][17]; //nome dos animaizinhos lalala
int pepemoreno[5050];
int matriz[101][101];

//DECLARAÇÃO DE FUNÇÕES
void read_file(); //leitura de dados e construção de tabela
void compare(); //
double distance_e(int a, int b);
int converte_em_matriz();

int main(){
  double teste=exp(0.5);
    read_file();
    compare();
    return 0;
}

void read_file(){
    //--------LEITURA DE zoo.data feito por ropis alone
    FILE *teto;
    int k=0;
    teto = fopen("pickles.in" ,"r+");
    while(fscanf(teto, "%s", name[k])!=EOF){
        for(int j=0;j<17;++j){
            fscanf(teto, "%d ", &data[k][j]);
        }
        ++k;
    }
    fclose(teto);
    //---------FIM LEITURA DE ARQUIVO
    printf("%s \n", name[100]);
    for(int i=0; i<17;++i){
        printf("%d ", data[100][i]);
    }
}

void compare(){
    int n_iteracoes = size_inst*(size_inst-1)/2;
    double temp;
    for(int i=0;i<101;++i){
        for(int j=0;j<101;++j){
            if(i!=j && j>i){
                temp = exp(distance_e(i,i+1)/(2*pow(sigma,2)));
                pepemoreno[((i*j)/2)] = temp;
            }
        }
    }
    converte_em_matriz();
    faz_diagonal();

   }

double distance_e(int a, int b){
    float soma = 0;
    for (int i=0; i<size_att;++i){
        soma = soma + pow(data[a][i] - data[b][i],2);
    }
    return sqrt(soma);
}

void converte_em_matriz(){
    int novamatriz[101][101];
    for(int i=0;i<101;++i){
        for (int j = 0; j < 101; ++j)
        {
            if (i==j){
                matriz[i][j]
            }
            matriz[i][j] = pepemoreno[i/2];
        }
    }
}

void faz_diagonal(){
    for
}