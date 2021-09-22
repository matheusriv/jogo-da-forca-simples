#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "processfile.h"
#include "score.h"
#include "guessgame.h"

using namespace std;

int main(int argc, char *argv[]) {
    processfile pfile;
    guessgame game;

    pfile.initialize_infos(game, argc, argv);
    game.loop();
    pfile.save_score();

    return 0;
}