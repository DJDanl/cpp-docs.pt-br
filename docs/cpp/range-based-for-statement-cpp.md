---
title: Instrução for com base em intervalo (C++)
ms.date: 11/04/2016
ms.assetid: 5750ba1d-ba48-4236-a923-e32de8345c2d
ms.openlocfilehash: 1cbdb4e1636f471c26f6742b9e8686a332ed845f
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62244125"
---
# <a name="range-based-for-statement-c"></a>Instrução for com base em intervalo (C++)

Executa `statement` repetidamente e em sequência para cada elemento em `expression`.

## <a name="syntax"></a>Sintaxe

```
for ( for-range-declaration : expression )
   statement
```

## <a name="remarks"></a>Comentários

Usar baseado em intervalo **para** instrução para construir loops que devem ser executados por meio de um "intervalo", que é definido como qualquer coisa que você pode iterar por meio de — por exemplo, `std::vector`, ou qualquer outra biblioteca de padrão de C++ cujo intervalo de sequência é definido por uma `begin()` e `end()`. O nome que é declarado na `for-range-declaration` parte é local para o **para** instrução e não pode ser declarado novamente em `expression` ou `statement`. Observe que o [automática](../cpp/auto-cpp.md) palavra-chave é preferido no `for-range-declaration` parte da instrução.

**Novo no Visual Studio 2017:**  Baseada em intervalo para loops que não exigem mais que begin() e end() retornem objetos do mesmo tipo. Isso permite que end() retorne um objeto sentinela como usado por intervalos, conforme definido na proposta Ranges-V3. Para obter mais informações, consulte [Generalizing the Range-Based For Loop (Generalizando o loop “for” baseado em intervalo)](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0184r0.html) e [range-v3 library on GitHub (Biblioteca range-v3 no GitHub)](https://github.com/ericniebler/range-v3).

Este código mostra como usar baseado em intervalo **para** loops para iterar por meio de uma matriz e um vetor:

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

Este é o resultado:

```Output
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9 10
end of integer array test

0.14159 1.14159 2.14159 3.14159 4.14159 5.14159 6.14159 7.14159 8.14159 9.14159
end of vector test
```

Um baseado em intervalo **para** loop termina quando uma destas opções na `statement` é executado: um [quebra](../cpp/break-statement-cpp.md), [retornar](../cpp/return-statement-cpp.md), ou [goto](../cpp/goto-statement-cpp.md) para um rotulado instrução fora baseado em intervalo **para** loop. Um [continue](../cpp/continue-statement-cpp.md) instrução em um intervalo baseado **para** loop termina apenas a iteração atual.

Lembre-se destes fatos sobre baseado em intervalo **para**:

- Reconhece matrizes automaticamente.

- Reconhece os contêineres que têm `.begin()` e `.end()`.

- Usa a pesquisa dependente de argumentos `begin()` e `end()` para qualquer outra coisa.

## <a name="see-also"></a>Consulte também

[auto](../cpp/auto-cpp.md)<br/>
[Instruções de iteração](../cpp/iteration-statements-cpp.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[Instrução while (C++)](../cpp/while-statement-cpp.md)<br/>
[Instrução do-while (C++)](../cpp/do-while-statement-cpp.md)<br/>
[Instrução for (C++)](../cpp/for-statement-cpp.md)