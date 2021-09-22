#include "score.h"

using namespace std;

score::score(string nome, vector<string> palavras_acert, int pont){
    this->nome_user = nome;
    this->pontuacao = pont;
    for(int i=0; i<palavras_acert.size(); i++){
        this->palavras_acertadas.push_back(palavras_acert[i]);
    }
}

void score::print_score_infos(){
    cout << nome_user << " - " << "Pontuação: " << pontuacao << " - " << "Palavras acertadas: ";
    for(int i=0; i<palavras_acertadas.size(); i++)
        cout << palavras_acertadas[i] << " ";
    cout << endl;
}

void score::save_scores_ofs(ofstream & ofs){
    ofs << nome_user << ";";
    for(int i=0; i<palavras_acertadas.size(); i++){
        if(i != palavras_acertadas.size()-1)
            ofs << palavras_acertadas[i] << " ";
        else
            ofs << palavras_acertadas[i];
    }
    ofs << ";";
    ofs << pontuacao << endl;
}