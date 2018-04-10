---
title: __Func__ | Microsoft Docs
ms.custom: ''
ms.date: 10/19/2017
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-language
ms.tgt_pltfrm: ''
ms.topic: language-reference
f1_keywords:
- __func__
dev_langs:
- C++
ms.assetid: a5299b8d-f0ee-4af2-91dd-8fb165e68798
caps.latest.revision: 3
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 5ddb92e84545de175734550eca8911590fa1d539
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="func"></a>__func__

**(C + + 11)**  o identificador predefinido #95; &#95; func #95; &#95; é definido implicitamente como uma cadeia de caracteres que contém o nome não qualificado e acrescido da função de delimitador. &#95; &#95; func #95; &#95; é exigido pelo padrão do C++ e não é uma extensão da Microsoft.

## <a name="syntax"></a>Sintaxe

```cpp
__func__
```

## <a name="return-value"></a>Valor de retorno

Retorna um terminada em nulo const char matriz de caracteres que contém o nome da função.

## <a name="example"></a>Exemplo

```cpp
#include <string>
#include <iostream>

namespace Test
{
    struct Foo
    {
        static void DoSomething(int i, std::string s)
        {
           std::cout << __func__ << std::endl; // Output: DoSomething
        }
    };
}

int main()
{
    Test::Foo::DoSomething(42, "Hello");

    return 0;
}
```

## <a name="requirements"></a>Requisitos

C++11