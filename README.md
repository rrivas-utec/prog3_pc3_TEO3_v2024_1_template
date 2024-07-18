## Task #PC3: Simulacro Practica Calificada 3
**course:** Programación III  
**unit:** 6  
**cmake project:** prog3_pc3_TEO3_v2024_1
## Indicaciones Específicas
- El tiempo límite para la evaluación es 100 minutos.
- Cada pregunta deberá ser respondida en un archivo fuente (`.cpp`) y un archivo cabecera (`.h`) con el número de la pregunta:
    - `find_shortest_distance.h`
    - `lazy_hash_table.h`
- Deberás subir estos archivos directamente a [www.gradescope.com](https://www.gradescope.com) o se puede crear un `.zip` que contenga todos ellos y subirlo.

### Question #1 - find_shortest_distance - priority queue and unordered set (7 points)

#### **Objetivo:**
Implementa una función que determine la secuencia más corta de operaciones para transformar un valor inicial en un valor objetivo utilizando una serie de operaciones permitidas.

#### **Descripción:**
Dado un valor inicial `a` y un valor objetivo `b`, debes escribir un programa que determine la secuencia más corta de operaciones para transformar `a` en `b`. Se te proporcionará un conjunto de operaciones posibles, representadas como funciones o lambdas que se pueden aplicar al valor actual.

#### **Entrada:**
- Un valor inicial `a`.
- Un valor objetivo `b`.
- Una lista de operaciones representadas como funciones o lambdas. Cada operación debe ser una función que tome un valor y devuelva el resultado de aplicar la operación.

#### **Salida:**
El programa debe imprimir un solo número: la cantidad mínima de operaciones necesarias para transformar `a` en `b`. Si no es posible transformar `a` en `b` utilizando las operaciones dadas, imprimir `-1`.

#### **Requisitos:**
- No puedes usar funciones de búsqueda de caminos preexistentes de la biblioteca estándar.
- Debes implementar tu propia lógica para encontrar la secuencia más corta de operaciones.
- La solución debe manejar eficientemente el amplio rango de valores posibles para `a` y `b`.
- `a` y `b` pueden ser de cualquier tipo numérico (entero, flotante, doble)

**Nota:** La complejidad temporal de tu solución debe ser `O(N log N)`, donde `N` es el número de posibles estados explorados.

Declaración de la función:
```cpp
template 
  <
    typename T, 
    template<typename...> class Container = std::initializer_list, 
    typename Operation = function<T(T)>
  >
int find_shortest_distance(T a, T b, const Container<Operation>& operations);
```

**Use Case #1:**
```cpp
    int result = find_shortest_distance(2, 9,
        {
          [](int x) { return x + 1; },
          [](int x) { return x * 2; },
          [](int x) { return x - 1; }
        });
    
    // Debería imprimir 3 ( 2 * 2 * 2 + 1)
    std::cout << result << std::endl;

```

```cpp
2, 9, {[](int x) { return x + 1; }, [](int x) { return x * 2; }, [](int x) { return x - 1; }}               // 3
20, 5, {[](int x) { return x - 3; }, [](int x) { return x / 2; }}                                           // 2
1, 1024, {[](int x) { return x * 2; }}                                                                      // 10
5, 11, {[](int x) { return x + 2; }, [](int x) { return x - 1; }, [](int x) { return x * 3; }}              // 3
10, 1, {[](int x) { return x - 1; }, [](int x) { return x / 2; }}                                           // 3
```

### Question #2 - LazyHashTable Implementation (7 points)

#### **Objetivo:**
Implementa una clase de tabla hash perezosa (`LazyHashTable`) que permita insertar, buscar y reestructurar elementos de manera eficiente.

#### **Descripción:**
Se te pide implementar una tabla hash perezosa (`LazyHashTable`) que almacene elementos y permita las siguientes operaciones:

1. **Añadir un elemento (`add`)**: Inserta un elemento en la tabla hash si no está ya presente.
2. **Buscar un elemento (`find`)**: Verifica si un elemento está presente en la tabla hash.
3. **Reestructurar la tabla (`reshape`)**: Cambia el tamaño de la tabla hash y reubica los elementos. Si se produce una colisión durante la reestructuración, la operación falla.
4. **Iteradores (`begin` y `end`)**: Devuelve iteradores para recorrer la tabla hash.

#### **Requisitos:**
- La tabla hash debe utilizar un vector de pares de booleanos y elementos (`std::vector<std::pair<bool, T>>`) para almacenar los elementos.
- La función hash debe ser un functor pasado como plantilla, con un valor por defecto de `std::hash<T>`.
- La tabla hash debe manejar las colisiones de manera sencilla mediante la verificación de disponibilidad en la posición hash calculada usando el método de división: `h(k) % m`.
- La operación `reshape` debe redimensionar la tabla hash, reubicando todos los elementos. Si se produce una colisión durante esta reubicación, la operación debe fallar y la tabla debe permanecer sin cambios.

Declaración de la clase:
```cpp
template <typename T, typename Hash = std::hash<T>>
class LazyHashTable;
```

**Use Case #1:**
```cpp
    LazyHashTable<int> table(10);
    
    // Añadir elementos
    table.add(5);  // true
    table.add(15); // true (colisión si no se maneja correctamente)
    table.add(5);  // false (ya está presente)

    // Buscar elementos
    std::cout << table.find(5) << std::endl;  // true
    std::cout << table.find(10) << std::endl; // false

    // Reestructurar la tabla
    std::cout << table.reshape(20) << std::endl; // true o false dependiendo de si la reestructuración fue exitosa
```

**Use Case #2:**
```cpp
    LazyHashTable<std::string> table(5);
    
    // Añadir elementos
    table.add("apple");  // true
    table.add("banana"); // true
    table.add("cherry"); // true
    table.add("date");   // true
    table.add("fig");    // true
    table.add("grape");  // false (colisión)

    // Buscar elementos
    std::cout << table.find("banana") << std::endl; // true
    std::cout << table.find("kiwi") << std::endl;   // false

    // Reestructurar la tabla
    std::cout << table.reshape(10) << std::endl; // true o false dependiendo de si la reestructuración fue exitosa
```
