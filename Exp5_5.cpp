#include <iostream>
#include <cmath>
using namespace std;
int main(void){
    double rayon, surface;cout << "saisissez le rayon du cercle: ";
    cin >> rayon;surface = 3.14159 * pow(rayon, 2);
    cout << "la surface du cercle est " << surface << endl;
    return 0;
    
}
