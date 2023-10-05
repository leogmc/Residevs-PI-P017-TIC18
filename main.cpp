#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class Ponto {
private:
    double x;
    double y;

public:
    Ponto(double _x = 0, double _y = 0);
    double getX() ;
    double getY() ;
    void setCoordenadas(double _x, double _y);
    double calcularDistancia() ;
    ~Ponto();
};

Ponto::Ponto(double _x, double _y) {
    x = _x;
    y = _y;
}

double Ponto::getX() {
    return x;
}

double Ponto::getY()  {
    return y;
}

void Ponto::setCoordenadas(double _x, double _y) {
    x = _x;
    y = _y;
}

double Ponto::calcularDistancia()  {
    return sqrt(x * x + y * y); 
}

Ponto::~Ponto() {}

int main() {

    Ponto p1(3, 4);
    double distancia1 = p1.calcularDistancia();//valor ja inserido classe já instanciad em x= 0 e y = 0, novo objeto novo valor x =3 e y = 4;
    cout << "A distância do ponto (" << p1.getX() << ", " << p1.getY() << ") até a origem é aproximadamente " << fixed << setprecision(2) << distancia1 << "." << endl;

    Ponto p2(-2, 7);
    p2.setCoordenadas(1, 1);
    double distancia2 = p2.calcularDistancia();
    cout << "A distância do ponto (" << p2.getX() << ", " << p2.getY() << ") até a origem é aproximadamente " << fixed << setprecision(2) << distancia2 << "." << endl;

    Ponto p3(0, 3);
    Ponto p4(4, 0);
    double distancia_p3 = p3.calcularDistancia();
    double distancia_p4 = p4.calcularDistancia();
    cout << "A distância do ponto (" << p3.getX() << ", " << p3.getY() << ") até a origem é " << distancia_p3 << " e do ponto (" << p4.getX() << ", " << p4.getY() << ") até a origem é " << setprecision(2)<< distancia_p4 << "." << endl;

    Ponto pontos[3];
    pontos[0].setCoordenadas(2, 2);
    pontos[1].setCoordenadas(-1, 5);
    pontos[2].setCoordenadas(0, 0);
    for (int i = 0; i < 3; ++i) {
    double distancia = pontos[i].calcularDistancia();
    cout << "Distância do ponto " << i + 1 << " até a origem: " << distancia << endl;
    }
    // Resposta: Distância do ponto 1 até a origem: aproximadamente 2.82843
    // Distância do ponto 2 até a origem: aproximadamente 5.09902
    // Distância do ponto 3 até a origem: 0.0

    Ponto p5;
    cout << "Coordenadas do ponto p5: (" << p5.getX() << ", " << p5.getY() << ")" << endl;
    p5.setCoordenadas(8, -3);
    cout << "Novas coordenadas do ponto p5: (" << p5.getX() << ", " << p5.getY() << ")" << endl;
    // Resposta: Coordenadas do ponto p5: (0, 0)
    // Novas coordenadas do ponto p5: (8, -3)
    
    return 0;
}
