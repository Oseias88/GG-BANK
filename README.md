# GG BANK

Projeto acadêmico desenvolvido em C++ para a disciplina de Análise e Desenvolvimento de Sistemas (ADS).

O GG BANK é um sistema bancário desenvolvido por etapas, com o objetivo de aplicar conceitos de programação, estruturas de dados, lógica de programação e persistência de dados.

## Etapa 1 – Gerenciamento de contas

Funcionalidades implementadas:
- Cadastro de contas bancárias.
- Consulta de contas.
- Consulta de saldo.
- Alteração do tipo de conta.
- Ativação e desativação de contas.

## Etapa 2 – Movimentações bancárias

Funcionalidades implementadas:
- Cadastro de até 100 contas.
- Listagem de contas cadastradas.
- Consulta de dados bancários.
- Realização de depósitos.
- Realização de saques com verificação de saldo.
- Transferências entre contas.
- Registro de movimentações bancárias.
- Consulta de extrato por conta.

O sistema utiliza vetores para armazenar os dados das contas e o histórico de movimentações durante a execução.

## Etapa 3 – Persistência de dados em arquivos

Funcionalidades implementadas:
- Salvamento dos dados das contas no arquivo `contas.txt`.
- Salvamento do histórico de movimentações no arquivo `movimentacoes.txt`.
- Recuperação automática das contas e movimentações ao iniciar o programa.
- Atualização dos arquivos após cadastros, depósitos, saques e transferências.
- Manutenção do histórico de movimentações entre execuções do programa.

Foram utilizadas as funções `salvarContas()`, `carregarContas()`, `salvarMovimentacoes()` e `carregarMovimentacoes()), com recursos da biblioteca `fstream`.

## Tecnologias utilizadas

- C++
- Biblioteca iostream
- Biblioteca string
- Biblioteca fstream
- Online GDB

## Estrutura do projeto

- `Etapa-1/main.cpp`: código-fonte da primeira etapa.
- `Etapa-2/main.cpp`: código-fonte da segunda etapa.
- `Etapa-3/main.cpp`: código-fonte da terceira etapa.

## Desenvolvedor

Projeto acadêmico desenvolvido como parte do curso de Análise e Desenvolvimento de Sistemas.
