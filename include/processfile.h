#ifndef processfile_h
#define processfile_h

#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include "guessgame.h"

class processfile{
    public:
        processfile();
        void initialize_infos(guessgame &g, int argc, char *argv[]);
        void save_score();

    private:
        guessgame * game;
        std::string palavras_filename;
        std::string scores_filename;
        
        void read_scores();
        void tokenize(std::string const &str, const char delim, std::vector<std::string> &out);

};

#endif 