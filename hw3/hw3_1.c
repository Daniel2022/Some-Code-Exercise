#include <stdio.h>

typedef struct {
    float operand1, operand2;
    char operator;
} bexpression;

float compute1(bexpression expr);
float compute2(bexpression *expr);

int main() {
  bexpression e;
  char repeat = 'y';

  do {
    printf("Enter expression (op1 op2 op) :\n");
    scanf("%f %f %c", &e.operand1, &e.operand2, &e.operator);
    printf("compute1 = %f\n", compute1(e));
    printf("compute2 = %f\n", compute2(&e));
    getchar();
    printf("\nContinue ('y' or 'n') :\n");
    scanf("%c", &repeat);
  } while (repeat == 'y');
  return 0;
}

float compute1(bexpression expr) {
  switch(expr.operator){
    case '+': return expr.operand1 + expr.operand2; break;
    case '-': return expr.operand1 - expr.operand2; break;
    case '*': return expr.operand1 * expr.operand2; break;
    case '/': return expr.operand1 / expr.operand2; break;
    default: printf("Not a correct operator.\n"); return 0;
  }
}

float compute2(bexpression *expr) {
  switch(expr->operator){
    case '+': return expr->operand1 + expr->operand2; break;
    case '-': return expr->operand1 - expr->operand2; break;
    case '*': return expr->operand1 * expr->operand2; break;
    case '/': return expr->operand1 / expr->operand2; break;
    default: printf("Not a correct operater.\n"); return 0;
  }
}
