```
$ sudo apt install python3-dev
```

```
gcc -I /usr/include/python3.9 main.c
```

```
gcc -I /usr/include/python3.9 -L /usr/lib/python3.9 main.c -o main -lpython3.9
```