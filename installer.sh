#!/bin/bash

git clone https://github.com/janhan42/PlanetGravity.git
cd PlanetGravity
bash -c "$(curl -fsSL https://raw.githubusercontent.com/janhan42/SFML-installer/master/installer.sh)"
mkdir .OBJ
make
./PlanetGravity
