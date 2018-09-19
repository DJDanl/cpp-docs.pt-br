---
title: Compilador aviso (nível 4) C4629 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4629
dev_langs:
- C++
helpviewer_keywords:
- C4629
ms.assetid: 158cde12-bae5-4d43-b575-b52b35aaa0b9
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e5f728d60a654a672002610d41aa4e387b4479e0
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46081308"
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