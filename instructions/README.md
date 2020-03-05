# Instructions

## PokeURL
Read a file containing a list of URLs, line delineated, to provide a user with an interactive
terminal to view the different sites visited. The user should be able to print a list of all 
root domains, a list of pages on a root domain, and a list of all information, root domains 
and pages nested under the root domain. The lists should be sorted alphabetically by default.
The root domains should be able to be sorted by frequency of pages visited.

## Requirements
Requirements: | |
------------ | -------------
Written in C |
Compiled flags: | `-std=c11 -Wall -Werror -Wvla -Wextra`<br>`-Wpedantic -Wwrite-strings -Wstack-usage=512`
Operating system | ubuntu 18.04
URLS will be formatted (in file): | `http[s]://ROOT/PAGES`
Accept URL file | default file from resources/.urls or command line
Option flags:  | `-r` Reverse root domain alphabetic sort 
|              | `-f` Frequency of root visited sort then alphabetical sort
|              | `-F` Reverse frequency of root sort then alphabetical sort
|              | `-h` Help menu
|              | (NOTE: Sorting of frequency and names can be combined: `-rf` Sort by ascending count and descending alpabetical)
User interaction: | `ALL` will display all root domains with sub pages underneath sorted by
|                 | `ROOT` will display all the root domains and their frequency
|                 | `{root}` will display the root domain their frequency and the pages associated with it
|                 |(Note: CTRL-d will cancel user input session and close program)
File structure: | <pre>../<br>└── project<br>  ├── Makefile<br>  ├── README.md<br>  ├── bin/<br>  ├── doc/<br>  ├── include/<br>  ├── obj/<br>  ├── resource/<br>  ├── src/<br>  └── test/</pre>
No memory leaks | Use valgrind
Assumptions | Assume case insensitivity |
URLS | URLs will be generated using the urlGenny provided |
|    | ./urlGenny.py 5 : will generate 5 urls |
|    | ./urlGenny.py 100 2 : will generate 100 urls with a 1 in 2 chance of being a duplicate URL |
|    | ./urlGenny.py 100 100 : will generate 100 urls with a 1 in 100 chance of being a duplicate |

------------

## Examples:
```bash
# ./urlgenny.py 5 >> resource/.urls
cat resource/.urls
https://pikachu.pom/daily.html
http://gyms.cr/gym_list.htm
http://gyms.cr/gym_blue.htm
http://gyms.cr/gym_green.htm
https://blastoise.pom/attacks/water-cannon.html
```

#### *ALL* example (Default sorting)
```bash
Select:> ALL
blastoise.pom 1
  attacks/water-cannon.html
gyms.cr 3
  gym_blue.htm
  gym_green.htm
  gym_list.htm
pikachu.pom 1
  daily.html
```

#### *ROOT* example (Default sorting)
```bash
Select:> ROOT
blastoise.pom 1
gyms.cr 3
pikachu.pom 1
```

#### *Root search* example (Default sorting)
```bash
Select:> gyms.cr
gyms.cr 3
  gym_blue.htm
  gym_green.htm
  gym_list.htm
```

## Notes:
> - Valid URL's will start with http:// or https://
> - Subdomains of a root are different root domains:
>    <div>ww<span>w.</span>root.com != root.com</div>
> - All urls will end in `.pom`, `.pedu`, and `.porg`

## Features for challenges
- Allow for sorting in the command line on the fly
- Use an AVL to hold the items
- Add page frequency records
- Handle other signals
- Cunit testing for modules
