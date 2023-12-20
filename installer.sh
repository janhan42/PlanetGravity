#!bin/bash

git clone https://github.com/janhan42/PlanetGravity.git
make -C PlanetGravity bash -c "$(curl -fsSL https://raw.githubusercontent.com/janhan42/SFML-installer/master/installer.sh)"
make -C PlanetGravity all

make -C ./PlanetGravity
