// Projeto Arrays, WeMEDS, Segundo tópico: euclidean.md, Sendo um array, começando em zero, percorrendo o array com um offset, contar as vezes que isso é possível antes de repetir um índice já passado
// Ex: Sendo array de tamanho N=10 e espaçamento M=4, a iteração da lista com offset será 0,4,8,2,6 resultando em 5 iterações

// Autor: João André Agustinho da Silva

#include <iostream>
#include <string>
using namespace std;

void solution(unsigned int ArraySize, unsigned int ArrayOffset)
{
    bool* array = new bool[ArraySize];
    fill_n(array, ArraySize, 1);
    int i = 0, cnt = 0;

    while (array[i]) {
        array[i] = 0;
        i += ArrayOffset;
        ++cnt;

        while (i >= ArraySize) i -= ArraySize;
    }
    cout << "A quantidade de chocolates comidos é " << to_string(cnt) << "!";
    delete[] array;
    return;
}

bool ValidateInput(int input, int minValue)
{
    string _error = "";
    if (input < minValue) _error = "Valor deve ser maior que zero!";

    if (_error != "") {
        cout << _error << " Insira outro valor!" << endl;
        return 1;
    }
    return 0;
}

int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");

    unsigned int ArraySize = 0;
    unsigned int ArrayOffset = 0;
    int _input = 0;

    cout << "Insira o tamanho da lista: ";
    do { cin >> _input; } while (ValidateInput(_input, 1));
    ArraySize = _input;

    cout << "Insira o espaçamento para a iteração: ";
    do { cin >> _input; } while (ValidateInput(_input, 1));
    ArrayOffset = _input;

    solution(ArraySize, ArrayOffset);
    return 0;
}