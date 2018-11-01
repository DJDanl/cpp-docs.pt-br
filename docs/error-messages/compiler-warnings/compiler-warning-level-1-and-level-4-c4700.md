---
title: Aviso C4700 (compilador) (nível 1 e nível 4)
ms.date: 02/21/2018
f1_keywords:
- C4700
helpviewer_keywords:
- C4700
ms.assetid: 2da0deb4-77dd-4b05-98d3-b78d74ac4ca7
ms.openlocfilehash: fa3326bd5ab495dbc4c54130bb168422eb827dce
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50463213"
---
# <a name="compiler-warning-level-1-and-level-4-c4700"></a>Aviso C4700 (compilador) (nível 1 e nível 4)

> variável local não inicializada '*nome*' usado

A variável local *nome* tiver sido *usado*, ou seja, ler, antes que ele tenha sido atribuído um valor. Em C e C++, as variáveis locais não são inicializadas por padrão. As variáveis não inicializadas podem conter qualquer valor, e seu uso leva a um comportamento indefinido. Aviso C4700 quase sempre indica um bug que pode causar resultados inesperados ou falhas em seu programa.

Para corrigir esse problema, você pode inicializar variáveis locais quando eles são declarados ou atribuir um valor a eles antes de serem usadas. Uma função pode ser usada para inicializar uma variável que é passado como um parâmetro de referência, ou quando seu endereço for passado como um parâmetro de ponteiro.

## <a name="example"></a>Exemplo

Este exemplo gera C4700 quando variáveis t, u e v são usados antes que eles são inicializados e mostra o tipo de valor de lixo que pode resultar. As variáveis x, y e z não fazem com que o aviso, pois eles são inicializados antes de usar:

```cpp
// c4700.cpp
// compile by using: cl /EHsc /W4 c4700.cpp
#include <iostream>

// function takes an int reference to initialize
void initialize(int& i)
{
    i = 21;
}

int main()
{
    int s, t, u, v;   // Danger, uninitialized variables

    s = t + u + v;    // C4700: t, u, v used before initialization
    std::cout << "Value in s: " << s << std::endl;

    int w, x;         // Danger, uninitialized variables
    initialize(x);    // fix: call function to init x before use
    int y{10};        // fix: initialize y, z when declared
    int z{11};        // This C++11 syntax is recommended over int z = 11;

    w = x + y + z;    // Okay, all values initialized before use
    std::cout << "Value in w: " << w << std::endl;
}
```

Quando esse código é a execução, t, u e v é inicializados e a saída para s é imprevisível:

```Output
Value in s: 37816963
Value in w: 42
```
