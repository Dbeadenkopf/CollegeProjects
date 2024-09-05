import requests
from bs4 import BeauifulSoup





def news():

    url = 'https://www.gameinformer.com/2022/02/04/dying-light-2-pc-player-count-nearly-four-times-more-than-dying-lights-all-time-peak'
    resp = reqeusts.get(url)

    if resp.status.get(url) == 200:
        print("Successfully opened the webpage")
        print("The news are as follow :-\n")

        #useing a python built in parser
        soup = BeautifulSoup(resp.text,'html.parser')

        #l is the list which contains all the test i.e. news
        L=soup.find("ul", {"class": "searchNews"})

        #now to print out all the text parts
        for i in L.findall("a"):
            print(i.text)
            
    else:
        print("Error")

news()
