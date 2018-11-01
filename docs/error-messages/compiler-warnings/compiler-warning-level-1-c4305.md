---
title: Compilador aviso (nível 1) C4305
ms.date: 1/17/2018
f1_keywords:
- C4305
helpviewer_keywords:
- C4305
ms.openlocfilehash: 3f9116b0e7bdd9ee13c42b48f44da4b090f41ccd
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50649118"
---
# <a name="compiler-warning-level-1-c4305"></a>Compilador aviso (nível 1) C4305

> '*contexto*': truncamento de '*type1*'para'*type2*'

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

Para corrigir esse problema, inicializar usando um valor do tipo correto ou use uma conversão explícita para o tipo correto. Por exemplo, usar um **float** literal, como 2.71828f em vez de uma **duplo** (o tipo padrão para literais de ponto flutuantes) para inicializar um **float** variável, ou para passar para um construtor que usa um **float** argumento.
