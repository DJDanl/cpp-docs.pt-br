---
title: Instrução for com base em intervalo (C++)
ms.date: 11/04/2016
ms.assetid: 5750ba1d-ba48-4236-a923-e32de8345c2d
ms.openlocfilehash: 504f177cf68b978642f15ba4799cab8cb517f447
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80188344"
---
# <a name="range-based-for-statement-c"></a>Instrução for com base em intervalo (C++)

Executa `statement` repetidamente e em sequência para cada elemento em `expression`.

## <a name="syntax"></a>Sintaxe

```
for ( for-range-declaration : expression )
   statement
```

## <a name="remarks"></a>Comentários

Use a instrução **for** baseada em intervalo para construir loops que devem ser executados por meio de um "intervalo", que é definido como qualquer coisa que você possa iterar, por exemplo, `std::vector`C++ ou qualquer outra sequência de biblioteca padrão cujo intervalo seja definido por um `begin()` e `end()`. O nome declarado na parte `for-range-declaration` é local para a instrução **for** e não pode ser declarado novamente em `expression` ou `statement`. Observe que a palavra-chave [auto](../cpp/auto-cpp.md) é preferida na parte `for-range-declaration` da instrução.

**Novidade no Visual Studio 2017:**  Loops for com base em intervalos não exigem mais que os objetos de retorno Begin () e End () do mesmo tipo. Isso permite que end() retorne um objeto sentinela como usado por intervalos, conforme definido na proposta Ranges-V3. Para obter mais informações, consulte [Generalizing the Range-Based For Loop (Generalizando o loop “for” baseado em intervalo)](https://wg21.link/p0184r0) e [range-v3 library on GitHub (Biblioteca range-v3 no GitHub)](https://github.com/ericniebler/range-v3).

Este código mostra como usar loops **for** baseados em intervalo para iterar por meio de uma matriz e um vetor:

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

Um loop **for** baseado em intervalo termina quando um desses em `statement` é executado: um [Break](../cpp/break-statement-cpp.md), [Return](../cpp/return-statement-cpp.md)ou [goto](../cpp/goto-statement-cpp.md) para uma instrução rotulada fora do loop **for** baseado em intervalo. Uma instrução [continue](../cpp/continue-statement-cpp.md) em um loop **for** com base em intervalo encerra apenas a iteração atual.

Tenha em mente estes fatos sobre o baseado em intervalo **para**:

- Reconhece matrizes automaticamente.

- Reconhece os contêineres que têm `.begin()` e `.end()`.

- Usa a pesquisa dependente de argumentos `begin()` e `end()` para qualquer outra coisa.

## <a name="see-also"></a>Confira também

[auto](../cpp/auto-cpp.md)<br/>
[Instruções de iteração](../cpp/iteration-statements-cpp.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[Instrução while (C++)](../cpp/while-statement-cpp.md)<br/>
[Instrução do-while (C++)](../cpp/do-while-statement-cpp.md)<br/>
[Instrução for (C++)](../cpp/for-statement-cpp.md)
