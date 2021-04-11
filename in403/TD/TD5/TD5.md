# TD5

### Rappel

**Chaîne hamiltonienne** :  Chaîne qui passe par tous les sommets une fois.
**Cycle hamiltonien** : Chemin hamiltonien qui est un cycle.
**Chaîne Eulérien** : Chaîne qui passe une fois par chaque arrête. Une chaîne Eulérienne existe si 2 sommets sont de degrés impairs et tous les autres de degré  pairs.
**Cycle Eulérien** : Chaîne Eulérienne qui revient au sommet de départ. Un cycle Eulérien existe si tous les sommets sont de degré pair.

### 1 - Sur des petits graphes pour se faire la main

<iframe frameborder="0" style="width:100%;height:164px;" src="https://viewer.diagrams.net/?highlight=0000ff&edit=_blank&layers=1&nav=1#R7Zlbb9owFMc%2FDY%2BrYpvcHgdtd9culbZ2b25iiNUQI2NG2KefQ%2BxcDB2GLqQTBQn5HNvHyd%2B%2FHA5mgMaz%2FA3H8%2BQTi0k6gE6cD9DlAEIU%2BvKzcKxLBwSwdEw5jUsXqB039DdRTkd5lzQmi9ZAwVgq6LztjFiWkUi0fJhztmoPm7C0veocT9WKTu24iXBKtob9oLFISm%2FgNka%2FJXSa6JWBo3rucfQw5WyZqfUGEMGweJfdM6xjqfGLBMds1XChqwEac8ZE2ZrlY5IW0mrZynnXj%2FRW181JJmwmjN13n79%2F%2FQk%2B%2BO9H30JGry7Jx1duGeUXTpdE38bmYsVaCySjyL2QxmiVUEFu5jgqelaSBulLxCyVFpBNvJiXGzShOZGLjiY0TccsZXwTCMWYBJNI%2BheCswfS6PGigNxPqh69D1Kikbo%2BwgXJH71xUMkpKSVsRgRfyyFqAgzUDihCh56yV%2FV%2BI%2BVKGlutfVgRNq0i1yrLhhL6ANE9cAaqo2enOjxD1Su7N9XRGahuZpj%2BVR%2BegeoIGaqjvlX3LFTP4tdF1SKtjGWkrXRbJlRIzTKhaibgKbsh8PXmddSWkJyKW7Vu0b6TbUe1L%2FOmsdZGJkW6bRp3en5h1JM2lp5VKkBiXYU9ts1SJbbkEbHIJQLzKRF78d8GpwGGuwMM7eMkxYL%2Bal%2FwLlrUCl8YlbdSZ4PQ%2BOYDBnDljapZzYrNCISGBuCeEagUYivQBt7qtp%2FAc9Abz7voBEfQ6eyh8%2FDn5l%2FyPLTlGfbJs5lnh%2FBYns2vSf%2FEPIf98VzReeEekj31c6CmWeXpfpnWv%2BFfmD4J03q5F6a7Y9rtt5oYXgSoDat7JKy7YpnFSde82px9dMwraNLagHcfr01aK3afIa%2F6pGN%2FDka95mBH0gjD%2BtUG0yx2rTPy38Oaib5r3m1OnV54P03N0Wsi3z4QrZPxwYyD%2FbG6BtvmYO%2BUYFuXHf9H0WFfSPebxM3DDsc9Emm4J1DXPNscmXZdSB%2FDs%2F0BXv9F9PP%2FXSgrZBQiFAYwgNABQZtJf2fv4dnbvfAcz3OAD3xfBmsvsrv3yY%2BBNOs%2Fm8vh9R%2F66OoP"></iframe>

Cycle hamiltonien ☑️
Chaîne Eulérienne ❌

