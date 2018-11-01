---
title: A.30   Uso de reprivatização
ms.date: 11/04/2016
ms.assetid: 26529090-6c39-40f2-b806-e12374d6b5f8
ms.openlocfilehash: dc1d142a282fe6bb55c9cc512e6a6e8155b286e4
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50437317"
---
# <a name="a30---use-of-reprivatization"></a>A.30   Uso de reprivatização

O exemplo a seguir demonstra a reprivatização de variáveis. Variáveis privadas podem ser marcadas `private` novamente em uma diretiva aninhada. Eles não precisam ser compartilhados na região paralela delimitador.

```
int i, a;
...
#pragma omp parallel private(a)
{
  ...
  #pragma omp parallel for private(a)
  for (i=0; i<10; i++)
     {
       ...
     }
}
```