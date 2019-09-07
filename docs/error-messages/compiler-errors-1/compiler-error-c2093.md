---
title: Erro do compilador C2093
ms.date: 11/04/2016
f1_keywords:
- C2093
helpviewer_keywords:
- C2093
ms.assetid: 17529a70-9169-46b5-9fc6-57a5ce224e6a
ms.openlocfilehash: d57b452e63f7bf76051ef6a23c5f8f6ba81aed1e
ms.sourcegitcommit: 180f63704f6ddd07a4172a93b179cf0733fd952d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/06/2019
ms.locfileid: "70741148"
---
# <a name="compiler-error-c2093"></a>Erro do compilador C2093

' variable1 ': não pode ser inicializado usando o endereço da variável automática ' intervalo2 '

Ao compilar com [/za](../../build/reference/za-ze-disable-language-extensions.md), o programa tentou usar o endereço de uma variável automática como um inicializador.

O exemplo a seguir gera C2093:

```
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