<iframe frameborder="0" style="width:100%;height:114px;" src="https://viewer.diagrams.net/?highlight=0000ff&edit=_blank&layers=1&nav=1#R7Vpbk9ogFP41PnYnQK6PVXd7n152pu32jU3QZDYGJ%2BKq%2FfUlAibBS6OriVnVGYdzgAN8fJwcTuyg3mj%2BLsXj8AsNSNyBRjDvoH4HQuQ5%2FDdTLIQCAigUwzQKhArkivvoL5FKQ2qnUUAmpYaM0phF47LSp0lCfFbS4TSls3KzAY3Lo47xUI5o5Ip7H8dkrdmvKGCh0LpWofV7Eg1DNTIwZM0j9p%2BGKZ0mcrwORNDLvqJ6hJUt2X4S4oDOCip020G9lFImSqN5j8QZtAo20e9uS%2B1q3ilJWJUOPevD15%2Ff%2F4BPzsfuD49Gt33y%2BY0lrDzjeErUMpaTZQsFELfC94IL3VkYMXI%2Fxn5WM%2BNs4LqQjWIuAV7Ek7HYoEE0J3zQ7iCK4x6Nabo0hAJM3IHP9ROW0idSqLF9lzwOVjVqHzhEXTk%2FkjIy37pwsIKTs5TQEWHpgjeRHaAnd0Ay1FR7O8v3G0lVWNhqpcOSYcOV5RxlXpBA7wG6DS4AdWSfG%2BrwAlFHTtOoowtAXfcwzaNuXgDqJjoz1N1LeJrqqDfu1137AlC3jHND3amAehK8zSJ0LiU0IWWkyzChDGqaMHk%2FALaUCwDfLT9cT%2BYR%2B811xo0lpQdpMyv3M8QMJSyUkPBFFzpl4kOxLu%2B2lFS%2F%2FbdfoEACdevYttUcKTpNfVLh2clwOiRsR0NrM3cK3LA2cEPpUhJjFj2X57uJMHKEbzTiK8lDDlejpq1xTqxT9ipeUDRDa54FaIYEDmuGlvxdLfsFlPaap%2FT%2BhAbtoTNsBZ2BtZuFVem8Zkg%2FFyems1flllkfnXNvvRehc3fdakoLV94Ypx3zBnkIeS50ITSAWyamYd3Yhm0bwAGOw9scyHe40cyK%2FRunUNdZqHL3v0YrNZ2FLaFuXWdBuzV61oF816%2BfuqFTc7pKZuW0nAaH%2BHejRf7dagel3WOFLLqhukOWKmmra8jyIkq7LeG0fhl0DnXTzn8MnZrTVZKC19DjZaGHWZHTbqNXS9M8EqdNPRtYN6erpFyvmZLT87lZH21aR4o71gzVHXecQTL7tccd1TkNm%2FXRdaRKvDNOlbiNnwWwv283Xp9vF%2B81zyVWOThNoscqtadJGnyr00Y%2FrV6nn3ssbe90ocfx0xbY%2BTA4kZ%2FmYv6vUNE8%2F%2Bctuv0H"></iframe>

Cycle hamiltonien ☑️
Chaîne Eulérienne ☑️ 
Cycle Eulérienne ❌

<iframe frameborder="0" style="width:100%;height:194px;" src="https://viewer.diagrams.net/?highlight=0000ff&edit=_blank&layers=1&nav=1#R7Ztbb9owFMc%2FDY9Ddpzr46Dt7tql0rbuLU0MRA0xCmbAPv0cYudiQDFpc6FApQof2yfJ3784x8dhgMbzzbvYXcy%2BEB%2BHAw34mwG6GWiabpnsf2LYpgbN0FPDNA781ARzw33wD3Mj4NZV4ONlqSElJKTBomz0SBRhj5ZsbhyTdbnZhITloy7cKT8iyA33nhvivWa%2FAp%2FOUqttFFq%2Fx8F0Jo4MAa95dL2naUxWET%2FeQEOak%2Fyl1XNX%2BOLtlzPXJ%2BuCCd0O0DgmhKbf5psxDhNphWxpv7sjtdl5xziiKh3GxoevP7%2F%2FgZ%2Bsj6MfDglub%2FDnN0bq5a8brrC4jN3J0q0QiHlhY8EKo%2FUsoPh%2B4XpJzZrRwGwzOg9ZCbKv7nKRDtAk2GB20NEkCMMxCUm8c4R8F9sTj9mXNCZPuFBjejZ%2BnGQ1YhyYRCN%2BfjimeHP0wmEmJ6MUkzmm8ZY14R00h48AJ1QXY7vOxxtx06ww1MLmcsKmmedcZfaFC32C6Ca8ANWR2TfVtQtUHVldq44uQHV5huledf0CVNdRz1S3L%2BFpKqve%2BbxuWwqqR%2F7bJFZkpYhEuKx0WSaUSE0iyiNVaPJyQeC73YfZ8Sagv5kNDA1eeuA%2Bk%2B83iWJAFLaiELGLLnRKig%2FFurzbriT6nT78qQrYF%2FHvsaFmSpFV7GGFWZy68RTTqnhyn50CG8YBNoQtxqFLg7%2Fl8z0EDD%2FCNxKwK8kffraEpikxl14n71UMlSVHe4xDyVGqw56jHb%2FZZddH2lEJEBtGugB0jncF0rAEdM53L5HWFJFO2e%2BMaUsfIgchx9ZstsKDdhlMYAxNYJoAWtCyWJt6vCPtoJvsNjp4Cm3dCyph%2B3V6b%2BleOBIbtHUvSAGfY9TkXY4cZUdNM62yKGqWaVhnfgdnNL8b54G0WDMcizSUkZYdybFP00irrDivIcuzkLbPhGk5erbqTtNWhaOmmVZZz19Dj%2BeFHroi03anS0tdfyGmddAx02b3TJ9ONHx9PHc7R%2BvGC8Ude47ajjt6kP177XGHOtNat3N0G6kSp7%2BpkuzVhFe9ASFvtmXlrjYgILjE%2FfweyK6SGTx32eWtiB7I3n3y6ryfuJ2ty%2BV3Q4A%2BlB5Q6hsGla4af9ZdE07nieHeaxuMHcspfOpmi%2BSXcCr8Ng7oNXt0noAWJjOBklZzdXzAldXu%2BhiCHiR8rhjW3Pk%2FNH89m8kKv60D2oMMzhXQmvmWJgCt8ts6oHb3gCrjeTpm9ZLsqnAqpBez%2FEnfX8UywRCAQnIPlbmEztBx8swgtGrOz%2FLa6sV4Z8X850Zp8%2FwnXej2Pw%3D%3D"></iframe>

