---
title: Compilador aviso (nível 1) C4552 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4552
dev_langs:
- C++
helpviewer_keywords:
- C4552
ms.assetid: ebbbb5ee-1c19-45bd-b386-41a19630fc76
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 62c08ea81f5f8794a1dd4ff7d0b5644e9a669e0f
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46048065"
---
# <a name="compiler-warning-level-1-c4552"></a>Compilador aviso (nível 1) C4552

'operator': operador não tem nenhum efeito; operador esperado com efeito colateral

Se uma instrução de expressão tem um operador com nenhum efeito colateral, como a parte superior da expressão, ele é provavelmente um erro.

Para substituir esse aviso, coloque a expressão entre parênteses.

O exemplo a seguir gera C4552:

```
// C4552.cpp
// compile with: /W1
int main() {
   int i, j;
   i + j;   // C4552
   // try the following line instead
   // (i + j);
}
```