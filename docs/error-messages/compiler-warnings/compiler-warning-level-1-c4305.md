---
title: "Compilador (nível 1) de aviso C4305 | Microsoft Docs"
ms.custom: 
ms.date: 1/17/2018
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4305
dev_langs:
- C++
helpviewer_keywords:
- C4305
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 8fe4b2b420c44584fdd5b4d48b4264bbc7a51bee
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="compiler-warning-level-1-c4305"></a>Compilador C4305 de aviso (nível 1)

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

Para corrigir esse problema, inicializar usando um valor do tipo correto, ou use uma conversão explícita para o tipo correto. Por exemplo, usar um **float** literal como 2.71828f em vez de um **duplo** (o tipo padrão para literais de ponto flutuantes) para inicializar um **float** variável, ou para passar para um construtor que usa um **float** argumento.