Chaîne hamiltonien ☑️
Cycle hamiltonien ❌
Cycle Eulérienne ☑️

### 2 - Jouons un peu aux échecs

<iframe frameborder="0" style="width:100%;height:204px;" src="https://viewer.diagrams.net/?highlight=0000ff&edit=_blank&layers=1&nav=1#R7ZrbjtsgEIafxpeVDPiUW2fT7VFVG6mVekdsEluLjUVIk%2FTpS2rs2J6stJW6ayRWkSIzAyaZD4YfbI8sq9O9pE3xWeSMe9jPTx658zAO4kh%2FXwzn1oDDoDXsZJm3JnQ1rMvfzBh9Yz2UOduPKiohuCqbsTETdc0yNbJRKcVxXG0r%2BLjXhu5Mj%2F7VsM4oZ6DajzJXRWtNwkHtd6zcFV3PyDeeDc0edlIcatOfhwleXD6tu6LdvUz9fUFzcRyYyMojSymEaq%2Bq05LxS2i7sLXt3j7i7X%2B3ZLV6SoNl%2BP7L968%2F0cf4Q%2FptIcrVHfv0Bvnm5%2F6i%2FDCOyF6duxgdi1KxdUOzS%2Fmoh4FH0kJVXJeQvqT7piWzLU9M95ZyumE87eOzFFxI7a5FrW%2BQ7pUUD32wdRzSraiVGRkoupRLzrtGOqw5Zck261sOPFGWsM1We8yfYFKx06PxQX3U9WBmomJKnnUV0wAHBlQ3kBNTPl6HRVelGIyIzkbNQNz1d77C0BeGx7%2Bw6abIkA1xEw7B1sFBAE7sJpvAt45NACdOYhschvKQxbfgLKKY0Og%2FTZzIOjghgIMDN%2BH0MKyBg28sOQvb4LyQHpjA6Zeg%2BeDAJQe7qgci6%2BAQOHOwbXBeJq1NBYEFcKAgcFUPYOvYQD2AXNUDgW1wArjkuCoHpmyi2dlgKAdCN%2BGArDY%2FnBty4PV8wBY4EYAT2cZmnuMBC9jEMKu5yQZsQOdnk8Ck5uiKM4XTJ7n54Nx4kuPoo5xpVpsfTnjj6MbRtDaVAxbAgULa0Q3oVEdbwAbq6P6BumNwpjtQC%2BDAoxtHz6MBm2B2NnCP4%2BqbHSCrzQ8HbnIc1dFADczOptOOQx39ejpgCxyoo5GrcmC6A30%2BOLp4fU%2Fxr2%2FwLihZ%2FQE%3D"></iframe>

