
import numpy as np
import pygame
import random 
import time
import cmath
from colorsys import hls_to_rgb


from pygame.locals import (
    K_UP,
    K_DOWN,
    K_LEFT,
    K_RIGHT,
    K_ESCAPE,
    KEYDOWN,
    QUIT,
)
width = 2000
height = 1500
grid = 1
depth =   100

frameLeft = -3
frameRight = 1 
frameTop = 1.5
frameBottom = -1.5


pygame.init()
screen = pygame.display.set_mode((width, height))

surfB = pygame.Surface((grid, grid))
surfB.fill((50, 50, 50))



running = True

def draw_gray(x,y, count):
    surfG = pygame.Surface((grid, grid))
    scalar = (100 * count) // depth
    surfG.fill((scalar+10, 0, 2*scalar + 20))
    screen.blit(surfG, (x*grid % width, y*grid % height))
def draw_black(x,y):
    screen.blit(surfB, (x*grid % width, y*grid % height))

def inSet(x,y):
    X = float(x) /(width//grid) *(frameRight - frameLeft) + frameLeft
    Y = float(y) /(height//grid) *(frameBottom-frameTop) + frameTop
  
    C = complex(X,Y)
    count = 0 
    while count < depth and -2 < C.real < 2 and -2 < C.imag < 2:
        C = C ** 2 + complex(X,Y)
        count = count + 1 
    return count


def solve(x1,x2,y1,y2):
    if  x2-x1 < 2 and y2-y1 < 2:
        return 
    temp = True
    temp2 = True
    for i in range(x1,x2):
        count = inSet(i,y1)
        if count == depth:
            draw_black(i,y1)
            temp2 = False
        else:    
            draw_gray(i,y1, count)
            temp = False
    for i in range(x1,x2):
        count = inSet(i,y2)
        if count == depth:
            draw_black(i,y2)
            temp2 = False
        else:    
            draw_gray(i,y2, count)
            temp = False
    for i in range(y1,y2):
        count = inSet(x1,i)
        if count == depth:
            draw_black(x1,i)
            temp2 = False
        else:    
            draw_gray(x1,i, count)
            temp = False
    for i in range(y1,y2):
        count = inSet(x2,i)
        if count == depth:
            draw_black(x2,i)
            temp2 = False
        else:    
            draw_gray(x2,i, count)
            temp = False            
    if temp == True: 
        surfS = pygame.Surface(((x2-x1)*grid, (y2-y1)*grid))
        surfS.fill((50, 50, 50))
        screen.blit(surfB, (x1*grid % width, y1*grid % height))
        return
    if temp2 == True and (x2 - x1 < 50 or y2-y1 < 50):
        surfS = pygame.Surface(((x2-x1)*grid, (y2-y1)*grid))
        surfS.fill((200, 200, 200))
        screen.blit(surfB, (x1*grid % width, y1*grid % height))
        return
    pygame.display.flip()
    if x2 - x1 > y2 - y1:
        xbar = (x2+x1)//2
        solve(x1,xbar,y1,y2)
        solve(xbar,x2,y1,y2)
    else:
        ybar = (y2+y1)//2
        solve(x1,x2,y1,ybar)
        solve(x1,x2,ybar,y2)


screen = pygame.display.set_mode((width, height))

solve(0,width,0,height)

pygame.display.flip()
time.sleep(1)





while running:
    
    for event in pygame.event.get():
        if event.type == KEYDOWN:
            if event.key == K_ESCAPE:
                running = False
        elif event.type == QUIT:
            running = False
