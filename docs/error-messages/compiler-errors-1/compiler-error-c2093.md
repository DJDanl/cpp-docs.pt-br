---
title: Erro do compilador C2093
ms.date: 11/04/2016
f1_keywords:
- C2093
helpviewer_keywords:
- C2093
ms.assetid: 17529a70-9169-46b5-9fc6-57a5ce224e6a
ms.openlocfilehash: 52fcd69e631f1ca24664cde06478ae33ca2a37f2
ms.sourcegitcommit: a5fa9c6f4f0c239ac23be7de116066a978511de7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75301945"
---
# <a name="compiler-error-c2093"></a>Erro do compilador C2093

' variable1 ': não pode ser inicializado usando o endereço da variável automática ' intervalo2 '

Ao compilar com [/za](../../build/reference/za-ze-disable-language-extensions.md), o programa tentou usar o endereço de uma variável automática como um inicializador.

O exemplo a seguir gera C2093:

```c
// C2093.c
// compile with: /Za /c
void func() {
   int li;   // an implicit auto variable
   int * s[]= { &li };   // C2093 address is not a constant

   // OK
   static int li2;
   int * s2[]= { &li2 };
}
```
