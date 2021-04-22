c = 12

def examOne():
c = 10
examTwo(c)

def examTwo(v):
v = v + 20
examThree(c, v)

def examThree(v, b):
c = 20
print(c + v + b)

examOne()
