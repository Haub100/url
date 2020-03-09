#!/usr/bin/env python3

import random
import argparse

class URL:
    def __init__(self):
        self.root = ""
        self.domain = ""
        self.page = ""

    def __str__(self):
        return "https://www.{}.{}/{}".format(self.root, self.domain, self.page)

def main():
    parser = argparse.ArgumentParser(description='Generate random Urls')
    parser.add_argument('num_urls', type=int)
    parser.add_argument('dups', nargs='?', default=3, type=int, help='adjust duplicate value chance. 1 in dups chance of being a duplicate')


    args = parser.parse_args()

    if args.dups <= 0:
        args.dups = 1
    
    roots = [
    "red",
    "blue",
    "green",
    "yellow",
    "gold",
    "silver",
    "crystal",
    "ruby",
    "sapphire",
    "emerald",
    "diamond",
    "pearl",
    "platinum",
    "black",
    "white",
    "x",
    "y",
    "sun",
    "moon",
    "ultrasun",
    "ultramoon",
    "sword",
    "shield",
    "isleofarmor",
    "crowntundra"
    ]

    domains = [
    "pom",
    "pedu",
    "porg"
    ]

    pages = list()

    pagesI = [
    "houses",
    "shops",
    "gyms",
    "pokecenters",
    "towns"
    ]

    pagesII = [
    "location",
    "inhabitants",
    "items",
    "pokemon",
    ]

    pagesIII = [
    "list.json",
    "map.jpg",
    "info.csv",
    "stats.html",
    ]

    for pageI in pagesI:
        pages.append(pageI + ".html")
    for pageII in pagesII:
        pages.append(pageII + ".html")
    for pageIII in pagesIII:
        pages.append(pageIII)

    for pageI in pagesI:
        for pageII in pagesII:
            pages.append(pageI + "/" + pageII)
            for pageIII in pagesIII:
                pages.append(pageI + "/" + pageII + "/" + pageIII)

    # INSERT RANDOM GENERATOR HERE
    random.seed()
    urls = list()
    for i in range(args.num_urls):
        rando = random.randint(1,args.dups)
        if rando == 1 and urls:
            urls.append(random.choice(urls))
        else:
            tmp = URL()
            tmp.root = random.choice(roots)
            tmp.domain = random.choice(domains)
            tmp.page = random.choice(pages)
            urls.append(tmp)

    random.shuffle(urls)

    for url in urls:
        print(str(url))


if __name__ == "__main__":
    main()
