---
title: Erro do compilador C3551
ms.date: 11/04/2016
f1_keywords:
- C3551
helpviewer_keywords:
- C3551
ms.assetid: c8ee23da-6568-40db-93a6-3ddb7ac47712
ms.openlocfilehash: 48b378eb734c5830bedbf417d99d34955e2e6d0f
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59023263"
---
# <a name="compiler-error-c3551"></a>Erro do compilador C3551

"esperado que um final de tipo de retorno especificado"

Se você usar o `auto` palavra-chave como um espaço reservado para o tipo de retorno de uma função, você deve fornecer um tipo de retorno com especificação tardia. No exemplo a seguir, o retorno com especificação tardia tipo de função `myFunction` é um ponteiro para uma matriz de quatro elementos do tipo `int`.

```
auto myFunction()->int(*)[4];
```

## <a name="see-also"></a>Consulte também

[auto](../../cpp/auto-cpp.md)