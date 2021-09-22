#ifndef score_h
#define score_h

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class score{
    private:
        std::string nome_user;
        std::vector<std::string> palavras_acertadas;
        int pontuacao;

    public:
        score(std::string nome, std::vector<std::string> palavras_acert, int pont);
        score(std::string nome, int pont);
        void print_score_infos();
        void save_scores_ofs(std::ofstream & ofs);
};

#endif 