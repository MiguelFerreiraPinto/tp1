#include "../include/utils.h"

using namespace std;

int main (int argc, char* argv[]){
    if (argc < 2) {
        cerr << "Uso: " << argv[0] << " <arquivo_entrada>" << endl;
        cerr << "Exemplo: " << argv[0] << " arquivo.txt" << endl;
        return 1;
    }
    
    vector<Dado> dados;
    string filename = argv[1];
    readfile(dados, filename);
    sortVector(dados);
    printDados(dados);
    return 0;
}