#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    ios::sync_with_stdio(false);

    // O primeiro parâmetro é definido na linha de comando da execução do gerador
    auto N = atoi(argv[1]);
    auto M = rnd.next(0.0, 20.0);

    ensuref(0 <= N and N <= 100, "N must be in range [0, 100]");

    cout << N << ' ' << M << '\n';

    for (int i = 0; i < N; ++i)
    {
        if (i)
            cout << ' ';

        auto x = rnd.next(0.0, 10.0);
        cout << x;
    }
    cout << '\n';

    /**
     * Segue mais uma série de exemplos de geração de entradas como referência. 

    // Sorteia um número inteiro aleatório entre 1 e N
    cout << rnd.next(1, N) << endl;

    // Sorteia um número real entre 0.0 e 10.0
    cout << rnd.next(0.0, 10.0) << endl;

    // Escolhe uma entre as 3 string abaixo
    cout << rnd.next("Abacaxi|Banana|Caju") << endl;

    // Gera uma string com tamanho de 1 a 20 caracteres maísculos, minúsculos ou dígitos
    cout << rnd.next("[A-Za-z0-9]{1,20}") << endl;

    // Encadeamentos de chamadas de rnd.next() num mesmo cout tem comportamento indefinido
    // e deve ser evitado
    cout << rnd.next(1) << rnd.next(2) << endl;

    // Chamadas com mesmo parâmetro de entrada gera sempre o mesmo teste
    // Amplie o número de parâmetros de entrada na chamada para maior variabilidade da saída
    // (mesmo que eles não sejam usandos no código do gerador
    auto M = atoi(argv[2]);

    // Sorteia um número inteiro entre 0 e M
    cout << rnd.next(M) << endl;

    vector<int> ns { 1, 2, 3, 4, 5 };

    // Embaralha os números do vetor
    shuffle(ns.begin(), ns.end());

    for (size_t i = 0; i < ns.size(); ++i)
        cout << ns[i] << (i + 1 == ns.size() ? "\n" : " ");

    // Escolhe um dentre os elementos do contêiner (vector ou string funcionam)
    string symbols { "+*-/" };
    cout << rnd.any(symbols.begin(), symbols.end()) << endl;

    *
    **/

    return 0;
}
