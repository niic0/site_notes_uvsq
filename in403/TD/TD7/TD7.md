# TD7

### 1 - Commençons sur un petit graphe

|            | $s_2$ | $s_3$ | $s_4$     | $s_5$ | $s_6$     |
| ---------- | ----- | ----- | --------- | ----- | --------- |
| Init $s_1$ | 4     | 8     | $+\infty$ | 11    | $+\infty$ |
| $s_2$      |       | 7     | 6         |       |           |
| $s_4$      |       | /     |           | =     | 13        |
| $s_3$      |       |       |           | 9     |           |
| $s_5$      |       |       |           |       | 12        |
| $s_6$      |       |       |           |       |           |

Arborescence du plus court chemin : 

<iframe frameborder="0" style="width:100%;height:264px;" src="https://viewer.diagrams.net/?highlight=0000ff&edit=_blank&layers=1&nav=1#R7VjbjtowEP2aPFbKhVx4bIDtbauqXamV%2BmaSIXHXySDHYWG%2Fvk5iQyy0bHhAabUBCewz4xl7js8gYnmLYv%2BBk23%2BFVNglmune8tbWq7rz1352QCHDnA8uwMyTlMFnYAH%2BgwK1G41TaEyHAUiE3RrggmWJSTCwAjn%2BGS6bZCZWbckUxntE%2FCQEAZnbr9oKvIOjfye90egWa4zO7ayrEnymHGsS5XPcj133rw7c0F0LOVf5STFpx7krSxvwRFFNyr2C2BNaXXZunV3L1iP%2B%2BZQiiELFv6nbz%2B%2F%2F3a%2BhJ%2FjH3OkqyXcv%2FPDsIuzI6wGfZB2u%2BKgSwSprJialljKrzip%2BQ6awI6cIBc5ZlgSdo%2B4VeAfEOKg6Ca1QAnlomDKWgmOj7BAhrzN4QVJBOvN0aKpkFWKN1gKFcgJ1Ly38q59NThlrIenBKJNIvHuPM0hXqycgiqseQIXy%2BWrK0p4BuKiZ3DkWEoHsADBD3IlB0YE3Zl7IeoSZ0e%2FE5FyoLi8ilf%2FjNfKcgMmmhLXaznMmqGjMZmlB59dAQF7YTJIGM1KOU5kEUGWPN4BF1Tq6r0yFDRNm%2BUxh4o%2Bk3UbypbzLdJStAf2Y8tfNrHk%2FagUw1cQrk4o88L%2BMrXnNKgFkVan6l4z3b2eTr1AQ3mvDWjsBsTNJ0FeI8hgsCCjUQUZOROvN%2BE1skflVW%2F0lUbrTo3WbLTz0RttNIi42VsnLnQM4vzZ2MRF3tRJr%2BikkT24k7rj%2FkLagwTpvXFBhqHZSf8BQZ7%2F15gE%2BZrMBglyNq4g3UGC9CdBGoIM7NEFORtEXPA%2FE8dRSA1gqeLegsfgZjzK6enBX2vrPVz1Vn8B"></iframe>

### 2 - Randonnées en montagne

Il n'y a que des valuations positive, on peut donc appliquer l'algorithme de Dijkstra pour le plus court chemin. Pour le plus long chemin, on utilisera l'algorithme de Ford-Bellman. Dans la mesures où on a affaire à un DAG, le plus simple consiste à faire un tri topologique et à traiter le sommets dans cet ordre (où on connaît la valeur de tous les prédécesseurs)

| Ordre Topologique    | + court (père)                    | + long (père)                 |
| -------------------- | --------------------------------- | ----------------------------- |
| St Veran             | 0                                 | 0                             |
| La petite chapelle   | 20 (St Veran)                     | 30 (St Veran)                 |
| Col de St Veran      | 60 (St Veran)                     | 75 (La petite chapelle)       |
| Col de Chamoussière  | 130 (La petite Chapelle)          | 165 (col de St Veran)         |
| Refuge Agnel         | 100 (Le petite Chapelle)          | 205 (Col de Chamoussiere)     |
| Le lac glacé         | 130 (Refuge Agnel)                | 235 (Refuge Agnel)            |
| Le cul du chien      | 155 (Le lac glacé)                | 265 (Refuge Agnel)            |
| Belvedère du Viso    | 205 -Col de Chamoussière)         | 365 (cul du chien)            |
| Combe de soustre     | 170 (Lac glacé)                   | 295 (Cul du chien)            |
| Cascade du pisse dru | 200 (cul du chien)                | 335 (Combe)                   |
| Lac bleu             | 205 (Combe de soustre)            | 350 (Cascade du pisse dru)    |
| La pointe Johanne    | 325/295/280/265 \| 265 (Lac bleu) | 485/405/415/410 \| 485 (Belv) |
| La vallee du Guil    | 235 (Lac bleu)                    | 525 (Pointe)                  |
| Col de chaude maison | 270 (Lac Bleu)                    | 565 (Vallée)                  |
| Queyras              | 295 (Vallée)                      | 620 (Col de chaude maison)    |

