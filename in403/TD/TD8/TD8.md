# TD8

### 1 - Ford-Bellman

 L'idée est de créer un tableau ou à chaque sommet est associé sa valeur du plus court chemin. On initialise tous les sommets à $\infty$ et on pose **L** qui indiquera quel sommets il faudra traiter en fonction des valeurs de sommets affecter sur le sommet correspondant. C'est à dire que par exemple pour la ligne du sommet $S_1$, on voit sur le graphe que le sommet à deux successeurs : $S_2$ et $S_4$. On met alors dans le tableau les valeurs 3 et 1 correspondant aux sommets. 

Il faut maintenant traiter les sommets $S_2$ et $S_4$ puisqu'on vient de leur affecter une valeurs. On met donc dans les sommets à traiter (dans la colonne **L**), ${S_2, S_4}$ et on met passe au sommet $S_2$ (puisqu'il est à traiter). On aurait très bien put traiter $S_4$ en premier, l'ordre n'a pas d'importance. 

Néanmoins, pour ne pas se perdre, il vaut mieux traiter les sommets les plus anciens en premier. On voit bien dans le graphe que par exemple, on a ajouter à la liste des sommets à traiter, $s_5$ à la ligne $S_4$ au début. On ira d'abord traiter le sommet $s_4$ pour "finir" le sommet $S_1$. Pour faire clair on traite les sommets comme une file ou le premier arrivé et le premier servis.

