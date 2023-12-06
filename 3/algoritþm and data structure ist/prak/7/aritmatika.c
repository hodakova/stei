// NIM       : 18222082
// Nama      : Ahmad Habibie Marjan
// Tanggal   : 23年10月24日
// Topik     : Prapraktikum 7
// Deskripsi : Program implementasi aritmatika.h

#include "aritmatika.h"

boolean isOperator(char input)
/* Proses: Mengecek apakah input merupakan operator */
/*         input adalah operator jika input merupakan salah
           satu dari berikut:
                - +
                - -
                - *
                - /
*/
{
    return input == '+' || input == '-' || input == '*' || input == '/';
}

int hitung(int angka1, int angka2, char op)
/* Proses: Menghitung ekspresi */
/*
    Contoh input / output:
    angka1 : 2
    angka2 : 10
    op     : -

    return : -8 (penjelasan: 2 - 10 = 8)
*/
{
    int res;
    if(op == '+')
        res = angka1 + angka2;
    else if(op == '-')
        res = angka1 - angka2;
    else if(op == '*')
        res = angka1 * angka2;
    else if(op == '/')
        res = angka1 / angka2;
}

int eval(char *input, int length)
/* Proses: Menghitung keseluruhan ekspresi */
/* I.S. input adalah string. setiap operand dipastikan < 10 */
/*
    Contoh input / output:
    input   : 23+
    output  : 5 (penjelasan: ekspresi ekuivalen dengan 2 + 3)

    input   : 9423+*5/-
    output  : 5 (penjelasan: ekspresi ekuivalen dengan 9-(4*(2+3))/5)

*/
{
    Stack arith;
    CreateEmpty(&arith);
    int i, angka1, angka2, hasil;

    for(i = 0; i < length; i ++) {
        if(!isOperator(input[i]))
            Push(&arith, input[i] - '0'); // agar menjadi int yg sesuai dgn charnya
        else {
            Pop(&arith, &angka2);
            Pop(&arith, &angka1);
            hasil = hitung(angka1, angka2, input[i]);
            Push(&arith, hasil);
        }
    }
    Pop(&arith, &hasil);
    return hasil;
}