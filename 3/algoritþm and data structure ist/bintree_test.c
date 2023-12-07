// #include "bintree.h"
#include "1207_bintree.c"

int main() {
    BinTree p, q, r, s, t, u, v, w, x, y, z;
    p = newTreeNode(1);
    CreateTree(1, newTreeNode(2), newTreeNode(3), &q);
    printPreorder(p); printf("\n");
    printPreorder(q); printf("\n");
    printInorder(p); printf("\n");
    printInorder(q); printf("\n");
    printPostorder(p); printf("\n");
    printPostorder(q); printf("\n");
    printTree(p, 2);
    printTree(q, 2);
    return 0;
}