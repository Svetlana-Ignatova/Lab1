#include <stdio.h>
#include <time.h>                   //для задержек
#include "array.h"        //вся работа с массивом хранится тут
#include "examples.h"

const char *MENU[] = {"0. Exit", "1. We working with integer numbers",
                      "2. We working with complex numbers"};
const int MENU_SIZE = sizeof(MENU) / sizeof(MENU[0]);

const char *GENERAL_MENU[] = {"0. Back", "1. Sort", "2. Map", "3. Reduce", "4. Where", "5. Concatenation"};
const int GENERAL_MENU_SIZE = sizeof(GENERAL_MENU) / sizeof(GENERAL_MENU[0]);

const char *MENU_INT_MAP[] = {"0. Back", "1. Add 2 to each element", "2. Square each element"};
const int MENU_INT_MAP_SIZE = sizeof(MENU_INT_MAP) / sizeof(MENU_INT_MAP[0]);

const char *MENU_INT_REDUCE[] = {"0. Back", "1. x1 * 2 + x2 * 3", "2. x1 * x2 - (x1 + x2)"};
const int MENU_INT_REDUCE_SIZE = sizeof(MENU_INT_REDUCE) / sizeof(MENU_INT_REDUCE[0]);

const char *MENU_INT_WHERE[] = {"0. Back", "1. Even", "2. Odd"};
const int MENU_INT_WHERE_SIZE = sizeof(MENU_INT_WHERE) / sizeof(MENU_INT_WHERE[0]);

const char *MENU_COMPLEX_WHERE[] = {"0. Back", "1. Positive real part", "2. Negative real part"};
const int MENU_COMPLEX_WHERE_SIZE = sizeof(MENU_COMPLEX_WHERE) / sizeof(MENU_COMPLEX_WHERE[0]);

// функция задержки для меню
void delay (int milli_seconds);

// функция для работы меню
int dialog (const char *msgs[], int n);

//функция для обработки ошибок
void handlerError (CEXCEPTION_T EXPT);

