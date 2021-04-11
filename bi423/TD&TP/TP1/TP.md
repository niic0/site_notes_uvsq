# TP - Introduction à la programmation Python

## Exercice 1

```python
>>> 5+3 = 8
>>> 2-9 = -7
>>> 34+20*4 = 114
>>> (34+20)*4 = 216
>>> 20/3 =  6
>>> 20.0/3.0 = 6.66666
```

## Exercice 2

Les variables changent quand on lui affecte une autre valeur.

## Exercice 3

Différence entre python 2.7 et 3.x, il faut mettre les virgules en 2.7.

## Exercice 4

```python
>>> a = c
>>> a = b
>>> b = c
```

## Exercice 5

En python comme dans n'importe quel langage, les variables sont typés, `int`, `float` et `str`. Quand on mélange des `int` et des `float`, on obtient des `float`.

## Exercice 6

Une chaîne de caractères est un type en python qu'on appelle `str` pour string. On peut concaténer 2 chaînes de caractères en faisant simplement `a+b` ou a et b sont des chaînes de caractères. On peut encapsuler les chaînes de caractères par des simples ou double quotes.

## Exercice 7

```python
print seq[0:3]
# Affiche les caractères du caractère 0 au caractère 2 (car 3 non inclus).
```

```python
print seq[3:]
# Affiche les caractères du 3ème au dernier caractères
```

```python
print seq[0:1000]
#Affiche de 0 au caractère 1000 même si cela dépasse le nombre de case du tableau
```

```python
print seq[:]
# Affiche toute la séquence
```

## Exercice 8

Les opérateurs > ; != ; == ; < ; or, renvoie des booléen.

## Exercice 9

On utilise ces opérateurs pour comparer des chaînes de caractères. En revanche, faire `>>> 'A'>'a'` renverra `False` car python va prendre le code ASCII des caractères et 65 n'est pas supérieur à 97 (le code ASCII correspondant respectivement à 'A' et 'a').

## Exercice 12

`find` permet de trouver la position de la première occurrence.