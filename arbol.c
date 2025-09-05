#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int valor;
    struct Nodo* izq;
    struct Nodo* der;
} Nodo;
Nodo* crearNodo(int valor) {
    Nodo* nuevo = (Nodo*) malloc(sizeof(Nodo));
    nuevo->valor = valor;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    return nuevo;
}
Nodo* insertar(Nodo* nodo, int x) {
    if (nodo == NULL) {
        return crearNodo(x);
    }
    if (x < nodo->valor) {
        nodo->izq = insertar(nodo->izq, x);
    } else {
        nodo->der = insertar(nodo->der, x);
    }
    return nodo;
}
void preorden(Nodo* nodo) {
    if (nodo != NULL) {
        printf("%d ", nodo->valor);
        preorden(nodo->izq);
        preorden(nodo->der);
    }
}
void inorden(Nodo* nodo) {
    if (nodo != NULL) {
        inorden(nodo->izq);
        printf("%d ", nodo->valor);
        inorden(nodo->der);
    }
}
void postorden(Nodo* nodo) {
    if (nodo != NULL) {
        postorden(nodo->izq);
        postorden(nodo->der);
        printf("%d ", nodo->valor);
    }
}
void liberarArbol(Nodo* nodo) {
    if (nodo != NULL) {
        liberarArbol(nodo->izq);
        liberarArbol(nodo->der);
        free(nodo);
    }
}
int main() {
    Nodo* raiz = NULL;

    raiz = insertar(raiz, 10);
    insertar(raiz, 8);
    insertar(raiz, 13);
    insertar(raiz, 5);
    insertar(raiz, 9);
    insertar(raiz, 12);
    insertar(raiz, 20);

            printf("PREORDEN:\n");
                preorden(raiz);
            printf("\nINORDEN:\n");
                inorden(raiz);
            printf("\nPOSTORDEN:\n");
                postorden(raiz);

    printf("\n");
    liberarArbol(raiz);
    return 0;
}
