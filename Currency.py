from bs4 import BeautifulSoup
import requests

def find_currency(currency):
    #currency = any(USD, EUR, UZS)
    page = requests.get('https://www.cbr.ru/currency_base/daily/')
    soup = BeautifulSoup(page.text, 'html.parser')
    rows = soup.find_all('tr')
    for row in rows:
        cells = row.find_all('td')
        if len(cells) > 1 and cells[1].get_text(strip=True) == currency:
            return cells[-1].get_text(strip=True)