Plus court chemin :

<iframe frameborder="0" style="width:100%;height:24px;" src="https://viewer.diagrams.net/?highlight=0000ff&edit=_blank&layers=1&nav=1#R7Zlbb6JAFMc%2FDY%2BbcBGVx4pt99LNpjXpJvs2whFmOzBmHKz20%2B8ZmFEIqYWk0U1QE2HO3M9%2FfhxmtLww290Lsk5%2F8hiY5drxzvLmlus6tm3jRVn2lcUbTStDImisCx0NC%2FoGpqa2FjSGTaOg5JxJum4aI57nEMmGjQjBX5vFVpw1e12TRPdoHw2LiDBoFftNY5lW1qlfK%2F0VaJKanh0z4SWJXhLBi1z3Z7meG6hvlZ0R05Yuv0lJzF9rJu%2FW8kLBuazusl0ITPnWuK2qd%2FdO7mHcAnLZpULof%2Fv1%2FPjH%2BTH5PnsKOL2dw8MXf6rV2hJWgJlIOVy5Ny6CGD2mkznP8TKLCrEF1bCDCS5kyhOeE%2FbA%2BVob%2F4KUey03KSRHUyozpnM3UvAXCDnjouzDG0dTWK4OOUYK9NJsxXOpG3LGOl2reVd%2BlJ0yVrPHBKarCO3VfNQk3vWcNm14ISI46a6xXqJEJCBPlpwcNEZ2gGcgxR5rCmBE0m1zLEQv4uRQ7igk3mgte%2Bk6bum6IBTn69rPIEjeElnCTjY1IowmOd5H6CZAp862ICRFcm50RkbjWFWfCdjQN7Ism7IxvebYUzklf2b5c9UWroCN1rCHpHoO2C%2FsTovXdrSuMDIk6%2BeTb%2Fh9PdJ%2BYDqtkW64%2FXxtAvvKXB%2FmJp2ZCy7L3KSl6wNRswZJJagYlpI1NgSDge%2Bw1E%2FBNzovfO4Vvj7wBV3hC95ZCueCL2jp%2BgSrIlHc3SS5emsdCHSTSQfonPNCN7pC1wO6wGyEPobOuyh0ZqCNiBeh4Z7hJfSsm2Aw2AXex9gF56WuvQe4UvcRS52o8y9LndfSNeTZUkW6WP0seIGeHs5bpmOPO0Q8%2F7zsXc9VerHnd2bvsucqZqD1iKeYY2XYQz6K4WDndsDurBFvbF9PVnpR1%2FlkJbjsyUrQPll5JlivfMMs416hXjoLOpxdnjOy%2F79tXnsP%2FliA2GNPg5HF7%2FBQnH6OKpg8%2Fn1U5tX%2Bo%2FNu%2FwE%3D"></iframe>

Plus long chemin : 