int main (int argc, char **argv)
{
    CEXCEPTION_T EXCEPTION;

    int menu;
    do {
        menu = dialog(MENU, MENU_SIZE);
        switch (menu) {
            case 1: {
                int menu_int;
                Array array1 = constructIntArray();
                do {
                    menu_int = dialog(GENERAL_MENU, GENERAL_MENU_SIZE);
                    switch (menu_int) {
                        case 1: {
                            Try {
                                sort(&array1);
                                printIntArray(&array1);
                            } Catch(EXCEPTION) {
                                handlerError(EXCEPTION);
                            }
                        }
                            break;

                        case 2: {
                            int menu_map;
                            do {
                                menu_map = dialog(MENU_INT_MAP, MENU_INT_MAP_SIZE);
                                if (menu_map >= 1 && menu_map <= 2) {
                                    Try {
                                        Array array2;
                                        if (menu_map == 1)
                                            array2 = map(intFuncMap1, &array1);
                                        else if (menu_map == 2)
                                            array2 = map(intFuncMap2, &array1);
                                        printIntArray(&array2);
                                        destructArray(&array2);
                                    } Catch(EXCEPTION) {
                                        handlerError(EXCEPTION);
                                    }
                                }
                            } while (menu_map != 0);
                        }
                            break;


                        case 3: {
                            int menu_reduce;
                            do {
                                menu_reduce = dialog(MENU_INT_REDUCE, MENU_INT_REDUCE_SIZE);
                                if (menu_reduce >= 1 && menu_reduce <= 2) {
                                    printf("Enter start element\n");
                                    int start_element;
                                    scanf("%d", &start_element);
                                    Try {
                                        if (menu_reduce == 1)
                                            printf("%d",
                                                   *((int *) reduce(intFuncReduce1, &array1, &start_element)));
                                        else if (menu_reduce == 2)
                                            printf("%d",
                                                   *((int *) reduce(intFuncReduce2, &array1, &start_element)));
                                        printf("\n");
                                        while (getchar() != '\n');
                                    } Catch(EXCEPTION) {
                                        handlerError(EXCEPTION);
                                    }
                                }
                            } while (menu_reduce != 0);
                        }
                            break;

                        case 4: {
                            int menu_where;
                            do {
                                menu_where = dialog(MENU_INT_WHERE, MENU_INT_WHERE_SIZE);
                                if (menu_where >= 1 && menu_where <= 2) {
                                    Try {
                                        Array array2;
                                        if (menu_where == 1)
                                            array2 = where(intFuncWhere1, &array1);
                                        if (menu_where == 2)
                                            array2 = where(intFuncWhere2, &array1);
                                        printIntArray(&array2);
                                        destructArray(&array2);
                                    } Catch(EXCEPTION) {
                                        handlerError(EXCEPTION);
                                    }
                                }
                            } while (menu_where != 0);
                        }
                            break;

                        case 5: {
                            Try {
                                Array array2 = constructIntArray();
                                Array array3 = concatenat(&array1, &array2);
                                printf("result:\n");
                                printIntArray(&array3);
                                destructArray(&array3);
                                destructArray(&array2);
                            } Catch(EXCEPTION) {
                                handlerError(EXCEPTION);
                            }
                        }
                            break;

                        default:
                            break;

                    }
                } while (menu_int != 0);
                destructArray(&array1);
            }
                break;

            case 2: {
                int menu_complex;
                Array array1 = constructComplexArray();
                printComplexArray(&array1);
                do {
                    menu_complex = dialog(GENERAL_MENU, GENERAL_MENU_SIZE);
                    switch (menu_complex) {
                        case 1: {
                            Try {

                                sort(&array1);
                                printComplexArray(&array1);
                            } Catch(EXCEPTION) {
                                handlerError(EXCEPTION);
                            }
                        }
                            break;

                        case 2: {
                            int menu_map;
                            do {
                                menu_map = dialog(MENU_INT_MAP, MENU_INT_MAP_SIZE);
                                if (menu_map >= 1 && menu_map <= 2) {
                                    Try {
                                        Array array2;
                                        if (menu_map == 1)
                                            array2 = map(complexFuncMap1, &array1);
                                        else if (menu_map == 2)
                                            array2 = map(complexFuncMap2, &array1);
                                        printComplexArray(&array2);
                                        destructArray(&array2);
                                    } Catch(EXCEPTION) {
                                        handlerError(EXCEPTION);
                                    }
                                }
                            } while (menu_map != 0);
                        }
                            break;


                        case 3: {
                            int menu_reduce;
                            do {
                                menu_reduce = dialog(MENU_INT_REDUCE, MENU_INT_REDUCE_SIZE);
                                if (menu_reduce >= 1 && menu_reduce <= 2) {
                                    printf("Enter start element\n");
                                    complex double start_element;
                                    double x1, x2;
                                    scanf("%lf", &x1);
//                                    getchar();
//                                    getchar();
//                                    getchar();
                                    scanf("%lf", &x2);
                                    start_element = x1 + x2 * I;
                                    Try {
                                        if (menu_reduce == 1) {
                                            printf("%1.f + ",
                                                   creal(*((complex double *) reduce(complexFuncReduce1,
                                                                                     &array1,
                                                                                     &start_element))));
                                            printf("%1.fi",
                                                   cimag(*((complex double *) reduce(complexFuncReduce1,
                                                                                     &array1,
                                                                                     &start_element))));
                                        } else if (menu_reduce == 2) {
                                            printf("%1.f + ",
                                                   creal(*((complex double *) reduce(complexFuncReduce2,
                                                                                     &array1,
                                                                                     &start_element))));
                                            printf("%1.fi",
                                                   cimag(*((complex double *) reduce(complexFuncReduce2,
                                                                                     &array1,
                                                                                     &start_element))));
                                        }
                                        printf("\n");
                                        while (getchar() != '\n');
                                    } Catch(EXCEPTION) {
                                        handlerError(EXCEPTION);
                                    }
                                }
                            } while (menu_reduce != 0);
                        }
                            break;

                        case 4: {
                            int menu_where;
                            do {
                                menu_where = dialog(MENU_COMPLEX_WHERE, MENU_COMPLEX_WHERE_SIZE);
                                if (menu_where >= 1 && menu_where <= 2) {
                                    Try {
                                        Array array2;
                                        if (menu_where == 1)
                                            array2 = where(complexFuncWhere1, &array1);
                                        if (menu_where == 2)
                                            array2 = where(complexFuncWhere2, &array1);
                                        printComplexArray(&array2);
                                        destructArray(&array2);
                                    } Catch(EXCEPTION) {
                                        handlerError(EXCEPTION);
                                    }
                                }
                            } while (menu_where != 0);
                        }
                            break;

                        case 5: {
                            Try {
                                Array array2 = constructComplexArray();
                                Array array3 = concatenat(&array1, &array2);
                                printComplexArray(&array3);
                                destructArray(&array3);
                                destructArray(&array2);
                            } Catch(EXCEPTION) {
                                handlerError(EXCEPTION);
                            }
                        }
                            break;

                        default:
                            break;

                    }
                } while (menu_complex != 0);
                destructArray(&array1);
            }
                break;

            default:
                break;
        }
    } while (menu != 0);

    return 0;
}

void handlerError (CEXCEPTION_T EXPT)
{
    switch (EXPT) {
        case NULL_POINTER:
            printf("Array points to a null pointer!");
            break;

        case WRONG_ELEMENT_SIZE:
            printf("Element length less than or equal to 0!");
            break;

        case WRONG_DIMENSION:
            printf("Array length is less than or equal to 0!");
            break;

        case NO_COMPARATOR:
            printf("No comparison function!");
            break;

        case DIFFERENT_ELEMENT_SIZE:
            printf("Different element length!");
            break;

        case DIFFERENT_COMPARATOR:
            printf("Different comparison functions!");
            break;

        case OVERFLOW_EL:
            printf("Variable overflow has occurred!");
            break;

        default:
            printf("Unknown error %d", EXPT);
            break;
    }
    printf("\n");
}

int dialog (const char *msgs[], int n)
{
    int choice;
    do {
        for (int i = 0; i < n; ++i)
            puts(msgs[i]);
        printf("> ");

        choice = getchar() - '0';
        while (getchar() != '\n');
        if (choice < 0 || choice >= n)
            printf("You're wrong. Try again!\n");

//        delay(500);
//        printf("\033[0d\033[2J");

    } while (choice < 0 || choice >= n);

    return choice;
}

void delay (int milli_seconds)
{
    int nano_seconds = 1000 * milli_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + nano_seconds);
}
