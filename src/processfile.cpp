#include "processfile.h"

using namespace std;

processfile::processfile(){}

void processfile::initialize_infos(guessgame &g, int argc, char *argv[]){
    this->game = &g;

    if(argc < 3){
        cerr << ">>> Sem arquivo(s)!\n" <<
                ">>> Simulação Falhou!" << endl;
        exit(1);
    }

    palavras_filename = argv[1];
    scores_filename = argv[2];

    ifstream ifs_palavras(palavras_filename);
    ifstream ifs_scores(scores_filename);

    if(!ifs_palavras || !ifs_scores){
        cerr << ">>> ERRO, arquivo não foi aberto!" << endl;
        exit(1);
    }

    game->get_palavras_file(ifs_palavras);
    
    //ler scores
    if(ifs_scores.peek() != ifstream::traits_type::eof()) {
        string count_user, nome_user, count_words, word, pont;
        vector<string> palavras;

        getline(ifs_scores, count_user);
        
        for(auto i = 0; i<stoi(count_user); i++) {
            getline(ifs_scores, nome_user);
            getline(ifs_scores, count_words);
            for(auto j=0; i<stoi(count_words); i++) {
                getline(ifs_scores, word);
                palavras.push_back(word);
            }
            getline(ifs_scores, pont);
            score novo_score(nome_user, palavras, stoi(pont));
            game->add_scores(novo_score);
            palavras.clear();
        }
    }

}

void processfile::save_score(){
    ofstream ofstream_scores(scores_filename);

    if(!ofstream_scores) {
        cerr << "Erro ao salvar usuários! " << endl;
        return; 
    }

    game->save_score(ofstream_scores);

    ofstream_scores.close();

}

/*void processfile::tokenize(std::string const &str, const char delim,
            std::vector<std::string> &out){
    size_t start;
    size_t end = 0;
 
    while ((start = str.find_first_not_of(delim, end)) != std::string::npos){
        end = str.find(delim, start);
        out.push_back(str.substr(start, end - start));
    }
}*/