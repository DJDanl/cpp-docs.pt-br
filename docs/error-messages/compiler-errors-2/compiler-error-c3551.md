---
title: Erro do compilador C3551
ms.date: 11/04/2016
f1_keywords:
- C3551
helpviewer_keywords:
- C3551
ms.assetid: c8ee23da-6568-40db-93a6-3ddb7ac47712
ms.openlocfilehash: 1555817de6e50ea27a021718c8b094efeaebacde
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87230838"
---
# <a name="compiler-error-c3551"></a>Erro do compilador C3551

"esperado um tipo de retorno mais recente especificado"

Se você usar a **`auto`** palavra-chave como um espaço reservado para o tipo de retorno de uma função, deverá fornecer um tipo de retorno especificado de forma tardia. No exemplo a seguir, o tipo de retorno de função de última especificação `myFunction` é um ponteiro para uma matriz de quatro elementos do tipo **`int`** .

```
auto myFunction()->int(*)[4];
```

## <a name="see-also"></a>Confira também

[Automático](../../cpp/auto-cpp.md)
