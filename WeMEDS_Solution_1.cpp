// Projeto Arrays, WeMEDS, Primeiro tópico: array.md, Dada uma lista ímpar de array feita por valores repetidos, achar o elemento sozinho
// Ex: Sendo o array A: A[0] = 9 A[1] = 3 A[2] = 9 A[3] = 3 A[4] = 9 A[5] = 7 A[6] = 9, o programa deve retornar 7

// Autor: João André Agustinho da Silva

#include <iostream>
#include <string>
using namespace std;

void solution(unsigned int array[], unsigned int ArraySize)
{
    for (unsigned int i = 0; i < ArraySize; ++i)
    {
        bool isAlone = true;
        for (unsigned int j = 0; j < ArraySize; ++j) {
            if (i == j) continue;
            if (array[i] == array[j]) isAlone = false;
        }

        if (isAlone) {
            cout << endl << "O valor " << to_string(array[i]) << ", no índice " << to_string(i) << ", está sem par!";
            return;
        }
    }
    cout << endl << "Nenhum valor sozinho encontrado!";
    return;
}

bool ValidateInput(int input, int minValue, int maxValue, bool oddAllowed)
{
    string _error = "";
    if (input < minValue) _error = "Valor abaixo do intervalo!";
    else if (input > maxValue) _error = "Valor acima do intervalo!";
    else if (!oddAllowed && input % 2 == 0) _error = "Valor não é ímpar!";

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
    int _input;

    cout << "Insira o tamanho da lista, deve ser ímpar e dentro do intervalo [1, 1000000]: ";
    do { cin >> _input; } while (ValidateInput(_input, 1, 1000000, false));
    ArraySize = _input;

    cout << "Insira os elementos da lista de tamanho " << to_string(ArraySize) << ", um por vez, devem estar no intervalo [1, 1000000000]:" << endl;
    unsigned int* array = new unsigned int[ArraySize];
    for (unsigned int i = 0; i < ArraySize; ++i)
    {
        cout << "Elemento " << to_string(i) << ": ";
        do { cin >> _input; } while (ValidateInput(_input, 1, 1000000000, true));
        array[i] = _input;
    }

    solution(array, ArraySize);
    delete[] array;
    return 0;
}