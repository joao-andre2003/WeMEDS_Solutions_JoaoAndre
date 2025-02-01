// Projeto Arrays, WeMEDS, Segundo tópico: distinct.md, dado um array, mostrar a quantidade de valores distintos
// Ex: Sendo o array A: A[0] = 2 A[1] = 1 A[2] = 1 A[3] = 2 A[4] = 3 A[5] = 1, o programa deve retornar 3, pois os valores distintos são 1,2 e 3

// Autor: João André Agustinho da Silva

#include <iostream>
#include <string>
using namespace std;

void solution(int array[], unsigned int ArraySize)
{
    int* distinctArray = new int[ArraySize];
    unsigned int distinctArray_cnt = 0;

    for (unsigned int i = 0; i < ArraySize; ++i)
    {
        bool notRepeated = true;
        for (unsigned int j = 0; j < distinctArray_cnt; ++j)
            if (array[i] == distinctArray[j]) notRepeated = false;

        if (notRepeated)
            distinctArray[distinctArray_cnt++] = array[i];
    }
    cout << endl << "O array tem " << to_string(distinctArray_cnt) << " valores distintos!";
    delete[] distinctArray;
    return;
}

bool ValidateInput(int input, int minValue, int maxValue)
{
    string _error = "";
    if (input < minValue) _error = "Valor abaixo do intervalo!";
    else if (input > maxValue) _error = "Valor acima do intervalo!";

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

    cout << "Insira o tamanho da lista, deve ser ímpar e dentro do intervalo [1, 100000]: ";
    do { cin >> _input; } while (ValidateInput(_input, 1, 100000));
    ArraySize = _input;

    cout << "Insira os elementos da lista de tamanho " << to_string(ArraySize) << ", um por vez, devem estar no intervalo [-1000000, 1000000]:" << endl;
    int* array = new int[ArraySize];
    for (unsigned int i = 0; i < ArraySize; ++i)
    {
        cout << "Elemento " << to_string(i) << ": ";
        do { cin >> _input; } while (ValidateInput(_input, -1000000, 1000000));
        array[i] = _input;
    }

    solution(array, ArraySize);
    delete[] array;
    return 0;
}