# Calcul haute performance

Le calcul haute performance est la branche de l'informatique qui traite des **supercalculateurs**. Ils sont utilisés pour la modélation et la simulation de problèmes. Ce sont des problèmes qui ne cesse de croître (en temps de calcul / en taille de données).

### Quelques chiffres

*TOP500* : Classement bi-annuel des supercalculateurs dont la première place est détenue par Fugako (*RIKEN Center for Computational Science*, Japan):

* Nombre de coeurs : 7 630 848
* Performances max : 442 010 TFLOPS
* Puissance énergétique : 29 899 kW

Green500 : classement fait sur le rapport performance / puissance énergétique

### Centre de calcul

Un centre de calcul est constitué de plusieurs noeuds de calcul organisés en îlot : les noeuds placés sur le même îlot ont des connexions plus directes qu'avec les autres. Il peut être constitué de plusieurs technologies et/ou processeurs. Un centre de calcul est généralement accompagné d'un centre de connées, pour y stocker les données des programmes : 

* Systèmes se composant de Petaoctets, voire ExaOctet de données
* Généralement constitué de plusieurs technologies (Flash, rotatif, bande magnétiques...)

### Le rapport avec le système d'exploitation

* Il faut **toujours** pouvoir assurer la liaison entre les applications et les ressources matérielles
* Il faut **toujours** pouvoir assurer le partage *équitable* des ressources entre les applications
* Utilisation d'allocateur de tâche (slurm par exemple)
* Appels systèmes effectués par des bibliothéque utilisées dans le milieu HPC

## Bibliothéque utilisées dans le HPC

### Calcul parallèle : OpenMP

### Calcul parallèle : MPI

* Utilisation en mémoire distribuée
* Chaque processus MPI possède un identifiant
* Communications : pair à pair, diffusion, groupes

### Calcul parallèle : CUDA

* Utilisation dur processeur graphgique
* Très efficace en SMIF (Single Instruction Multiple Data)
* Coût des communications entre RAM et GPU non négligeable

### Entrées / sorties parallèles

* MPI-IO : S'appuie sur MPI pour l'écriture de fichiers de large taille en parallèle
* HDF5 : format de fichier de large taille organisé en conteneurs de données