---
title: expressões lambda constexpr emC++
ms.date: 04/08/2019
helpviewer_keywords:
- lambda expressions [C++], constexpr
ms.assetid: b56346cd-fbff-475f-aeaa-ed2010c6d6f7
ms.openlocfilehash: 9467d9e404204012df6461adacd5dc4cdbdfe71d
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80179569"
---
# <a name="constexpr-lambda-expressions-in-c"></a>expressões lambda constexpr emC++

**Visual Studio 2017 versão 15,3 e posterior** (disponível com [/std: c++ 17](../build/reference/std-specify-language-standard-version.md)): uma expressão lambda pode ser declarada como **constexpr** ou usada em uma expressão constante quando a inicialização de cada membro de dados que ele captura ou apresenta é permitida dentro de uma expressão constante.

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

Um lambda é implicitamente **constexpr** se o resultado satisfizer os requisitos de uma função **constexpr** :

```cpp
    auto answer = [](int n)
    {
        return 32 + n;
    };

    constexpr int response = answer(10);
```

Se um lambda for implícito ou explicitamente **constexpr**e você convertê-lo em um ponteiro de função, a função resultante também será **constexpr**:

```cpp
    auto Increment = [](int n)
    {
        return n + 1;
    };

    constexpr int(*inc)(int) = Increment;
```

## <a name="see-also"></a>Confira também

[Referência da linguagem C++](../cpp/cpp-language-reference.md)<br/>
[Objetos de função na Biblioteca Padrão C++](../standard-library/function-objects-in-the-stl.md)<br/>
[Chamada de função](../cpp/function-call-cpp.md)<br/>
[for_each](../standard-library/algorithm-functions.md#for_each)
