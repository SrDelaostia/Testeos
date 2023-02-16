/* Se desea desarrollar un juego para adivinar palabras las cuales deberán ser generadas de forma aleatoria tomando en
cuenta que la longitud de las palabras representa los niveles de dificultad del juego, el usuario podrá seleccionar la
dificultad del juego y adivinar la palabra. El programa podrá generar número de pistas según el nivel del juego, el jugador
tendrá un número determinado de vidas según cada nivel de dificultad y se restará cada vez que no adivine una palabra, las
pistas se restarán del número de pistas generadas según el nivel, si el jugador gana se le brindará una vida extra si sigue
jugando, al finalizar el juego deberá generar un fichero con el alias del jugador y la puntuación alcanzada. */

#include <iostream>
#include <fstream>
#include <time.h>
#include <list>

using namespace std;

class Jugador{
    private:
    string name;
    string word;
    int lvl;
    int life;
    int extraLifes;
    int points;
    int numClues;

    public:
    //constructor
    Jugador();
    Jugador(string, string, int, int, int, int, int);

    //Metodos
    void GenerarPalabra(int difficulty);
    void obtenerPuntajes();
    void generarNumVidas();
    void generarVidasExtras();
    void generarPistas();

    //getters

};

Jugador::Jugador(){}

Jugador::Jugador(string name, string word, int lvl, int life, int extraLifes, int points, int numClues){
    this->name = name;
    this->word = word;
    this->lvl = lvl;
    this->extraLifes = extraLifes;
    this->points = points;
    this->numClues = numClues;
}

void Menu();
void dificultad();
void Jugar(string word, int vidas);
void agregarPalabras();

void Jugador::GenerarPalabra(int difficulty){
    ifstream file;
    string nameFile, word;
    int selection, i = 0, vidas;

    if(difficulty == 1){
        vidas = 6;
    }
    else if(difficulty = 2){
        nameFile = "Medio.txt";
    }
    else{
        nameFile = "Dificil.txt";
    }

    file.open("Facil.txt", ios::in);

    if(file.fail()){
        cout <<"\nError al abrir el archivo\n";
    }
    else{
        srand(time(NULL));

        selection = 1 + rand()%(10);

        while(!file.eof() && i != selection){
            getline(file, word);
            
            cout << word << endl;

            i++;
        }

        file.close();

        system("pause");
        system("cls");
        Jugar(word, vidas);
    }
}


int main(){

    Menu();

    return 0;
}

void Menu(){
    int option;
    bool loop = true;

    do{
        cout <<"\n---------- Menu ----------\n";
        cout <<"1. Iniciar partida\n";
        cout <<"2. Agregar palabras\n";
        cout <<"3. \n";
        cout <<"4. \n";
        cout <<"5. Salir\n";
        cout <<"Opcion: "; cin >> option;

        switch(option){
            case 1: system("cls"); dificultad(); break;

            case 2: agregarPalabras(); break;

            case 5: loop = false; break;
            default: cout <<"\nIngrese una opcion valida\n";
        }
    }while(loop);
}

void dificultad(){
    int difficulty;
    string name;
    Jugador datos;

    do{
        cout <<"\nSeleccione la dificultad:\n";
        cout <<"1. Facil\n2. Medio\n3. Dificil\n4. Regresar al Menu principal\n";
        cout <<"Opcion: "; cin >> difficulty;

        switch(difficulty){
        case 1: cin.ignore();
                cout <<"\nIngrese su nombre: "; getline(cin ,name);
                datos.GenerarPalabra(difficulty); return;

        case 4: system("cls"); break;

        default: cout <<"\nIngrese una opcion valida\n"; break;
        }
    }while(difficulty != 4);
}

void Jugar(string word, int vidas){
    string word2, palabraAdivinando = "_ _ _ _";

    do{
        cout << palabraAdivinando << endl;
        cout <<"\nIngrese una letra: "; cin >> word2;

        for(int i = 0; i <= word.length(); i++){
            if(word2[0] == word[i]){
                palabraAdivinando[i] = word2[0];
            }
            else{
                vidas--;
            }
        }

    }while(vidas != 0);
}

void agregarPalabras(){
    ofstream file;
    string palabra;

    file.open("Facil.txt", ios::out | ios::app);

    cin.ignore();
    cout <<"\nIngrese una palabra de 4 letras\n"; getline(cin, palabra);

    if(file.fail()){
        cout <<"\nNo se pudo abrir el fichero\n";
    }
    else{
        file << palabra << endl;

        cout <<"\nSe agrego la palabra al fichero\n";
    }

    file.close();
}