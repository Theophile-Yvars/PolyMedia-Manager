# PolyMedia-Manager

![PolyMedia](assets/logo.png)

## PolyMedia - Gestionnaire de Bibliothèque

PolyMedia est une application console en C++ qui permet de gérer un catalogue de médias variés. L'objectif est de simuler le fonctionnement d'une bibliothèque où chaque objet a ses propres règles.

## Installation & Compilation

### Compiler le projet :

```bash
chmod +x build.sh
./build.sh
```
Ceci génère l'exécutable dans le dossier /build.

### Nettoyer les fichiers de build :

```bash
./clean.sh
```
### Exécution

Pour lancer l'application principale :

```bash
./run.sh
```
Ou manuellement : ./build/PolyMediaMain

### Tests & Qualité

```bash
./testWithCoverage.sh
```

Ce script génère un rapport montrant quelles lignes de code sont réellement testées. -> index.html