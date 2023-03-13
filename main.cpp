#include <iostream>
#include <cmath>

using namespace std;

typedef double (*pointFunc)(double);

double f(double x) { return exp(-x * x); };

double runge_step(double eps)
{
    return pow(eps, 0.25);
}

double left_riemann_sum_h(pointFunc f, double a, double b, double h)
{
    double x, fx, sum = 0.0;
    int n = (b - a) / h; // number of steps
    for (int i = 0; i < n; i++)
    {
        x = a + i * h;
        fx = f(x);
        sum += fx;
    }
    return (sum * h); // sum of rectangles areas
}

double left_riemann_sum_n(pointFunc f, double a, double b, int n)
{
    double x, h, fx, sum = 0.0;
    h = (b - a) / n; // step value
    for (int i = 0; i < n; i++)
    {
        x = a + i * h;
        fx = f(x);
        sum += fx;
    }
    return (sum * h);
}

int main()
{
    double a, b, eps, s;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "epsilon = ";
    cin >> eps;

    double h = runge_step(eps); // step value using Runge rule
    s = left_riemann_sum_h(f, a, b, h);
    cout << "Integral (left_riemann_sum_h) = " << s << endl;

    int n = 1;
    double s1 = left_riemann_sum_n(f, a, b, n);
    do
    {
        s = s1;
        n = 2 * n; // multiply steps count by 2 - reduce step value by 2
        s1 = left_riemann_sum_n(f, a, b, n);
    } while (fabs(s1 - s) > eps);
    cout << "Integral (left_riemann_sum_n) = " << s1 << endl;
    return 0;
}