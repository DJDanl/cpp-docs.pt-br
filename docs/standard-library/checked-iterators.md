---
title: Iteradores verificados
ms.date: 11/04/2016
f1_keywords:
- _SECURE_SCL_THROWS
helpviewer_keywords:
- Safe Libraries
- Safe Libraries, C++ Standard Library
- Safe C++ Standard Library
- iterators, checked
- checked iterators
ms.assetid: cfc87df8-e3d9-403b-ab78-e9483247d940
ms.openlocfilehash: f5a31843386d2246f5d74eae1f40b93f0ae35c90
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68452134"
---
# <a name="checked-iterators"></a>Iteradores verificados

Os iteradores verificados garantem que os limites de seu contêiner não serão substituídos. Os iteradores verificados aplicam-se a compilações de liberação e compilações de depuração. Para obter mais informações sobre como usar a iteradores de depuração ao compilar no modo de depuração, consulte [Suporte a iterador de depuração](../standard-library/debug-iterator-support.md).

## <a name="remarks"></a>Comentários

Para obter informações sobre como desabilitar avisos gerados pelos iteradores verificados, consulte [_SCL_SECURE_NO_WARNINGS](../standard-library/scl-secure-no-warnings.md).

Você pode usar a macro do pré-processador [\_ITERATOR\_DEBUG\_LEVEL](../standard-library/iterator-debug-level.md) para habilitar ou desabilitar o recurso de iteradores verificados. Se _ITERATOR_DEBUG_LEVEL for definido como 1 ou 2, o uso não seguro de iteradores causará um erro de tempo de execução e o programa será encerrado. Se definido como 0, os iteradores verificados serão desabilitados. Por padrão, o valor de _ITERATOR_DEBUG_LEVEL é 0 para Builds de versão e 2 para compilações de depuração.

> [!IMPORTANT]
> Código-fonte e documentação mais antigos podem se referir à macro [_SECURE_SCL](../standard-library/secure-scl.md). Use _ITERATOR_DEBUG_LEVEL para controlar o _SECURE_SCL. Para obter mais informações, consulte [_ITERATOR_DEBUG_LEVEL](../standard-library/iterator-debug-level.md).

Quando _ITERATOR_DEBUG_LEVEL é definido como 1 ou 2, essas verificações de iterador são executadas:

