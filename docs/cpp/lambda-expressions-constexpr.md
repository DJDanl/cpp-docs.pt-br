---
title: Expressões Lambda em C++ de constexpr | Microsoft Docs
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
ms.openlocfilehash: 1e01f41aaf8b761020f57625e7cbf06f8fba2659
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="constexpr-lambda-expressions-in-c"></a>constexpr expressões Lambda em C++
**Visual Studio 2017 versão posterior e 15,3** (disponível com [/std:c + + 17](../build/reference/std-specify-language-standard-version.md)): uma expressão lambda pode ser declarada como `constexpr` ou usados em uma expressão de contant quando a inicialização de cada membro de dados que ele captura ou introduz é permitida dentro de uma expressão constante.  

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
Uma expressão lambda é implicitamente `constexpr` se seu resultado satisfaz os requisitos de um `constexpr` função:
```cpp
    auto answer = [](int n) 
    {
        return 32 + n; 
    };

    constexpr int response = answer(10);
``` 
Se uma expressão lambda é implicitamente ou explicitamente `constexpr`e convertê-lo para um ponteiro de função, a função resultante também é `constexpr`:

```cpp
    auto Increment = [](int n)
    {
        return n + 1;
    };

    constexpr int(*inc)(int) = Increment;
```
  
## <a name="see-also"></a>Consulte também  
 [Referência da linguagem C++](../cpp/cpp-language-reference.md)   
 [Objetos de função na biblioteca C++ padrão](../standard-library/function-objects-in-the-stl.md)   
 [Chamada de função](../cpp/function-call-cpp.md)   
 [for_each](../standard-library/algorithm-functions.md#for_each)