Sur un échiquier en 5x5, il y a une chaîne mais pas de cycle. Sur un 4x4, pas de chaîne. Sur un 8x8, existence d'un cycle.

### 3 - Algorithme pour trouver un circuit Eulérien

1. $\forall s\ d^+(s)=d^-(s) \rightarrow cycle$ 

2. On créer une anti-arborescence à partir d'un sommet de départ. Prenons par exemple l'anti arborescence obtenue  partir de 1 et d'un parcours en profondeur.

   <iframe frameborder="0" style="width:100%;height:194px;" src="https://viewer.diagrams.net/?highlight=0000ff&edit=_blank&layers=1&nav=1#R7VrbcpswEP0aP6YDyMbosXaS3tLpJTNt0jcF1kAjIyrLMfTrK4FkQ4hdPBMHt9h%2BgD26snuOpMUeoOk8e8NJGn1kAdCBYwXZAJ0PHMe2sSUvCslLxEVuCYQ8DnSlDXAd%2FwYN6nbhMg5gUasoGKMiTuugz5IEfFHDCOdsVa82Y7Q%2BakpCPaK1Aa59QqFR7XsciKhEvVGl9luIw8iMbFu65I749yFny0SPN3CQg9W3LJ4T05euv4hIwFYVCF0M0JQzJsq7eTYFqnxr3Fa2u9xSup43h0S0aTAdvfv07csP%2B8P4%2FeQrZvHFOVyd2WOv7OeB0CWYBymmK3LjIgikx7SZsEReJsVzg%2BrZkhbjImIhSwi9YiyVoC3BnyBEruNNloJJKBJzqksXgrN7mDLKeDEIcn0P7mbrEhMLJJEZS4TuyHa1XWl5WXwUHlNawQMC3syXOGSxuNHjqvtbNe1XI22dZ%2FopCiPXRukE9eRb3a2hBVtyH3b6WCtCEB6C2FlzvCaGFBywOQiey5YcKBHxQ30uRDM%2FXNfbRF%2FeaALsRQb3CTK4VGif11jh%2FloyU3C2KKLzWlawcZptCuVdqK6u6UbOq%2BypxJtUo1QKXzFsFcUCrlNSuHYl1546f8giLVeDWZwpHk4ouQM6WWvS8EDztU4q5ylSbSHPdqJqXwEXkO0mSTOgpoFZHPJH9qqyFGkoqqxCBnt%2BCnjO%2F78ePKu2x2217W2hwktpe3wgbQ9P2n5S287wkbbdzrVtNWNyACmb7dZ6hV1U23IR8nZuutKzPL%2BpGremT2VsGhWWafXSR4nPwGMZEeCHOCrgf%2BWogA%2B0nODTctLqqOCgzpeT4emosI%2B2PZPe%2Fv2ogDrVtploJbDjvssPuUe3m%2Fcgc39W%2BaHW8ut2azUTrQTW67v8ht6xyc%2B89zzJr6X82ifKuFv5NRPlUd%2Fl5x5dLotP76n2k1%2FrxBJ3%2B57KayaWqO%2Fy86yjk98p99tLfrh17oe7zf1wM%2FdTZt8ViI8u%2FcPNLMHue5Tsxu9phwuTNDe%2F3RdllT9IoIs%2F"></iframe>

