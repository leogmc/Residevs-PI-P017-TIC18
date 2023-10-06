#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

class Produto {
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

class CarrinhoDeCompras
{
    private:
        vector<Produto> carrinho;
        vector<int> quantidade;
    public:
        ~CarrinhoDeCompras();
        CarrinhoDeCompras();
        void adicionaProduto(Produto& _produto, int _quantidade);
        void removeProduto(int codigo, int _quantidade);
        double calculaTotal(vector<Produto> carrinho);

    
};

CarrinhoDeCompras::CarrinhoDeCompras() 
{
}

CarrinhoDeCompras::~CarrinhoDeCompras()
{
}

void CarrinhoDeCompras::adicionaProduto(Produto& _produto, int _quantidade)
{
    carrinho.push_back(_produto);
    quantidade.push_back(_quantidade);

}

void CarrinhoDeCompras::removeProduto(int _codigo, int _quantidade)
{
    int tamanho = carrinho.size();

    for (int i = 0; i < tamanho; i++) {
        if (carrinho[i].getCodigo() == _codigo) {
            if (quantidade[i] >= _quantidade) {
                quantidade[i] -= _quantidade;
                if (quantidade[i] == 0) {
                    carrinho.erase(carrinho.begin() + i);
                    quantidade.erase(quantidade.begin() + i);
                }
                return;
            } else {
                cout << "Quantidade insuficiente no carrinho." << endl;
                return;
            }
        }
    }
    cout << "Produto não encontrado no carrinho." << endl;
}

double CarrinhoDeCompras::calculaTotal(vector<Produto> carrinho) {
    double total = 0;

    for (Produto produto : carrinho)
    {
        total += produto.getPreco();
    }

    return total;
}

int main(){
    //Testes
    CarrinhoDeCompras carrinho;
    vector<Produto> produtos;

    Produto p1("Maçã", 2.5);
    Produto p2("Arroz", 10.0);
    Produto p3("Leite", 4.0);
    Produto p4("Café", 8.99);

    produtos.push_back(p1);
    produtos.push_back(p2);
    produtos.push_back(p3);
    produtos.push_back(p4);

    cout << "Total: " <<  carrinho.calculaTotal(produtos) << endl;


    cout << fixed << setprecision(2);
    cout << "Produto " << p1.getCodigo() << ":" << "\t" << p1.getNome() << "\t"  << p1.getPreco() << endl;
    cout << "Produto " << p2.getCodigo() << ":" << "\t" << p2.getNome() << "\t"  << p2.getPreco() << endl;
    cout << "Produto " << p3.getCodigo() << ":" << "\t" << p3.getNome() << "\t"  << p3.getPreco() << endl;
    cout << "Produto " << p4.getCodigo() << ":" << "\t" << p4.getNome() << "\t"  << p4.getPreco() << endl;

    return 0;
}
