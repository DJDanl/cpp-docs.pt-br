---
title: Uniforme de inicialização e delegação de construtores | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
ms.assetid: aa4daa64-eaec-4a3c-ade4-d9325e31e9d4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 80beb5e840e182396f519b6b827dd8d727252d61
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46116237"
---
# <a name="uniform-initialization-and-delegating-constructors"></a>Inicialização uniforme e delegação de construtores

No C++ moderno, você pode usar *chave de inicialização* para qualquer tipo, sem o sinal de igual. Além disso, você pode usar construtores de delegação para simplificar o seu código quando você tem vários construtores que executam um trabalho semelhante.

## <a name="brace-initialization"></a>Inicialização da chave

Você pode usar a inicialização da chave para qualquer classe, struct ou união. Se um tipo tem um construtor padrão, implícita ou explicitamente declarado, você pode usar a inicialização da chave padrão (com chaves vazias). Por exemplo, a classe a seguir pode ser inicializada usando o padrão e a inicialização da chave não padrão:

```cpp
#include <string>
using namespace std;

class class_a {
public:
    class_a() {}
    class_a(string str) : m_string{ str } {}
    class_a(string str, double dbl) : m_string{ str }, m_double{ dbl } {}
double m_double;
string m_string;
};

int main()
{
    class_a c1{};
    class_a c1_1;

    class_a c2{ "ww" };
    class_a c2_1("xx");

    // order of parameters is the same as the constructor
    class_a c3{ "yy", 4.4 };
    class_a c3_1("zz", 5.5);
}
```

Se uma classe tiver construtores não padrão, a ordem na qual classe membros aparecem no inicializador de chave é a ordem na qual os parâmetros correspondentes são exibidos no construtor, não a ordem na qual os membros são declarados (assim como acontece com `class_a` no exemplo anterior). Caso contrário, se o tipo não tem nenhum construtor declarado, a ordem na qual os membros são exibidos no inicializador de chave é o mesmo que a ordem na qual eles são declarados; Nesse caso, você pode inicializar o máximo de membros públicos como desejar, mas não é possível ignorar qualquer membro. O exemplo a seguir mostra a ordem em que é usada na inicialização da chave quando não há nenhum construtor declarado:

```cpp
class class_d {
public:
    float m_float;
    string m_string;
    wchar_t m_char;
};

int main()
{
    class_d d1{};
    class_d d1{ 4.5 };
    class_d d2{ 4.5, "string" };
    class_d d3{ 4.5, "string", 'c' };

    class_d d4{ "string", 'c' }; // compiler error
    class_d d5("string", 'c', 2.0 }; // compiler error
}
```

Se o construtor padrão é explicitamente declarado, mas marcado como excluído, a inicialização da chave padrão não pode ser usada:

```cpp
class class_f {
public:
    class_f() = delete;
    class_f(string x): m_string { x } {}
    string m_string;
};
int main()
{
    class_f cf{ "hello" };
    class_f cf1{}; // compiler error C2280: attempting to reference a deleted function
}
```

Você pode usar a inicialização da chave em qualquer lugar que normalmente faria inicialização — por exemplo, como um parâmetro de função ou um valor de retorno, ou com o **novo** palavra-chave:

```cpp
class_d* cf = new class_d{4.5};
kr->add_d({ 4.5 });
return { 4.5 };
```

## <a name="initializerlist-constructors"></a>initializer_list construtores

O [classe initializer_list](../standard-library/initializer-list-class.md) representa uma lista de objetos de um tipo especificado que pode ser usado em um construtor e em outros contextos. Você pode construir um initializer_list, usando a inicialização da chave:

```cpp
initializer_list<int> int_list{5, 6, 7};
```

> [!IMPORTANT]
>  Para usar essa classe, você deve incluir a [ \<initializer_list >](../standard-library/initializer-list.md) cabeçalho.

Um `initializer_list` podem ser copiados. Nesse caso, os membros da nova lista são referências para os membros da lista original:

```cpp
initializer_list<int> ilist1{ 5, 6, 7 };
initializer_list<int> ilist2( ilist1 );
if (ilist1.begin() == ilist2.begin())
    cout << "yes" << endl; // expect "yes"
```

As classes de contêiner da biblioteca padrão e também `string`, `wstring`, e `regex`, têm `initializer_list` construtores. Os exemplos a seguir mostram como chave de inicialização com esses construtores:

```cpp
vector<int> v1{ 9, 10, 11 };
map<int, string> m1{ {1, "a"}, {2, "b"} };
string s{ 'a', 'b', 'c' };
regex rgx{'x', 'y', 'z'};
```

## <a name="delegating-constructors"></a>Construtores de delegação

Muitas classes de tem vários construtores que fazem coisas semelhantes — por exemplo, validar parâmetros:

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

Você pode reduzir o código repetitivo, adicionando uma função que faz a validação, mas o código para `class_c` seria mais fácil de entender e manter se um construtor pode delegar a parte do trabalho para outro. Para adicionar os construtores de delegação, use o `constructor (. . .) : constructor (. . .)` sintaxe:

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

Conforme você percorre o exemplo anterior, observe que o construtor `class_c(int, int, int)` primeiro chama o construtor `class_c(int, int)`, que por sua vez chama `class_c(int)`. Cada um dos construtores executa apenas o trabalho que não é executado pelos outros construtores.

O primeiro construtor é chamado inicializa o objeto, de modo que todos os seus membros são inicializados nesse ponto. Você não pode fazer a inicialização de membro em um construtor que delega para outro construtor, conforme mostrado aqui:

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

O exemplo a seguir mostra o uso de inicializadores de membro de dados não estáticos. Observe que, se um construtor também inicializa um determinado membro de dados, o inicializador de membro é substituído:

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

A sintaxe de delegação do construtor não impede a criação acidental de recursão de construtor — Constructor1 chama Constructor2 que chama Constructor1 — e nenhum erro é gerado até que haja um estouro de pilha. É sua responsabilidade para evitar ciclos.

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