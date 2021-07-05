
#include "examples.h"

// функции примеры для int
void intFuncMap1 (int *element)
{
    if(*((int *) element) > INT_MAX - 2) Throw(OVERFLOW_EL);
    *((int *) element) = *((int *) element) + 2;
}
void intFuncMap2 (int *element)
{
    if ((*((int *) element)) > INT_MAX / (*((int *) element))) Throw(OVERFLOW_EL);
    if (((*((int *) element)) < INT_MIN / (*((int *) element)))) Throw(OVERFLOW_EL);
    *((int *) element) = (*((int *) element))*(*((int *) element));
}
int *intFuncReduce1 (const int *first, const int *second)
{
    if ((*((int *) first)) > INT_MAX / 2) Throw(OVERFLOW_EL);
    if (2 < INT_MIN / (*((int *) first))) Throw(OVERFLOW_EL);
    if ((*((int *) second)) > INT_MAX / 3) Throw(OVERFLOW_EL);
    if (3 < INT_MIN / (*((int *) second))) Throw(OVERFLOW_EL);
    if(((*((int *) second)) > 0) && ((*((int *) first)) * 2 > INT_MAX - (*((int *) second)) * 3)) Throw(OVERFLOW_EL);
    if(((*((int *) second)) < 0) && ((*((int *) first)) * 2 < INT_MIN - (*((int *) second)) * 3)) Throw(OVERFLOW_EL);
    int *result = malloc(sizeof(int));
    *result = (*((int *) first)) * 2 + (*((int *) second)) * 3;
    return result;
}
int *intFuncReduce2 (const int *first, const int *second)
{
    int *result = malloc(sizeof(int));
    *result = (*((int *) first)) * (*((int *) second)) - (*((int *) second) + *((int *) second));
    return result;
}
bool intFuncWhere1 (const int *element)
{
    return !(*element % 2);
}
bool intFuncWhere2 (const int *element)
{
    return (*element % 2);
}

// функции примеры для real
void realFuncMap1 (double *element)
{
    *((double *) element) = *((double *) element) + 2;
}
void realFuncMap2 (double *element)
{
    *((double *) element) = (*((double *) element))*(*((double *) element));
}
double *realFuncReduce1 (const double *first, const double *second)
{
    double *result = malloc(sizeof(double));
    *result = (*((double *) first)) * 2 + (*((double *) second)) * 3;
    return result;
}
double *realFuncReduce2 (const double *first, const double *second)
{
    double *result = malloc(sizeof(double));
    *result = (*((double *) first)) * (*((double *) second)) - (*((double *) second) + *((double *) second));
    return result;
}
bool realFuncWhere1 (const double *element)
{
    return (*element > 0);
}
bool realFuncWhere2 (const double *element)
{
    return (*element <= 0);
}

// функции примеры для complex
void complexFuncMap1 (complex double *element)
{
    *((complex double *) element) = *((complex double *) element) + 2;
}
void complexFuncMap2 (complex double *element)
{
    *((complex double *) element) = (*((complex double *) element))*(*((complex double *) element));
}
complex double *complexFuncReduce1 (const complex double *first, const complex double *second)
{
    complex double *result = malloc(sizeof(double));
    *result = (*((complex double *) first)) * 2 + (*((complex double *) second)) * 3;
    return result;
}
complex double *complexFuncReduce2 (const complex double *first, const complex double *second)
{
    complex double *result = malloc(sizeof(complex double));
    *result = (*((complex double *) first)) * (*((complex double *) second)) - (*((complex double *) second) + *((complex double *) second));
    return result;
}
bool complexFuncWhere1 (const complex double *element)
{
    return (creal(*element) <= 0);
}
bool complexFuncWhere2 (const complex double *element)
{
    return (creal(*element) > 0);
}