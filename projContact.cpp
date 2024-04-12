#include <iostream>
#include <string>
#include <ctime> 
#include <sstream>

using namespace std;

class Data {
private:
    int dia, mes, ano;

public:
    Data(int d, int m, int a) : dia(d), mes(m), ano(a) {}

    int getDia() const { return dia; }
    int getMes() const { return mes; }
    int getAno() const { return ano; }
};

class Contato {
private:
    string email;
    string nome;
    string telefone;
    Data dtnasc;

public:
    Contato() : dtnasc(0, 0, 0) {}
    Contato(string em, string nm, string tel, Data dt) : email(em), nome(nm), telefone(tel), dtnasc(dt) {}

    // Getters
    string getEmail() const { return email; }
    string getNome() const { return nome; }
    string getTelefone() const { return telefone; }

    // Setter para a data de nascimento
    void setDataNascimento(Data dt) { dtnasc = dt; }

    // Método para calcular idade
    int idade() const {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        int anoAtual = 1900 + ltm->tm_year; 
        return anoAtual - dtnasc.getAno();
    }
};

// Função para aplicar a máscara de telefone
string aplicarMascaraTelefone(const string& telefone) {
    string telefoneFormatado;
    for (char c : telefone) {
        if (isdigit(c)) {
            telefoneFormatado += c;
        }
    }
    return telefoneFormatado;
}

int main() {
    Contato contatos[5];

    for (int i = 0; i < 5; ++i) {
        string email, nome, telefone;
        int dia, mes, ano;

        cout << "Digite o nome do contato " << i + 1 << ": ";
        getline(cin, nome);

        cout << "Digite o email do contato " << i + 1 << ": ";
        getline(cin, email);

        cout << "Digite o telefone do contato " << i + 1 << ": ";
        getline(cin, telefone);
        telefone = aplicarMascaraTelefone(telefone);

        cout << "Digite a data de nascimento do contato " << i + 1 << " (DD MM AAAA): ";
        cin >> dia >> mes >> ano;
        cin.ignore(); 

        Data dataNascimento(dia, mes, ano);

        contatos[i] = Contato(email, nome, telefone, dataNascimento);
    }

    for (int i = 0; i < 5; ++i) {
        cout << "Contato " << i + 1 << ":" << endl;
        cout << "Nome: " << contatos[i].getNome() << endl;
        cout << "Email: " << contatos[i].getEmail() << endl;
        cout << "Telefone: " << contatos[i].getTelefone() << endl;
        cout << "Data de Nascimento: " << contatos[i].getDataNascimento().getDia() << "/" 
                                        << contatos[i].getDataNascimento().getMes() << "/"
                                        << contatos[i].getDataNascimento().getAno() << endl;
        cout << "Idade: " << contatos[i].idade() << " anos" << endl << endl;
    }

    return 0;
}
