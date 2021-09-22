# Jogo da Forca

Para compilar:

1. Entre na pasta de arquivo, no caso `data`:
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