// Implementação método da bisseção.
#include <cmath>
#include <iostream>
using namespace std;

// Ok...
double bissecao(double a, double b, int iter, double precisao){
    int k = 1;
    double x;
    double m;
    // Escreva a função aqui (inicialmente)
    auto f = [](double x) {return -(pow(M_E, x)/2) + 2*cos(x);};
    
    if ((b - a) < precisao)
        return a;
    m = f(a);
    while (k < iter && (b - a) > precisao){
        x = (a + b) / 2;
        if (m * f(x) > 0)
            a = x;
        else 
            b = x;
        k++;
    }
    return ((a + b) / 2);
}
// Ok...
double posicao_falsa(double a, double b, int iter, double precisao, double precisao2){
    int k = 1;
    double x;
    double m;
    // Escreva a função aqui (inicialmente)
    auto f = [](double x) {return -(pow(M_E, x)/2) + 2*cos(x);};
    if (fabs(f(a)) < precisao2)
        return a;
    if (fabs(f(b)) < precisao2)
        return b;
    
    m = f(a);
    while (k < iter && (b - a) > precisao){
        x = (a * f(b) - b * f(a)) / (f(b) - f(a));
        if (fabs(f(x)) < precisao2)
            return x;  
        if (m * f(x) > 0)
            a = x;
        else 
            b = x;
        k++;
    }
    return (f((a + b) / 2)); // Podemos manter isso, qualquer x no intervalo vale.
}

// Provavelmente do_while
double ponto_fixo(double x0, double precisao, double precisao2){
    double x1;
    auto f = [](double x) {return 6 - (x * x);};
    auto phi = [](double x) {return sqrt(6 - x);}; // x isolado
    if (fabs(f(x0)) < precisao)
        return x0;
    x1 = phi(x0);
    while(fabs(f(x1)) >= precisao && fabs(x1-x0) >= precisao2){
        x0 = x1;
        x1 = phi(x0);
    }
    return x1;

}
// Mesma coisa do de cima...
double newton_raphson(double x0, double precisao, double precisao2){
    double x1;
    auto f = [](double x) {return pow(x, 2) + x - 6;}; // escreva aq sua funcao
    auto phi = [](double x) {return x - ((pow(x, 2) + x - 6)/(2*x + 1));}; // escreva aq x - (f(x)/f'(x))
    if (fabs(f(x0)) < precisao)
        return x0;
    x1 = phi(x0);
    while(fabs(f(x1)) >= precisao && fabs(x1-x0) >= precisao2){
        x0 = x1;
        x1 = phi(x0);
    }
    return x1;
}
// Ok...
double secante(double x0, double x1, double precisao, double precisao2){
    double x2;
    auto f = [](double x) {return pow(x, 2) + x - 6;}; // escreva aq sua funcao
    if (fabs(f(x0)) < precisao)
        return x0;
    if (fabs(f(x1) < precisao) || fabs(x1 - x0) < precisao2)
        return x1;
    
    do {
        x2 = x1 - (f(x1) / (f(x1) - f(x0))) * (x1 - x0);
        x0 = x1;
        x1 = x2;
    } while (fabs(f(x1)) >= precisao && fabs(x1 - x0) >= precisao2);
    return x2;
}



int main(int argc, char* argv[]){
    double resposta;
    resposta = secante(1.5, 3, 0.0000000000000000000000001, 0.000000000000000000000001);
    cout << "A resposta é: " << resposta << endl;
    return 0;


}