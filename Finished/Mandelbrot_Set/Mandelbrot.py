
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
depth =   200

frameLeft = -3
frameRight = 1 
frameTop = 1.5
frameBottom = -1.5


pygame.init()
screen = pygame.display.set_mode((width, height))

surfB = pygame.Surface((grid, grid))
surfB.fill((0, 0, 0))



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


screen = pygame.display.set_mode((width, height))

for i in range(0,1):
    for x in range(0, width//grid):
        if x % 10 == 0:
            pygame.display.flip()
    
        for event in pygame.event.get():
            if event.type == KEYDOWN:
                if event.key == K_ESCAPE:
                    exit()
            elif event.type == QUIT:
                exit()

        for y in range(0,height//grid):          
            count = inSet(x,y)
            if count == depth:
                draw_black(x,y)
            else:    
                draw_gray(x,y, count)
    #frameTop = 0.275
    #frameBottom = -0.1
    #frameLeft = -1.5
    #frameRight = -1
    #pygame.display.flip()
    #time.sleep(1)





while running:
    
    for event in pygame.event.get():
        if event.type == KEYDOWN:
            if event.key == K_ESCAPE:
                running = False
        elif event.type == QUIT:
            running = False
