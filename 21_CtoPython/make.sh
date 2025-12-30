gcc main.c -o main \
  $(python3-config --includes) \
  $(python3-config --embed --ldflags)

# gcc -I /usr/include/python3.8 -L /usr/lib/python3.8 main.c -o main -lpython3.8