3. On créer le chemin en ne choisissant l'arc de l'anti-arborescence que quant il n'y a plus d'autres possibilités.

   <iframe frameborder="0" style="width:100%;height:1204px;" src="https://viewer.diagrams.net/?highlight=0000ff&edit=_blank&layers=1&nav=1#R7Zxdb5swFIZ%2FTS4rYTshcLmm7b46TVulTdqdExxgdXBGnCbZr58JNoE4aYzUyUS4vQCOPzj4nAfMa5QBmiy273O8TL6wiNAB9KLtAN0NIAQg9MSmsOxKi4%2F80hDnaSQrHQxP6V8ijbJdvE4jsmpU5IxRni6bxhnLMjLjDRvOc7ZpVpsz2jzrEsfyjN7B8DTDlGjVfqYRT0prMKrV%2FkDSOFFnBp4smeLZc5yzdSbPN4AIhsV%2FWbzAqi9Zf5XgiG1qJnQ%2FQJOcMV7uLbYTQouxVcNWtns4U1r5nZOMmzSYjD5%2B%2FfHtF%2Fg8%2FnT7PWTp%2FR15vAFhUPbzgumaqAvZu8t3aohIJEZMHmYsE5vb%2FXWTomdPHLGcJyxmGaaPjC2FEQjjb8L5TsYbrzkTpoQvqCxd8Zw9kwmjLN%2BfBPmzgEznVYmKBRKWOcu47Aj48rjW8mH%2FV9hTSmv2CJNgPhP28oKKqzg7dNK0Yut8Rl4br7HMbo7zmPBXR3ZcBVnAQ9iC8HwnWuaEYp6%2BNH3BMovjqt4hkmJHBrNNYJWjjcD6lMvxa0TY%2F7NmquBmtR%2Fpd6ICCJfbQ6HYi4stUN0Iv8qeSrueNpQKiIts2SQpJ09LvB%2FajbiPNHMBr5Yl2fN0W%2BTULcVTQm8rvlRMZe41EwSeSpAziXA%2B6eRYkZyT7etJogdUNVCg746ON7XbijQltTuKsr15CkB1p3Jsm7FdEmvEdmiVbeVoLbDjvuNXcdQd%2FKDDrxV%2BoSF%2B4slkF79QCyzqO37DYefwGzr8WuAnoTLCD9nEr3K0Fljf4dfEr%2BLKHn6n3j8cfhegMsJvZBc%2FpAX2RGT7hZ%2FvdQ4%2Fp%2Bu0w29kjJ9VXadytBbYkcOviV%2F1NLSGH3DSSzv8TKUX6FmVXipHa4EFemT7hd%2FY7xx%2BTnpph5%2Bx9AKsSi%2BVo7XABn3HL4Sdw89JL63wA8bSC7ArvQBdeum98gm8oHP86ZMUx99Fqoz48%2B3yp2svvV%2F4A3DYOf70WYod%2FgI4Rb7%2FpvyNSBAN35o%2F049qIAjs8qeL2r1fetD4q9QYa%2FxBfZrinn8XqTLhr%2FblohX%2BdFV76Pg74q%2BSY%2Bzxp09THH8XqTLiD1rlD%2Bqy9onI9oy%2F4%2Fe%2FDvCnrxE5%2Fi5SZcTf0C5%2Fuq4d9p2%2FY%2FmzA%2Fh1RX65ktc%2FNYczwM%2Bu%2FAJ1Xbv308%2Fjxb8O4OfUl3b4Gasv0K76AnX1pffq5zF%2B1dPQGn6oK%2BLLteBnLL4gu%2BIL1MUXYfH04PabwMP7oD0Eu6K%2FXAmCyFh%2FQXb1F6TrL73%2F%2BFPjD1pf%2F0Nd0V%2BuhT9j%2FQXZ1V%2BUo%2B77l%2FP6Sxf4cwJMO%2F6MBRhkV4BBugBzIrL94k9bf%2BgCgPqbeu%2B%2FktfWaf9nnMTh4ZeF9mW1n29C9%2F8A"></iframe>

4. Non, on ne trouve même pas de circuit Hamiltonien.

### 4 -  Degré minimum

1. Soit un sommet quelconque $s_1$. Il a au moint $\delta(G)$ voisins. soit $s_2$ l'un d'entre eux $s_1 - s_2$. $S_2$ a au moins $\delta(G)-1$ autres voisins que $s_1$ soit $s_3$ l'un d'entre eux  $s_1 - s_2 - s_3$ etc... $s_1 - s2 - s_3 ... s_{\delta(G)}$
   $s_{\delta(G)}$ a au moins $\delta(G)$ voisins. Ce peut être $s_1,s_2,..., s_{\delta(G)}$. Mais il y en a forcément un autre : $s_{\delta(G)+1}$ . $s_1 - s_2 ... s_{\delta(G)}, s_{\delta(G)}-1$
2. On repart de la chaîne précédente si $s_{\delta(G)+1}$ est voisin avec $s_1$ - cycle de longueur $\delta(G)+1$ sinon il peut être voisin avec $s_2....s_{\delta(G)}$ mais ily en a forcémet un autre : $s_{\delta(G)} +2$
   $s_1 - s_2 ... s_{\delta(G)}, s_{\delta(G)+1}, s_{\delta(G)+2}$
   Si $S_{\delta(G)+2}$ est voisin avec $s_1$ ou $s_2$ : cycle de longueur $\geq \delta(G)+1$ Sinon voisin avec nouveau sommet $s_{\delta(G)}+3$
   .....
   On finit par arriver au dernier sommet $s_n$. 

