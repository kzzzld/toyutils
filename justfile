default:
    @just --list

build:
    mkdir -p out
    gcc -o out/cp src/cp.c