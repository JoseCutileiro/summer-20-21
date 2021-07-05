"""
License @gnu
author: José Cutileiro
font: freeCodeCamp.org
"""

import turtle
import random

jan = turtle.Screen()
jan.title("|||| Pong |||| @summer 20/21")
jan.bgcolor("black")
jan.setup(width=700,height=700)
jan.tracer(0)

# color palet 
# more info: https://cs111.wellesley.edu/labs/lab01/colors

def random_color():
    cs = ["white","magenta","SeaGreen1","tan","red","orange","blue"]
    r = random.randrange(0,6)
    return cs[r]


# padle base

def padle_creator(p):
    p = turtle.Turtle()
    p.speed(0)
    p.shape("square")
    p.color("white")
    p.shapesize(stretch_wid=5,stretch_len=1)
    p.penup()
    return p

def ball(b):
    b = turtle.Turtle()
    b.speed(0)
    b.shape("circle")
    b.color(random_color())
    b.dx = random.random()
    b.dy = random.random()
    b.penup()
    return b

# P1 && P2

p = turtle.Turtle()
p1 = padle_creator(p)
p2 = padle_creator(p)
p1.goto(-250,0)
p2.goto(250,0)

# Ball

b = turtle.Turtle()
b1 = ball(b)
b2 = ball(b)
b3 = ball(b)
b4 = ball(b)

# Movement

def p1_up():
    y = p1.ycor()
    y += 40
    p1.sety(y)

def p1_down():
    y = p1.ycor()
    y -= 40
    p1.sety(y)

def p2_up():
    y = p2.ycor()
    y += 40
    p2.sety(y)

def p2_down():
    y = p2.ycor()
    y -= 40
    p2.sety(y)

# Read keyboard

jan.listen()
jan.onkeypress(p1_up,"w")
jan.onkeypress(p1_down,"s")
jan.onkeypress(p2_up,"Up")
jan.onkeypress(p2_down,"Down")

# Game loop

while True:
    jan.update()

    # ball movement

    #b1.setx(b1.xcor() + b1.dx)
    #b1.sety(b1.ycor() + b1.dy)

    # border

    for e in [b1,b2,b3,b4]:
        
        e.setx(e.xcor() + e.dx)
        e.sety(e.ycor() + e.dy)


        if e.ycor() > 330:
            e.sety(330)
            e.dy *= -1

        if e.ycor() < -330:
            e.sety(-330)
            e.dy *= -1

        if e.xcor() > 330:
            e.setx(330)
            e.dx *= -1

        if e.xcor() < -330:
            e.setx(-330)
            e.dx *= -1
    
        # p collision

        if  -250<e.xcor()<-230 and e.ycor() < p1.ycor()+40 and e.ycor() > p1.ycor() -40:
            e.dx *= -1
        if  250<e.xcor()<270 and e.ycor() < p2.ycor()+40 and e.ycor() > p2.ycor() -40:
            e.dx *= -1