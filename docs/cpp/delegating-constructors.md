---
title: Delegando construtores (C++)
description: Use os construtores de delegação no C++ para invocar outros construtores e reduzir a repetição de código.
ms.date: 11/19/2019
ms.openlocfilehash: 533cdfbeb882f3770cc554b0633611a4ffc2cfbd
ms.sourcegitcommit: 654aecaeb5d3e3fe6bc926bafd6d5ace0d20a80e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/20/2019
ms.locfileid: "74250670"
---
# <a name="delegating-constructors"></a>Delegação de construtores

Muitas classes têm vários construtores que fazem coisas semelhantes, por exemplo, validar parâmetros:

```cpp
class class_c {
public:
    int max;
    int min;
    int middle;

    class_c() {}
    class_c(int my_max) {
        max = my_max > 0 ? my_max : 10;
    }
    class_c(int my_max, int my_min) {
        max = my_max > 0 ? my_max : 10;
        min = my_min > 0 && my_min < max ? my_min : 1;
    }
    class_c(int my_max, int my_min, int my_middle) {
        max = my_max > 0 ? my_max : 10;
        min = my_min > 0 && my_min < max ? my_min : 1;
        middle = my_middle < max && my_middle > min ? my_middle : 5;
    }
};
```

Você pode reduzir o código repetitivo adicionando uma função que faz toda a validação, mas o código para `class_c` seria mais fácil de entender e manter se um Construtor pudesse delegar um pouco do trabalho para outro. Para adicionar construtores de delegação, use a sintaxe `constructor (. . .) : constructor (. . .)`:

```cpp
class class_c {
public:
    int max;
    int min;
    int middle;

    class_c(int my_max) {
        max = my_max > 0 ? my_max : 10;
    }
    class_c(int my_max, int my_min) : class_c(my_max) {
        min = my_min > 0 && my_min < max ? my_min : 1;
    }
    class_c(int my_max, int my_min, int my_middle) : class_c (my_max, my_min){
        middle = my_middle < max && my_middle > min ? my_middle : 5;
}
};
int main() {

    class_c c1{ 1, 3, 2 };
}
```

Conforme você percorre o exemplo anterior, observe que o Construtor `class_c(int, int, int)` primeiro chama o Construtor `class_c(int, int)`, que por sua vez chama `class_c(int)`. Cada um dos construtores executa apenas o trabalho que não é executado por outros construtores.

O primeiro construtor chamado Inicializa o objeto para que todos os seus membros sejam inicializados nesse ponto. Você não pode fazer a inicialização de membro em um construtor que delega para outro construtor, como mostrado aqui:

```cpp
class class_a {
public:
    class_a() {}
    // member initialization here, no delegate
    class_a(string str) : m_string{ str } {}

    //can’t do member initialization here
    // error C3511: a call to a delegating constructor shall be the only member-initializer
    class_a(string str, double dbl) : class_a(str) , m_double{ dbl } {}

    // only member assignment
    class_a(string str, double dbl) : class_a(str) { m_double = dbl; }
    double m_double{ 1.0 };
    string m_string;
};
```

O exemplo a seguir mostra o uso de inicializadores de membro de dados não estáticos. Observe que, se um construtor também inicializar um determinado membro de dados, o inicializador do membro será substituído:

```cpp
class class_a {
public:
    class_a() {}
    class_a(string str) : m_string{ str } {}
    class_a(string str, double dbl) : class_a(str) { m_double = dbl; }
    double m_double{ 1.0 };
    string m_string{ m_double < 10.0 ? "alpha" : "beta" };
};

int main() {
    class_a a{ "hello", 2.0 };  //expect a.m_double == 2.0, a.m_string == "hello"
    int y = 4;
}
```

A sintaxe de delegação de construtor não impede a criação acidental de recursão de Construtor — Constructor1 chama Constructor2 que chama Constructor1 – e nenhum erro é lançado até que haja um estouro de pilha. É sua responsabilidade evitar ciclos.

```cpp
class class_f{
public:
    int max;
    int min;

    // don't do this
    class_f() : class_f(6, 3){ }
    class_f(int my_max, int my_min) : class_f() { }
};
```
