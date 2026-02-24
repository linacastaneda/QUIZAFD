# AFD – Python y C

## 1. Descripción

Este proyecto implementa un Autómata Finito Determinístico (AFD) en Python y en C.

El programa realiza análisis léxico sobre un archivo de texto (.txt) y reconoce los siguientes tokens:

- ++  → INCR  
-  + → SUMA  
- [A-Z][a-z0-9]* → ID  

Si una línea contiene un carácter o patrón inválido, el programa imprime:

NO ACEPTA

Cada línea del archivo se analiza de manera independiente.

---

## 2. Expresiones Regulares Implementadas

1. INCR  
   ++

2. SUMA  
   +

3. ID  
   [A-Z][a-z0-9]*

---

## 3. Características del AFD

- Procesamiento carácter por carácter.
- Aplica la regla de máxima coincidencia (longest match), reconociendo ++ antes que +.
- Ignora espacios en blanco.
- Ignora líneas vacías.
- Procesa el archivo línea por línea.
- No se detiene ante el primer error; cada línea es evaluada de manera independiente.

---
## 4. Ejecución en Python

Ubicarse en la carpeta del proyecto:

cd QUIZAFD

Ejecutar:

python3 AFD.py entrada.txt

---

## 5. Ejecución en C (Linux / Fedora)

Compilar:

gcc AFD.c -o AFD

Ejecutar:

./AFD entrada.txt
