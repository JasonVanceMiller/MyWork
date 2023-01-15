from urllib import request
import os 
from bs4 import BeautifulSoup
import requests
from urllib.request import Request, urlopen
import time 
#from selenium import webdriver
#from requests_html import HTMLSession 


def get_data(j):
    id = 356379
    url = f'https://online-go.com/player/{id}/'
    urldata = f"https://online-go.com/api/v1/players/356379/games/?ended__isnull=false&ordering=-ended&page={j}&page_size=10&source=play"
    player = 'WolV'

    req = requests.get(urldata)
    data = req.json()
    count = data['count']
    var = 10
    if count < (j-1) * 10:
        var = count - (j-2)*10
    
    for i in range(var):
        time.sleep(1)
        game_id = data['results'][i]['id']

        if data['results'][i]['black_lost'] == True:
            winner = 'white'
        elif data['results'][i]['white_lost'] == True:
            winner = 'black'
        else:
            winner = 'none'
            
        size = data['results'][i]['width']
        size = f"{size}x{size}"

        if data['results'][i]['players']['white']['id'] == id:
            my_color = 'white'
        elif data['results'][i]['players']['black']['id'] == id:
            my_color = 'black'
        else:
            my_color = 'none'

        if my_color == winner:
            outcome = "won"
        else:
            outcome = "loss"


        if True:

            sgf_url = f'https://online-go.com/api/v1/games/{game_id}/sgf'
            req2 = requests.get(sgf_url, allow_redirects=True)
            path = f"SGFs/{size}/{my_color}/{outcome}"
            if not os.path.exists(path):
                os.makedirs(path)
            open(f'{path}/game{10*j - 20 + i}.sgf','wb').write(req2.content) 


        print(f"game number = {10*j - 20 + i} game_id = {game_id} \n winner = {winner} \n my color = {my_color} \n size = {size}")
if False:
    for j in range(17,300):
        get_data(j)



def sgf_to_map(path):
    print(path)
    data = open(path, "r").read()[2:-1]
    data = data[data.find(';') - 1 :]
    data = data.replace(')','')
    data = data.replace('(','')
    data = data.replace('\n','')
    s = data.split(';')
    s = s[1:10]
    l = []
    for i in range(len(s)):
        l = [[s[len(s)-i-1]], [l]]
    return l

#M is the larger of the two 
def merge (m, n):
    tm = m 
    tn = n 
    while len(tn) > 0 and len(tm) > 0: 
        
        
        if tn[0][0] in tm[0]:
            index = tm[0].index(tn[0][0])
            tm = tm[1][index]
            tn = tn[1][0]
        else:
            tm[0].append(tn[0][0])
            tm[1].append(tn[1][0])
            return 

    if len(tn) > 0:
        tm = tn 

def map_to_sgt(map):
    s = ''   
    #base case 
    if len(map) == 0:
        return ''
    for i in range(len(map[0])):
        s = s + f"(;{map[0][i]}" + map_to_sgt(map[1][i]) + ")"
    return s 



games = os.listdir("SGFs/19x19/black/won/").reverse()

s1 = sgf_to_map("SGFs/19x19/black/won/game5.sgf")
for i in range(2,80):
    s2 = sgf_to_map(f"SGFs/19x19/white/won/{games[i]}")
    merge(s1,s2)

out = ";" + map_to_sgt(s1)
open('out.sgf','w').write(out) 
