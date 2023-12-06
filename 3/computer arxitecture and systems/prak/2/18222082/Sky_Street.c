// スカイストリート

int func4(int a) {
    if(a == 0)
        return 7;
    else
        return 7 * func4(a - 1);
}

void Sky_Street() {
    int d, e;
    scanf("%d %d", &d, &e);
    if(func4(d) != e || e != 117649)
        illegal_move();
    printf("Upon traversing the sky street you started to realize something and that the key lies on the ##@64#$#\n");
}