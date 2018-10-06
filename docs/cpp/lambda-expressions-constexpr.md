---
title: as expressões lambda constexpr em C++ | Microsoft Docs
ms.custom: ''
ms.date: 07/19/2017
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- lambda expressions [C++], constexpr
ms.assetid: b56346cd-fbff-475f-aeaa-ed2010c6d6f7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 71c28ab1531c2af19f2b8f594db457d0272b0664
ms.sourcegitcommit: a738519aa491a493a8f213971354356c0e6a5f3a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/05/2018
ms.locfileid: "48820354"
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