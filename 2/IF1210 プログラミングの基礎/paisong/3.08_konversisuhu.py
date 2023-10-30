fromCelcius = float(input())
convertTo = str(input())

if convertTo == 'R':
    result = 4/5*fromCelcius
elif convertTo == 'F':
    result = 9/5*fromCelcius+32
elif convertTo == 'K':
    result = fromCelcius + 273.15

print('{:.2f}'.format(result))