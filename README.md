# Nohup утилита

## Описание

Утилита запускающая другую программу и отвязывающая ее от управляющего терминала (аналог nohup).
Для простоты эксперимента утилите передается путь до исполняемого файла, например `/usr/bin/top`

### Как запускать

```
g++ -std=c++17 -o nohup main.cpp && ./nohup <path_to_executable_bin>
```