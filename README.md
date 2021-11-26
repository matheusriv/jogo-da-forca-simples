# Jogo da Forca

Este projeto é um jogo da forca simples. O usuário tenta adivinhar a palavra adivinhando letras diferentes, que então aparecem nos espaços apropriados da palavra conforme o usuário adivinha as palavras corretas. O usuário tem seis tentativas para adivinhar a palavra. A cada erro do usuário um pedaço do corpo enforcado é desenhado. O usuário possui uma pontuação, ao acertar uma letra ele ganha um ponto, se a letra se repetir ele vai ganhar pontuação na quantidade de vezes que a letra se repete. Se o usuário adivinhar corretamente a palavra ele ganha dois pontos, se acertar a palavra sem cometer nenhum erro ganha um ponto extra. 

As palavras para adivinhar vem de um arquivo de texto que deve ser passado na linha de comando e a pontuação do usuário é salva num arquivo de texto que também deve ser passado na linha de comando. A cada nova partida, o jogo pergunta se o usuário deseja prosseguir ou encerrar o jogo, quando se decide encerrar o programa pede o nome do usuário e em seguida salva o nome, pontuação e palavras acertadas do usuário no arquivo de texto do score.


Para compilar:

1. Entre na pasta `build`:
```
cd build
```
2. Execute os comandos do `cmake` para gerar os arquivos intermediários e o executável dentro de `build`.
```
cmake ..
cmake --build .
```
Isso criará um executável dentro de `build` chamado de `jogoforca`.

Logo após a compilação, para executar o programa gerado use os comandos:

```
./jogoforca arquivo_palavras.txt arquivo_score.txt
```

Utilizando os arquivos da pasta data, por exemplo:

```
./jogoforca ../data/palavras.txt ../data/score.txt
```
