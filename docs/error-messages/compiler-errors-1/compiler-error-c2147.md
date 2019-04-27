---
title: Erro do compilador C2147
ms.date: 11/04/2016
f1_keywords:
- C2147
helpviewer_keywords:
- C2147
ms.assetid: d1adb3bf-7ece-4815-922c-ad7492fb6670
ms.openlocfilehash: 0a093bbbaf9cf9f72625226f949a27b681005c35
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62175388"
---
# <a name="compiler-error-c2147"></a>Erro do compilador C2147

Erro de sintaxe: 'identifier' é uma nova palavra-chave

Foi usado um identificador que é agora uma palavra-chave reservada no idioma.

O exemplo a seguir gera C2147:

```
// C2147.cpp
// compile with: /clr
int main() {
   int gcnew = 0;   // C2147
   int i = 0;   // OK
}
```