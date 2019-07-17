---
title: Classe is_placeholder
ms.date: 11/04/2016
f1_keywords:
- functional/std::is_placeholder
helpviewer_keywords:
- is_placeholder class
ms.assetid: 2b21a792-96d1-4bb8-b911-0db796510835
ms.openlocfilehash: 9fa7d4aaade6244fe26f89f3a667598d39471a47
ms.sourcegitcommit: 3590dc146525807500c0477d6c9c17a4a8a2d658
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/16/2019
ms.locfileid: "68245143"
---
# <a name="isplaceholder-class"></a>Classe is_placeholder

Testa se o tipo é um espaço reservado.

## <a name="syntax"></a>Sintaxe

struct is_placeholder {valor int const estático;};

## <a name="remarks"></a>Comentários

O valor constante de `value` será 0 se o tipo `Ty` não for um espaço reservado; caso contrário, seu valor será a posição do argumento de chamada de função a que ele se associa. Você pode usá-lo para determinar o valor de `N` para o enésimo espaço reservado `_N`.

## <a name="example"></a>Exemplo

```cpp
// std__functional__is_placeholder.cpp
// compile with: /EHsc
#include <functional>
#include <iostream>

using namespace std::placeholders;

template<class Expr>
void test_for_placeholder(const Expr&)
{
    std::cout << std::is_placeholder<Expr>::value << std::endl;
}

int main()
{
    test_for_placeholder(3.0);
    test_for_placeholder(_3);

    return (0);
}
```

```Output
0
3
```
