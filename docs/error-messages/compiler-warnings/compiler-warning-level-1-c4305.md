---
title: Aviso do compilador (nível 1) C4305
ms.date: 01/17/2018
f1_keywords:
- C4305
helpviewer_keywords:
- C4305
ms.openlocfilehash: 567442bc48487e4f7d1f905f871d15f913646e87
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87233282"
---
# <a name="compiler-warning-level-1-c4305"></a>Aviso do compilador (nível 1) C4305

> '*Context*': truncamento de '*type1*' para '*type2*'

## <a name="remarks"></a>Comentários

Esse aviso é emitido quando um valor é convertido em um tipo menor em uma inicialização ou como um argumento de construtor, resultando em uma perda de informações.

## <a name="example"></a>Exemplo

Este exemplo mostra duas maneiras que você pode ver este aviso:

```cpp
// C4305.cpp
// Compile by using: cl /EHsc /W4 C4305.cpp

struct item
{
    item(float) {}
};

int main()
{
    float f = 2.71828;          // C4305 'initializing'
    item i(3.14159);            // C4305 'argument'
    return static_cast<int>(f);
}
```

Para corrigir esse problema, inicialize usando um valor do tipo correto ou use uma conversão explícita para o tipo correto. Por exemplo, use um **`float`** literal como 2.71828 f em vez de um **`double`** (o tipo padrão para literais de ponto flutuante) para inicializar uma **`float`** variável ou para passar para um construtor que usa um **`float`** argumento.
