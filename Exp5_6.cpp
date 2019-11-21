#include <iostream>
#include <complex>
using namespace std ;
main()
{ 
    complex<double> z1(1, 2), z2(2, 5), z, zr ;
    cout << "z1 : " << z1 << " z2 : " << z2 << "\n" ;
    cout << "Re(z1) : " << real(z1) << " Im(z1) : " << imag(z1)  << "\n" ;
    cout << "abs(z1) : " << abs(z1) << " arg(z1) : " << arg(z1) << "\n" ;
    cout << "conj(z1) : " << conj(z1) << "\n" ;
    cout << "z1 + z2 : " << (z1+z2) << " z1*z2 : " << (z1*z2)<< " z1/z2 : " << (z1/z2) << "\n" ;
    complex<double> i(0, 1) ; 
    // on definit la constante 
    iz = 1.0+i ;zr = exp(z) ;
    cout << "exp(1+i) : " << zr << " exp(i) : " << exp(i) << "\n" ;
    zr =log(i) ;cout << "log(i) : " << zr << "\n" ;
    zr = log(1.0+i) ;
    cout << "log(1+i) : " << zr << "\n" ;
    double rho, theta, norme ;
    rho = abs(z) ; 
    theta = arg(z) ; 
    norme = norm(z) ;
    cout << "abs(1+i) : " << rho << " arg(1+i) : " << theta<< " norm(1+i) : " << norme << "\n" ;
    double pi = 3.1415926535 ;
    cout << "cos(i) : " << cos(i) << " sinh(pi*i): " << sinh(pi*i)<< " cosh(pi*i) : " << cosh(pi*i) << "\n" ;
    z = polar<double> (1, pi/4) ;
    cout << "polar (1, pi/4) : " << z << "\n" ;
    
}
