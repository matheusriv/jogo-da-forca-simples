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
    ofs << nome_user << endl;
    ofs << palavras_acertadas.size() << endl;
    for(int i=0; i<palavras_acertadas.size(); i++){
        ofs << palavras_acertadas[i] << endl;
    }
    ofs << pontuacao << endl;
}

bool score::get_nome(string nome){
    if(nome == nome_user)
        return true;
    return false;
}

void score::edit_infos(std::vector<std::string> palavras_acert, int pont){
    this->pontuacao = pont;
    for(int i=0; i<palavras_acert.size(); i++){
        this->palavras_acertadas.push_back(palavras_acert[i]);
    }
}