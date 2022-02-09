#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void rc_calculation(double voltage)
{
    double Uc = 0;
    double I = 0;
    for (float i = 0; i <= 5; i += 0.5)
    {
        Uc = voltage * (1 - exp(-i));
        I = (voltage * exp(-i)) * 1000 / 10;
        printf("time %.1f s and Uc=%.2f V and Ic=%.2f uA\n", i, Uc, I);
    }
}
float power(float base, unsigned int math_power)
{
    float result = 1;
    for (int i = 0; i < math_power; i++)
    {
        result *= base;
    }
    return result;
}
double PI = 3.14159265358979323846;
void squarewave_harmonics(int n, double ua, double tr, double T)
{
    double D = (tr + T / 2) / T;
    double f = 1 / T;
    double un = 0;
    double F = 0;
    double t1, t2;
    for (int i = 1; i < n; i += 2)
    {
        F = f * i / 1E6;
        t1 = sin(i * PI * D) / (i * PI * D);
        t2 = sin((i * PI * tr) / T) / ((i * PI * tr) / T);
        un = 2 * ua * D * fabs(t1) * fabs(t2);
        printf("n=%d, f(MHz)=%.2f, un(V)=%f V\n", i, F, un);
    }
}
float circuit(float R1, float R2, float R3, int circuittype)
{
    return (circuittype == 2) ? R1 + R2 + R3 : 1 / (1 / R1 + 1 / R2 + 1 / R3);
}
float ohmslaw(float selection, float parameter1, float parameter2)
{
    return (selection == 1) ? parameter1 * parameter2 : (selection == 2) ? parameter1 / parameter2
                                                                         : parameter1 / parameter2;
}
void boundaries(float low_limit, float high_limit, float number)
{
    if (number >= low_limit && number <= high_limit)
    {
        printf("Number is in the right range\n");
    }
    else if (number < low_limit)
    {
        printf("Number value is too low\n");
    }
    else
    {
        printf("Number value is too large");
    }
}
unsigned long int bintodec(char *binary, int length)
{
    unsigned long int resutl = 0;
    for (int i = 0; i < length; i++)
    {
        resutl += (binary[i] == '1') ? pow(2, length - 1 - i) : 0;
    }
    return resutl;
}
float minimum(float number1, float number2, float number3, float number4)
{
    float num1, num2;
    num1 = (number1 < number2) ? number1 : number2;
    num2 = (number3 < number4) ? number3 : number4;
    return (num1 < num2) ? num1 : num2;
}
void calculate_subnets(int class_C)
{
    printf("Subnet mask 255.255.255.%d\n", class_C);
    for (int i = 0; i < 256 / (256 - class_C); i++)
    {
        printf("Network ID range %d - %d\n", i * (256 - class_C), (i + 1) * (256 - class_C) - 1);
    }
    printf("The number of subnets: %d\n", 256 / (256 - class_C));
    printf("IP addresses are divisible by number: %d\n", 256 - class_C);
    printf("The number of useable IP addresses in one subnet: %d\n", (256 - class_C) - 2);
    printf("The Total number of IP addresses: %d\n", 256 - 2 * (256 / (256 - class_C)));
}
int main(void)
{
    int class_C = 224;
    calculate_subnets(class_C);
}