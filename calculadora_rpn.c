#include <stdio.h>
#include <math.h>

float stack[8];

int main()
{
    int mi_opc;
    char opc2;
    float tmp;
    int i = 0;

    while (mi_opc != 5)
    {
        printf("\033[2J");
        imprimirpila();
        mi_opc = menu();
        if (mi_opc == 1)
        {
            // Insertar en la pila
            insertar();
            printf("\033[2J");
            imprimirpila();
        }
        else if (mi_opc == 2)
        {
            printf("\033[2J");
            imprimirpila();
            opc2 = operaciones();
            printf("\n\n");
            // Operaciones
            while (opc2 != '+' && opc2 != '-' && opc2 != '*' && opc2 != '/' && opc2 != 'r' && opc2 != 's' && opc2 != 'c' && opc2 != 't' && opc2 != 'p' && opc2 != 'x')
            {
                switch (opc2)
                {
                case '+':
                    tmp = stack[6] + stack[7];
                    movestackdown();
                    stack[7] = tmp;
                    printf("\033[2J");
                    imprimirpila();
                    break;
                case '-':
                    tmp = stack[6] - stack[7];
                    movestackdown();
                    stack[7] = tmp;
                    printf("\033[2J");
                    imprimirpila();
                    break;
                case '*':
                    tmp = stack[6] * stack[7];
                    movestackdown();
                    stack[7] = tmp;
                    printf("\033[2J");
                    imprimirpila();
                    break;
                case '/':
                    if (stack[7] != 0)
                    {
                        tmp = stack[6] / stack[7];
                        movestackdown();
                        stack[7] = tmp;
                        printf("\033[2J");
                        imprimirpila();
                        break;
                    }
                    else
                    {
                        printf("\033[2J");
                        printf("MATH ERROR\n--> División por cero no definida");
                        imprimirpila();
                        break;
                    }
                case 'r':
                    if (stack[7] >= 0)
                    {
                        stack[7] = sqrt(stack[7]);
                        printf("\033[2J");
                        imprimirpila();
                        break;
                    }
                    else
                    {
                        printf("\033[2J");
                        printf("MATH ERROR\n--> Raíz Negativa");
                        imprimirpila();
                        break;
                    }
                case 's':
                    stack[7] = sin(stack[7]);
                    printf("\033[2J");
                    imprimirpila();
                    break;
                case 'c':
                    stack[7] = cos(stack[7]);
                    printf("\033[2J");
                    imprimirpila();
                    break;
                case 't':
                    if (stack[7] != 270 && stack[7] != 90 && stack[7] != -270 && stack[7] != -90)
                    {
                        stack[7] = tan(stack[7]);
                        printf("\033[2J");
                        imprimirpila();
                        break;
                    }
                    else
                    {
                        printf("\033[2J");
                        printf("MATH ERROR\n--> Tangente no definida");
                        imprimirpila();
                        break;
                    }
                case 'p':
                    tmp = pow(stack[6], stack[7]);
                    movestackdown();
                    stack[7] = tmp;
                    printf("\033[2J");
                    imprimirpila();
                    break;
                case 'x':
                    break;
                }
            }
        }
        else if (mi_opc == 3)
        {
            // Limpiar último
            printf("\033[2J");
            movestackdown();
            imprimirpila();
        }
        else if (mi_opc == 4)
        {
            // Limpiar todo
            printf("\033[2J");
            for (i = 0; i < 8; i++)
            {
                stack[i] = 0;
            }
            imprimirpila();
        }
        else if (mi_opc == 5)
        {
            // Salir
            printf("\033[2J");
            imprimirpila();
            exit(0);
        }
        else
        {
            printf("\033[2J");
            imprimirpila();
        }
    }
}

void imprimirpila(void)
{
    int i = 0;
    for (i = 0; i < 8; i++)
    {
        printf("[%d]. %f", 8 - i, stack[i]);
        printf("\n");
    }
}

void movestackup(void)
{
    int i = 0;
    for (i = 1; i < 8; i++)
    {
        stack[i - 1] = stack[i];
    }
}

void movestackdown(void)
{
    int i = 0;
    for (i = 7; i > 0; i--)
    {
        stack[i] = stack[i - 1];
    }
}

void insertar()
{
    float num;
    printf("---> ");
    scanf("%f", &num);
    movestackup();
    stack[7] = num;
}

int menu()
{
    int opc;
    printf("==================================\n");
    printf("========== CALCULADORA ===========\n");
    printf("================ RPN =============\n");
    printf("== BY ALEJO ======================\n\n");

    // Opciones
    printf("== [1]. Insertar número         ==\n"); //
    printf("== [2]. Seleccionar operación   ==\n");
    printf("== [3]. Limpiar último          ==\n");
    printf("== [4]. Limpiar todo            ==\n");
    printf("== [5]. Salir                   ==\n");
    printf("==================================\n");
    printf("==================================\n");
    printf("Ingrese la Opción deseada: ");
    scanf("%d", &opc);
    return opc;
}

char operaciones()
{
    char opc;
    printf("=================================\n");
    printf("==     [+]. Suma               ==\n"); //
    printf("==     [-]. Resta              ==\n");
    printf("==     [*]. Multiplicación     ==\n");
    printf("==     [/]. División           ==\n");
    printf("==     [r]. Raíz Cuadrada      ==\n"); //
    printf("==     [s]. Seno               ==\n");
    printf("==     [c]. Coseno             ==\n");
    printf("==     [t]. Tangente           ==\n");
    printf("==     [p]. Potencia (x^2)     ==\n");
    printf("==     [x]. Salir              ==\n");
    printf("=================================\n");
    printf("Ingrese la Operación a realizar: ");
    scanf(" %c", &opc);
    return opc;
}