- Todos os iteradores padrão (por exemplo, [vector::iterator](../standard-library/vector-class.md#iterator)) serão verificados.

- Se um iterador de saída for um iterador verificado, chamadas para funções de biblioteca padrão como [std::copy](../standard-library/algorithm-functions.md#copy) terão comportamento verificado.

- Se um iterador de saída for um iterador não verificado, chamadas para funções de biblioteca padrão causarão avisos do compilador.

- As seguintes funções gerarão um erro de tempo de execução se houver um acesso fora dos limites do contêiner:

|||||
|-|-|-|-|
|[basic_string::operator\[\]](../standard-library/basic-string-class.md#op_at)|[bitset::operator\[\]](../standard-library/bitset-class.md#op_at)|[back](../standard-library/deque-class.md#back)|[front](../standard-library/deque-class.md#front)|
|[deque::operator\[\]](../standard-library/deque-class.md#op_at)|[back](../standard-library/list-class.md#back)|[front](../standard-library/list-class.md#front)|[back](../standard-library/queue-class.md#back)|
|[front](../standard-library/queue-class.md#front)|[vector::operator\[\]](../standard-library/vector-class.md#op_at)|[back](../standard-library/vector-class.md#back)|[front](../standard-library/vector-class.md#front)|

Quando _ITERATOR_DEBUG_LEVEL é definido como 0:

- Todos os iteradores padrão são não verificados. Os iteradores podem ir além dos limites do contêiner, o que leva a um comportamento indefinido.

- Se um iterador de saída for um iterador verificado, chamadas para funções de biblioteca padrão como `std::copy` terão comportamento verificado.

- Se um iterador de saída for um iterador não verificado, chamadas para funções de biblioteca padrão terão comportamento não verificado.

Um iterador verificado refere-se a um iterador que chamará `invalid_parameter_handler` se você tentar passar dos limites do contêiner. Para obter mais informações sobre `invalid_parameter_handler`, consulte [Validação do parâmetro](../c-runtime-library/parameter-validation.md).

Os adaptadores de iterador que dão suporte a iteradores são [Classe checked_array_iterator](../standard-library/checked-array-iterator-class.md) e [Classe unchecked_array_iterator](../standard-library/unchecked-array-iterator-class.md).

## <a name="example"></a>Exemplo

Quando você compilar usando _ITERATOR_DEBUG_LEVEL definido como 1 ou 2, um erro de tempo de execução ocorrerá se você tentar acessar um elemento que está fora dos limites do contêiner usando o operador de indexação de determinadas classes.

```cpp
// checked_iterators_1.cpp
// cl.exe /Zi /MDd /EHsc /W4

#define _ITERATOR_DEBUG_LEVEL 1

#include <vector>
#include <iostream>

using namespace std;

int main()
{
   vector<int> v;
   v.push_back(67);

   int i = v[0];
   cout << i << endl;

   i = v[1]; //triggers invalid parameter handler
}
```

Esse programa imprime “67” e então abre em pop-up uma caixa de diálogo de falha de asserção com informações adicionais sobre a falha.

## <a name="example"></a>Exemplo

Da mesma forma, quando você compila usando _ITERATOR_DEBUG_LEVEL definido como 1 ou 2, ocorrerá um erro de tempo de execução se você tentar acessar um `front` elemento `back` usando ou em classes de contêiner quando o contêiner estiver vazio.

```cpp
// checked_iterators_2.cpp
// cl.exe /Zi /MDd /EHsc /W4
#define _ITERATOR_DEBUG_LEVEL 1

#include <vector>
#include <iostream>

using namespace std;

int main()
{
   vector<int> v;

   int& i = v.front(); // triggers invalid parameter handler
}
```

Esse programa abrirá em pop-up uma caixa de diálogo de falha de asserção com informações adicionais sobre a falha.

## <a name="example"></a>Exemplo

O código a seguir demonstra vários cenários de caso de uso de iterador com comentários sobre cada um. Por padrão, _ITERATOR_DEBUG_LEVEL é definido como 2 em builds de depuração e como 0 em compilações de varejo.

```cpp
// checked_iterators_3.cpp
// cl.exe /MTd /EHsc /W4

#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

template <typename C>
void print(const string& s, const C& c)
{
    cout << s;

    for (const auto& e : c) {
        cout << e << " ";
    }

    cout << endl;
}

int main()
{
    vector<int> v(16);
    iota(v.begin(), v.end(), 0);
    print("v: ", v);

    // OK: vector::iterator is checked in debug mode
    // (i.e. an overrun causes a debug assertion)
    vector<int> v2(16);
    transform(v.begin(), v.end(), v2.begin(), [](int n) { return n * 2; });
    print("v2: ", v2);

    // OK: back_insert_iterator is marked as checked in debug mode
    // (i.e. an overrun is impossible)
    vector<int> v3;
    transform(v.begin(), v.end(), back_inserter(v3), [](int n) { return n * 3; });
    print("v3: ", v3);

    // OK: array::iterator is checked in debug mode
    // (i.e. an overrun causes a debug assertion)
    array<int, 16> a4;
    transform(v.begin(), v.end(), a4.begin(), [](int n) { return n * 4; });
    print("a4: ", a4);

    // OK: Raw arrays are checked in debug mode
    // (an overrun causes a debug assertion)
    // NOTE: This applies only when raw arrays are given to C++ Standard Library algorithms!
    int a5[16];
    transform(v.begin(), v.end(), a5, [](int n) { return n * 5; });
    print("a5: ", a5);

    // WARNING C4996: Pointers cannot be checked in debug mode
    // (an overrun causes undefined behavior)
    int a6[16];
    int * p6 = a6;
    transform(v.begin(), v.end(), p6, [](int n) { return n * 6; });
    print("a6: ", a6);

    // OK: stdext::checked_array_iterator is checked in debug mode
    // (an overrun causes a debug assertion)
    int a7[16];
    int * p7 = a7;
    transform(v.begin(), v.end(), stdext::make_checked_array_iterator(p7, 16), [](int n) { return n * 7; });
    print("a7: ", a7);

    // WARNING SILENCED: stdext::unchecked_array_iterator is marked as checked in debug mode
    // (it performs no checking, so an overrun causes undefined behavior)
    int a8[16];
    int * p8 = a8;
    transform(v.begin(), v.end(), stdext::make_unchecked_array_iterator(p8), [](int n) { return n * 8; });
    print("a8: ", a8);
}
```

Quando você compila esse código usando `cl.exe /EHsc /W4 /MTd checked_iterators_3.cpp`, o compilador emite um aviso, mas compila sem erro em um executável:

```Output
algorithm(1026) : warning C4996: 'std::_Transform1': Function call with parameters
that may be unsafe - this call relies on the caller to check that the passed values
are correct. To disable this warning, use -D_SCL_SECURE_NO_WARNINGS. See documentation
on how to use Visual C++ 'Checked Iterators'
```

Quando executado na linha de comando, o executável gera esta saída:

```Output
v: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
v2: 0 2 4 6 8 10 12 14 16 18 20 22 24 26 28 30
v3: 0 3 6 9 12 15 18 21 24 27 30 33 36 39 42 45
a4: 0 4 8 12 16 20 24 28 32 36 40 44 48 52 56 60
a5: 0 5 10 15 20 25 30 35 40 45 50 55 60 65 70 75
a6: 0 6 12 18 24 30 36 42 48 54 60 66 72 78 84 90
a7: 0 7 14 21 28 35 42 49 56 63 70 77 84 91 98 105
a8: 0 8 16 24 32 40 48 56 64 72 80 88 96 104 112 120
```

## <a name="see-also"></a>Consulte também

[Visão geral da biblioteca padrão C++](../standard-library/cpp-standard-library-overview.md)\
[Suporte ao iterador de depuração](../standard-library/debug-iterator-support.md)
