# Flot Maximum

L'idée est de trouver le flot maximum qui peut circuler dans un réseau de transport ou informatique. Il se représente par un graphe où les arcs sont valués par les capacités (valeur maximale qui peut circuler sur cet arc). On rajoute une source et un puits s'ils n’existent pas. La source est reliée aux points de départ, avec comme valuations les disponibilités de ces points de départ. Les points d'arrivée sont reliés au puits avec comme valuation les demandes de ces points d'arrivée. On rajoute finalement un arc de retour virtuel de $p$ à $s$.

### Définition

1. **Un flot est une fonction s'appliquant sur les arcs d'un réseau de transport telle que** :

   * Sur chaque arc, le flot est positif ou nul et inférieur à la capacité,

   * En chaque nœud, la quantité totale de flot entrant est égale à la quantité totale du flot sortant (équivalent à la loi de Kirchhoff en électricité)

   L'idée est donc de trouver un flot qui maximise $f(p,s)$ ( - flot circulant dans le réseau).

2. **Un arc $(x,y)$ sur lequel le flot est égal à la capacité est dit <u>saturé</u>**.

3. **Un flot tel que, sur chaque chemin allant de $s$ à $p$, il existe au moins un arc saturé est dit <u>complet</u>**

### Exemple

On part du graphe suivant :

<iframe frameborder="0" style="width:100%;height:325px;" src="https://viewer.diagrams.net/?highlight=0000ff&edit=_blank&layers=1&nav=1#R7VvblpowFP0aH2ctIIr4OGNv03YuXXb18hghIp1IaIij9usbIOEaRqc6YAech9GdmMTsfTY5RxyA6Wr7nsJgeUMchAeG5mwH4M3AMHRgAv4vQnYJMh4PE8ClniM6ZcDM%2B4MS0NAEuvYcFBY6MkIw84IiaBPfRzYrYJBSsil2WxBcnDWALqoAMxviKvrdc9gyQa2RluEfkOcu5cy6Jlrm0H5wKVn7Yr6BAYxJ9Jc0r6AcS%2FQPl9AhmxwE3g7AlBLCkmer7RThaG%2FltiXve1fTmq6bIp8d8gb%2F04%2BdNQEf7bvt%2FYev3x6vTTq5MJJRHiFeI%2Fkx4sWyndyg%2BCOiaBBtAK4IZUviEh%2Fiz4QEHNQ5%2BAsxthPUwjUjHFqyFRatCw%2FjKcGExuMBByJrYXM8ZJQ8oFyLaVtovkhbJB1DjiSrQk6Fy%2BzTCygka2qLXjd%2F7qcP7%2B%2B%2B2MP7TchurJ%2FXm%2B2FFBmkLmJPbI2ecsS1j8gKMbrj76MIQ%2BY9FtcBhQjdtF9GBH8iuHgGLzrYT0y0GzPx0ic%2B%2F3d1NFfVnX8%2Be21wZTRE1lOrLHBlYhbtLG8yXRZvSoJ4ZSBczyU0kxhfRQ6W6JyWEd6vMh7H8rOWNYMxN9ZIKpulx9AsgPH%2Bb7i3F4UAwyBx24W3jQT1DzpYEJ%2FlcE0z%2BaOiMZAuUyGQR0QZ2uagKsWi1RIuK65CxlC83uQ8XUDLnJ1L7OQBPOxa%2FNZ76AHxC9r0WrOn6hlUjVq9LNY6bWQ2Bc7M32siGy7CmIRL3sHQg23WKH0y757JSP%2Bhf1bMUiGEWv80tKKB6kbLBqqruO5eWIJDT0Camt5m4lJ1Wj1FXN52Pi6BeWZxafVhKa%2BCB4TluM2oHL1QVH7to9I8s3RjXEt1JUGs5JXHiSGoFUMKV2Ys5q1dEc3IODPR6Fqvml41z1ZNny9nJcdDTuatZsyGKsZ7tuo7TtpkSy7zoFJyGEC%2F3oE3wgsiD%2FYJXUFcdWFFDfry6Rp0hMbT7qlqv%2FZa9UlrLelpsjVL75O6zKkPMYlW0zq9Pq9ryCRu%2FskkOhrt5Vyx%2FWivTxbloV7epSG1oNfLosK%2Bd5qsQHWxUCmtmwWI88sKJo2a0u0er1GeP3r3OYP6sTxaHFOV1IrmodnpbmYgeBc%2FqtIZH2oefNNZiXzsuT5%2FbvPNR3zCq4gaz4b4UjSsPMfB8dEI8eXCeTxUdDgKiOezeCtHV4PRm2gsfhoSPqtX5CIOWKfgv%2Fy9nsIohgr%2BjRfjX3VnRJP8R1WvDglgOC5dKbSqAMxGBXCCryWOEoDVLf5HJf4Vx89mDUBVP2yS%2F0m3%2BB%2FvTz%2Ba5X9%2F%2BvGy%2FHP9pZcA5Tnx9YvCmJREYbUtClUFqklRjLrFf%2Fl22db5r08fGzOFDvFfzgpUh8JG%2BQf1X0X3WcELCEAHZ5YVgBPc2nucAIadFgBQ1AVOJAD%2BMvuVW9yW%2BykhePsX"></iframe>

