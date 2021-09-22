#include "guessgame.h"

using namespace std;

guessgame::guessgame(){}

void guessgame::get_palavras_file(std::ifstream & ss){
    string word;
    while(ss >> word){
        palavras.push_back(word);
    }
}

void guessgame::initialize(){
    pontuacao = 0;

    cout << "\n---- Bem vindo ----" << endl
         << "-- Jogo da Forca --" << endl
         << " Você tem 6 tentativas para adivinhar a palavra" << endl
         << " Digite 'i' para iniciar o jogo ou 'r' para rever os scores anteriores! \n";
    
    while(true){
        cin>>std::ws>>choice;
        if(choice == "i" || choice == "r")
            break;
    }

    if(choice == "r"){ 
        show_scores();
    }

}

void guessgame::word_guessing_game(){
    if(palavras.size() == palavras_sorteadas.size()){ 
        cout << "Todas palavras disponíveis já utilizadas" << endl
            << "Game over" << endl;
        int_game_over = 1;
        return;
    }

    num_of_wrong_guesses = 0;
    int i = 0;

    string unknown(palavra_rodada.length(), ('_')); 

    while(num_of_wrong_guesses < max_tentativas){
        cout << "\nPontos: " << pontuacao << endl;

        if(num_of_wrong_guesses > 0){
            vector<string> c = corpo.get_body(num_of_wrong_guesses);
            for(int i = 0; i<c.size(); i++) {
                cout << c[i] << endl;
            }
        }

        cout << unknown; 
        cout << "\nQual seu palpite? ";
        cin >> letter;      

        matches = letter_fill(letter, palavra_rodada, unknown);

        if(matches == 0){
            cout << "Letra não está na palavra!" << endl;
            pontuacao -= 1;
            num_of_wrong_guesses++;
        }
        else if(matches == -1){
            cout << "Você já adivinhou essa letra!" << endl;
            pontuacao -= 1;
            num_of_wrong_guesses++;
        }
        else{
            cout << "Letra está na palavra!" << endl;
            for(int j=0; j<matches; j++) 
                pontuacao += 1;
            if(i == 0) pontuacao++;
        }          

        if(palavra_rodada != unknown){
            cout << "\nVocê tem " << max_tentativas - num_of_wrong_guesses 
            << " tentativas restantes." << endl; 
        }
        else{
            pontuacao += 2;
            if(num_of_wrong_guesses == 0) pontuacao += 1;
            palavras_acertadas.push_back(palavra_rodada);
            cout << "\nVocê acertou a palavra '" << palavra_rodada << "'!" << endl;
            cout << "Pontuação: " << pontuacao << endl;
            break;
        }
        i++;
    }

    if(num_of_wrong_guesses == max_tentativas){
        cout << "\nVocê perdeu a palavra era " << palavra_rodada << "!" << endl;
    }
}

void guessgame::process_action(){
    cout << "\nVocê gostaria de jogar outra rodada?" << endl;
    cout << "Digite 's' para continuar ou 'p' para parar: "; 

    while(true){
        cin>>std::ws>>choice;
        if(choice == "s" || choice == "p")
            break;
    }

    if(choice == "s"){
        return;
    }
    else{
        cout << "Digite o seu nome: " << endl;
        cin >> choice;
        auto it = search_scores_nome(choice);
        if(it != scores.end()){
            //cout << "score com esse nome ja cadastrado\n";
            it->edit_infos(palavras_acertadas, pontuacao);
        }
        else{
            score novo_score(choice, palavras_acertadas, pontuacao);
            scores.push_back(novo_score);
        }
        cout << "Saindo do jogo...\n";
        int_game_over = 1;
    }
}

void guessgame::loop(){
    initialize();
    while(int_game_over == 0){
        random_word();
        word_guessing_game();
        if(int_game_over == 1) break;
        process_action();
    } 
}

void guessgame::random_word(){
    while(true){
        std::random_device random_device;
        std::mt19937 engine{random_device()};
        std::uniform_int_distribution<int> dist(0, palavras.size()-1);
        string random = palavras[dist(engine)];

        if(!search_palavras_sorteadas(random)){ 
            //cout << "palavra sorteada: " << random << endl;
            palavras_sorteadas.push_back(random);
            palavra_rodada = random;
            break;
        }
    } 
}

int guessgame::letter_fill(char letter_guess, string palavra_rodada, string & unknown){ 
    int matches = 0;
    for(int i = 0; i<palavra_rodada.length(); i++){
        if(letter_guess == unknown[i])
            return -1;
        if(letter_guess == palavra_rodada[i]){
            unknown[i] = letter_guess;
            matches++;
        }
    }

    return matches;
}

void guessgame::save_score(ofstream & ofs){
    ofs << scores.size() << endl; 
    for(auto it = scores.begin(); it != scores.end(); it++) {
        it->save_scores_ofs(ofs);
    }
}

void guessgame::show_scores(){
    if(scores.size() == 0)
        cout << "Sem scores anteriores!" << endl;
    else{
        cout << "--- Scores Anteriores ---" << endl;
        for(int i=0; i<scores.size(); i++)
            scores[i].print_score_infos();
        cout << "------------------------\n";
    }
}

void guessgame::add_scores(score novo_score){
    scores.push_back(novo_score);
}

bool guessgame::search_palavras_sorteadas(string word){
    if(std::find(palavras_sorteadas.begin(), palavras_sorteadas.end(), word) != palavras_sorteadas.end()){
        return true;
    }
    else{
        return false;
    }
}

std::vector<score>::iterator guessgame::search_scores_nome(string nome){
    auto it = std::find_if(scores.begin(), scores.end(), 
                            [&](score entrada){ 
                                    return entrada.get_nome(nome);
                                });

    return it;
}