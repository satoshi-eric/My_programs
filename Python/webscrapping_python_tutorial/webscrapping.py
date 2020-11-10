from bs4 import BeautifulSoup 
import requests
import csv

# with open('simple.html', 'r') as html_file:
#     soup = BeautifulSoup(html_file, 'lxml')

# print(soup.prettify())

# match = soup.title.text
# print(match)

# match = soup.find('div', class_ = 'footer')
# print(match)

# article = soup.find('div', class_ = 'article')
# print(article)

# for article in soup.find_all('div', class_ = 'article'):
#     headline = article.h2.a.text
#     print(headline)
    
#     summary = article.p.text
#     print(summary)
    
#     print()

source = requests.get('https://coreyms.com').text

soup = BeautifulSoup(source, 'lxml')

csv_file = open('cms_scrape.csv', 'w')

csv_writter = csv.writer(csv_file)
csv_writter.writerow(['headline', 'summary', 'video_link'])

# print(soup.prettify())
# article = soup.find('article')

for article in soup.find_all('article'):
    try:
        # print(article.prettify())

        headline = article.h2.a.text

        summary = article.find('div', class_ = 'entry-content').p.text

        vid_src = article.find('iframe', class_ = 'youtube-player')['src']

        vid_id = vid_src.split('/')[4]
        vid_id = vid_id.split('?')[0]
        # print(vid_id)

        yt_link = f'https://youtube.com/watch?v={vid_id}'

    except:
        yt_link = None
    
    print(headline)
    print(summary)
    print(vid_src)
    print(yt_link)
    print()

    csv_writter.writerow([headline, summary, yt_link])

csv_file.close()