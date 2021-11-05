# TRABAJO PRÁCTICO ESPECIAL ARQUITECTURA DE COMPUTADORAS - 2C 2021

## INTEGRANTES

* Camila Sierra Perez, 60242
* Malena Vasquez Currie, 60072
* Magdalena Flores Levalle, 60077

## MANUAL DE USO

### Requerimientos previos a arrancar
* Contar con una terminal para poder ejecutar el programa
* Asegurarse de que que el archivo. 60242-60072-60077.zip se encuentre descargado y descomprimido en su computadora.
* Disponer de los programas docker y qemu.

### Compilación
i. Ubicándose en el directorio de trabajo, ejecutar el siguiente comando en la terminal: `docker pull agodio/itba-so:1.0`.
ii. Luego correr el comando `docker run -v ${PWD}:/root --security-opt seccomp:unconfined -ti agodio/itba-so:1.0` para ingresar al docker.
iii. Una vez dentro de docker, correr el comando `cd root/Toolchain` para dirigirse al directorio Toolchain y ejecutar el comando `make clean all`.
iv. Salir del directorio Toolchain con el comando `cd ..` y ejecutando nuevamente el comando `make clean all`.
v. Si se desea salir del docker, correr el comando `exit`.

### Ejecución
Una vez compilado el programa y ubicándose en el directorio de trabajo, correr el comando `./run.sh` si se encuentra en Linux o `./run.bat` en caso de encontrarse en Windows. Al hacer esto, (...) 

### Funcionalidades

**A tener en cuenta**
