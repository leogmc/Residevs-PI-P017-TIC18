#include <iostream>
#include <math.h>
#include <iomanip>

#define TRACO "-------------------------------------------------"

using namespace std;

class Ponto
{
private:
    double x;
    double y;
public:
    double getX(){
        return x;
    }

    void setX(double _x){
        x = _x;
    }

     double getY(){
        return y;
    }

    void setY(double _y){
        y = _y;
    }

    //Método construtor
    Ponto(){
        x = 0;
        y = 0;
    }

    double calcularDistancia(){
        double x1 = 0, y1 = 0, distancia;
        distancia = sqrt(pow(x - x1, 2) + pow(y - y1, 2));
        return distancia;
    }



};   


int main(){

    Ponto ponto;
    int coordenadaX;
    int coordenadaY;

    cout << "Insira a coordenada x do plano cartesiano: ";
    cin >> coordenadaX;
    ponto.setX(coordenadaX);

    cout << "Insira a coordenada y do plano cartesiano: ";
    cin >> coordenadaY;
    ponto.setY(coordenadaY);

    cout << TRACO << endl;

    cout << "Pronto! A distância entre " << "(" << coordenadaX << "," << coordenadaY << ") até a origem (0,0) é de: " << ponto.calcularDistancia();  


    return 0;
}