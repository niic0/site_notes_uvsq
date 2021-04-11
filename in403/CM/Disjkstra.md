# Algorithme de Dijkstra

Cette algorithme permet d'avoir le plus court chemin entre deux sommets d'un graphe. Le problème s'applique dans plein de domaines comme un itinéraire simple comme dans google map, waze etc.. Dijkstra calcul le plus court chemin entre deux points d'un garphe avec des arcs positifs.

### Idée

* On calcule progressivement les plus courtes distances de $s$ vers chaque sommet $x_i(d_i)$
* A chaque itération, on traite le sommet non encore traité de plus petite valeur $d_i$ (car on est sûr avec les valuations positives qu’il ne pourra plus être amélioré).
* On crée progressivement une arborescence des plus courts chemins de racine $s$ par la structure $pere$.

### Algorithme

> Initialisation :
>
> * $T = \{s\}; d_s=0$
> * $\forall i \neq s$, si l'arc $(s,i)$ existe alors $s_i = w(s,i)$ $(\infty$ sinon$),pere(i)=s$
>
> Boucle principale : Tant que $T \neq V$ faire
>
> 	* Trouver un noeud $t$ de $V-T$ tant que $d_ty = Min(d_i,i\in V-T)$,
> 	* $T = T \cup \{ t\}$
>  * $\forall k \in \Gamma_t^+$
>    	* Si $(d_k>d_t+w(t,k))$ alors $d_k=d_t+w(t,k), pere(k) =t$

### Exemple

On part de ce graphe du sommet $s_1$. On créer alors le tableau correspondant en regardant tout les arcs partant de $s_1$ et leur poids et ont les met dans le tableau. Chaque sommet aura alors une valeur attribuée, ici $s_2$ aura la valeur 10, $s_3$ 3 etc...

<iframe frameborder="0" style="width:100%;height:334px;" src="https://viewer.diagrams.net/?highlight=0000ff&edit=_blank&layers=1&nav=1#R7Vtdc6M2FP01flwPSAjDY%2BJk%2B7WdbpuZ7W7fCMiYLkaukNd2f30FSICQ4%2BK1LRw7yUyMroQk6xzdc%2FWREZwuNj%2FQYDn%2FlUQ4HQEr2ozgwwgAD9j8b2HYVgYH%2BpUhpklUmezG8JT8i4XREtZVEuFcKcgISVmyVI0hyTIcMsUWUErWarEZSdVWl0EsWrQaw1MYpFgr9mcSsbn4WqhV%2BkecxHPZsm2JnOcg%2FBpTsspEeyMAgV%2F8VtmLQNYlyufzICLrlgk%2BjuCUEsKqp8VmitNiaOWwVe%2B9fyG37jfFGevzwhT99Nun3%2F%2Byf5n8fP%2BHT5LHB%2FzhHRB9Y1s5HuU3wsU71gjeE8rmJCZZkH4gZMmNNjf%2BjRnbCiSDFSPcNGeLVOTiTcI%2Bt56%2FiKqK54dNO7EViVmSplOSElr2AEYB9mYht%2BeMkq%2B4leOGHn6e1TkSL1hUmDG6%2FSxrLxJfZB%2BKRNNwmZItV98eR3GXDM2gClNOVjTEe0ZScjegMWZ7ysEaej6jMFlg3h%2F%2BHsVpwJJvaj8Cwe24Lle%2F%2BpEkvIfAEtMQSFaKWQihpVZR9Uu81bCEP7S60ZhK7hzAIwdpRCpG9UkkM5Lxj%2FuTccsa%2B5M2vcbQcvdSTCfMjGRMtGO7It2i2vvy57vIWTT8EdOEjymmwxHNO5JoCkUO5YOo91uQrrB0j27KxDgrRHH%2FWRGZ8S4vEbnjBfjgbJpM%2FhQXn7msJl89S5srbbynLXPLWrUpzV2epinXmoKe63nC8NMyKId%2FzdVOJV%2BQLysBmiWbgsQn8VtinDBleLOfGjqUUoI7U98V6XVLzoRp3lIyzzoT9tAz7QsQVJwB8Ly9zqDRirFVDGyjF%2FW7ezRjaFdS9uaM%2FgUa8i%2Flq3eUBttWgWUhUPnLOgcdlewAWR2%2BVjWeVtwco4RuB072XiIbpeLOAMsaI3MhVl9m2v5ZYixke6qj9V2zMZZr2K%2Bi3kRseVSk0OOCfOkARERDhmDQYAhm33gI1l1%2BAWfgGMw5GnzbUcG3wnowG6OcjxpJQF%2Fo%2BZgzFWMVOuHV2jgLU5AmccaTIceoiIPuCwSTMEjvRMYiiaL0JVKpblIlBToNKexOrAKBTgpnBynA2QJzwwLSDsr7yUe9X9Nn8%2BaVigfqG8UMKR4OHCzk7UmVg%2Fb5rpwqg271IINxBnqLMxRJcbyh93omw0lKvT45RFT%2Bf8H6Sn2F19NXHHv%2BcBRdPIO%2BAty4r3Aubk1i6YP8FlOY9hPy3P38u2jHkUU%2Fmb4UYbl24AfdtZK9NCIRzptEXFg46Q83678jmLxWifBfw7rTsc1yZWzZ6jEz8i9GJs595eQ8B2rdmwvINntpSfLciNbAG9caBC7smooz0dDXz%2Fn144n%2Bxw4Uc54Ez2VVxYQUdxt4veh%2BhB6Kuri3yYVDOMA%2FnAAN2EXD19EAJs8mHH1rQN%2BCvlY0unEY3LFUN4uG7hn19di1olHPBRkVD40G0tdEtzM3uje%2BkDU0GvrdVj0SvVY0nElnbqCh0QA3rOKoqxs7bhiYRUO%2FdCRj%2BhuAAwKkwAGgDgc0Cod%2BDeiG0IDq5AA7NrfMTg79pFy%2FkHOtaIDuZaihFxzIvWEZB5NLEw59MX47aNhuJ6jasTVyIjR4svmP02ofrfmvXvj4Hw%3D%3D"></iframe>

