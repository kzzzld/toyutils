default:
    @just --list

build:
    mkdir -p out
    gcc -o out/cp src/cp/main.c
    gcc -o out/pwd src/pwd/main.c
    gcc -o out/echo src/echo/main.c
    gcc -o out/ls src/ls/main.c
    gcc -o out/yes src/yes/main.c
    gcc -o out/cat src/cat/main.c
    gcc -o out/touch src/touch/main.c
