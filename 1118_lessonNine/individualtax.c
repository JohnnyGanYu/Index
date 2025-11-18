#include <stdio.h>

int main(void)
{
    float preTaxSalary;
    float afterTaxSalary;
    scanf("%f", &preTaxSalary);
    switch ( (int)preTaxSalary / 1000 )
    {
    case 0:
        afterTaxSalary = preTaxSalary;
        break;
    case 1:
        afterTaxSalary = 0.9 * preTaxSalary;
        break;
    case 2:
        afterTaxSalary = 0.85 * preTaxSalary;
        break;
    case 3:
        afterTaxSalary = 0.8 * preTaxSalary;
        break;
    default:
        afterTaxSalary = 0.75 * preTaxSalary;
        break;
    }
    printf("%.2f", afterTaxSalary);
    return 0;
}