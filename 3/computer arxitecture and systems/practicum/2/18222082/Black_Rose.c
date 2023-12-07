// ブラックローズ

void Black_Rose() {
    int i, a = 1, d[6];
    read_six_numbers(d);
    for(i = 0; i < 6; i ++) {
        if(i % 2)
            a *= i;
        else
            a += i;
        if(a != d[i])
            illegal_move();
    }
    printf("Looks like it's too easy huh? The second area is still merely warm-up.\n");
}