# ALG — Integer Algebra Interpreter

A lightweight interpreter for a custom integer-based expression language, written in C.

It supports arithmetic, logical, and bitwise operations, along with variables, assignments, and increment/decrement semantics — all implemented through a full compiler-style pipeline:

**Lexer → Parser → AST → Evaluator**

---

## Features

* ✅ Arithmetic: `+ - * / %`
* ✅ Bitwise: `& | ^ << >>`
* ✅ Logical: `&& || !`
* ✅ Equality: `== !=`
* ✅ Assignment:

  * Simple: `=`
  * Compound: `+= -= *= /= <<= >>=`
* ✅ Increment / Decrement:

  * Prefix: `++x`, `--x`
  * Postfix: `x++`, `x--`
* ✅ Variables with symbol table
* ✅ Interactive REPL
* ✅ File execution mode
* ✅ `show` keyword to display all variables

---

## Architecture

This project follows a classic interpreter design:

```
Input → Lexer → Tokens → Parser → AST → Evaluator → Output
```

### Components

* **Lexer**
  Converts raw input into tokens using a finite state machine

* **Parser**
  Recursive descent parser implementing operator precedence

* **AST (Abstract Syntax Tree)**
  Structured representation of expressions and statements

* **Evaluator**
  Walks the AST and computes results

* **Symbol Table**
  Stores variable bindings using a flat array

---

## 📂 Project Structure

```
.
├── lexer.c / lexer.h        # Tokenization (FSM-based)
├── parser.c / parser.h      # Recursive descent parser
├── astdefs.c                # AST node constructors & memory handling
├── eval.c / eval.h          # AST evaluation
├── symtable.c / symtable.h  # Variable storage
├── grammar.txt              # Language grammar specification
├── main.c                   # Entry point (REPL + file execution)
```

---

## ⚙️ Build Instructions

Compile using `gcc`:

```bash
gcc *.c -o alg
```

---

## ▶️ Usage

### 🔹 Interactive Mode (REPL)

```bash
./alg
```

Example:

```
>>> x = 5
>>> y = x * 2
>>> y++
10
>>> show
=== BINDINGS TILL NOW ===
x: 5
y: 11
```

---

### 🔹 Run from File

```bash
./alg program.txt
```

---

## 🧩 Language Overview

### Example expressions

```
x = 10
y = x * 2 + 3
z = y << 1
z++
```

### Grammar Highlights

* Expressions follow strict precedence rules
* Right-associative logical and bitwise chains
* No chained assignment (`a = b = 5` not supported)
* Only integer arithmetic

Full grammar available in:

* `grammar.txt` 

---

## ⚠️ Limitations

* ❌ No floating point support
* ❌ No control flow (if/while/for)
* ❌ No relational operators (`< <= > >=`)
* ❌ Fixed-size symbol table (64 variables)
* ❌ Error handling uses sentinel values (`0`)

---

## 🧠 Key Concepts Demonstrated

* Lexical analysis (FSM-based tokenizer)
* Recursive descent parsing
* Abstract Syntax Trees (AST)
* Expression evaluation via tree traversal
* Symbol table design
* Operator precedence handling
* Memory management in C

---

## 📈 Possible Improvements

* Add relational operators (`<, >, <=, >=`)
* Introduce control flow constructs
* Replace symbol table with hash table
* Add type system (floats, strings)
* Improve error handling (no sentinel values)
* Generate intermediate representation (IR)
* Add bytecode or JIT execution
