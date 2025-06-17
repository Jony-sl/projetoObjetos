# Projeto orientado a objeto

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
     </ul>
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

## Diagrama de Sequência

<p align="left">
    <img src="https://github.com/user-attachments/assets/45567248-659e-403c-af6a-aff98e38fe07" alt="Diagrama de domínio"
     width="50%" 
     style="padding: 10px">
</p>


<div align="center">

[Retroceder](analise.md) | [Avançar](implementacao.md)

</div>
