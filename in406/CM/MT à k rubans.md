# Machine de Turing à $k$ rubans

### Définition formelle

On généralise les machine de Turing en leur permettant d'utiliser $k$ rubans avec une tête de lecture sur chaque ruban. 

* Une configuration est donnée par$(B_1,pos_1,pos_2,...,B_k,pos_k,q)$ avec $B_i$ le contenu de la $i$ème bande et $pos_i$ la position de la tête de lecture sur la $i$ème bande.
* La fonction de transition $\delta$ est définie de $\Gamma^k \times Q$ vers $\Gamma^k \times Q \times \{L,H,R\}$, c'est à dire qu'à chaque étape tous les syùboles sous les têtes de lecture sont lus, modiiés et les têtes déplacées.

On peut également ajouter un ruban spécial destiné à contenir la sortie de la fonction calculée.

### Exemple de machine à $k$ rubans

cf TD

### Équivalence de modèles de calcul

Deux modèles de calcul sont équivalents s'ils reconnaissent les mêmes langages. On dit que le modèle de calcul $ \mathcal M_1$ simule le modèle de calcul $\mathcal M_2$ si pour tout $M\in \mathcal M$, il existe $M' \in \mathcal M_1$ tel que $L_M = L_{M'}$ .

Pour montrer qu'un modèle simule un autre, généralement on représente un calcul de $M \in \mathcal M_1$ qui reproduit cette suite de configurations.

> **Théorème**
>
> Les machines de Turing à $k$ rubans sont équivalentes aux machines à 1 ruban.

**idée de preuve** :
On code les $k$ rubans sur un seul ruban, $k$ cases consécutives (de $ik$ à $(i+1)k-1)$ représentent les $k$ cases en position $i$ des $k$ rubans. On enrichit également l'alphabet pour noter sur quelles cases sont les têtes de lecture. Chaque étape de simulation nécessite de balayer le ruban pour trouver les $k$ têtes de lecture et la lettre qu'elles lisent puis de nouveau pour modifier cette lettre et la position de la tête.

### Alphabet d'une machine de Turing

Un codage est une fonction de $\Sigma$ vers $\Sigma'$ qui s'étend aux mots. Par exemple on peut coder $\{a,b,c,d \}$ par $\{00,01,10,11\}$

> **Théorème**
>
> Les machines de Turing sur l'alphabet $\Gamma$ sont équivalentes aux MT sur lalphabet $\{0,1\}$ (à codage près)

**Idée de preuve**
Pour réduire un alphabet avec $\Sigma =2^k$ symboles à l'alphabet $\{0,1\}$, on <u>numérote chaque symbole</u> et on le remplace par son numéro en binaire. 
On <u>simule</u> une étape de calcul d'une machine avec l'alphabet $\Sigma$ par $k$ étapes de calcul qui lisent $k$ cases consécutives avant de changer d'état selon le résultat de la lecture.