Le poids des arêtes est le flots maximum que peut admettre cette arêtes. Par exemple de $S$ à **B**, on ne pourra pas mettre plus de 10. Si on met 10 entre $S$ et **B**, il faut distribuer ces 10 aux nœuds sortant de **B**. 
Là aussi il ne faut pas dépasser le poids des arêtes, ici 7 pour aller à **N** et 6 pour aller à **T**. On peut par exemple mettre 7 pour aller à **N** et 3 pour aller à **T**. Les deux successeurs acceptent ces valeurs puisqu'elles sont inférieur ou égales aux poids des arêtes et on a pas dépasser le flot qui est de 10. 
On peut répeter cette opération sur tous les nœuds et on obtient le graphe suivant. A noter qu'il existe plusieurs manière de faire ce graphe à flot.

<iframe frameborder="0" style="width:100%;height:325px;" src="https://viewer.diagrams.net/?highlight=0000ff&edit=_blank&layers=1&nav=1#R7Vtbk5owFP41Pu4MEEV93KX3dtvt2OnlMUJEupHQEFftr2%2BAhGtY2a6CLbgzq34JScz5zpdzjjgC1mb%2FmsJgfUschEeG5uxH4MXIMHRgAv4UIYcEmU7HCeBSzxGdMmDh%2FUYJaGgC3XoOCgsdGSGYeUERtInvI5sVMEgp2RW7rQguzhpAF1WAhQ1xFf3mOWydoLOJluFvkOeu5cy6JlqW0L53Kdn6Yr6RAYx59Jc0b6AcS%2FQP19AhuxwEXo6ARQlhyavN3kI42lu5bcl1r2pa03VT5LMmF%2Fjvvx9mc%2FDO%2FrS%2Fe%2FPl68Nbk86vjGSUB4i3SH6MeLHsIDco%2FogoGkQbgRtC2Zq4xIf4AyEBB3UO%2FkSMHYRp4ZYRDq3ZBovWlYexRTCh8XjAgWi2sjkeMkruUa7FtGdouUpbpDnGHElWhZyKLbNPL6CQbKktet3%2BvrPuX3%2F6bI%2FvdiG7nf14u9tfSZJB6iL2yNboqY049xHZIEYP%2FDqKMGTeQ3EdUJDQTftlhuAvhC2eYBcdHDdMtBsL8dYnPn%2B6ebatqjv%2FdOt1YSujJWM9tsqCrUzMop3lTabL4k1JEK8MhNulhBYS46vIwRJd0jLC%2B1XG41h%2B1jJnMObCGlFlt%2FYYWgQw3v8d1%2FYiEWAYJGq78vYRof6CByvisxyuaSZ%2FVDgG0mUqCPKAKEP7HFQ1sWidCZUVp5AxFu93OU0X0Don5xI7uQOP%2B%2Ba%2F9RrawH9Bl1prDqZ6gqkmnR6LtUobiU3BZuavLZENV2FshGvewdCDfdYodTKvnslI%2F6B%2BVsRSQYRa%2FTS0ooDqRscCqqts3T%2B3BE0jIE1t3nb8UhWtnsIvP%2FbeL4F5YX45G9xSnoIN3HLapVdOzuSVXwavNC8s3ZjWmrqSIFbyyueRIaglQwpXZizmrX0hzcS4MNLo2sCagTVPZs2QL2clxyaReacZs6Hy8cFa9R3nXVpLLrNRKTkMoF%2BvwDuhBZEG%2B4RuIK6qsKIGff14DTpC42mPVLX%2F91r1SWstaTTZmaQPSV2m1E1EotO0Tq%2FP61oSidu%2FEomeens5V%2Bze2%2BuTRRnUy7s0JBf0elpUrO%2BdJitQHRYqpvWzAHF5WcG8VVH6eERrlPHHoD4XUD%2BWoYWCKFWjNS4yaEU50ex0fzMQvIofVTJxPbSmTSWFm4KVKIE91%2BevbW4SxCe9iQzm2RBfi4aN5zg4DpgQXzJcxkNFIVNAPJ%2FFGzy5GU1eRGPxGEmor14hkQi7ThGBzo%2BzwlSwYnw2Vqjul2iTA1EtzIr%2B9YgF43IVW2umDcbZWHCCbyyexQKeB1mgXxwYlzigiE5VSnA%2BDqjKi21ygAcyltkvDkyOZyjtcuB4hnJeDpgJB9LjQBlO%2Fv%2FEKN9VCWZdE0NVqGqTGJPeHRDGtHRATLvmQH2m2Z449IsDQDseKLbKAVD%2FzfWQLpyLBXq55tR1ugBOcDvw81jAs1Zr3i8SgFJIoCg8nkgK%2BNvs13FxW%2B4niODlHw%3D%3D"></iframe>

