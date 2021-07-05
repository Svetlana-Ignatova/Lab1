
#ifndef SVETALAB_EXAMPLES_H
#define SVETALAB_EXAMPLES_H

#include "array.h"               //вся работа с массивом хранится тут

#include <limits.h>                        // для проверки на переполнение


// примеры функции для работы с map, reduce, where

//примеры для int

//map
void         intFuncMap1        (int *element);                                         // к каждому элементу прибавляем 2
void         intFuncMap2        (int *element);                                         // возводим в квадрат

//reduce
int         *intFuncReduce1     (const int *first, const int *second);                  // x1 * 2 + x2 * 3
int         *intFuncReduce2     (const int *first, const int *second);                  // x1 * x2 - (x1 + x2)


bool         intFuncWhere1      (const int *element);                                   // берём четные
bool         intFuncWhere2      (const int *element);                                   // берём нечетные



//примеры для real

//map
void         realFuncMap1        (double *element);                                      // к каждому элементу прибавляем 2
void         realFuncMap2        (double *element);                                      // возводим в квадрат

//reduce
double       *realFuncReduce1    (const double *first, const double *second);            // x1 * 2 + x2 * 3
double       *realFuncReduce2    (const double *first, const double *second);            // x1 * x2 - (x1 + x2)

//where
bool         realFuncWhere1      (const double *element);                                // берём положительные
bool         realFuncWhere2      (const double *element);                                // берём отрицательные


//примеры для complex

//map
void                    complexFuncMap1          (complex double *element);
void                    complexFuncMap2          (complex double *element);

//reduce
complex double          *complexFuncReduce1      (const complex double *first, const complex double *second);
complex double          *complexFuncReduce2      (const complex double *first, const complex double *second);

//where
bool                    complexFuncWhere1        (const complex double *element);
bool                    complexFuncWhere2        (const complex double *element);

#endif //SVETALAB_EXAMPLES_H