On fait tout d'abord tout les sommets partant de $s_1$.

$V = \{s_1\}$

| Sommet | $s_1$ | $s_2$ | $s_3$ | $s_4$    | $s_5$ | $s_6$    |
| ------ | ----- | ----- | ----- | -------- | ----- | -------- |
| d      | 0     | 10    | 3     | $\infty$ | 6     | $\infty$ |
| père   | -     | $s_1$ | $s_1$ | -        | $s_1$ | -        |

On voit que $s_3$ possède la plus petite valeur. On va donc voir à partir de $s_3$ garder la valeur 3 est l'additionner au poids des arcs partant de $s_3$ et voir quelle est le plus petit. On répétera cette opération jusqu'à obtenir le plus court chemin.

$V = \{s_1,s_3\}$

| Sommet | $s_1$ | $s_2$ | $s_3$ | $s_4$    | $s_5$ | $s_6$    |
| ------ | ----- | ----- | ----- | -------- | ----- | -------- |
| d      | 0     | 7     | 3     | $\infty$ | 5     | $\infty$ |
| père   | -     | $s_3$ | $s_1$ | -        | $s_3$ | -        |

$V = \{s_1,s_3,s_5\}$

| Sommet | $s_1$ | $s_2$ | $s_3$ | $s_4$    | $s_5$ | $s_6$ |
| ------ | ----- | ----- | ----- | -------- | ----- | ----- |
| d      | 0     | 7     | 3     | $\infty$ | 5     | 6     |
| père   | -     | $s_3$ | $s_1$ | -        | $s_3$ | $s_5$ |

$V = \{s_1,s_3,s_5,s_6\}$

| Sommet | $s_1$ | $s_2$ | $s_3$ | $s_4$    | $s_5$ | $s_6$ |
| ------ | ----- | ----- | ----- | -------- | ----- | ----- |
| d      | 0     | 7     | 3     | $\infty$ | 5     | 6     |
| père   | -     | $s_3$ | $s_1$ | -        | $s_3$ | $s_5$ |

$V = \{s_1,s_3,s_3,s_5,s_6\}$

| Sommet | $s_1$ | $s_2$ | $s_3$ | $s_4$    | $s_5$ | $s_6$ |
| ------ | ----- | ----- | ----- | -------- | ----- | ----- |
| d      | 0     | 7     | 3     | $\infty$ | 5     | 6     |
| père   | -     | $s_3$ | $s_1$ | -        | $s_3$ | $s_5$ |

Finalement on obtient le chemin suivant qui forme un arbre : 

