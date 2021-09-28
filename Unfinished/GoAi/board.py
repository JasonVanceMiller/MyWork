import time
import random
class goban:
    def __init__(self, size):
        
        self.size = size
        self.goban = []
        for i in range(0,size):
            self.goban.append([])
            for j in range(0,size):
                self.goban[i].append('empty')
    


    def get(self,x,y):
        if 0 <= x < self.size and 0 <= y < self.size:
            return self.goban[x][y]
        else:
            #print("Error, oob on get")
            return "error"

    def place(self,x,y,move):
        if 0 <= x < self.size and 0 <= y < self.size:
            if self.get(x,y) == 'empty':
                self.goban[x][y] = move
                return 0
            #print("invalid move on {x}, {y}")
            return -1
        else:
            #print("Error, oob on place")
            return -1

    def delete(self,x,y):
        if 0 <= x < self.size and 0 <= y < self.size:
            self.goban[x][y] = "empty"
        else: 
            #print("Error, oob on delete")
            return -1

    def print(self):
        spacing = " "
        print(" ", end = spacing)
        for i in range(0,self.size):
            print(f"{i+1}",end = spacing)
        print("")
        for x in range(0,self.size):
            print(f"{x+1}", end = spacing)
            for y in range(0,self.size):
                if self.get(x,y) == "empty":
                    print("+", end = spacing)
                if self.get(x,y) == "black":
                    print("○", end = spacing)
                if self.get(x,y) == "white":
                    print("●", end = spacing)
            print("")
        print('')

    #return -1 if no deletions 
    def check_captures(self,color):
        error = -1
        for x in range(0,self.size):
            for y in range(0,self.size):
                if self.get(x,y) == color: 
                    group = self.get_group(x,y)
                    if self.lib(group) == 0:
                        for stone in group:
                            self.delete(stone[0],stone[1])
                            error = 0 
        return error 

    def get_group(self,x,y):    
        color = self.get(x,y)
        
        temp_group = []
        group = []
        group.append((x,y))
        temp_group.append((x,y))
        while(len(temp_group) > 0):
            temp_stone = temp_group.pop(0)
            X = temp_stone[0]
            Y = temp_stone[1]
            if (X-1,Y) not in group and self.get(X-1,Y) == color:
               temp_group.append((X-1,Y))
               group.append((X-1,Y))
            if (X+1,Y) not in group and self.get(X+1,Y) == color:
               temp_group.append((X+1,Y))
               group.append((X+1,Y))
            if (X,Y-1) not in group and self.get(X,Y-1) == color:
               temp_group.append((X,Y-1))
               group.append((X,Y-1))
            if (X,Y+1) not in group and self.get(X,Y+1) == color:
               temp_group.append((X,Y+1))
               group.append((X,Y+1))
                
        return group

    def single_lib(self,x,y):
        libs = set([])
        if self.get(x-1,y) == "empty":
            libs.add((x-1,y))    
        if self.get(x+1,y) == "empty":
            libs.add((x+1,y))    
        if self.get(x,y-1) == "empty":
            libs.add((x,y-1))    
        if self.get(x,y+1) == "empty":
            libs.add((x,y+1))    
        return libs
    
    def lib(self,group):
        libs = set([])
        for stone in group: 
            libs = set.union(libs,self.single_lib(stone[0],stone[1]))
        return len(libs)

    def copy(self):
        gb2 = goban(self.size)
        temp = []
        for i in range(0,self.size):
            temp.append(self.goban[i].copy())
        gb2.goban = temp
        return gb2

    def score(self, color):
        temp = 0
        for x in range(0,self.size):
            for y in range(0,self.size):
                if self.get(x,y) == color:
                    temp = temp + 1
        return temp

    #0 is valid move, 1 is pass, -1 if collision, -2 if suicide, -x fails heuristic 
    def play(self, x, y, color):
        x = x - 1
        y = y - 1
        if x < 0 and y < 0:
            return 1
        backup = self.copy()
        error = self.place(x,y,color)
        if error < 0:
            return error
        if color == "black":
            if self.check_captures("white") == -1 and self.check_captures("black") != -1:
                self.goban = backup.goban
                return -2
        if color == "white":
            if self.check_captures("black") == -1 and self.check_captures("white") != -1:
                self.goban = backup.goban
                return -2
        return 0
