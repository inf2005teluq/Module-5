#include <iostream>
#include <valarray>
#include <iostream>
#include <iomanip>
#include <valarray>
using namespace std ;
main()
{ 
    int i ;
    int t[] = { 1, 2, 3,4, 5, 6} ;
    bool mt[] = { true, true, false, true, false, true} ;
    valarray <int> v1 (t, 6), v2 ; 
    // v2 est vide
    valarray <bool> masque (mt, 6) ;
    v2 = v1[masque] ;cout << "v2 : " ;
    for (i=0 ; i<v2.size() ; i++) 
    cout << setw(4) << v2[i] ;
    // setw(n) Spécifie que la prochaine sortie s'effectuera sur n  
    // caractères
    cout << "\n" ;
    v1[masque] = -1 ;
    cout << "v1 : " ;
    for (i=0 ; i<v1.size() ; i++) 
    cout << setw(4) << v1[i] ;
    cout << "\n" ;
    valarray <int> v3(8); 
    /* il faut au moins 4 elements dans v3 */
    for (i=0 ; i<v3.size() ; i++)
    v3[i] = 10*(i+1) ;
    v1[masque] = v3 ;
    cout << "v1 : " ;
    for (i=0 ; i<v1.size() ; i++) 
    cout << setw(4) << v1[i] ;
    cout << "\n" ;
    
}
