from urllib import request
from bs4 import BeautifulSoup
import requests
from urllib.request import Request, urlopen
#from selenium import webdriver
#from requests_html import HTMLSession 

def print_data():
    print(f"game_id = {game_id} \n winner = {winner} \n my color = {my_color}")


id = 356379
url = f'https://online-go.com/player/{id}/'
urldata = 'https://online-go.com/api/v1/players/356379/games/?page_size=1&page=1&source=play&ended__isnull=false&ordering=-ended'
winner = ''
player = 'WolV'
my_color =  ''

req = requests.get(urldata)
data = req.json()
i = 0 
game_id = data['results'][i]['id']

#winner
if data['results'][i]['black_lost']:
    winner = 'white'
elif data['results'][i]['white_lost']:
    winnner = 'black'
else:
    winner = 'none'

print(winner)
print(data['results'][i]['players']['white']['id'])
if data['results'][i]['players']['white']['id'] == id:
    my_color = 'white'
elif data['results'][i]['players']['black']['id'] == id:
    my_color = 'black'
else:
    my_color = 'none'

if True:

    sgf_url = f'https://online-go.com/api/v1/games/{game_id}/sgf'
    req2 = requests.get(sgf_url, allow_redirects=True)
    open('19x19/game0','wb').write(req2.content) 


print_data()