On peut continuer l'exemple en prenant le sommet $S_5$. On voit sur ce sommet que pour aller à $S_2$, on fait -1 ce qui donne un parcours plus intéressant pour aller sur $S_2$. La valeur du plus cours chemin pour aller à $S_2$ change donc et c'est là que l'algorithme de Ford-Bellman est intéressant car contrairement à Dijkstra, les valeurs de plus court chemin peuvent changer. On assigne donc à la valeur $S_2$ la valeur 3. On fait ensuite la même chose pour les sommets $S_7$ et $S_8$. 
A noter que si un sommet va sur un autre sommet qui à déjà une valeur mais que cette valeur est plus grande que la valeur déjà indiqué, alors on ne la met pas dans le tableau. (Si elle est plus petite on la met puisqu'elle est plus intéressante pour le plus court chemin comme on vient de le voir). 

Par exemple si on prend ici  $S_7$ au début du tableau, on remarque que ses successeurs sont $S_4$, $S_6$ et $S_{10}$. Pourtant aucune valeur n'est mise dans le tableau en $S_4$. Ceci est dut au fait que pour aller au sommet $S_4$, on fait comme pour tous les sommets, le valeur du plus court chemin pour aller jusqu'au sommet qu'on est en train  de traiter + le poids de l'arête pour aller au successeur voulu. Ceci nous donne une valeur supérieur à la valeur précédement mis dans $S_4$ ce qui est inintéressant pour trouver le plus court chemin. 

|          | $S_2$    | $S_3$    | $S_4$    | $S_5$    | $S_6$    | $S_7$    | $S_8$    | $S_9$    | $S_{10}$ | L                        |
| -------- | -------- | -------- | -------- | -------- | -------- | -------- | -------- | -------- | -------- | ------------------------ |
| Init     | $\infty$ | $\infty$ | $\infty$ | $\infty$ | $\infty$ | $\infty$ | $\infty$ | $\infty$ | $\infty$ | $\{s_1\}$                |
| $S_1$    | 3        |          | 1        |          |          |          |          |          |          | $\{s_2,s_4\}$            |
| $S_2$    |          |          |          | 7        |          |          |          |          |          | $\{s_4,s_5\}$            |
| $S_4$    |          |          |          | 3        |          |          |          |          |          | **$\{s_5\}$**            |
| $S_5$    | 2        |          |          |          |          | 8        | 6        |          |          | $\{s_2,s_7,s_8\}$        |
| $S_2$    |          |          |          |          |          |          |          |          |          | $\{s_7,s_8\}$            |
| $S_7$    |          |          |          |          | 11       |          |          |          | 10       | $\{s_8,s_6,s_{10}\}$     |
| $S_8$    |          |          |          |          |          | 7        |          |          |          | $\{s_6,s_{10},s_7\}$     |
| $S_6$    |          | 12       |          |          |          |          |          |          |          | $\{s_{10},s_7,s_3\}$     |
| $S_{10}$ |          |          |          |          |          |          |          | 12       |          | $\{s_7,s_3,s_9\}$        |
| $S_7$    |          |          |          |          | 10       |          |          |          | 9        | $\{s_3,s_9,s_6,s_{10}\}$ |
| $S_3$    |          |          |          |          |          |          |          |          |          | $\{s_9,s_6,s_{10}\}$     |
| $S_9$    |          |          |          |          |          |          |          |          |          | $\{s_6,s_{10}\}$         |
| $S_6$    |          | 11       |          |          |          |          |          |          |          | $\{s_{10},s_3\}$         |
| $S_{10}$ |          |          |          |          |          |          |          | 11       |          | $\{s_3,s_9\}$            |
| $S_3$    |          |          |          |          |          |          |          |          |          | $\{s_9\}$                |
| $S_9$    |          |          |          |          |          |          |          |          |          | $\emptyset$              |

On obtient l’arborescence du plus court chemin suivante :

<iframe frameborder="0" style="width:100%;height:243px;" src="https://viewer.diagrams.net/?highlight=0000ff&edit=_blank&layers=1&nav=1#R7Vpbb5swGP01PFYCbCA8Nmm77qZNyrTt1QEXWB2cOSYh%2B%2FUz2A6QW5m0FWsheQDOZ%2BPLd86R%2FCUWmC3LNwyt0o80xsRy7bi0wJ3lug7wgbhUyE4iQQAlkLAsVo0aYJ79whJ0bYUWWYzXnYacUsKzVReMaJ7jiHcwxBjddps9UdIddYUSfATMI0SO0W9ZzFOJTjy7wR9xlqR6ZMdWkQWKnhNGi1yNZ7nADauvDC%2BRfpdqv05RTLctCNxbYMYo5fJuWc4wqfZWb5vs93Amup83wznv0yF%2F%2F303CcG76FP5%2BfHL181bn4U3QCVrg0iB9Trq2fKd3iEciw1TjznNxWVaLxtXL7bFE2U8pQnNEflA6UqAjgB%2FYM53Kt2o4FRAKV8SFV1zRp%2F3Gw73yIwSyuphwUP9ERE5oWoWZ1euoDUtWIQvLVetjiOWYH6pIdhnSDAf0yXmbCc6MkwQzzbdmSBFwWTfrkmDuFGZ%2BJOsuCey4hMx4ekTFWtup8f%2FWVAduFnX%2B30rGrj%2BqmyCtX70zjag3uMW5CfVda6HWxcLjTkaE0tqwS1Uzk3DByziuORdDiCSJbm4j0QasZjadIMZz4Qyb1VgmcUxqemGxcLQon5VRbgVzXJeb7o3tby76l2CYXLxLXqdJ1M1Ei4v0%2Bk4%2BbqDoxStHM8N1PO28Q9fQWnLOqD9r%2BjiX5eIQV8Re4OKGBgoYjiKWInWM03Ek%2BsSsddXxMGQItbpHrNy0DAc1Fo9A63VG61VRkFomrUGBtLFHekio557QBd7YLrAU6ev%2F9jzw56eD8%2Fk8ZU8PzRQxJNRxKdFDODQIr6uwhbUpdMXRTxoYQte1yGnf1aGPeQ4BlprMFqrsk3fNGu9rnIj7FtuhIOWG6GJ5UZ%2FFLGMBhPDzsTQxBIKGOkio%2BHhmXhounjXVQeFQV%2FPH7QOCk0sbFW%2Fjo4qrk0%2F6KoYnqhsTV7V9E2soYQjXZTpw5fp8pdMXzw2fzyqY61%2Fd4H73w%3D%3D"></iframe>

