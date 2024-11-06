#include "function.cpp"
#include <unistd.h> // Include per getcwd

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
    double somma_CS = 0;
    double tempo_CS = 0;
    double risultati_CS[times];
    // vettore dei risultati -> 100000/100 = 1000 dimensioni diverse, per ogni dim effettuo 100 test e prendo tempo medio

    string path = "INSERT YOUR PATH";

    ofstream output(path + "/worst_case_CS.csv", ios::out | ios::app); // per scrittura su file
    if (!output.is_open())
    {
        std::cerr << "Errore nell'aprire il file per la scrittura!" << std::endl;
        return 1; // Exit if the file cannot be opened
    }
    // output.open("best_case_CS.csv", ios::out | ios::app);

    for (int n = 10; n <= 10000; n = n + 10) // avrò 1000 diversi tempi di esecuzione
    {
        sizes[index] = n;
        somma_CS = 0; // azzero ogni volta che faccio dei test con una nuova dimensione
        int *A = new int[n];
        int *B = new int[n];
        srand(time(NULL));

        for (int i = 0; i < 50; i++) // per ogni dim effettuo 100 test
        {
            // int k = rand() % 100; // best_case: k<n
            int k = rand() % n + n; // worst_case: k>n

            for (int j = 0; j < n; j++) // creo vettore da ordinare
            {
                A[j] = rand() % (k + 1); // restituisce un valore nel range [0,k]
            }

            if (n == 10)
            {
                cout << "A_iniziale: ";
                stampa(A, n);
            }

            auto start_CS = chrono::high_resolution_clock::now();
            CountingSort(A, B, n, k);
            auto end_CS = chrono::high_resolution_clock::now();
            somma_CS += chrono::duration_cast<chrono::nanoseconds>(end_CS - start_CS).count();

            if (n == 10)
            {
                cout << "B_ordinato: ";
                stampa(B, n);
            }
        }

        tempo_CS = somma_CS / num_test; // come tempo di esecuzione prendo quello medio tra i 100 trovati
        output << n << "," << tempo_CS;
        output << endl;
        // cout << n;
        risultati_CS[index] = tempo_CS;

        index++; // se incremento index all'interno di [] da errore, ovviamente devo prima assegnare valore ad entrambi i vettori e poi incrementare

        delete[] A;
        delete[] B;
    }

    output.close();

    return 0;
}
