---
title: __func__
ms.date: 10/19/2017
f1_keywords:
- __func__
ms.assetid: a5299b8d-f0ee-4af2-91dd-8fb165e68798
ms.openlocfilehash: eecd3efea6239c92a8bc81c0ed13a9563e5b87d2
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50438578"
---
# <a name="func"></a>__func__

**(C++11)**  o identificador predefinido &#95; &#95;func&#95; &#95; está implicitamente definido como uma cadeia de caracteres que contém o nome qualificado e não adornado da função. &#95;&#95;Func&#95; &#95; é exigido pelo padrão C++ e não é uma extensão da Microsoft.

## <a name="syntax"></a>Sintaxe

```cpp
__func__
```

## <a name="return-value"></a>Valor de retorno

Retorna um terminada em nulo const char uma matriz de caracteres que contém o nome da função.

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