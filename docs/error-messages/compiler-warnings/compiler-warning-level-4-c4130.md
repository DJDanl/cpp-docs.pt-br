---
title: Compilador aviso (nível 4) C4130
ms.date: 11/04/2016
f1_keywords:
- C4130
helpviewer_keywords:
- C4130
ms.assetid: 45e4c7b2-6b51-41c7-ba5e-941aa5c7d3dc
ms.openlocfilehash: 1b1fb72d68309a4bef56ccd844ad30d967bbadbd
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62401300"
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