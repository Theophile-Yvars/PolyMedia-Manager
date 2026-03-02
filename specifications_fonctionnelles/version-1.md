# Spécifications Fonctionnelles : Système "PolyMedia"
## Projet : Gestionnaire de Bibliothèque de Médias Évolutif

Version : 1.0

Objectif : Refonte du système de gestion de stock pour supporter le multi-support et les règles métier variables.

## 1. Contexte du projet
La bibliothèque souhaite moderniser son catalogue pour inclure non seulement des livres, mais aussi des supports numériques et des objets de collection. Le système doit être robuste, facile à maintenir et permettre l'ajout de nouveaux types de médias sans réécriture majeure du coeur de l'application.

## 2. Périmètre Fonctionnel (User Stories)
### 2.1 Gestion du Catalogue (Core)
[F-01] Ajout de Médias : Le système doit pouvoir enregistrer des Livres, des DVD et des Magazines.

Livre : Titre, Auteur, Nombre de pages, ISBN.

DVD : Titre, Réalisateur, Durée (minutes).

Magazine : Titre, Numéro d'édition, Mois de parution.

[F-02] Recherche : L'utilisateur doit pouvoir lister l'intégralité du catalogue ou rechercher un média par son identifiant unique (ID) ou son titre.

[F-03] Suppression : Possibilité de retirer un média du catalogue via son ID.

### 2.2 Gestion des Flux (Emprunts)
[F-04] Statut d'Emprunt : Le système doit suivre si un média est "Disponible" ou "Emprunté".

[F-05] Éligibilité à l'Emprunt : * Les Livres et DVD sont empruntables.

Les Magazines sont consultables sur place uniquement (interdiction technique de les emprunter).

[F-06] Retour et Amendes : Lors du retour, le système calcule une amende si le délai est dépassé.

Règle Livre : 0.50€ par jour de retard.

Règle DVD : 1.50€ par jour de retard.

### 2.3 Reporting et Export
[F-07] Statistiques : Afficher le nombre total de médias, le nombre de médias actuellement empruntés et la valeur totale des amendes perçues.

[F-08] Exportation : Le système doit pouvoir générer un récapitulatif textuel du catalogue.

## 3. Contraintes Techniques (Architecture)
Le respect de ces contraintes est éliminatoire pour la validation du projet.

Extensibilité (OCP) : L'ajout d'un type "Disque Vinyle" ne doit nécessiter aucune modification de la classe de gestion Library.

Modularité des Interfaces (ISP) : Un média non-empruntable ne doit pas posséder de méthodes checkOut() ou checkIn().

Abstraction du Stockage (DIP) : La logique métier ne doit pas dépendre directement de la console ou d'un fichier. On utilisera une interface d'abstraction pour l'affichage et la sauvegarde.

Gestion Mémoire (Modern C++) : Utilisation obligatoire des Smart Pointers (std::unique_ptr ou std::shared_ptr) pour éviter toute fuite mémoire.

## 4. Critères d'Acceptation
Le programme compile sans warnings avec les flags -Wall -Wextra.

Aucune fuite mémoire détectée (Valgrind ou Sanitizers).

Un nouveau média peut être ajouté en créant une seule classe supplémentaire.