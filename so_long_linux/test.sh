#!/bin/bash

# Répertoire contenant les fichiers de cartes
MAPS_ERR_DIR="maps_err"
MAPS_VALID_DIR="maps_valid"

# Fonction pour exécuter les fichiers de cartes dans un répertoire donné
execute_maps() {
    local dir=$1
    for map in "$dir"/*; do
        if [ -f "$map" ]; then
            echo "Exécution de $map..."
            valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./so_long "$map"
            echo "$map terminé."
        fi
    done
}

# Exécuter les fichiers dans maps_err
execute_maps "$MAPS_ERR_DIR"

# Exécuter les fichiers dans maps_valid
execute_maps "$MAPS_VALID_DIR"
