---
title: Erro do compilador C3551
ms.date: 11/04/2016
f1_keywords:
- C3551
helpviewer_keywords:
- C3551
ms.assetid: c8ee23da-6568-40db-93a6-3ddb7ac47712
ms.openlocfilehash: 9dfdee155e85bd772ed1d4ce22c525f8a4c79f5c
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50458741"
---
# <a name="compiler-error-c3551"></a>Erro do compilador C3551

"esperado que um final de tipo de retorno especificado"

Se você usar o `auto` palavra-chave como um espaço reservado para o tipo de retorno de uma função, você deve fornecer um tipo de retorno com especificação tardia. No exemplo a seguir, o retorno com especificação tardia tipo de função `myFunction` é um ponteiro para uma matriz de quatro elementos do tipo `int`.

```
auto myFunction()->int(*)[4];
```

## <a name="see-also"></a>Consulte também

[auto](../../cpp/auto-cpp.md)