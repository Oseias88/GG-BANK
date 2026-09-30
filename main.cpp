#include <iostream>
#include <string>
using namespace std; //evita usar a cada momento std::cout, std::cin, std::string

int main () {
// Vetores para armazenar os dados de ate 5 contas
int numeroConta[5];
string nomeCliente[5];
string cpf[5];
int tipoConta[5];
double saldo[5];
bool contaAtiva[5];

int contaConsulta, contaSaldo;
int contaAlterar, novoTipo, contaStatus;
int opcao;
int quantidadeContas = 0;  // controla quantas contas foram cadastradas
int posicao;              // guarda a posicao da conta encontrada
bool encontrou;          // informa se a conta foi encontrada
    
 do { //Tudo aqui será executado.
     
   cout << "********************************************************************"  << endl;
   cout << "***************************GG BANK**********************************"  << endl;
   cout << "********************************************************************"  << endl;
  
    cout << "1 - Cadastrar conta." << endl;
    cout << "2 - Consultar conta." << endl;
    cout << "3 - Verificar saldo." << endl;
    cout << "4 - Alterar tipo da conta." << endl;
    cout << "5 - Ativar/Desativar conta." << endl;
    cout << "6 - Sair." << endl;
    
    cout << "Escolha uma opcao: ";
    cin >> opcao;
    
  switch (opcao) {
     
     case 1:
       cout << "=== CADASTRO DE CONTA ===" << endl;
    
    if (quantidadeContas < 5) {  // cadastro limite de 5 contas !

        cout << "Digite o numero da conta: ";
        cin >> numeroConta[quantidadeContas];

        while (numeroConta[quantidadeContas] <= 0) {
            cout << "Numero invalido! Digite um numero maior que zero: ";
            cin >> numeroConta[quantidadeContas];
        }

        cin.ignore();

        cout << "Digite o nome do titular: ";
        getline(cin, nomeCliente[quantidadeContas]);

        cout << "Digite o CPF do titular: ";
        getline(cin, cpf[quantidadeContas]);

        cout << "Digite o tipo da conta (1 - Corrente / 2 - Poupanca): ";
        cin >> tipoConta[quantidadeContas];

        while (tipoConta[quantidadeContas] != 1 &&
               tipoConta[quantidadeContas] != 2) {

            cout << "Tipo invalido! Digite 1 para Corrente ou 2 para Poupanca: ";
            cin >> tipoConta[quantidadeContas];
        }

        cout << "Digite o saldo inicial: R$ ";
        cin >> saldo[quantidadeContas];

        while (saldo[quantidadeContas] < 0) {
            cout << "Saldo invalido! O saldo nao pode ser negativo." << endl;
            cout << "Digite novamente o saldo: R$ ";
            cin >> saldo[quantidadeContas];
        }

        contaAtiva[quantidadeContas] = true;

        quantidadeContas++;

        cout << "Sua conta foi cadastrada!" << endl;

    } else {
        cout << "Limite de 5 contas atingido!" << endl;
       
    }
        break;   //indica que a case terminou
    
     case 2: 
        cout << "=== CONSULTAR CONTA ===" << endl;

    cout << "Digite o numero da conta que deseja consultar: ";
    cin >> contaConsulta;

    encontrou = false;

    for (int i = 0; i < quantidadeContas; i++) {  // Procura a conta cadastrada
        // i++ faz a posicao avançar uma por vez

        if (contaConsulta == numeroConta[i]) {
            posicao = i;
            encontrou = true;
            break;
        }
    }

    if (encontrou == true) {

        cout << "=== DADOS DA CONTA ===" << endl;

        cout << "Numero da conta: " << numeroConta[posicao] << endl;
        cout << "Titular: " << nomeCliente[posicao] << endl;
        cout << "CPF: " << cpf[posicao] << endl;

        if (tipoConta[posicao] == 1) {
            cout << "Tipo da conta: Corrente" << endl;
        } else {
            cout << "Tipo da conta: Poupanca" << endl;
        }

        cout << "Saldo: R$ " << saldo[posicao] << endl;

        if (contaAtiva[posicao] == true) {
            cout << "Situacao: Ativa" << endl;
        } else {
            cout << "Situacao: Inativa" << endl;
        }

    } else {
        cout << "Conta nao encontrada!" << endl;
    }

        break;
        
     case 3: 
        cout << "=== VERIFICAR SALDO ===" << endl;

    cout << "Digite o numero da conta: ";
    cin >> contaSaldo;

    encontrou = false;

    for (int i = 0; i < quantidadeContas; i++) {
         // i++ faz a posicao avançar uma por vez

        if (contaSaldo == numeroConta[i]) {
            posicao = i;
            encontrou = true;
            break;
        }
    }

    if (encontrou == true) {

        if (contaAtiva[posicao] == true) {
            cout << "Titular: " << nomeCliente[posicao] << endl;
            cout << "Saldo atual: R$ " << saldo[posicao] << endl;
        } else {
            cout << "A conta esta inativa!" << endl;
        }

    } else {
        cout << "Conta nao encontrada!" << endl;
    }
        break;
        
     case 4:
         cout << "=== ALTERAR TIPO DA CONTA ===" << endl;

    cout << "Digite o numero da conta: ";
    cin >> contaAlterar;

    encontrou = false;

    for (int i = 0; i < quantidadeContas; i++) {
         // i++ faz a posicao avançar uma por vez

        if (contaAlterar == numeroConta[i]) {
            posicao = i;
            encontrou = true;
            break;
        }
    }

    if (encontrou == true) {

        if (contaAtiva[posicao] == true) {

            if (tipoConta[posicao] == 1) {
                cout << "Tipo atual: Corrente" << endl;
            } else {
                cout << "Tipo atual: Poupanca" << endl;
            }

            cout << "Digite o novo tipo (1 - Corrente / 2 - Poupanca): ";
            cin >> novoTipo;

            while (novoTipo != 1 && novoTipo != 2) {
                cout << "Tipo invalido! Digite 1 para Corrente ou 2 para Poupanca: ";
                cin >> novoTipo;
            }

            tipoConta[posicao] = novoTipo;

            cout << "Tipo da conta alterado com sucesso!" << endl;

        } else {
            cout << "A conta esta inativa!" << endl;
        }

    } else {
        cout << "Conta nao encontrada!" << endl;
    }
    
        break;
    
     case 5: 
     
        cout << "=== ATIVAR/DESATIVAR CONTA ===" << endl;

    cout << "Digite o numero da conta: ";
    cin >> contaStatus;

    encontrou = false;

    for (int i = 0; i < quantidadeContas; i++) {
         // i++ faz a posicao avançar uma por vez

        if (contaStatus == numeroConta[i]) {
            posicao = i;
            encontrou = true;
            break;
        }
    }

    if (encontrou == true) {

        if (contaAtiva[posicao] == true) {

            contaAtiva[posicao] = false;
            cout << "Conta desativada com sucesso!" << endl;

        } else {

            contaAtiva[posicao] = true;
            cout << "Conta ativada com sucesso!" << endl;
        }

    } else {
        cout << "Conta nao encontrada!" << endl;
    }

        break;
        
     case 6:
        cout << "Saindo do sistema..aguarde.." << endl;
        break; 
        
     default: //Qualquer opcao que não exista, opcao invalida.


    cout << "Essa opcao e invalida!" << endl;
  }  
    
        
 } while (opcao != 6); //Repetição se a opcao for diferente de 6.


  return 0;

}

