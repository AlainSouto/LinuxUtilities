# Réplicas de Comandos de Linux en C (`my_cat`, `my_cp`, `my_grep`)

Este repositorio contiene una colección de utilidades de línea de comandos en **C** creadas desde cero para simular el comportamiento de las herramientas estándar de Linux `cat`, `cp` y `grep`. 

El objetivo de este proyecto es profundizar en la programación de sistemas en C, la gestión de ficheros, la manipulación de buffers de memoria, la inspección de metadatos del sistema con `stat()` y el uso de llamadas a la biblioteca estándar POSIX/Linux.

---

##  Herramientas e Implementación

### 1. `my_cat` (`my_cat/my_cat.c`)
Reimplanta el funcionamiento de `cat`. 
* **Características:** Lee y muestra el contenido de uno o varios ficheros en la salida estándar (`stdout`). Si no se le proporciona ningún archivo de entrada, lee dinámicamente desde la entrada estándar (`stdin`).

### 2. `my_cp` (`my_cp/my_cp.c`)
Reimplanta la funcionalidad de copia de ficheros y directorios de `cp`.
* **Características:** Copia el contenido de un archivo origen a un archivo destino utilizando un buffer dinámico. Emplea la estructura `stat` para detectar si el destino es un directorio existente y concatenar automáticamente el nombre del archivo.

### 3. `my_grep` (`my_grep/my_grep.c`)
Reimplanta la búsqueda de patrones de `grep`.
* **Características:** Busca la aparición de una cadena/patrón dentro de uno o múltiples ficheros e imprime las líneas correspondientes indicando el número de línea exacto donde ocurre la coincidencia.

---

##  Compilación y Uso

### Requisitos
* Compilador **GCC** en un entorno tipo Linux o POSIX.

---

###  `my_cat`

#### Compilación:
```bash
gcc -o my_cat my_cat/my_cat.c -Wall
```

#### Uso:
* **Leer uno o varios archivos:**
  ```bash
  ./my_cat archivo1.txt archivo2.txt
  ```
* **Leer desde la entrada estándar (`stdin`):**
  ```bash
  ./my_cat
  ```

---

### `my_cp`

#### Compilación:
```bash
gcc -o my_cp my_cp/my_cp.c -Wall
```

#### Uso:
* **Copiar a un nuevo archivo:**
  ```bash
  ./my_cp origen.txt destino.txt
  ```
* **Copiar a un directorio existente:**
  ```bash
  ./my_cp origen.txt ruta/del/directorio/
  ```

---

### `my_grep`

#### Compilación:
```bash
gcc -o my_grep my_grep/my_grep.c -Wall
```

#### Uso:
* **Buscar un patrón en uno o más ficheros:**
  ```bash
  ./my_grep "cadena_a_buscar" archivo1.txt archivo2.txt
  ```

---

## Autores

Proyecto desarrollado por:
* Suhar Aristegui
* Iker Vicente
* Alain Souto