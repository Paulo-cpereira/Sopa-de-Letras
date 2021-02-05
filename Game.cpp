#include "Game.h"
#include "Board.h"
#include <iostream>
#include <string>
#include "Char.h"
#include <time.h>
#include "windows.h" 


using namespace std;


Game::Game(int w, int h, string s, int _idade, int _dificuldade)
{
    Nome = s;
    idade = _idade;
    Difficulty = _dificuldade;
    if (Difficulty == 1) {
        Noob.set_nome(Nome);
        Noob.set_idade(idade);
        PlayBoard.Init(h, w, Noob.get_num_Words());
    }
    else if (Difficulty == 2) {
        Exp.set_nome(Nome);
        Exp.set_idade(idade);
        PlayBoard.Init(h, w, Exp.get_num_Words());
    }
	GameScore = 0;
    Ronda = 0;
}

Game::Game(int w, int h)
{
    Nome = "Player";
    cout << endl << "Introduza a idade: ";
    cin >> idade;

    cout << endl << "Introduza a dificuldade:" << endl << "1.Principiante" << endl << "2.Experiente" << endl;
    cout << "Opcao:";
    cin >> Difficulty;
    if (Difficulty == 1) {
        Noob.set_nome(Nome);
        Noob.set_idade(idade);
        PlayBoard.Init(h, w, Noob.get_num_Words());
    }
    else if (Difficulty == 2) {
        Exp.set_nome(Nome);
        Exp.set_idade(idade);
        PlayBoard.Init(h, w, Exp.get_num_Words());
    }
    GameScore = 0;
    Ronda = 0;
}

int Game::Play() {
    if (PlayBoard.get_remainingWords() <= 0) { return PlayBoard.get_remainingWords(); }

    int n_aux = 0;

    system("cls");
    if (Difficulty == 1) {
        for (int i = 0; i < Noob.get_num_Words(); i++) {
            n_aux = PlayBoard.get_value(i);
            PlayBoard.view_Info(n_aux);
        }
    }
    Ronda++;
    cout << "\t\t\t\t\t\t SOPA DE LETRAS " << endl << endl << endl;
    cout << "Jogada " << Ronda << endl;
    cout << "Restam encontrar " << PlayBoard.get_remainingWords() << " palavras..." << endl;

    PlayBoard.View();



    Word input;
    string aux1;


    cout << "Digite uma palavra: " << endl;
    cout << "ou" << endl;
    cout << "1.Guardar Jogo" << endl;
    cout << "2.Sair" << endl;
    cin >> aux1;

    if (aux1 == "1") {

    }

    if (aux1 == "2") {
        cout << endl;
        cout << "\t\t\t\t\t\tThanks for playing";
        cout << endl << endl << endl;
        Sleep(1000);
        exit(0);

    }



    input.set_Letters(aux1);


    input.upper((int)aux1.length());

    n_aux = -3;

    n_aux = PlayBoard.find(input.get_Letters());

    if (n_aux != -1 && n_aux != -2) {
        cout << endl << "Descobriu a palavra: " << input.get_Letters() << endl;
        PlayBoard.view_Info(n_aux);
        PlayBoard.less_remainingWords();
        GameScore += 3;
    }
    else if (n_aux == -2) {
    cout << "A palavra " << input.get_Letters() << " ja foi descoberta!" << endl;
    GameScore -= 1;
    }
    
    else if (n_aux == -1) {
        cout << "A palavra " << input.get_Letters() << " nao existe!" << endl;
        GameScore -= 3;
    }
    
    else if (n_aux == -3) 
        cout << "Erro!" << endl;
    
    Sleep(1000);
    return PlayBoard.get_remainingWords();
    
}

void Game::View()
{
    PlayBoard.View();
}

void Game::Run() {

    cout << "Bem Vindo " << Nome << "!!" << endl;
 //   Sleep(500);
    int a=0;
    do{
        a = Play();
    } while (Play() > 0);



        cout << endl << endl << endl;
        if (Difficulty == 1) { // So para efeitos de diversao
            if (GameScore < 0 && GameScore <= 5) {
                cout << "MAU!" << endl;
                cout << "O seu score foi de " << GameScore << " pontos!" << endl;
                Sleep(2000);
                system("pause");
            }
            else if (GameScore >= 6 && GameScore <= 9) {
                cout << "RAZOAVEL!" << endl;
                cout << "O seu score foi de " << GameScore << " pontos!" << endl;
                Sleep(2000);
                system("pause");
            }
            else if (GameScore >= 10 && GameScore <= 14) {
                cout << "BOM!" << endl;
                cout << "O seu score foi de " << GameScore << " pontos!" << endl;
                Sleep(2000);
                system("pause");
            }
            else if (GameScore == 15) {
                cout << "EXCELENTE!" << endl;
                cout << "O seu score foi de " << GameScore << " pontos" << endl;
                Sleep(2000);
                system("pause");
            }
        }
        
}