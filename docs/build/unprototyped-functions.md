---
title: Funções sem protótipo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 34200b8c-5b52-4f0d-aff8-9f70d82868ed
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 2c030bd99fc185b3c52535aecb45697672ef4c14
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45717672"
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