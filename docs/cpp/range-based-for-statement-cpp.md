---
title: Instrução for com base em intervalo (C++)
ms.date: 11/04/2016
ms.assetid: 5750ba1d-ba48-4236-a923-e32de8345c2d
ms.openlocfilehash: 1197080e2e96e0e5c51bc06e93026567a33c7842
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87223610"
---
# <a name="range-based-for-statement-c"></a>Instrução for com base em intervalo (C++)

Executa `statement` repetidamente e em sequência para cada elemento em `expression`.

## <a name="syntax"></a>Sintaxe

> **`for (`** declaração de intervalo *para* **`:`** *expressão* de**`)`**\
&emsp;*instrução*

## <a name="remarks"></a>Comentários

Use a instrução baseada em intervalo **`for`** para construir loops que devem ser executados por meio de um *intervalo*, que é definido como qualquer coisa na qual você possa iterar — por exemplo, `std::vector` ou qualquer outra sequência de biblioteca padrão do C++ cujo intervalo seja definido por um `begin()` e `end()` . O nome declarado na `for-range-declaration` parte é local para a **`for`** instrução e não pode ser declarado novamente em `expression` ou `statement` . Observe que a [`auto`](../cpp/auto-cpp.md) palavra-chave é preferida na `for-range-declaration` parte da instrução.

**Novidade no Visual Studio 2017:**  **`for`** Os loops baseados em intervalo não exigem mais que `begin()` e `end()` retornem objetos do mesmo tipo. Isso permite que o `end()` retorne um objeto Sentinel, como usado por intervalos, conforme definido na proposta intervalos-v3. Para obter mais informações, consulte [generalizando o `For` loop baseado em intervalo](https://wg21.link/p0184r0) e a [biblioteca Range-v3 no GitHub](https://github.com/ericniebler/range-v3).

Este código mostra como usar loops baseados em intervalo **`for`** para iterar por meio de uma matriz e um vetor:

```cpp
// range-based-for.cpp
// compile by using: cl /EHsc /nologo /W4
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Basic 10-element integer array.
    int x[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // Range-based for loop to iterate through the array.
    for( int y : x ) { // Access by value using a copy declared as a specific type.
                       // Not preferred.
        cout << y << " ";
    }
    cout << endl;

    // The auto keyword causes type inference to be used. Preferred.

    for( auto y : x ) { // Copy of 'x', almost always undesirable
        cout << y << " ";
    }
    cout << endl;

    for( auto &y : x ) { // Type inference by reference.
        // Observes and/or modifies in-place. Preferred when modify is needed.
        cout << y << " ";
    }
    cout << endl;

    for( const auto &y : x ) { // Type inference by const reference.
        // Observes in-place. Preferred when no modify is needed.
        cout << y << " ";
    }
    cout << endl;
    cout << "end of integer array test" << endl;
    cout << endl;

    // Create a vector object that contains 10 elements.
    vector<double> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i + 0.14159);
    }

    // Range-based for loop to iterate through the vector, observing in-place.
    for( const auto &j : v ) {
        cout << j << " ";
    }
    cout << endl;
    cout << "end of vector test" << endl;
}
```

Esta é a saída:

```Output
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9 10
end of integer array test

0.14159 1.14159 2.14159 3.14159 4.14159 5.14159 6.14159 7.14159 8.14159 9.14159
end of vector test
```

Um loop baseado em intervalo **`for`** termina quando um desses em `statement` é executado: a [`break`](../cpp/break-statement-cpp.md) , [`return`](../cpp/return-statement-cpp.md) ou [`goto`](../cpp/goto-statement-cpp.md) a uma instrução rotulada fora do loop baseado em intervalo **`for`** . Uma [`continue`](../cpp/continue-statement-cpp.md) instrução em um loop baseado em intervalo **`for`** encerra apenas a iteração atual.

Tenha em mente estes fatos sobre o baseado em intervalo **`for`** :

- Reconhece matrizes automaticamente.

- Reconhece os contêineres que têm `.begin()` e `.end()`.

- Usa a pesquisa dependente de argumentos `begin()` e `end()` para qualquer outra coisa.

## <a name="see-also"></a>Confira também

[`auto`](../cpp/auto-cpp.md)<br/>
[Instruções de iteração](../cpp/iteration-statements-cpp.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[`while`Instrução (C++)](../cpp/while-statement-cpp.md)<br/>
[`do-while`Instrução (C++)](../cpp/do-while-statement-cpp.md)<br/>
[`for`Instrução (C++)](../cpp/for-statement-cpp.md)
