#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Produto{
    private:
        static int codigo_atual;
        int codigo;
        string nome;
        double preco;

    public:
        ~Produto();
        Produto(string _nome, double _preco);
        int getCodigo();
        string getNome();
        double getPreco();
        void setPreco(double _preco);
};

    // Inicializa o código_atual do produto
    int Produto::codigo_atual = 0;

    Produto :: ~Produto() {
        
    }
    Produto :: Produto(string _nome, double _preco){
        codigo_atual++;
        codigo = codigo_atual;
        nome = _nome;
        preco = _preco;
    };
    int Produto :: getCodigo(){
        return codigo;
    };
    string Produto :: getNome(){
        return nome;
    };
    double Produto :: getPreco(){
        return preco;
    };
    void Produto :: setPreco(double _preco){
        preco = _preco;
    };


    int main(){
        //Testes
        Produto p1("Maçã", 2.5);
        Produto p2("Arroz", 10.0);
        Produto p3("Leite", 4.0);
        Produto p4("Café", 8.99);


        cout << fixed << setprecision(2);
        cout << "Produto " << p1.getCodigo() << ":" << "\t" << p1.getNome() << "\t"  << p1.getPreco() << endl;
        cout << "Produto " << p2.getCodigo() << ":" << "\t" << p2.getNome() << "\t"  << p2.getPreco() << endl;
        cout << "Produto " << p3.getCodigo() << ":" << "\t" << p3.getNome() << "\t"  << p3.getPreco() << endl;
        cout << "Produto " << p4.getCodigo() << ":" << "\t" << p4.getNome() << "\t"  << p4.getPreco() << endl;

    return 0;
}