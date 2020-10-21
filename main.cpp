#include <iostream>
#include <locale.h>
#define qtd 15

//Paola Capita, 1° Semestre de 2020
//NP1 de Algotimo e Lógica de Programação - Professor Lucas Baggio
//Vending Machine

using namespace std;
int main() {
	setlocale(LC_ALL, "Portuguese");
  
	char operacao, alteracao_Senha, repor;
	string vet_Produtos[qtd] = {"Coca", "Bis", "Fandangos", "Sprite", "H20", "Kit-Kat", "Doritos", "Fanta", "Yakut", "Oie", "Jaboti", "Amendoin", "Hals", "Alpino", "Sonho de Valsa"};
	int codigo_Produto = 0, cod_ADM[2] = {12345, 12345}, qtd_Produto[qtd] = {1, 1, 1, 0, 0,1,1,0,0,1,1,1,0,0,1}, totalProduto = 0, acao_ADM, cod_Repor;
	float preco_Produtos[qtd] = {7.5, 3, 3.5, 5, 1.80, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5}, pagamento = 0, troco = 0, lucroAtual = 0, lucroFuruto = 0, lucroTotal = 0;

	//Soma o total de produtos e do faturamento maximo
	for(int i = 0; i < qtd; i++){
		totalProduto += qtd_Produto[i];
    	lucroTotal += qtd_Produto[i] * preco_Produtos[i];
  	}

	//faça enquanto o total de produtos for diferente de 0
	do{
    	cout<<"\t---------BEM VINDO A VENDING MACHINE---------"<<endl<<endl;
    	cout<<"Estes são os meus produtos:"<<endl<<endl;

    	//menu usuário
    	for(int i = 0; i < qtd ;i++){
			cout<<"\tCódigo "<<i<<" -> "<<vet_Produtos[i]<< " R$ "<<preco_Produtos[i]<<endl;
    	}
  
			cout<<endl<<"Digite o código do produto desejado?"<<endl;
    	cin>>codigo_Produto;
    
    	//verifica se é um codigo invalido
    	if (!(codigo_Produto < qtd && codigo_Produto > -1) && (!(codigo_Produto == cod_ADM[0] && codigo_Produto == cod_ADM[1]))){
      		cout<<"CÓDIGO INVÁLIDO"<<endl<<"--------------------------------------------------------------------------------------------"<<endl<<endl;
    	}

    	//Verifica se o código é compátivel com os usuários
    	if ((codigo_Produto < qtd) && (codigo_Produto > -1)){ 
				cout<<"produto: "<<vet_Produtos[codigo_Produto]<<endl<<endl;
				cout<<"Insira o pagamento no compartimento."<<endl;
				cin>>pagamento;
				cout<<endl<<"Foi inserido R$"<<pagamento<<endl<<endl;

      	//Verifica a qtd do produto escolhido
      	if(qtd_Produto[codigo_Produto] != 0){

				//Verifica o valor inserido
				if(pagamento > preco_Produtos[codigo_Produto]){
					troco = pagamento - preco_Produtos[codigo_Produto];
					qtd_Produto[codigo_Produto] -= 1;
					totalProduto -= 1;
					lucroAtual += preco_Produtos[codigo_Produto];
					cout<<"Retire o produto e não se esqueca de retirar o seu troco de R$"<<troco<<" no compartimento\nBOM PROVEITO"<<endl<<"--------------------------------------------------------------------------------------------"<<endl<<endl;
				}else if(pagamento == preco_Produtos[codigo_Produto]){
					qtd_Produto[codigo_Produto] -= 1;
					totalProduto -= 1;
					cout<<"Retire o produto\nBOM PROVEITO"<<endl<<"--------------------------------------------------------------------------------------------"<<endl<<endl;
				}else{
					cout<<"O valor inserido não é suficiente\nRetire-o no compartimento"<<endl<<"--------------------------------------------------------------------------------------------"<<endl<<endl;
				}  
      		}else{
        		cout<<"Desculpe, o produto está em falta\nRetire o valor inserido no compartimento"<<endl<<"--------------------------------------------------------------------------------------------"<<endl<<endl;
      		}
    	}

		//Verifica se o codigo é igual ao do ADM
		if((codigo_Produto == cod_ADM[0]) || (codigo_Produto == cod_ADM[1])){

			do{
				cout<<endl<<"\t---------MODO ADMINISTRADOR---------"<<endl<<endl;
				cout<<"Bem vindo ADM, o que gostaria de fazer hoje?"<<endl<<endl;
				cout<<"Digite 1 para visualizar um inventário completo\nDigite 2 para visualizar os faturamentos\nDigite 3 para repor os produtos\nDigite 4 para alterar a senha do administrador"<<endl<<endl;
				cin>>acao_ADM;

				switch (acao_ADM){
					case 1:
						//inventário
						cout<<endl<<"Estes são os produtos vendidos na máquina e a suas respectivas quantidades:"<<endl<<endl;
						for(int i = 0; i < qtd ;i++){
							cout<<"O produto de código "<<i<<"("<<vet_Produtos[i]<<") possui "<<qtd_Produto[i]<<" quantidades disponíveis para venda"<<endl;
						}
						cout<<endl<<"A máquina possui um total de "<<totalProduto<<" produtos no estoque"<<endl<<"--------------------------------------------------------------------------------------------"<<endl<<endl;
					break;
					case 2:
						//faturamentos
						cout<<endl<<"O faturamento atual da máquina é de R$"<<lucroAtual<<endl;
						cout<<"A máquina ainda pode faturar R$"<<(lucroTotal-lucroAtual)<<endl;
						cout<<"O lucro máximo da máquina, de acordo com o inventário atual, é de R$"<<lucroTotal<<endl<<"--------------------------------------------------------------------------------------------"<<endl<<endl;
					break;
					case 3:
						//Reposição de produtos
						cout<<endl<<"Você escolheu reposição de produtos"<<endl;
						do{
							cout<<"Digite o código de produto que deseja repor:"<<endl;
							cin>>cod_Repor;
							if(cod_Repor > -1 && cod_Repor < qtd){
								cout<<"Quantas unidades serão colocadas?"<<endl;
								cin>>qtd_Produto[cod_Repor];
								totalProduto += qtd_Produto[cod_Repor];
								for(int i = 0; i < qtd; i++){
									lucroTotal += qtd_Produto[i] * preco_Produtos[i];
								}
								cout<<"--------------------------------------------------------------------------------------------"<<endl;
							}else{
								cout<<"Código inválido"<<endl<<"--------------------------------------------------------------------------------------------"<<endl;
							}
							cout<<endl<<"Deseja repor outro produto?\nDigite S para sim\nDigite N para não"<<endl;
							cin>>repor;
							cout<<endl<<"--------------------------------------------------------------------------------------------"<<endl<<endl;
						}while(repor == 'S' || repor == 's');
					break;
					case 4:
						//alteração de senha
						cout<<endl<<"Você escolheu alterar a senha de acesso ao modo administrador\nDigite S, se tiver certeza disso?"<<endl;
						cin>>alteracao_Senha;
						if(alteracao_Senha == 'S' || alteracao_Senha == 's'){
							cout<<endl<<"Digite o novo código:"<<endl;
							cin>>cod_ADM[1];
							cout<<endl<<"O código do ADM foi alterado para "<<cod_ADM[1]<<endl<<"--------------------------------------------------------------------------------------------"<<endl<<endl;
						}
					break;
				}
				
				cout<<"Deseja realizar outra operação?\nDigite S para sim\nDigite N para não"<<endl;
				cin>>operacao;
				if (operacao == 'N'){
					cout<<endl<<"--------------------------------------------------------------------------------------------"<<endl<<endl;
				}
			}while (operacao == 'S');
		}
    }while (totalProduto != 0); 

	if(totalProduto == 0){
		cout<<"PRODUTOS ESGOTADOS\nDESLIGANDO"<<endl<<"--------------------------------------------------------------------------------------------"<<endl<<endl;
	}
	
	return 0;
}