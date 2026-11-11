#include <iostream>
#include <string>
using namespace std; //evita usar a cada momento std::cout, std::cin, std::string

int main () {
    
const int MAX_CONTAS = 100;
const int MAX_MOVIMENTACOES = 500;
    
// Vetores para armazenar os dados de ate 100 contas
int numeroConta[MAX_CONTAS];
string nomeCliente[MAX_CONTAS];
string cpf[MAX_CONTAS];
int tipoConta[MAX_CONTAS];
double saldo[MAX_CONTAS];
bool contaAtiva[MAX_CONTAS];

int contaMovimentacao[MAX_MOVIMENTACOES];
char tipoMovimentacao[MAX_MOVIMENTACOES];
double valorMovimentacao[MAX_MOVIMENTACOES];
double valorDeposito; // valor em  que o cliente deseja depositar.

int contaConsulta, contaSaldo;
int contaAlterar, novoTipo, contaStatus;
int opcao;
int quantidadeContas = 0;  // controla quantas contas foram cadastradas
int quantidadeMovimentacoes = 0;

int posicao;              // guarda a posicao da conta encontrada
int posicaoDestino;
bool encontrouMovimentacao;
bool encontrouDestino;
bool encontrou;          // informa se a conta foi encontrada
bool numeroRepetido;
    
 do { //Tudo aqui será executado.
     
   cout << "********************************************************************"  << endl;
   cout << "***************************GG BANK**********************************"  << endl;
   cout << "********************************************************************"  << endl;
  
    cout << "1 - Cadastrar conta." << endl;
    cout << "2 - Listar contas." << endl;
    cout << "3 - Consultar conta." << endl;
    cout << "4 - Realizar deposito." << endl;
    cout << "5 - Realizar saque." << endl;
    cout << "6 - Realizar transferência." << endl;
    cout << "7 - Exibir extrato." << endl;
    cout << "8 - Sair." << endl;
    
    cout << "Escolha uma opcao: ";
    cin >> opcao;
    
  switch (opcao) {
     
       case 1:
    cout << "=== CADASTRO DE CONTA ===" << endl;

    if (quantidadeContas < MAX_CONTAS) {

        do {
            cout << "Digite o numero da conta: ";
            cin >> numeroConta[quantidadeContas];

            while (numeroConta[quantidadeContas] <= 0) {
                cout << "Numero invalido! Digite um numero maior que zero: ";
                cin >> numeroConta[quantidadeContas];
            }

            numeroRepetido = false;

            for (int i = 0; i < quantidadeContas; i++) {

                if (numeroConta[quantidadeContas] == numeroConta[i]) {
                    numeroRepetido = true;
                    break;
                }
            }

            if (numeroRepetido == true) {
                cout << "Essa conta ja existe! Digite outro numero." << endl;
            }

        } while (numeroRepetido == true);

        cin.ignore();

        cout << "Digite o nome do titular: ";
        getline(cin, nomeCliente[quantidadeContas]);

        cout << "Digite o CPF do titular: ";
        getline(cin, cpf[quantidadeContas]);

        cout << "Digite o tipo da conta (1 - Corrente / 2 - Poupanca): ";
        cin >> tipoConta[quantidadeContas];

        while (tipoConta[quantidadeContas] != 1 &&
               tipoConta[quantidadeContas] != 2) {

            cout << "Tipo invalido! Digite 1 ou 2: ";
            cin >> tipoConta[quantidadeContas];
        }

        cout << "Digite o saldo inicial: R$ ";
        cin >> saldo[quantidadeContas];

        while (saldo[quantidadeContas] < 0) {
            cout << "Saldo invalido! Digite novamente: R$ ";
            cin >> saldo[quantidadeContas];
        }

        contaAtiva[quantidadeContas] = true;

        quantidadeContas++;

        cout << "Conta cadastrada com sucesso!" << endl;

    } else {
        cout << "Limite de 100 contas atingido!" << endl;
    }

    break;
    
     case 2: 
        cout << "=== CONTAS CADASTRADAS ===" << endl;
        
    if (quantidadeContas == 0) {
      // nenhuma conta cadastrada  
    cout << "Nenhuma conta cadastrada." << endl;
    
    
    } else {
        
    for (int i = 0; i < quantidadeContas; i++) {  // Procura a conta cadastrada
        // i++ faz a posicao avançar uma por vez
        
      
      cout << "numero da conta: " << nomeCliente[i] << endl;
      cout << "Titular: " << nomeCliente[í] << endl;
      cout << "CPF: " << cpf[i] << endl;
      
        
        
        if (tipoConta[i] == 1) {
            cout << "Tipo da conta: Corrente" << endl;
        } else {
            cout << "Tipo da conta: Poupanca" << endl;
       }

        cout << "Saldo: R$ " << saldo[i] << endl;

         if (contaAtiva[i] == true) {
            cout << "Situacao: Ativa" << endl;
        } else {
            cout << "Situacao: Inativa" << endl;
        }

        cout << "------------------------" << endl;

    } // Fecha o for.

    } // Fecha o else.

    break; // Finaliza o case 2.

     case 3: 
        cout << "=== VERIFICAR SALDO ===" << endl;

    cout << "Digite o numero da conta: ";
    cin >> contaConsulta;

    encontrou = false;

    for (int i = 0; i < quantidadeContas; i++) {
         // i++ faz a posicao avançar uma por vez

        if (contaConsulta == numeroConta[i]) {
            posicao = i;
            encontrou = true;
            break;
        }
    }

    if (encontrou == true) {

            cout << "Conta encontrada!" << endl;
            cout << "Numero da conta: " << numeroConta[posicao] << endl;
            cout << "Titular: " << nomeCliente[posicao] << endl;
            cout << "CPF: " << cpf[posicao] << endl;
        
        if (tipoConta[posicao] == 1) {
        
        cout << "Tipo: conta Corrente" << endl;
    } else {
        cout << "Tipo: conta Poupanca" << endl;
        
    }    
    
        cout << "Saldo: R$ " << saldo[posicao] << endl;
        if (contaAtiva[posicao] == true) {
            cout << "Situacao: Ativa" << endl;
        } else {     
            cout << "Situacao: Inativa" << endl;
        }
          
  } else {
      cout << "Conta não encontrada!" << endl;
  }
        break;
        
        
     case 4:
        
    cout << "=== REALIZAR DEPOSITO ===" << endl;

    cout << "Digite o numero da conta: ";
    cin >> contaConsulta;

    encontrou = false;

    for (int i = 0; i < quantidadeContas; i++) {

        if (contaConsulta == numeroConta[i]) {
            posicao = i;
            encontrou = true;
            break;
        }
    }

    if (encontrou == true) {

        if (contaAtiva[posicao] == true) {

            cout << "Digite o valor do deposito: R$ ";
            cin >> valorDeposito;

            while (valorDeposito <= 0) {
                cout << "Valor invalido! Digite um valor positivo: R$ ";
                cin >> valorDeposito;
            }

            if (quantidadeMovimentacoes < MAX_MOVIMENTACOES) {

                saldo[posicao] += valorDeposito;

                contaMovimentacao[quantidadeMovimentacoes] = numeroConta[posicao];
                tipoMovimentacao[quantidadeMovimentacoes] = 'D';
                valorMovimentacao[quantidadeMovimentacoes] = valorDeposito;

                quantidadeMovimentacoes++;

                cout << "Deposito realizado com sucesso!" << endl;
                cout << "Novo saldo: R$ " << saldo[posicao] << endl;

            } else {
                cout << "Limite de movimentacoes atingido!" << endl;
            }

        } else {
            cout << "A conta esta inativa!" << endl;
        }

    } else {
        cout << "Conta nao encontrada!" << endl;
    }

    break;
    
     case 5: 
     
    cout << "=== REALIZAR SAQUE ===" << endl;

    cout << "Digite o numero da conta: ";
    cin >> contaConsulta;

    encontrou = false;

    for (int i = 0; i < quantidadeContas; i++) {
        if (contaConsulta == numeroConta[i]) {
            posicao = i;
            encontrou = true;
            break;
        }
    }

    if (encontrou == true) {
        if (contaAtiva[posicao] == true) {
            cout << "Digite o valor do saque: R$ ";
            cin >> valorDeposito;

            while (valorDeposito <= 0) {
                cout << "Valor invalido! Digite um valor positivo: R$ ";
                cin >> valorDeposito;
            }

            if (valorDeposito <= saldo[posicao]) {
                if (quantidadeMovimentacoes < MAX_MOVIMENTACOES) {
                    saldo[posicao] -= valorDeposito;

                    contaMovimentacao[quantidadeMovimentacoes] = numeroConta[posicao];
                    tipoMovimentacao[quantidadeMovimentacoes] = 'S';
                    valorMovimentacao[quantidadeMovimentacoes] = valorDeposito;

                    quantidadeMovimentacoes++;

                    cout << "Saque realizado com sucesso!" << endl;
                    cout << "Novo saldo: R$ " << saldo[posicao] << endl;
                } else {
                    cout << "Limite de movimentacoes atingido!" << endl;
                }
            } else {
                cout << "Saldo insuficiente!" << endl;
            }
        } else {
            cout << "A conta esta inativa!" << endl;
        }
    } else {
        cout << "Conta nao encontrada!" << endl;
    }

    break;
        
    case 6:
    cout << "=== REALIZAR TRANSFERENCIA ===" << endl;

    cout << "Digite o numero da conta de origem: ";
    cin >> contaConsulta;

    encontrou = false;

    for (int i = 0; i < quantidadeContas; i++) {
        if (contaConsulta == numeroConta[i]) {
            posicao = i;
            encontrou = true;
            break;
        }
    }

    cout << "Digite o numero da conta de destino: ";
    cin >> contaAlterar;

    encontrouDestino = false;

    for (int i = 0; i < quantidadeContas; i++) {
        if (contaAlterar == numeroConta[i]) {
            posicaoDestino = i;
            encontrouDestino = true;
            break;
        }
    }

    if (encontrou == true && encontrouDestino == true) {

        if (posicao != posicaoDestino) {

            if (contaAtiva[posicao] == true &&
                contaAtiva[posicaoDestino] == true) {

                cout << "Digite o valor da transferencia: R$ ";
                cin >> valorDeposito;

                while (valorDeposito <= 0) {
                    cout << "Valor invalido! Digite um valor positivo: R$ ";
                    cin >> valorDeposito;
                }

                if (valorDeposito <= saldo[posicao]) {

                    if (quantidadeMovimentacoes <= MAX_MOVIMENTACOES - 2) {

                    saldo[posicao] -= valorDeposito;
                    saldo[posicaoDestino] += valorDeposito;
                    contaMovimentacao[quantidadeMovimentacoes] = numeroConta[posicao];
                    tipoMovimentacao[quantidadeMovimentacoes] = 'S';
                    valorMovimentacao[quantidadeMovimentacoes] = valorDeposito;

                    quantidadeMovimentacoes++;

                    contaMovimentacao[quantidadeMovimentacoes] = numeroConta[posicaoDestino];
                    tipoMovimentacao[quantidadeMovimentacoes] = 'D';
                    valorMovimentacao[quantidadeMovimentacoes] = valorDeposito;

                    quantidadeMovimentacoes++;

                    cout << "Transferencia realizada com sucesso!" << endl;
                    cout << "Saldo da conta de origem: R$ " << saldo[posicao] << endl;
                    cout << "Saldo da conta de destino: R$ " << saldo[posicaoDestino] << endl;

                    } else {
                        cout << "Espaco insuficiente no historico de movimentacoes!" << endl;
                    }

                } else {
                    cout << "Saldo insuficiente!" << endl;
                }

            } else {
                cout << "Uma das contas esta inativa!" << endl;
            }

        } else {
            cout << "A conta de origem e destino nao podem ser iguais!" << endl;
        }

    } else {
        cout << "Conta de origem ou destino nao encontrada!" << endl;
    }

    break;
    
    case 7:
    
    cout << "=== EXTRATO BANCARIO ===" << endl;

    cout << "Digite o numero da conta: ";
    cin >> contaConsulta;

    encontrou = false;

    for (int i = 0; i < quantidadeContas; i++) {
        if (contaConsulta == numeroConta[i]) {
            posicao = i;
            encontrou = true;
            break;
        }
    }

    if (encontrou == true) {

        cout << "Conta: " << numeroConta[posicao] << endl;
        cout << "Titular: " << nomeCliente[posicao] << endl;
        cout << "Saldo atual: R$ " << saldo[posicao] << endl;

        cout << "=== MOVIMENTACOES ===" << endl;

        encontrouMovimentacao = false;

        for (int i = 0; i < quantidadeMovimentacoes; i++) {

            if (contaMovimentacao[i] == numeroConta[posicao]) {

                encontrouMovimentacao = true;

                if (tipoMovimentacao[i] == 'D') {
                    cout << "Entrada: R$ " << valorMovimentacao[i] << endl;
                } else if (tipoMovimentacao[i] == 'S') {
                    cout << "Saida: R$ " << valorMovimentacao[i] << endl;
                }
            }
        }

        if (encontrouMovimentacao == false) {
            cout << "Nenhuma movimentacao registrada." << endl;
        }

    } else {
        cout << "Conta nao encontrada!" << endl;
    }

    break;
    
case 8:
        cout << "Encerrando o GG BANK..." << endl;
        break;

    default:
        cout << "Opcao invalida!" << endl;
        break;

    } 

} while (opcao != 8); // Repete enquanto nao escolher sair

return 0;
} 
