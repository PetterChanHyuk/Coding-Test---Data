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
    int isFirstTerm = 1; // 첫 번째 항인지 확인하는 플래그

    for (int i = 0; i < poly.size; i++) {
        if (poly.terms[i].coef == 0) {
            continue; // 계수가 0인 항은 출력하지 않음
        }

        // 첫 번째 항이 아니고 계수가 양수일 경우 '+'를 붙임
        if (!isFirstTerm && poly.terms[i].coef > 0) {
            printf(" + ");
        }

        // 계수가 음수일 경우 '-'를 붙임
        if (poly.terms[i].coef < 0) {
            // 첫 번째 항이 음수일 경우 isFirstTerm를 False로 설정
            isFirstTerm = 0;
            printf(" - ");
        }

        // 절대값을 사용하여 계수 출력
        float absCoef = fabs(poly.terms[i].coef);
        printf("%.2f", absCoef);

        if (poly.terms[i].exponX > 0) { // x의 지수가 0보다 크면 출력
            printf("x^%d", poly.terms[i].exponX);
        }
        if (poly.terms[i].exponY > 0) { // y의 지수가 0보다 크면 출력
            if (poly.terms[i].exponX > 0) printf("*"); // x 지수가 있으면 *를 추가
            printf("y^%d", poly.terms[i].exponY);
        }
        isFirstTerm = 0; // 첫 번째 항 출력 완료
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

    printf("결과: ");
    printPolynomial(result);

    free(A.terms);
    free(B.terms);
    free(result.terms);

    return 0;
}
