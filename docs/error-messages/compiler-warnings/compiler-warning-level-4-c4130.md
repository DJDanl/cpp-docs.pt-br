---
title: Compilador aviso (nível 4) C4130 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4130
dev_langs:
- C++
helpviewer_keywords:
- C4130
ms.assetid: 45e4c7b2-6b51-41c7-ba5e-941aa5c7d3dc
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 21d73595e41c4c83eda61fa749c9f2dc72bb14bc
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46038094"
---
# <a name="compiler-warning-level-4-c4130"></a>Compilador aviso (nível 4) C4130

'operator': operação lógica em endereço de constante de cadeia de caracteres

Usando o operador com o endereço de um literal de cadeia de caracteres produz código inesperado.

O exemplo a seguir gera C4130:

```
// C4130.cpp
// compile with: /W4
int main()
{
   char *pc;
   pc = "Hello";
   if (pc == "Hello") // C4130
   {
   }
}
```

O **se** instrução compara o valor armazenado no ponteiro `pc` para o endereço da cadeia de caracteres "Hello", que é alocado separadamente cada vez que a cadeia de caracteres ocorre no código. O **se** instrução não compara a cadeia de caracteres apontada por `pc` com a cadeia de caracteres "Hello".

Para comparar cadeias de caracteres, use o `strcmp` função.