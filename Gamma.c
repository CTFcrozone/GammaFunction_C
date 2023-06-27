#include <stdio.h>
#include <math.h>

double lanczosCoefficients[8] = {0.99999999999980993, 676.5203681218851, -1259.1392167224028,
                                 771.32342877765313, -176.61502916214059, 12.507343278686905,
                                 -0.13857109526572012, 0.9934937113930748e-05};

double gammaFunction(double x) {
    if (x < 0.5) {
        return M_PI / (sin(M_PI * x) * gammaFunction(1 - x));
    }
    x -= 1;
    double sum = lanczosCoefficients[0];
    for (int i = 1; i < 8; i++) {
        sum += lanczosCoefficients[i] / (x + i);
    }
    double t = x + 7.5;
    return sqrt(2 * M_PI) * pow(t, (x + 0.5)) * exp(-t) * sum;
}

int main() {
    double n;
    printf("Enter a value for n (must be an positive and greater than 0): ");
    scanf("%lf", &n);
    if (n <= 0) {
        printf("Gamma(%.2f) diverges", n);
        return 1;
    }
    double gamma = gammaFunction(n);
    printf("Gamma(%.2f) = %.6f", n, gamma);
    return 0;
}
