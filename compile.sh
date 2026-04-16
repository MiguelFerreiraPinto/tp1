#!/bin/bash

# Script de teste: limpa e recompila o projeto

echo "==================================="
echo "Limpando arquivos compilados..."
echo "==================================="
make clean

echo ""
echo "==================================="
echo "Compilando projeto..."
echo "==================================="
make all

echo ""
echo "==================================="
if [ -f bin/tp2.out ]; then
    echo "✓ Compilação realizada com sucesso!"
    echo "Executável: bin/tp2.out"
else
    echo "✗ Erro na compilação!"
    exit 1
fi
echo "==================================="
