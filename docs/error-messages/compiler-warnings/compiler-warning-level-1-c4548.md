---
title: Compilador aviso (nível 1) C4548 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4548
dev_langs:
- C++
helpviewer_keywords:
- C4548
ms.assetid: 2cee817e-e463-4d90-bbd2-de120d48c101
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 19ad8863858e7bbb4fdc5f200926ef4ab93ab794
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46086636"
---
# <a name="compiler-warning-level-1-c4548"></a>Compilador aviso (nível 1) C4548

expressão antes da vírgula não tem efeito; expressão esperada com efeito colateral

O compilador detectou uma expressão de vírgula mal formado.

Esse aviso é desativado por padrão. Para obter mais informações, consulte [compilador avisos que são desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md).

O exemplo a seguir gera C4548:

```
// C4548.cpp
// compile with: /W1
#pragma warning (default : 4548)
int main()
{
   int i = 0, k = 0;

   if ( i, k )   // C4548
   // try the following line instead
   // if ( i = 0, k )
      i++;
}
```