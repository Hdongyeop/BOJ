#include <iostream>
#include <math.h>
using namespace std;
struct PT{
    double x;
    double y;

    PT(double a, double b){
        x = a;
        y = b;
    }
};
int main() {
    double a,t;

    cin >> a >> t;

    double p_y = -sqrt(3)*a*a/(t*2);
    double p_x = sqrt(a*a - p_y*p_y);

    PT p(p_x,p_y);
    PT b(-t/2, -sqrt(3)*t/2);
    PT c(t/2, -sqrt(3)*t/2);

    double pb = sqrt((p.x-b.x) * (p.x-b.x) + (p.y-b.y) * (p.y-b.y));
    double pc = sqrt((p.x-c.x) * (p.x-c.x) + (p.y-c.y) * (p.y-c.y));

    cout << pb*pc << '\n';
    return 0;
}
