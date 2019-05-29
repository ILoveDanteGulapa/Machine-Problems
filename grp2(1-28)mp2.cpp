#include <iostream>
#include <string>
#include <math.h>
#include <cmath>
using namespace std;

int main()
{
	double angle = 0.0, a = 0.0, b = 0.0, c = 0.0,
	s = 0.0, 
	aa = 0.0, ab = 0.0, ac = 0.0,
    perimeter = 0.0, area = 0.0,
	apothem = 0.0, circumcenter = 0.0, pi = 0.0,
	a2 = 0.0, b2 = 0.0, x = 0.0;
	
	pi = 3.141592654;
	x = 2.0;
	
    cout << "Enter Side A: ";
    cin >> a;
    cout << "Enter Side B: ";
    cin >> b;
    cout << "Enter Side C: ";
    cin >> c;
    
    a2 = ((pow(b, x)+pow(c, x)) - pow(a, x)) / (2*b*c);
    aa = acos(a2) * ((180) / (pi));
    
    b2 = ((pow(a, x)+pow(c, x)) - pow(b, x)) / (2*a*c);
    ab = acos(b2) * ((180) / (pi));
    
    ac = 180 - aa - ab;
    
    cout << " A. Interior Angle"; 
    cout << "\n     a: " << aa;
    cout << "\n     b: " << ab;
    cout << "\n     c: " << ac;
    
    
    // determine triangle
    bool scalene = a != b && b != c && a != c;
    bool isoceles = (a == b && a != c) || (b == c && b != a) || (a == c && a != b); // a != b || b != c || a != c;
    bool equilateral = a == b || b == c || c == a;
    
    string tri = "";
    tri = scalene ? "Scalene" : isoceles ? "Isoceles" : equilateral ? "Equilateral" : "Not";
    cout << "\n B. " <<  tri;
    
    // perimeter and area
    double p = (a + b + c) / 2;
    area = sqrt (p * (p - a) * (p - b) * (p - c));
    perimeter = p*2;
    
    cout << "\n C. Perimeter and area of triangle";
    cout<<"\n   Perimeter: "<< perimeter;
	cout<<"\n   Area: "<< area;
    
    // classify whether acute, right or obtuse
    bool acute = aa < 90 && ab < 90 && ac <90;
    bool right = false;
    if (aa == 90 && ab != 90 && ac != 90){
        right = true;
    } else if (aa != 90 && ab == 90 && ac != 90){
        right = true;
    } else if (aa != 90 && ab != 90 && ac == 90){
        right = true;
    }
    
    bool obtuse = false;
    if (aa > 90 && ab <= 90 && ac <= 90){
        obtuse = true;
    } else if (aa <= 90 && ab > 90 && ac <= 90){
        obtuse = true;
    } else if (aa <= 90 && ab <= 90 && ac > 90){
        obtuse = true;
    }
    
    string type = "";
    type = acute ? "Acute" : right ? "Right" : obtuse ? "Obtuse" : "Not";
    cout << "\n D. " <<  type << " triangle";
    
    if (equilateral){
    	apothem = 2 * area / perimeter;
	    circumcenter = (a * b * c) / sqrt((a + b + c) * (b + c - a) * (a + b - c));
    	
		cout << "\n E. Length of Apothem: ";
		cout<<"\n   Apothem: "<< apothem;
		cout<<"\n   Circumcenter: "<< circumcenter;
	}

    return 0;
}
