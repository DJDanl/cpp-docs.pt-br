---
title: Expressões Lambda em C++ constexpr | Microsoft Docs
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
ms.openlocfilehash: b78fa3de7777ffc6702902cf967a405595caf12f
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39408197"
---
# <a name="constexpr-lambda-expressions-in-c"></a>constexpr expressões Lambda em C++
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
 [Referência da linguagem C++](../cpp/cpp-language-reference.md)   
 [Objetos de função na biblioteca padrão C++](../standard-library/function-objects-in-the-stl.md)   
 [Chamada de função](../cpp/function-call-cpp.md)   
 [for_each](../standard-library/algorithm-functions.md#for_each)