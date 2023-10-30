import dt

def ayamberkokok():
    count = 0
    for i in range (1,dt.Ncandi) :
        if dt.candi[i] != [None for i in range(5)]:
            count += 1

    if count >= 100:
        print("Kukuruyuk... Kukuruyuk...")
        print("Jumlah Candi : ",100)
        print("Yah, Bandung Bondowoso memenangkan permainan!")
        print("Hayoloh harus nikah sama Mas Bondo :D")
        exit()
    else:
        print("Kukuruyuk... Kukuruyuk...")
        print("Jumlah Candi : ",count)
        print("Selamat, Roro Jonggrang memenangkan permainan!")
        print("Hayoloh, Bandung Bondowoso marah")
        print("Roro Jonggrang dikutuk menjadi candi")
        exit()