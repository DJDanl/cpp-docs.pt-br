---
title: Funções sem protótipo
ms.date: 11/04/2016
ms.assetid: 34200b8c-5b52-4f0d-aff8-9f70d82868ed
ms.openlocfilehash: 38207be6111dadc338593e55b683b88e0480e1ca
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50633410"
---
# <a name="unprototyped-functions"></a>Funções sem protótipo

Para funções não totalmente com protótipo, o chamador passará valores inteiros como valores de ponto flutuantes e inteiros como de precisão dupla. Para valores de ponto flutuante somente, o registro de inteiro e o registro de ponto flutuante conterá o valor de float, caso o receptor espera que o valor em registros de inteiros.

```
func1();
func2() {   // RCX = 2, RDX = XMM1 = 1.0, and R8 = 7
   func1(2, 1.0, 7);
}
```

## <a name="see-also"></a>Consulte também

[Convenção de chamada](../build/calling-convention.md)