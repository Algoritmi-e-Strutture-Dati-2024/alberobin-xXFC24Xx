#include <iostream>

template <typename T>
class Albero_Binario {
private:
    T nodi[100];

public:
    Albero_Binario() {
        for (int i = 0; i < 100; ++i) {
            nodi[i] = -1; 
        }
    }

    bool Albero_Vuoto() const {
        return nodi[0] == -1;
    }

    void Ins_Radice(const T& valore) {
        nodi[0] = valore;
    }

    T Radice() const {
        return nodi[0];
    }

    bool is_Foglia(int indice) const {
        return (2 * indice + 1 >= 100 || nodi[2 * indice + 1] == -1) && 
               (2 * indice + 2 >= 100 || nodi[2 * indice + 2] == -1);
    }

    int Figlio_Sinistro(int indice) const {
        return 2 * indice + 1 < 100 ? nodi[2 * indice + 1] : -1;
    }

    int Figlio_Destro(int indice) const {
        return 2 * indice + 2 < 100 ? nodi[2 * indice + 2] : -1;
    }

    void ins_Figlio_Sinistro(int indice, const T& valore) {
        if (2 * indice + 1 < 100 && nodi[2 * indice + 1] == -1) {
            nodi[2 * indice + 1] = valore;
        }
    }

    void ins_Figlio_Destro(int indice, const T& valore) {
        if (2 * indice + 2 < 100 && nodi[2 * indice + 2] == -1) {
            nodi[2 * indice + 2] = valore;
        }
    }

    void Rimuovi(int indice) {
        if (is_Foglia(indice)) {
            nodi[indice] = -1;
        }
    }

    void Stampa() const {
        for (int i = 0; i < 100; ++i) {
            if (nodi[i] != -1) {
                std::cout << "questa è la posizione " << i 
                          << ", questo è il valore: " << nodi[i] 
                          << ", questo è il figlio sinistro: " << Figlio_Sinistro(i) 
                          << ", questo è il figlio destro: " << Figlio_Destro(i) 
                          << std::endl;
            }
        }
    }
};

int main() {
    Albero_Binario<int> albero;

    albero.Ins_Radice(10);
    albero.ins_Figlio_Sinistro(0, 20);
    albero.ins_Figlio_Destro(0, 30);

    std::cout << "Questo è l'albero iniziale:" << std::endl;
    albero.Stampa();

    albero.Rimuovi(2);
    std::cout << "Questo è l'albero dopo la rimozione di una foglia:" << std::endl;
    albero.Stampa();

    return 0;
}
