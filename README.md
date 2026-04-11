# Password Generator

A C program that generates strong passwords based on user-defined security criteria.

## Features

- Customizable character sets (uppercase, lowercase, numbers, symbols)
- Adjustable length (8–32 characters)
- Guarantees at least one character from each selected set
- Security level scoring (0/5 to 5/5)
- Interactive menu with option to generate multiple passwords

## Build & Run

```bash
gcc main.c -o main
./main
```
```

## Example

====== MENU ======
1. Gerar senha forte
2. Sair
Escolha uma opção: 1

Gerenciador de senhas fortes
Deseja incluir letras maiusculas?(s/n): s
Deseja incluir letras minusculas?(s/n): s
Deseja incluir numeros?(s/n): s
Deseja incluir simbolos?(s/n): n
Qual será o comprimento da senha?(8-32): 12

Senha gerada: aB4kL9xP2mR7
Nivel de segurança: 3/5

## Dependencies

C standard libraries only (stdio.h, stdlib.h, string.h, time.h)

## License

Educational use only