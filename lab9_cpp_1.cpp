#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Triangle{
    int a, b, c;
public:
    Triangle(int s1, int s2, int s3){
        if ((s1 + s2 < s3) || (s1 + s3 < s2) || (s2 + s3 < s1))
            throw "Incorrect data!";
        a = s1; b = s2; c = s3;
    }
    double findSquare(){
        double p = (a + b + c)/2;
        return sqrt(p*(p-a)*(p-b)*(p-c));
    }
};
int main() {
    try{
        int a, b, c;
        cin >> a; cin >> b; cin >> c;
        Triangle t1 = Triangle(a, b, c);
        cout << t1.findSquare();
    }
    catch (const char* error)
    {
        cerr << error << endl;
    }
    return 0;
}
