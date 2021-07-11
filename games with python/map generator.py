"""
@gnu
author: José Cutleiro

nota: Por vezes vai demorar algum tempo a configurar,
significa que o mundo é bastante complexo com várias ilhas
se não pretendes muita complexidade no mapa podes reduzir
a variavel global
"""
import turtle
import random

jan = turtle.Screen()
jan.title("|||| World map generator |||| @summer 20/21")
jan.bgcolor("black")
jan.setup(width=700,height=700)
jan.tracer(0)

t = turtle.Turtle()
t.color("white")

#constantes
up = 5
t.speed(0)
def pixel(x,y,color):
    t.penup()
    t.goto(x,y)
    t.pendown()
    t.color(color)
    i = 0
    t.begin_fill()
    while(i<4):
        t.forward(up)
        t.left(90)
        i+=1
    t.end_fill()

def update(r):
    notchange = random.randint(0,13)
    if not notchange and r:
        r = 0
    elif not notchange and not r:
        r = 1
    return r

def eval_color(r):
    if (r):
        cor = "white"
    if (not r):
        cor = "black"
    return cor

r = random.randint(0,1)
cor = eval_color(r)

# strip worldenized
x = -300
y = -300
while (x<=-250):
    y = -300
    while (y<=-250):
        pixel(x,y,cor)
        r = update(r)
        cor = eval_color(r)
        y+=up

    x+=up

# random world
up = 1
i = random.randint(2,10)
while (i):
    x = random.randint(-100,100)
    y = random.randint(-100,100)
    j = 0
    isle = random.randint(100,5000)
    while j<isle:
        pixel(x,y,"white")
        x += random.randint(-1,1)*up
        y += random.randint(-1,1)*up
        j +=1
    i-=1

# main loop 
while True:
    jan.update()
