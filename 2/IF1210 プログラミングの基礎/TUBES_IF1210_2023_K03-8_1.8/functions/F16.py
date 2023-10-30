from functions import F14

def eksit():    
    ask = input("Apakah Anda mau melakukan penyimpanan file yang sudah diubah? (y/n) ")

    # ketika masukan salah (selain huruf y atau n)
    while ask!= "n" and ask!="N" and ask!="Y" and ask!="y":
        ask = input("Apakah Anda mau melakukan penyimpanan file yang sudah diubah? (y/n) ")

    if ask == "n" or ask == "N" :
        exit()
    elif ask == "y" or ask =="Y" :
        F14.save()
        exit()