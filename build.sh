#!/bin/bash

# Créer un dossier build et configurer le projet
mkdir build
cd build
cmake ..

# Compiler le projet et les tests
cmake --build .