#include "function.cpp"
#include <unistd.h> // Include per getcwd
#include <map>

const int times = 1000; // 1000 tempi differenti

int main()
{

    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        std::cout << "Current working directory: " << cwd << std::endl;
    }
    else
    {
        perror("getcwd() error");
    }

    double num_test = 50.0; // 100 test
    int sizes[times];
    int index = 0;
    double tempo_QS = 0;
    double somma_QS = 0;
    double risultati_QS[times];

    string path = "INSERT YOUR PATH";

    ofstream output(path + "/best_case_RQS.csv", ios::out | ios::app); // per scrittura su file
    if (!output.is_open())
    {
        std::cerr << "Errore nell'aprire il file per la scrittura!" << std::endl;
        return 1; // Exit if the file cannot be opened
    }

    for (int n = 10; n <= 10000; n = n + 10) // avrò 1000 diversi tempi di esecuzione
    {
        sizes[index] = n;
        somma_QS = 0;
        srand(time(NULL));
        int *A = new int[n];
        int *Q = new int[n];

        for (int i = 0; i < 50; i++) // per ogni dim effettuo 100 test
        {
            int k = rand() % 100; // best_case: k<n

            for (int j = 0; j < n; j++) // creo vettore da ordinare
            {
                A[j] = rand() % (k + 1); // restituisce un valore nel range [0,k]
                                         // Q[j] = A[j];						// metto nel vettore di QS gli stessi elementi usati con CS
                                         // Q[j] = rand() % (k + 1);			//serve per testare QS, riempio vettore con valori tra 0 e k
            }

            if (n == 10)
            {
                cout << "A_iniziale: ";
                stampa(A, n);
            }

            // CountingSort(A, Q, n, k); // per fare worst case QS, Q sarà un vettore ordinato

            auto start_QS = chrono::high_resolution_clock::now();
            // QuickSort(A, 0, n - 1);
            // QuickSort(Q, 0, n - 1); // QS riceve un vettore già ordinato e posso confrontare con la versione randomizzata
            Randomized_QuickSort(A, 0, n - 1);
            auto end_QS = chrono::high_resolution_clock::now();
            somma_QS += chrono::duration_cast<chrono::nanoseconds>(end_QS - start_QS).count();

            if (n == 10)
            {
                cout << "B_ordinato: ";
                stampa(A, n);
            }
        }
        tempo_QS = somma_QS / num_test;
        output << n << "," << tempo_QS;
        output << endl;
        risultati_QS[index] = tempo_QS;

        index++; // se incremento index all'interno di [] da errore, ovviamente devo prima assegnare valore ad entrambi i vettori e poi incrementare

        delete[] A;
        delete[] Q;
    }

    output.close();

    return 0;
}
