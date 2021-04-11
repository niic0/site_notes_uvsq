# TD5

1. Position : 

   * ORF19 + 3 1545 4619 3075 | 1024
   * ORF20 + 3 4671 5924 1254 | 417
   * ORF2 + 1 331 1422 1092 | 363
   * ORF17 + 2 5939 6601 663 | 220 

2. Item: Positions:
   boite -35 268, 387, 4096, 4732, 6630, -6291
   boite -35 1471, 3230, -663
   boite -10 410, -3643
   boite -10 294, 1495, 5352, 5495, 5636, -5970 

3. --> ORF2 + 1 331 1422 1092 | 363
   boite -35: 268
   boite -10: 294

   --> ORF19 + 3 1545 4619 3075 | 1024
   boite -35: 1471
   boite -10: 1495

   --> ORF20 + 3 4671 5924 1254 | 417
   boite -35: RAS
   boite -10: RAS

   --->

   ORF17 + 2 5939 6601 663 | 220
   boite -35: RAS
   boite -10: RAS

   5 + 5981 6601 621 1
   boite -35: RAS
   boite -10: RAS 

   Item: Positions:
   RBS 155, 314, 328, 452, 731, 1211, 1534, 1951, 2035, 2146, 2668, 4659, 4985, 5962, -1784, -1865, -2630, -2677, -2987, -3151, -3502, -4542, -5209, -5370, -5656, -6433, -6523 

4. --> ORF2 + 1 331 1422 1092 | 363
   RBS: 314

   [Pas 328:

   RBS A G G A
   328 329 330 331
   ATG A T G
   331 332 333

   A priori pas de signaux qui se chevauchent...]

   --> ORF19 + 3 1545 4619 3075 | 1024
   RBS: 1534

   --> ORF20 + 3 4671 5924 1254 | 417
   RBS: 4659

   --->

   ORF17 + 2 5939 6601 663 | 220
   RBS: RAS!

   5 + 5981 6601 621 1
   RBS: 5962!

   On peut enfin lever l'ambiguité: GeneMark semble avoir raison:

   5 + 5981 6601 621 1
   RBS: 5962! 

1. La requète (query) fait 135 acides aminés.
2. Il y a beaucoup de protéines qui ressemble à la notre.
3. Dans l'onglet description on a la e-value. On obtient $10^{-72}$ et $10^{-47}$ jusqu'à $10^{-15}$.  Cutoff = seuil = $10^{-7}$. 
4. Cette protéine appartient à une bactérie comme son nom l'indique dans l'onglet alignment *Bacillius*. Sa e-value (à voir dans Excpect toujours dans alignements) est de $10^-{72}$. On a une identité de 100%.
5. La longueur de l'alignement correspond à ce qu'il y a dans identities, positive et gaps (x/longueurAlignement), ici 104.
6. La Query va de 32 à 135 et le sujet de 1 à 104.
7. Partie non couverte de 1 à 31 (23% non couvert et donc 77% couvert).