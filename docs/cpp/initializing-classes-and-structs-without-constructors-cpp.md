---
title: Inicialização de chaves para classes, structs e uniões
description: Usar a inicialização de chave C++ com qualquer classe, struct ou União
ms.date: 11/19/2019
ms.assetid: 3e55c3d6-1c6b-4084-b9e5-221b151402f4
ms.openlocfilehash: a2c9db4572b0dde94c42ec6768a0f3bed7766a96
ms.sourcegitcommit: 15677b0e4d2518847ce59b158990b25c4077e565
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/03/2020
ms.locfileid: "75652618"
---
# <a name="brace-initialization"></a>Inicialização de chaves

Nem sempre é necessário definir um construtor para uma classe, especialmente aqueles que são relativamente simples. Os usuários podem inicializar objetos de uma classe ou estrutura usando a inicialização uniforme, conforme mostrado no exemplo a seguir:

```cpp
// no_constructor.cpp
// Compile with: cl /EHsc no_constructor.cpp
#include <time.h>

// No constructor
struct TempData
{
    int StationId;
    time_t timeSet;
    double current;
    double maxTemp;
    double minTemp;
};

// Has a constructor
struct TempData2
{
    TempData2(double minimum, double maximum, double cur, int id, time_t t) :
       stationId{id}, timeSet{t}, current{cur}, maxTemp{maximum}, minTemp{minimum} {}
    int stationId;
    time_t timeSet;
    double current;
    double maxTemp;
    double minTemp;
};

int main()
{
    time_t time_to_set;

    // Member initialization (in order of declaration):
    TempData td{ 45978, time(&time_to_set), 28.9, 37.0, 16.7 };

    // Default initialization = {0,0,0,0,0}
    TempData td_default{};

    // Uninitialized = if used, emits warning C4700 uninitialized local variable
    TempData td_noInit;

    // Member declaration (in order of ctor parameters)
    TempData2 td2{ 16.7, 37.0, 28.9, 45978, time(&time_to_set) };

    return 0;
}
```

Observe que, quando uma classe ou struct não tem nenhum construtor, você fornece os elementos da lista na ordem em que os membros são declarados na classe. Se a classe tiver um construtor, forneça os elementos na ordem dos parâmetros. Se um tipo tiver um construtor padrão, implicitamente ou explicitamente declarado, você poderá usar a inicialização de chave padrão (com chaves vazias). Por exemplo, a seguinte classe pode ser inicializada usando a inicialização de chave padrão e não padrão:

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

Se uma classe tiver construtores não padrão, a ordem na qual os membros da classe aparecem no inicializador de chave é a ordem na qual os parâmetros correspondentes aparecem no construtor, não a ordem na qual os membros são declarados (como com `class_a` no exemplo anterior). Caso contrário, se o tipo não tiver um construtor declarado, a ordem na qual os membros aparecerão no inicializador de chaves será igual à ordem na qual eles são declarados; Nesse caso, você pode inicializar quantos membros públicos desejar, mas não pode ignorar nenhum membro. O exemplo a seguir mostra a ordem usada na inicialização de chaves quando não há um construtor declarado:

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
    class_d d5{ "string", 'c', 2.0 }; // compiler error
}
```

Se o construtor padrão for declarado explicitamente, mas marcado como excluído, a inicialização de chave padrão não poderá ser usada:

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

Você pode usar a inicialização de chaves em qualquer lugar em que normalmente faria a inicialização — por exemplo, como um parâmetro de função ou um valor de retorno, ou com a **nova** palavra-chave:

```cpp
class_d* cf = new class_d{4.5};
kr->add_d({ 4.5 });
return { 4.5 };
```

No modo **/std: c++ 17** , as regras para a inicialização de chaves vazias são um pouco mais restritivas. Consulte [construtores derivados e inicialização de agregação estendida](constructors-cpp.md#extended_aggregate).

## <a name="initializer_list-constructors"></a>construtores de initializer_list

A [classe initializer_list](../standard-library/initializer-list-class.md) representa uma lista de objetos de um tipo especificado que podem ser usados em um construtor e em outros contextos. Você pode construir um initializer_list usando a inicialização de chaves:

```cpp
initializer_list<int> int_list{5, 6, 7};
```

> [!IMPORTANT]
>  Para usar essa classe, você deve incluir o [\<initializer_list cabeçalho >](../standard-library/initializer-list.md) .

Um `initializer_list` pode ser copiado. Nesse caso, os membros da nova lista são referências aos membros da lista original:

```cpp
initializer_list<int> ilist1{ 5, 6, 7 };
initializer_list<int> ilist2( ilist1 );
if (ilist1.begin() == ilist2.begin())
    cout << "yes" << endl; // expect "yes"
```

As classes de contêiner de biblioteca padrão, e também `string`, `wstring`e `regex`, têm construtores de `initializer_list`. Os exemplos a seguir mostram como fazer a inicialização de chaves com estes construtores:

```cpp
vector<int> v1{ 9, 10, 11 };
map<int, string> m1{ {1, "a"}, {2, "b"} };
string s{ 'a', 'b', 'c' };
regex rgx{ 'x', 'y', 'z' };
```


## <a name="see-also"></a>Veja também

[Classes e Structs](../cpp/classes-and-structs-cpp.md)<br/>
[Construtores](../cpp/constructors-cpp.md)
