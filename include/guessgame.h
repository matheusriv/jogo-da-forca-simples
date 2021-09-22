#ifndef guessgame_h
#define guessgame_h

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <random>
#include "score.h"
#include "body.h"

class guessgame{
    public:
        guessgame();
        void get_palavras_file(std::ifstream & ss);
        void add_scores(score novo_score);
        void save_score(std::ofstream & ofs);
        void initialize();
        void loop();

    private:
        int max_tentativas = 6;
        int int_game_over = 0;
        int pontuacao, num_of_wrong_guesses, matches;
        char letter;
        body corpo;
        std::vector<std::string> palavras;
        std::vector<std::string> palavras_sorteadas;
        std::vector<std::string> palavras_acertadas;
        std::string palavra_rodada;
        std::string choice;
        std::vector<score> scores;

        void random_word();
        void word_guessing_game();
        void process_action();
        int letter_fill(char guess, std::string secretword, std::string & guessword);
        bool search_palavras_sorteadas(std::string word);
        void show_scores();

};

#endif 