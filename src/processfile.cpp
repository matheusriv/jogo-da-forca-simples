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
        string count_user, line;
        vector<string> lines, out, palavras;

        getline(ifs_scores, count_user);
        
        for(auto i = 0; i<stoi(count_user); i++) {
            getline(ifs_scores, line);
            lines.push_back(line);
        }

        for(auto i = 0; i<lines.size(); i++) {
            tokenize(lines[i], ';', out);
            for(auto j = 0; j<out[1].size(); j++){
                if(isspace(out[1][j])){ 
                    tokenize(out[1], ' ', palavras);
                    //cout << out[1] << " tem espaco em branco" << endl;
                    break;
                }
                if(j == out[1].size()-1){
                    //cout << out[1] << " nao tem espaco em branco" << endl;
                    palavras.push_back(out[1]);
                }
            }
            score novo_score(out[0], palavras, stoi(out[2]));
            game->add_scores(novo_score);
            out.clear();
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

void processfile::tokenize(std::string const &str, const char delim,
            std::vector<std::string> &out){
    size_t start;
    size_t end = 0;
 
    while ((start = str.find_first_not_of(delim, end)) != std::string::npos){
        end = str.find(delim, start);
        out.push_back(str.substr(start, end - start));
    }
}