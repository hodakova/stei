// メトロポリス

void Metropolis() {
    int d, e;
    scanf("%d %d", &d, &e);
    switch (d) {
    case 1:
        if(e != 444)
            illegal_move();
        break;
    case 2:
        if(e != 444)
            illegal_move();
        break;
    case 3:
        if(e != 804)
            illegal_move();
        break;
    case 4:
        if(e != 856)
            illegal_move();
        break;
    case 5:
        if(e != 142)
            illegal_move();
        break;
    case 6:
        if(e != 714)
            illegal_move();
        break;
    case 7:
        if(e != 444)
            illegal_move();
        break;
    case 8:
        if(e != 444)
            illegal_move();
        break;
    case 9:
        if(e != 444)
            illegal_move();
        break;
    default:
        illegal_move();
        break;
    }
    printf("Kurohime's metropolis has been conquered. The street above the sky awaits.\n");
}