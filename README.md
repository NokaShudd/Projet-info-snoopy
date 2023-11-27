# Projet info Snoopy

<p align="center">
  <a title="Wagner Paintings Gallery, CC BY-SA 4.0 &lt;https://creativecommons.org/licenses/by-sa/4.0&gt;, via Wikimedia Commons" href="https://commons.wikimedia.org/wiki/File:Snoopy_and_Woodstock_in_the_Starry_Night_With_Sunset_End.jpg"><img width="256" alt="Snoopy and Woodstock in the Starry Night With Sunset End" src="https://upload.wikimedia.org/wikipedia/commons/thumb/4/43/Snoopy_and_Woodstock_in_the_Starry_Night_With_Sunset_End.jpg/256px-Snoopy_and_Woodstock_in_the_Starry_Night_With_Sunset_End.jpg"></a>

</p>

## Projet informatique ING 1

Projet d'informatique de première année en c, suivant ce [cahier des charges](https://boostcamp.omneseducation.com/pluginfile.php/3806181/mod_resource/content/1/Projet-C-Snoopy-ING1-2023%20S1%20-%20Paris.pdf).

L'exécutable n'est pas, pour l'instant, inclus sur le repo.

## But du jeu

Le but de ce jeu, basé sur [*Snoopy's Magic Show*](https://en.wikipedia.org/wiki/Snoopy's_Magic_Show), un jeu Gameboy des années 90, est de récupérer les quatre oiseaux dans chaque niveau.
<p>
  <a href="https://en.wikipedia.org/wiki/File:Woodstock.png#/media/File:Woodstock.png">
    <img title="Woodstock, Charle Schulz, United Feature Syndicate Inc, obtained from http://peanuts.wikia.com/wiki/File:Woodstock.png" src="https://upload.wikimedia.org/wikipedia/en/d/db/Woodstock.png" alt="Woodstock.png" height="82" width="76">
  </a>
</p>

> *Woodstock*, l'oiseau dans snoopy et l'objectif du jeu.

Chaque niveau est un tableau de 10 lignes et 20 colonnes, où l'on peut voir des balles rebondissantes, des murs, certains cassables ou déplacables, certains piégé, clignotants ou dissimulants des *power-ups*, des tapis roulants...

Le jeu ce joue *contre-la-montre*, le joueur a $120s$ par niveau et $3$ vies par partie (❤️❤️❤️).

## Le projet en bref :

Le projet consiste à coder un jeu **console** en c. 

Il suivra les mécanismes de *Snoopy's Magic Show*, avec un total de quatres niveaux (un par membre du groupe) de difficultés croissantes.
Fini, le jeu contiendra :

* Un menu permettant de :
  - Voir les règles du jeu
  - Commencer / reprendre sa partie
  - Entrer un code pour accéder à chaque niveau
  - Voir les scores
  - Voir les crédits
  - Quitter le programme
* Un système de sauvegarde de parties
* Un système de scores notant la rapidité du joueur
* Un système de chargement de niveaux à partir de fichiers ```.txt```
* Et, bien sûr, la possibilité de jouer aux niveaux (et un mode pause)

## En jeu :

*(Temporaire, placeholders)*

Le jeu, en console, est limité en termes de caractères, voici ceux utilisés, leurs significations et leurs effets :

|Caractère|Signification|Effets
|:-:|:-|:-|
|■|Mur|Infranchissable|
|◄ / ▲ / ► / ▼| Tapis roulant|Décale le joueur dans la direction indiquée|
|$\color{cyan}◙$| Mur cassable |Détruit si le joueur appuie sur ```a``` en le regardant, infranchissable sinon|  
|$\color{cyan}▒$ / $\color{blue}▓$| Mur clignotant |Temporairement franchissable/infranchissable|
|$\color{yellow}◙$| Mur déplacable | Décalable **une** fois, infranchissable |
|$\color{magenta}◙$| Mur piégé | Tue le joueurs s'il le touche |
|$\color{red}•$| Balle | Enlève une vie et relance le niveau si elle touche le joueur| 
|$\color{green}☼$| Oiseau | Objectif, ramassable |
|♦|Snoopy| Icône du joueur| 



## État du projet

- [X] Listage des tâches, identification des problématiques 
- [X] Partage des taches (répartition pour l'instant)

+ Hugo $\rightarrow$ Menu
+ Pierre $\rightarrow$ Mouvements Snoopy
+ Otniel $\rightarrow$ Plateau
+ Nicolas $\rightarrow$ Mouvements items

- [ ] Codage
- [ ] Relecture, homogénéisation
- [ ] Préparation présentation finale


## Groupe **AI**, composé de :
- **Hugo Roure**
- **Pierre Juramie**
- **Otniel Sandeu**
- **Nicolas Tremblay**

## Idées bonus : 
- menu rajouter personnalisation personnage + personnalisation settings
