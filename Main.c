#include <stdio.h>
#include <math.h>

static void clear_input(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

static int read_int(const char *prompt, int *value) {
    printf("%s", prompt);
    if (scanf("%d", value) != 1) {
        clear_input();
        return 0;
    }
    clear_input();
    return 1;
}

static int read_double(const char *prompt, double *value) {
    printf("%s", prompt);
    if (scanf("%lf", value) != 1) {
        clear_input();
        return 0;
    }
    clear_input();
    return 1;
}

static void show_menu(void) {
    printf("\n=================================\n");
    printf("          C CALCULATOR\n");
    printf("=================================\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus (integers)\n");
    printf("6. Power (x^y)\n");
    printf("7. Square root\n");
    printf("8. Percentage (x%% of y)\n");
    printf("9. Exit\n");
    printf("=================================\n");
}

int main(void) {
    int choice;
    printf("Welcome to C Calculator!\n");

    for (;;) {
        show_menu();

        if (!read_int("Choose an option: ", &choice)) {
            printf("Invalid input. Enter 1-9.\n");
            continue;
        }

        if (choice == 9) {
            printf("Goodbye!\n");
            return 0;
        }

        double a, b, result;

        switch (choice) {
            case 1:
                if (read_double("Enter first number: ", &a) &&
                    read_double("Enter second number: ", &b))
                    printf("Result: %.12g\n", a + b);
                else printf("Invalid number.\n");
                break;

            case 2:
                if (read_double("Enter first number: ", &a) &&
                    read_double("Enter second number: ", &b))
                    printf("Result: %.12g\n", a - b);
                else printf("Invalid number.\n");
                break;

            case 3:
                if (read_double("Enter first number: ", &a) &&
                    read_double("Enter second number: ", &b))
                    printf("Result: %.12g\n", a * b);
                else printf("Invalid number.\n");
                break;

            case 4:
                if (read_double("Enter dividend: ", &a) &&
                    read_double("Enter divisor: ", &b)) {
                    if (b == 0.0) printf("Error: division by zero.\n");
                    else printf("Result: %.12g\n", a / b);
                } else printf("Invalid number.\n");
                break;

            case 5: {
                int x, y;
                if (!read_int("Enter first integer: ", &x) ||
                    !read_int("Enter second integer: ", &y))
                    printf("Invalid integer.\n");
                else if (y == 0)
                    printf("Error: modulus by zero.\n");
                else
                    printf("Result: %d\n", x % y);
                break;
            }

            case 6:
                if (read_double("Enter base: ", &a) &&
                    read_double("Enter exponent: ", &b)) {
                    result = pow(a, b);
                    if (isnan(result) || isinf(result))
                        printf("Error: invalid numeric result.\n");
                    else
                        printf("Result: %.12g\n", result);
                } else printf("Invalid number.\n");
                break;

            case 7:
                if (read_double("Enter number: ", &a)) {
                    if (a < 0.0) printf("Error: negative square root.\n");
                    else printf("Result: %.12g\n", sqrt(a));
                } else printf("Invalid number.\n");
                break;

            case 8:
                if (read_double("Enter percentage: ", &a) &&
                    read_double("Enter value: ", &b))
                    printf("Result: %.12g\n", (a / 100.0) * b);
                else printf("Invalid number.\n");
                break;

            default:
                printf("Invalid option. Choose 1-9.\n");
        }
    }
}
