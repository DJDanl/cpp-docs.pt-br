---
title: "Expressões Lambda em C++ de constexpr | Microsoft Docs"
ms.custom: 
ms.date: 07/19/2017
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- lambda expressions [C++], constexpr
ms.assetid: b56346cd-fbff-475f-aeaa-ed2010c6d6f7
caps.latest.revision: 0
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: c6221118477c79d683d468469b1f87dfa33efded
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

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
