

# Organisation de la mémoire

Comment le système d'exploitation va gérerl a mémoire.

### Hiérarchie de la mémoire

Il existe encore un rapport proportionnel entre la rapidité d'un composant mémoire, et son coût (en argent). On établit alors une hiérarchie mémoire (du plus rapide au plus lent) :

* Registre
* Cache
* Mémoire vive (RAM)
* Stockage de masse (Flash, Disques)

### Gestionnaire de mémoire

* Conserve l'état de la mémoire en cours d'utilisation
* Alloue la mémoire aux processus
* Swapping
  * Mécanisme stockant sur le disque les processus en attente, afin de libérer une partie de la mémoire principale
  * Un processus prêt àà être exécité peut être à nouveau chérgé en mémoire$

Le *swapping* 

###  Virtualisation de la mémoire

Chaque processus dispose de son propore espace mémoire :

* **Programme** : binaire exécutable

* **Donnée** : variables globales et statiques

* **Tas** : Mémoire allouée dynamiquement

* **pile** : variables locales, arguments et adresses de retour de fonction

  ![Screenshot from 2021-04-12 11-31-04](/home/nicof/Desktop/UVSQ/in405/CM/Screenshot from 2021-04-12 11-31-04.png)

* La taille de l'espace mémoire allouée à un processus peut être augmentée, et dépasser la capacité disponible de la mémoire physique
* Elle présente un adressage virtuel: besoin d'une traduction entre les adresses virtuelles / logiques (entre 0x000000 et 0xFFFFFF par exemple) et les adresses physiques (sur l'ensembles de la RAM)

### Traduction des adresses

La traduction est gérée à l'aide de deux registres, pour des meilleurs performances : 

* Registre de translation : adresse du début de l'espace alloué au programme, dans la RAM
* Registre de limite : limite des adresses logiques réservées à un processus
* Equation de traduction : $adr_{phys} = adr_{log}+reg_{translation} \\ zaer$

### Pagination

* L'espace d'adessage est divisé en blocs de taille fixe (de nos jours, 4ko ou 16ko)
* Une adresse physique est constituée d'un numéeo de page, et d'un déplacement dans cette page
* Par exemple, sur une taille de 4ko : $$adr_{phys}=19,5ko \iff $$ (page n°4, offset de 3,5ko)
* On a donc besoin d'ue table des pages en mémoire, décrivant chaque page de l'espace virtuel avec : numéro de page, bit de validité, bit d'accès en écriture, etc
* Cette table nécessite d'être stocké
  * Besoin d'espace, car potentiellement beaucoup de pages chargées -> disques ?
  * Besoin d'une faible latence d'accès, pour de mailleures performances -> registres ?
* *Translation Lookaside Buffer* : Solution hybride gardant en mémoire rapide les pages les plus utilisées. On utilise donc la RAM

### Segmentation

* Séparation de la mémoire en plusieurs espaces d'adressage linéaire, appelés segments
* Chaque segment peut posséder une taille différente des autres, pouvant augmenter dans le temps et ocntenant des objets de même type (juste le coden juste la plie d'exécution, etc.)
* Ceci permet d'ajuster les caractéristiques du segment aux donnéeds qu'il contient
* Une adresse physique est constituée d'un numéro de segment

### Segmentation paginée

C'est une combinaison de deux stratégies.

* Permet d'éviter de charger des segments trop grands, tout en ayant les avantages de la segmentation
* Une adresse physique est aors constituée d'un numéeo de segmen, puis d'un numéero de page dans le segment et d'un déplacement dans cette page

## Ordonnacement

On cherche maintenant à gérer cette segmentation paginée. Il existe plusieurs algorithmes d'ordonnancement de pages mémoire :

* Si l'espace mémoire est plein, quelle ancienne page enlevée pour accueillie la nouvelle ?

### Algorithme de Belady

**Principe** : La page enlevée est celle qui ne sera plus utiliées ou le plus tard possible

* <u>Avantage</u> : optimal, utilisé comme référentiel
* <u>Inconvénient</u> : Théorique uniquement, nécessite de connaître l'ordre des pages accédées

### Algorithme FIFO

**Principe** : La page enlevée est celle qui a été mise en mémoire il y a le plus de temps

* <u>Avantage</u> : Simple à mettre en place
* <u>Inconvéniant</u> : Des 'bonnes' pages peuvent être enlevées

### Algorithme de seconde chance

**Principe** : FIFO, chaque page possède une seconde chance avant d'être enlevée

* La seconde chance est représentée par un bit initialisé à 1
* Si le bit est à 1 lorsqaue la page doit être enlevée, elle est remisé à la fin de la FIFO avec le bit à 0
* Si le bit est à 0 lorsque la page doit être enlevée, elle est enlevée 
* Si la page est accédée, son bit est remis à 1

* <u>Avantage</u> : FIFO améliorée
* <u>Inconvéniant</u> : Manipulation un peu longue, peut être 

### Algorithme LRU (*Least Recently Used*)

**Principe** : La page enlevée est celle qui a été accédée il y a le plus de temps

<u>Avantage</u> : Efficace

<u>Inconvéniant</u> :

### Algorithme NFU (*Not frequently Used*)

**Principe** : La page enlevée est l'une des moins fréquemment utilisées. La fréquence est calculée pour chaque page dans un compteur

### Algorithme de *Working Set*

**Principe** : On considère un ensemble de page (généralement un ensemble de pages par thread), et on applique un LRU ou NFU dessus

* <u>Avantage</u> : Simple et efficace