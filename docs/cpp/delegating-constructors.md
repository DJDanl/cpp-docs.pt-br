---
title: Construtores delegantes (C++)
description: Use construtores delegantes em C++ para invocar outros construtores e reduzir a repetição de código.
ms.date: 11/19/2019
ms.openlocfilehash: f26a013aa3c081d900ffc3eb32649acc77505db0
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81316668"
---
# <a name="delegating-constructors"></a>Delegação de construtores

Muitas classes têm vários construtores que fazem coisas semelhantes — por exemplo, validam parâmetros:

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

Você poderia reduzir o código repetitivo adicionando uma função que `class_c` faz toda a validação, mas o código para seria mais fácil de entender e manter se um construtor pudesse delegar parte do trabalho para outro. Para adicionar construtores delegantes, `constructor (. . .) : constructor (. . .)` use a sintaxe:

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

Ao passar pelo exemplo anterior, observe `class_c(int, int, int)` que o construtor `class_c(int, int)`primeiro chama `class_c(int)`o construtor, que por sua vez chama . Cada um dos construtores realiza apenas o trabalho que não é realizado pelos outros construtores.

O primeiro construtor chamado inicializa o objeto para que todos os seus membros sejam inicializados nesse ponto. Você não pode fazer a inicialização de membros em uma construtora que delega para outro construtor, como mostrado aqui:

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

O próximo exemplo mostra o uso de iniciadores não estáticos de membros de dados. Observe que se um construtor também inicializar um determinado membro de dados, o inicializador do membro será substituído:

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

A sintaxe da delegação de construtores não impede a criação acidental de recursão de construtores — a Construtora1 chama de Constructor2 — e nenhum erro é lançado até que haja um estouro de pilha. É sua responsabilidade evitar ciclos.

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
