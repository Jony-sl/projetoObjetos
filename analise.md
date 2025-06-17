# Análise orientada a objeto
> [!NOTE]
> <p>A <strong>análise</strong> orientada a objeto consiste na descrição do 
> problema a ser tratado, duas primeiras etapas da tabela abaixo, a definição de 
> casos de uso e a definição do domínio do problema.</p>

## Descrição Geral do domínio do problema

O proograma visa compilar informações a respeito da variação do valor de ativos financeiros, apresentando dados históricos e gráficos representativos.
Utilizarei a chave de API Tiingo disponível em <https://www.tiingo.com/>.
O sistema deverá oferecer uma seleção de ativos para o usuário que ao selecionar o ativo será encaminhado para um gráfico onde ele poderá selecionar o período que deseja visualizar as variações de mercado. O período padrão de visualização ao entrar no gráfico será o do dia atual. 

## Diagrama de Casos de Uso

<img src="https://github.com/user-attachments/assets/02eea329-8cb7-493f-9d59-d87e910f4479" 
     width="50%" 
     style="padding: 10px">

<p><strong>Caso I:</strong></p>
     <ul>Objetivo: Determinar ativo.</ul>
     <ul>Requisitos: - .</ul>
     <ul>Atores: Usuário.</ul>
     <ul>Pré-condição: - .</ul>
     <ul>Condição de entrada: O usuário seleciona a opção de ativo.</ul>
     <ul>Fluxo principal:
                       <ol> <ul>- O sistema apresenta uma lista de ativos.</ul>
                            <ul>- O usuário seleciona o ativo desejado.</ul></ol>

<p><strong>Caso II:</strong></p>
     <ul>Objetivo: Gerar gráfico solicitado.</ul>
     <ul>Requisitos: Determinar ativo.</ul>
     <ul>Atores: Data Source (DS).</ul>
     <ul>Pré-condição: Usuário ter selecionado o ativo.</ul>
     <ul>Condição de entrada: O sistema enviar a solicitação para o DS.
     <ul>Fluxo principal:
                      <ol><ul>- Sistema faz a solicitação de dados.</ul>
                          <ul>- Padrão de período será dia atual, sendo o período alterado apenas no Caso III.</ul>
                          <ul>- DS retorna dados do ativo solicitado.</ul>
                          <ul>- Sistema gera e exibe o gráfico.</li></ul></ol>

<p><strong>Caso III:</strong></p>
     <ul>Objetivo: Alterar o período do gráfico exibido.</ul>
     <ul>Requisitos: Tela do gráfico estar aberta.</ul>
     <ul>Atores: Usuário.</ul>
     <ul>Pré-condição: Ter gerado um gráfico.</ul>
     <ul>Condição de entrada: Usuário selecionar outro período.</ul>
     <ul>Fluxo principal:
                      <ol><ul>- Usuário seleciona o período desejado.</ul>
                          <ul>- Sistema retorna ao Caso II com um novo período.</ul></ol></ul>
 
## Diagrama de Domínio do problema

<img src="https://github.com/user-attachments/assets/3dfb6c84-0339-424d-aa92-68d2f3cddc5a" alt="Diagrama de domínio"
     width="50%" 
     style="padding: 10px">

<div align="center">

## Diagrama de Sequência


<img src="https://github.com/user-attachments/assets/45567248-659e-403c-af6a-aff98e38fe07" alt="Diagrama de domínio"
     width="50%" 
     style="padding: 10px">


[Retroceder](README.md) | [Avançar](projeto.md)

</div>
