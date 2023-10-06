#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

class Ponto
{
    private:
        float x, y;

    public:
        Ponto(float x, float y);
        Ponto();
        ~Ponto();
        float getX();
        void setX(float _x);
        float getY();
        void setY(float _y);
        void setCoordenadas(double _x, double _y);
        double calculaDistancia();
};

Ponto::Ponto()
{
    x = 0;
    y = 0;
}

Ponto::Ponto(float _x, float _y)
{
    x = _x;
    y = _y;
}

Ponto::~Ponto()
{
}

float Ponto::getX()
{
    return x;
}

void Ponto::setX(float _x)
{
    x = _x;
}

float Ponto::getY()
{
    return y;
}

void Ponto::setY(float _y)
{
    y = _y;
}

double Ponto::calculaDistancia(){
    double distancia = sqrt((x * x) + (y * y));
    
    return distancia;
};

int main(void) {

    Ponto p1(3, 4);

    double distancia = p1.calculaDistancia();

    // Resposta: A distância do ponto (3, 4) até a origem é aproximadamente 5.0.
    cout << "A distância do ponto (3, 4) até a origem é: " << fixed << setprecision(2) << distancia << endl;

    Ponto p2(-2, 7);

    //altera o ponto
    p2.setCoordenadas(1, 1);
    distancia = p2.calculaDistancia();
    // Resposta: A distância do ponto (1, 1) até a origem é aproximadamente 1.41421.

    cout << "A distância do ponto (1, 1) até a origem é: " << fixed << setprecision(5) << distancia << endl;


    Ponto p3(0, 3);
    Ponto p4(4, 0);
    double distancia_p3 = p3.calculaDistancia();
    double distancia_p4 = p4.calculaDistancia();

    // Resposta: A distância do ponto (0, 3) até a origem é 3.0 e do ponto (4, 0) até a origem é 4.0.
    cout << "A distância do ponto (0, 3) até a origem é: " << fixed << setprecision(2) << distancia_p3 << endl;
    cout << "A distância do ponto (4, 0) até a origem é: " << fixed << setprecision(2) << distancia_p4 << endl;


    Ponto pontos[3];
    pontos[0].setCoordenadas(2, 2);
    pontos[1].setCoordenadas(-1, 5);
    pontos[2].setCoordenadas(0, 0);

    for (int i = 0; i < 3; ++i) {
        double distancia = pontos[i].calculaDistancia();
        cout << "Distância do ponto " << i + 1 << " até a origem: " << fixed << setprecision(5) << distancia << endl;
    }
    // Resposta: Distância do ponto 1 até a origem: aproximadamente 2.82843
    // Distância do ponto 2 até a origem: aproximadamente 5.09902
    // Distância do ponto 3 até a origem: 0.0

    Ponto p5;
    cout  << fixed << setprecision(1)<< "Coordenadas do ponto p5: (" << p5.getX() << ", " << p5.getY() << ")" << endl;
    p5.setCoordenadas(8, -3);
    cout << "Novas coordenadas do ponto p5: (" << p5.getX() << ", " << p5.getY() << ")" << endl;
    // Resposta: Coordenadas do ponto p5: (0, 0)
    // Novas coordenadas do ponto p5: (8, -3)
    return 0;
}