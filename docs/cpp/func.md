---
title: __func__
ms.date: 10/19/2017
f1_keywords:
- __func__
ms.assetid: a5299b8d-f0ee-4af2-91dd-8fb165e68798
ms.openlocfilehash: 8e94caffe120c325478d8b4f24c1915a516d69f4
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80179816"
---
# <a name="__func__"></a>__func__

**(C++ 11)** O identificador &#95; &#95;predefinido&#95; &#95; Func é implicitamente definido como uma cadeia de caracteres que contém o nome não qualificado e não adornado da função de circunscrição. &#95;&#95;Func&#95; &#95; é obrigatório pelo C++ padrão e não é uma extensão da Microsoft.

## <a name="syntax"></a>Sintaxe

```cpp
__func__
```

## <a name="return-value"></a>Valor retornado

Retorna uma matriz de caracteres const com final de nulo que contém o nome da função.

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
