// Projeto Arrays, WeMEDS, Segundo t�pico: euclidean.md, Sendo um array, come�ando em zero, percorrendo o array com um offset, contar as vezes que isso � poss�vel antes de repetir um �ndice j� passado
// Ex: Sendo array de tamanho N=10 e espa�amento M=4, a itera��o da lista com offset ser� 0,4,8,2,6 resultando em 5 itera��es

// Autor: Jo�o Andr� Agustinho da Silva

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
    cout << "A quantidade de chocolates comidos � " << to_string(cnt) << "!";
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

    cout << "Insira o espa�amento para a itera��o: ";
    do { cin >> _input; } while (ValidateInput(_input, 1));
    ArrayOffset = _input;

    solution(ArraySize, ArrayOffset);
    return 0;
}