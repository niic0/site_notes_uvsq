# TD3

### Exercice 1

1. Excentricité : A = 3 ; B = 2 ; C = 3 ; D = 3 ; E = 3 ; F = 2 ; G = 3 ; H = 4. La parcours le plus petit entre 2 sommets les plus éloigner permet de calculer l'excentricité des sommets. L'excentricité d'un graphe est la distance maximale existant entre un sommet et les autres sommets du graphe. Soit ici, 4.
2. Le diamètre du graphe est de 4.
3. Les centres sont B,F.

### Exercice 2

1. ```
   parcoursProfondeur (SOMMET s, GRAPHE g) :
   	si le sommet s de g n'est pas marqué
   		marqué le sommet s
   		pour tout sommet voisin de s
   			si voisin n'est pas marqué
   				parcoursProfondeur(voisin,g)
   ```

2. <iframe frameborder="0" style="width:100%;height:625px;" src="https://viewer.diagrams.net/?highlight=0000ff&edit=_blank&layers=1&nav=1#R7VnZcpswFP0aHjPDYgh5rLekM80kbaZt%2FCiDDCQyYoQwkK%2BvMBKbMSF2E9zG2A%2FoaLvcc8%2B9LJI2WSfXBATuLbYhklTZTiRtKqmqMlJVKfvLdpojpswBh3g2H1QCD94LzEFV5mjk2TCsDaQYI%2BoFddDCvg8tWsMAITiuD1thVN81AA7cAR4sgHbR355NXX4VulziN9BzXLGzIvOeJbCeHYIjn%2B8nqZp6lf3y7jUQa%2FHxoQtsHFcgbSZpE4Ixzc%2FWyQSizLfCbfm8%2BZ7ewm4CfdpnQry%2BI0%2FuIvj5Mga%2F0h93praYXnBjNwBFUFzG1liaCgdBm%2FmLNzGhLnawD9CsRMdWRDYw20VhjXLIN4wDDj5BSlPOPYgoZpBL14j3hpTgZzjBCJPtltp8exQ9ghfmsnFuXmbTXjdwKMQRsfio25f7yfP13XdrdB%2BH9NZcfI2TCxFtgDiQdvjILMhiIoB4DSlJ2TwCEaDepm4H4NHoFONKRtgJJ6WdoC4jawQZiGYOZF2GQ7c%2ByZEwWgpoJjC2aQUW6JI0ETauumAzBhBiesy4jl2PwocAbD0bs5RQpxKEQS7SlZdkITFeeQhVmLUBNFdWG%2BeGZcLlKpuBfVrBZdlgx04saIWZLdRvIKEwqUC77PHekVAzz16KUGtcyQUccitpQGDH8N0abIq84%2FwDFAUTjz6yc5mfLyr4NKl0TFPeeIsGmbtJ%2BiiWzBoLsWTWKDfYtsQOhyl3vyJ7KFfRjpQun3qPPWZiETSaUQ%2Baoi2WyA3jsxoBUZhxRIwofzNGlPeNEfnUY2T0LjGiq8PGiHlY3fjSXTf%2B3SqxUxJaoqp3lWDAwFVCO4ze6ZneFnq1plYHp9d4%2Fbb8JO%2BzOzJsn1Ssf9CddqeZb9XU%2BKyptpRpnpqm2ipix6Ouj314qo%2BzHerpI7PLQWWmHyazyed5oj1KePqoLryRPrDwRHH9f4V32Vd4V0MKT7j9zMM%2BBX1QArzskQCvz3mtkdeMxjOYbgx9Q9H27rzJ480nZ61ZjYyhWSteEXexNj%2Brr6k%2B48N4ZM3yo1j%2BOqz88qjN%2FgA%3D"></iframe>

   

### Exercice 3

1. Il faut qu'il n'y est pas de circuit car sinon, on se retrouve dans une impasse.
2. L'algorithme L'algorithme 1 initialise les sommets avec la couleur blanche et met tout les sommets avec un père égale à NULL. Ensuite, l'algorithme parcours tous les sommets avec l'algorithme 2. L'algorithme 2 met en Gris le sommet, cela correspond à sa phase de "traitement". On a 2 variables de temps, *d* et *f*  qui vont permettre de savoir à quel moment le sommet à été traité. Pour simplifier d = gris et f = noir. Noir correspondant au traitement finie du sommet. 

