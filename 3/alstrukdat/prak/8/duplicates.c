// NIM       : 18222082
// Nama      : Ahmad Habibie Marjan
// Tanggal   : 23年11月03日
// Topik     : Praktikum 8
// Deskripsi : Program implementasi duplicates.h

#include "duplicates.h"

boolean hasDuplicate(int n, int *nums, int k)
/* I.S Array nums bisa kosong, n merupakan panjang array nums, k merupakan integer positif */
/* F.S Mengembalikan boolean apabila terdapat duplicate number pada rentang k di array nums. 
Apabila nums kosong atau hanya 1 elemen maka mengembalikan nilai false */
{
    boolean found = false; int i = 0; HashMap cheque; CreateEmpty(&cheque);
    while(i < n && !found) {
        if(Value(cheque, nums[i]) == Undefined)
            Insert(&cheque, nums[i], i);
        else {
            if(i - Value(cheque, nums[i]) <= k) //cheque la distance
                found = true;
            else
                cheque.Elements[Hash(nums[i])].Value = i; //changer la valeur
        }
        i ++;
    }
    return found;
}
/* 
  Contoh:
- nums: [5, 6, 8, 2, 4, 6, 9]
  k: 4

  return: true
  Penjelasan: Elemen 6 berulang dengan jarak 4 yang mana <= k

- nums: [5, 6, 8, 2, 4, 6, 9]
  k: 2

  return: false
  Penjelasan: Tidak ada elemen berulang dengan jarak k = 2
*/