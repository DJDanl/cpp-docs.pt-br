---
title: Erro do compilador C3551
ms.date: 11/04/2016
f1_keywords:
- C3551
helpviewer_keywords:
- C3551
ms.assetid: c8ee23da-6568-40db-93a6-3ddb7ac47712
ms.openlocfilehash: e9a4ce2276a602d59e495a2f336bb9d59dc0cc99
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80200753"
---
# <a name="compiler-error-c3551"></a>Erro do compilador C3551

"esperado um tipo de retorno mais recente especificado"

Se você usar a palavra-chave `auto` como um espaço reservado para o tipo de retorno de uma função, deverá fornecer um tipo de retorno especificado de forma tardia. No exemplo a seguir, o tipo de retorno de função mais recente `myFunction` é um ponteiro para uma matriz de quatro elementos do tipo `int`.

```
auto myFunction()->int(*)[4];
```

## <a name="see-also"></a>Confira também

[auto](../../cpp/auto-cpp.md)
