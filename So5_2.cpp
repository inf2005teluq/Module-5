#include<iostream> 
#include <stdio.h>  
#include <stdlib.h> #include <math.h> 
using namespace std;  
int main() 
{ 
    float a, b, c; cout << "Entrer les coefficients de l'equation:"; 
    cin >> a >> b >> c; if (a == 0)  
    { 
        cout << "votre équation n'est pas du second degré: a == 0 \n"; 
        return 0; 
        
    }

cout << "l'équation est: " << a << " x^2 + " << b << " x + " << c << " = 0 \n";
double d, xl, x2;
d = b * b - 4 * a * c;
// the discriminant
if (d < 0)  { cout << "cette équation n'a pas de solution réelle: d < 0\n"; 
return 0;
xl = (-b +sqrt(d))/(2*a);
x2 = (-b -sqrt (d)) / (2*a); 
cout << "les solutions sont: " << xl << "," << x2 <<endl; 
} 
    
}