Néanmoins il existe une manière de maximiser la valeurs d'entrer et donc de sortie. Sur le graphe précédent on avait une valeur de flot de 19, c'est à dire une qu'il y avait 19 qui partait de $S$ et 19 qui entrait dans $P$. De plus on voit que sur l'arête de **A** à **N**, on fait passer un flot de 3 alors qu'on pourrait faire passer un flot plus important puisqu'on utilise seulement un flot de 9 sur l'arête de $S$ à **A** alors qu'on peut faire passer un flot de 14. Cela impliquerai de changer d'autres valeurs de flot du graphe pour qu'il soit plus optimale. 
On a donc ici la version optimisé du graphe qui fait passer un flot de 21 : 

<iframe frameborder="0" style="width:100%;height:325px;" src="https://viewer.diagrams.net/?highlight=0000ff&edit=_blank&layers=1&nav=1#R7Vttd6I4FP41fuw5QADxY%2Bu87m5nusc5%2B%2FIxQkSmkbAhVp1fvwESeQuVtgrOgD2n6pOQxNznPrn3ihMw3%2Bw%2FUhit74mH8MTQvP0EvJsYhg5swJ8S5JAh06mZAT4NPNEpBxbBD5SBhibQbeChuNSREYJZEJVBl4QhclkJg5SSXbnbiuDyrBH0UQ1YuBDX0b8Dj60z1LG0HP%2BEAn8tZ9Y10bKE7qNPyTYU800MYMySv6x5A%2BVYon%2B8hh7ZFSDwfgLmlBCWvdrs5wgneyu3LbvuQ0Prcd0UhazNBeHv%2FxycGfjN%2Fbp%2F%2BPTtr6fPNp3dGNkoTxBvkfwY6WLZQW5Q%2BhFRMog2AXeEsjXxSQjxH4REHNQ5%2BB0xdhCmhVtGOLRmGyxaVwHGc4IJTccDHkTOyuV4zCh5RIUW23XQcnVskeYwOZKtCnk1W%2BafXkAx2VJX9Lr%2F8TB%2F%2FPj1T9d82MXs3vn3825%2FI0kGqY%2FYM1ujH23EuY%2FIBjF64NdRhCELnsrrgIKE%2FrFfbgj%2BQtjiBXbRwWnDJLuxEG9DEvKnuzfbqr7zL7deH7YyOjLWc6ss2crGLNlZ3mT7LN2UDAmqQLxdSmghMb6KAizRJa0ivF9tPI4VZ61yBmMurAlVduuAoUUE0%2F3fcW0vEwHGUaa2q2CfEOoVPFiRkBVwTbP5o8YxcFymgiBPiDK0L0B1E4tWR6isOIUMU7zfFTRdQOuCnEvs7A5sDs1%2FmzW0hf%2BCPrXWHk31AlNZvR6LjUqbiE3JZvZ%2FWyIbbuLUCLe8g6FH%2B7xR6mRRPbORfkL9rImlggiN%2BmloZQHVjZ4FVFfZenhuCdpGQJravN34pSpaPYdffhm8XwL7yvzSGd1SnoIt3HLap1daF%2FLKb6NX2leWbkwbTV1LEGt55dvIEDWS4QjXZiznrUMhjWVcGWl0bWTNyJoXs2bMl%2FOSY5vIvNeM2VD5%2BGit5o6zPq0ll9mqlBxHMGxW4J3QgkSDQ0I3ENdVWFGDvn2%2BBp2g6bQnqtq%2Feq36rLWWYzTZm6SPSV2u1G1Eote0Tm%2FO6zoSiftXicRAvb2aK%2Fbv7c3Jogzq5V0akgt6My1q1g%2FOkxWoDgsV04ZZgLi%2BrGDWqSh9OaE1yvhjVJ8rqB%2FL0EJBlLrRWhcZtLKcaO5xf3MQfEgfdTJxPZxbbSWFm4JVKIEDP%2BSvXW4SxCe9SwwWuBDfioZN4Hk4DZgQXzJcpkMlIVNEgpClG2zdTax3yVg8RhLqq9dIJMKuc0Sgs9OssBWsMC%2FGCtX9El1yIKmFzZN%2FA2KBWa1ia%2B20wbgYC87wjcWbWOAMTglMs8IBRXSqUoLLcUBVXuySAzyQmdvD4oB1OkPplgOnM5TLcsDOOHA8DpTh5K9PjOpdlcDpmxiqQlWXxLAGd0AY08oBMe2bA82ZZnfiMCwOAO10oNgpB0DzN9djunApFujVmlPf6QI4w%2B3Ab2OBmbBAHzQLQMvK4ytYwN%2FmP49L2wq%2FQQTv%2Fwc%3D"></iframe>