<iframe frameborder="0" style="width:100%;height:334px;" src="https://viewer.diagrams.net/?highlight=0000ff&edit=_blank&layers=1&nav=1#R7Vtdk9o2FP01PIaxJcuYx4XdNGnTadqdaZO%2BCVsYN8aitgjQX1%2FZlmzLYolZQCaQ3ZnFupIloXN0z9XHDuB0uf0pxavFrzQg8QBYwXYAHwcAeMDmf3PDrjQ4cFwawjQKSpNdG56j%2F4gwWsK6jgKSKQUZpTGLVqrRp0lCfKbYcJrSjVpsTmO11RUORYtWbXj2cUy0Yn9FAVuIr4Uapd%2BRKFzIlm1L5Myw%2FyVM6ToR7Q0ABOP8t8xeYlmXKJ8tcEA3DRN8GsBpSikrn5bbKYnzoZXDVr739oXcqt8pSViXF6bo%2FW9%2F%2Fv63%2Fcvo58kfYxo9PZIPb4DoG9vJ8Si%2BEcnfsQZwQlO2oCFNcPyB0hU32tz4D2FsJ5DEa0a5acGWscgl24h9ajx%2FFlXlz4%2FbZmInEvMojqc0pmnRAxhg4s19bs9YSr%2BQRo7re2Q2r3IkXjCvMGHp7pOsPU98ln3IE3XDRUq2XH57EoRtMtSDKkwZXac%2BOTCSkrs4DQk7UA5W0PMZReiS8P7w91ISYxZ9VfuBBbfDqlz16kca8R4CS0xDIFkpZiGEllpF2S%2FxVs0S%2FtDoRm0quHMEjxykESkf1WeRTGjCPyZn45Y1HI%2Ba9BpCyz1IMZ0wc5ow0Y7tinSDam%2BLn1eRM2%2F4I0kjPqYk7Y9o3olEUyhyLB9EvV9xvCbSPboxE%2BOsEMX9d01lxpusQOSBF%2BCDs60z%2BVOYf2aymmw9kzZX2nhPG%2BaGtWxTmts8jWOuNTk9N4uIkecVLoZ%2Fw9VOJR%2FOVqUAzaNtTmKNGoh4gbOPGh6YQdfdS0MxTiRlZHuYGjqUUoJbU98V6U1DzoRp0VAyz7oQ9tAz7QsQVJwB8LyDzqDWiqGVD2ytF9W7BzSjb1dS9OaC%2FgUa8i%2FFqw9pineNAqtcoLKXdQ46KtkBslp8LWs8r7g5RgndDJzsg0Q%2BHxW%2F7br2B1jWEJkLsboy0x5fJMZCtqc62rFrNsZyDftV1JmIDY%2BKFHpckS%2FtgYiozxAMGgzB7DsPwdrLL%2BD0HIM5J4NvOyr4ll8NZm2U81EjCegKPR9zpmKsQie8WhNnYcJxFCY86XOM8jhokiMY%2BTh%2BEBnLKAjil0ilukmVFOg8pLBbsQoEOimcPaQAFwvMDQtIMyjvJh%2FVfk2XzRuT0c8ZxQN1jWL6FA8H9hbydqTKUft8N06VXrd6kME4A%2F2IMxRJcby%2B93pG%2FUlKtT45RlS%2BvWD9TtckXkdfcer5w0l08Qz6CnDnvsK5ujWJpQ%2Fyj5jCtJ%2BQ5%2B6X30U7jSz6yfS1CMutA9%2FrrpXspRGJcK5FIl5z4%2BECEtF%2FODnub9a%2FIpi8VYkYfw%2FrTsc2y5WhZavHzGhsSCY6HM5d%2BMrJZQ7U2jcXkG320pLkuRGtgdeiNT0tRxC4smsqzkhDXz%2Fn148nuh87pITzBM%2BKqvIJKe428HrRZIAe87q4t8mEQzjCP5wBDdhGY6yjAUyeTTj61oC%2BBX2raLTjMLhnqW4WDd0z6uuxW0WjmgsyKu4bDaSvie5nbrRvfCGrbzT0u616JHqraDij1txAfaMB7ljFUVs39twwMIuGfulIxvR3AAcESIEDQB0OaBQO%2FRrQHaEB1ckB9mxumZ0c%2Bkm5fiHnVtEA7ctQfS84kHvHMg5G1yYc%2BmL8ftCw3VZQtWdr5Exo8GT9H6flPlr9X73w6X8%3D"></iframe>

### Complexité

L’implémentation la plus simple consiste à faire un tableau pour $d$. On obtient alors une complexité en $O(n^2)$ : 

* A chaque itération, on traite un sommet ($n−1$ itérations)
* Lors du traitement d’un sommet, on parcourt le tableau $d$ pour rechercher le sommet non traité de plus petite valeur $(O(n))$
* Chaque successeur (en fait chaque arc) est traité une et une seule fois.Or $m≤n.(n−1)$. D’où $O(n^2)$

La meilleure complexité pouvant être obtenue pour cet algorithme est en $O(m+n.log_2n)$. On peut noter que si $m=O(n^2)$, c’est à dire si le graphe est complet ou tout du moins très dense, cela a donc peu d’intérêt.

#### Complexité en $O(n.log\ n)$

Pour obtenir, il faut utiliser une structure de données un peu complexe : soit un tas binoimial, soit un tas de Fibonnaci. L'objectif est que toutes les opérations suivantes soient en $log_2\ n$:

* Trouver l'élément de plus petite valeur
* Effacer du tas l'élément de plus petite valeur (en remontant les autres donc)
* Accéder à la valeur d'une élément donnée
* Diminuer la valeur d'une élément donnée (= Effacer u élément donnée du tas et insérer un nouvel élément)