<iframe frameborder="0" style="width:100%;height:23px;" src="https://viewer.diagrams.net/?highlight=0000ff&edit=_blank&layers=1&nav=1#R7Zpbb5swFMc%2FDY%2BTuAQIj0162bpOWxcpk%2Fbmwgl4BRwZkyb99LPBEBBraqQKJkErtfj4fv7%2BxfYhmrVOjncU7aNvJIBYM%2FXgqFnXmmm6ns7%2FCsOpNJiWUxpCioPSZJwNG%2FwK0ijrhTkOIGsVZITEDO%2FbRp%2BkKfisZUOUkpd2sR2J273uUSh71M%2BGjY9i6BT7hQMWldal3Sj9GXAYVT0busx5Qv5zSEmeyv400zI98VtmJ6hqS5bPIhSQl4bJutGsNSWElU%2FJcQ2xcG3ltrLe7Ru59bgppEylwtr%2B8n37%2BNv46t6vfnoE31zDwyd7uSzbOaA4h2oixXDZqXIRBNxjMpmSlP9b%2BTk9gGjY4AlCWURCkqL4gZC9NP4Bxk5SbpQzwk0RS2KZmzFKnmFNYkKLPizHX8LTrs6ppOBeWu1IymRDhiPTjZq3xY%2Bw4zhu2AMEy53P7eV8xCTe9Jw0ZSSnPlx0l1zcDNEQ2MWSbq0xRwdIAoyeeE0KMWL40B4Lkos4rMudheQPUsteujodXTcI8%2Fma%2BhYoSjsiMziytkYoxmHKn33uJuBOXR2AMszJuZIZCQ4CUX1FIcOv6KloSufpPeE9FVOyV5p9LdriKyCTGvaQVM6B9wvHy%2BJ1HS0rLCqS5eeTXfH7cqa9ZjpqkF5x%2B%2FHaVB%2BZM3NqzLnKzHnjMud2dH1AYtbAMAOxh0VozxuCycBXL%2FVL8C2Ghc%2Bc4esDn6cKn%2FfGUhgKPq%2BjK%2FeNOJgK8jbT2%2FhcR4E9a1j2FjN7PdjzqvvQ%2B%2BxZo7JXDbTD3jpCCcmzDAOdzqbnmQrg2cOC170NzOC9h5MSePa44FkdXX%2FCLg%2FFlncVpiJSMxHojHoru0SdMSx1c2ylF3W2MnXjxlaqgTa3u7w4aubFJQ%2FDdE6Zhuna73M3aHzF0ef4Si%2FulOMr3rjxFa8bX1lBzDUrTpclfVuckenAt9AV4Bs0vuLoc3ylF3yq8RVHHze%2B4nXjKz8ECoK8exKhNJ3ODc%2Bw3f8ttuLoc2ylB3eSJiXuRo2t1ANt6LpFxTuEcsO7y%2FGEbnmuytu8QW95jj7HVnqBpxpbcfRRYyv1QP%2F9QmEdobx4SBA%2FcU7ovuepHDmXwxLYvY8%2F5nCivKepyHI%2B5V%2BQ5YNU4cnzt5aKvMY3w6ybvw%3D%3D"></iframe>

### 3 - Le chemin le plus court pour aller d'un point à un autre, c'est encore ne pas y aller

1. > Initialisation :
   >
   > * $\forall\ i \neq s\ si\ arc(s,i) \ existe\ N_i=1$
   >   *  $Sinon\ N_i =0$
   >
   > Boucle Principale : 
   >
   > * $Si\ (D_t+w(b,k) <D_k)\ Alors\ N_k = N_t$
   >   * $Sinon\ si\ D_t+w(t,k) ==D_k)$	
   >     * $Alors\ N_K+=N_t$

2. Application de Dijkstra 

   |      | A      | B      | C      | D         | E         | F         | H         |
   | ---- | ------ | ------ | ------ | --------- | --------- | --------- | --------- |
   | Init | 5 \| 1 | 2 \| 1 | 3 \| 1 | $+\infty$ | $+\infty$ | $+\infty$ | $+\infty$ |
   | B    | /      |        |        |           | 8 \| 1    | 7  \| 1   |           |
   | C    | 5 \| 2 |        |        |           | /         | 7 \| 2    |           |
   | A    |        |        |        | 10 \| 2   | 7 \| 2    |           |           |
   | E    |        |        |        | 10 \| 4   |           | /         | 13 \| 2   |
   | F    |        |        |        |           |           |           | 12 \| 2   |
   | D    |        |        |        |           |           |           | 12 \| 6   |
   | H    |        |        |        |           |           |           |           |

3. Six chemins de valeur 12 :

   * $S\rightarrow A \rightarrow D \rightarrow H$
   * $S\rightarrow A \rightarrow E \rightarrow D \rightarrow H$
   * $S\rightarrow C \rightarrow A \rightarrow D \rightarrow H$
   * $S\rightarrow C \rightarrow A \rightarrow E \rightarrow D \rightarrow H$
   * $S\rightarrow C \rightarrow F \rightarrow H$
   * $S\rightarrow B \rightarrow F \rightarrow H$