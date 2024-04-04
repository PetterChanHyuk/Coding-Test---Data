#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    float coef;
    int exponX;
    int exponY;
} Term;

typedef struct {
    Term *terms;
    int size;
    int capacity;
} Polynomial;

Polynomial createPolynomial(int capacity) {
    Polynomial poly;
    poly.terms = (Term *)malloc(capacity * sizeof(Term));
    poly.size = 0;
    poly.capacity = capacity;
    return poly;
}

void addTerm(Polynomial *poly, float coef, int exponX, int exponY) {
    for (int i = 0; i < poly->size; i++) {
        if (poly->terms[i].exponX == exponX && poly->terms[i].exponY == exponY) {
            poly->terms[i].coef += coef;
            return;
        }
    }
    poly->terms[poly->size].coef = coef;
    poly->terms[poly->size].exponX = exponX;
    poly->terms[poly->size].exponY = exponY;
    poly->size++;
}

int compareTerms(const void *a, const void *b) {
    Term *termA = (Term *)a;
    Term *termB = (Term *)b;
    if (termA->exponX > termB->exponX) return -1;
    else if (termA->exponX < termB->exponX) return 1;
    else if (termA->exponY > termB->exponY) return -1;
    else if (termA->exponY < termB->exponY) return 1;
    return 0;
}

Polynomial multiplyPolynomials(Polynomial A, Polynomial B) {
    Polynomial result = createPolynomial(A.size * B.size);
    for (int i = 0; i < A.size; i++) {
        for (int j = 0; j < B.size; j++) {
            float coef = A.terms[i].coef * B.terms[j].coef;
            int exponX = A.terms[i].exponX + B.terms[j].exponX;
            int exponY = A.terms[i].exponY + B.terms[j].exponY;
            addTerm(&result, coef, exponX, exponY);
        }
    }
    qsort(result.terms, result.size, sizeof(Term), compareTerms);
    return result;
}

void printPolynomial(Polynomial poly) {
    int isFirstTerm = 1; // ù ��° ������ Ȯ���ϴ� �÷���

    for (int i = 0; i < poly.size; i++) {
        if (poly.terms[i].coef == 0) {
            continue; // ����� 0�� ���� ������� ����
        }

        // ù ��° ���� �ƴϰ� ����� ����� ��� '+'�� ����
        if (!isFirstTerm && poly.terms[i].coef > 0) {
            printf(" + ");
        }

        // ����� ������ ��� '-'�� ����
        if (poly.terms[i].coef < 0) {
            // ù ��° ���� ������ ��� isFirstTerm�� False�� ����
            isFirstTerm = 0;
            printf(" - ");
        }

        // ���밪�� ����Ͽ� ��� ���
        float absCoef = fabs(poly.terms[i].coef);
        printf("%.2f", absCoef);

        if (poly.terms[i].exponX > 0) { // x�� ������ 0���� ũ�� ���
            printf("x^%d", poly.terms[i].exponX);
        }
        if (poly.terms[i].exponY > 0) { // y�� ������ 0���� ũ�� ���
            if (poly.terms[i].exponX > 0) printf("*"); // x ������ ������ *�� �߰�
            printf("y^%d", poly.terms[i].exponY);
        }
        isFirstTerm = 0; // ù ��° �� ��� �Ϸ�
    }
    printf("\n");
}


int main() {
    Polynomial A = createPolynomial(3);
    addTerm(&A, 3, 0, 7); // 3y^7
    addTerm(&A, 4, 4, 0); // 4x^4
    addTerm(&A, -1, 0, 0); // 1

    Polynomial B = createPolynomial(3);
    addTerm(&B, 5, 4, 0); // 5x^4
    addTerm(&B, -3, 0, 2); // -3y^2
    addTerm(&B, 7, 0, 0); // 7

    Polynomial result = multiplyPolynomials(A, B);

    printf("���: ");
    printPolynomial(result);

    free(A.terms);
    free(B.terms);
    free(result.terms);

    return 0;
}
