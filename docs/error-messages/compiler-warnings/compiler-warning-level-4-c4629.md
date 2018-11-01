---
title: Compilador aviso (nível 4) C4629
ms.date: 11/04/2016
f1_keywords:
- C4629
helpviewer_keywords:
- C4629
ms.assetid: 158cde12-bae5-4d43-b575-b52b35aaa0b9
ms.openlocfilehash: db3f4201dbf5ff925449b0924d08a43ee4283b3e
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50651783"
---
# <a name="compiler-warning-level-4-c4629"></a>Compilador aviso (nível 4) C4629

dígrafo usado, a sequência de caracteres 'digraph' interpretada como token 'char' (inserir um espaço entre os dois caracteres quando se trata de não o que você pretendia)

Sob [/Za](../../build/reference/za-ze-disable-language-extensions.md), o compilador avisa quando ele detecta um dígrafo.

O exemplo a seguir gera C4629:

```
// C4629.cpp
// compile with: /Za /W4
int main()
<%   // C4629 <% digraph for {
}
```