### Graphe d'écart

Il est peut-être plus simple de présenter cela sur le graphe d'écart :

* Mêmes sommets
* Dès qu'un arc $(a,b)$ de capacité $c$ n'est pas saturé avec un flot $f<c$, créer l'arc $(a,b)$ dans le graphe d'écart et le valuer par $c-f$ (capacité d'augmentation)
* Dès qu'un arc $(a,b)$ a un flot $f>0$, créer l'arc $(b,a)$ dans le graphe d'écart et le valeur par $f$ (capacité de diminution)

Tant qu'il existe un chemin de $s$ à $p$ dans le graphe d'écart, le flot n'est pas optimal. Ce chemin = chaîne améliorante. 

### Algorithme sur le graphe d'écart (Ford-Fulkeron)

> $VF=0$ 
> Graphe initial = Réseau de transport
> Tant qu'il existe un chemin de $s$ à $p$ faire :
>
> * Soit $w$ la valuation minimale sur ce chemin. $VF+=w$
> * Pour chaque arc $(a,b)$ de ce chemin faire :
>   * $capa(a,b)-=w$ Si $capa(a,b) = 0$, alors supprimer l'arc.
>   * Si l'arc $(b,a)$ n'existe pas, le créer. $capa(b,a)+=w$

### Complexité

Edmonds et Karp ont proposé une implémentation particulière de l'algorithme de Ford-Fulkerson en parcours largeur (BFS) qui consiste à toujours choisir une chaîne améliorante de $s$ à $p$ de plus petite longueur (avec le moins d'arêtes possible). 
Cet algorithme se termine toujours (même pour des capacités non entières, contrairement à Ford Fulkerson) avec une complexité en $0(nm^2)$ avec $n$ sommets et $m$ arêtes.

### Couplage

Un **couplage** est un ensemble d'arêtes qui n'ont pas de sommets en commun. On peut aussi dire que c'est un ensemble de couples de sommets, tous différents, reliés par une arête (monogamie obligatoire).

Un **couplage maximum** est un couplage de cardinalité la plus grande possible, donc avec le plus grand nombre possible d'arêtes.