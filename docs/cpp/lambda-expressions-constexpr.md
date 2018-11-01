---
title: expressões lambda constexpr em C++
ms.date: 07/19/2017
helpviewer_keywords:
- lambda expressions [C++], constexpr
ms.assetid: b56346cd-fbff-475f-aeaa-ed2010c6d6f7
ms.openlocfilehash: 937fae7da0f20e81ac5450d597af7a822219d654
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50506588"
---
# <a name="constexpr-lambda-expressions-in-c"></a>expressões lambda constexpr em C++

**Visual Studio 2017 versão 15.3 e posterior** (disponível com [/std: c + + 17](../build/reference/std-specify-language-standard-version.md)): uma expressão lambda pode ser declarada como **constexpr** ou usado em uma expressão da constante quando a inicialização de cada membro de dados que ele captura ou apresenta é permitido dentro de uma expressão constante.

```cpp
    int y = 32;
    auto answer = [y]() constexpr
    {
        int x = 10;
        return y + x;
    };

    constexpr int Increment(int n)
    {
        return [n] { return n + 1; }();
    }
```

Um lambda é implicitamente **constexpr** se o seu resultado satisfaz os requisitos de um **constexpr** função:

```cpp
    auto answer = [](int n)
    {
        return 32 + n;
    };

    constexpr int response = answer(10);
```

Se uma lambda é implicitamente ou explicitamente **constexpr**e convertê-lo para um ponteiro de função, a função resultante é também **constexpr**:

```cpp
    auto Increment = [](int n)
    {
        return n + 1;
    };

    constexpr int(*inc)(int) = Increment;
```

## <a name="see-also"></a>Consulte também

[Referência da linguagem C++](../cpp/cpp-language-reference.md)<br/>
[Objetos de função na Biblioteca Padrão C++](../standard-library/function-objects-in-the-stl.md)<br/>
[Chamada de função](../cpp/function-call-cpp.md)<br/>
[for_each](../standard-library/algorithm-functions.md#for_each)