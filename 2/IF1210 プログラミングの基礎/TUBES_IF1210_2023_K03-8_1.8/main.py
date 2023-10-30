from functions import F13
import commands

F13.load()
while True:
    masukan = input(">>> ")
    commands.run(masukan)