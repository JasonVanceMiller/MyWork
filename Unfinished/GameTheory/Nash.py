import numpy as np 


def dominated(P):
    #print(P)
    P1 = P[0]
    P2 = P[1]
    marked1 = []
    marked2 = []
    for i in range(P1.shape[0]):
        for j in range(P1.shape[0]):
            if j != i:
                test = True
                for k in range(P1.shape[1]):
                    test = test and P1.item(i,k) > P1.item(j,k)
                if test and j not in marked1:
                    marked1.append(j)
    for i in range(P2.shape[1]):
        for j in range(P2.shape[1]):
            if j != i:
                test = True
                for k in range(P2.shape[0]):
                    test = test and P2.item(k,i) > P2.item(k,j)
                if test and j not in marked2:
                    marked2.append(j)
    P1 = np.delete(P1,marked1,0)
    P2 = np.delete(P2,marked1,0)
    P1 = np.delete(P1,marked2,1)
    P2 = np.delete(P2,marked2,1)
    return [P1,P2]

def true_dom(P):
    D = [0,0]
    while not np.array_equal(D[0], P[0]) and not np.array_equal(D[1],P[1]):
        print("looping")
        D = P 
        P = dominated(P)
    return P

def test_sizes(matrices):
    if len(matrices) != 2:
        print("More than 2 players.")
        exit()
    if len(matrices[0]) != len(matrices[1]):
        print("Wrong col size")
        exit()
    for i in range(len(matrices[0])):
        if len(matrices[0][i]) != len(matrices[1][i]):
            print(f"Wrong size on row {i}.")
        exit()

def simp_nash(P):
    P1 = P[0]
    P2 = P[1]
    for i in range(P1.shape[0]):
        for j in range(P2.shape[0]):




def equlib(matrices):
    test_sizes(matrices)
    P = [np.matrix(matrices[0]),np.matrix(matrices[1])]
    print(P)
    P = true_dom(P)
    print(P)
    


def main():
    game = [[[1,1],[2,0]],[[1,0],[1,0]]]
    equlib(game)
if __name__ == "__main__":
    main()
