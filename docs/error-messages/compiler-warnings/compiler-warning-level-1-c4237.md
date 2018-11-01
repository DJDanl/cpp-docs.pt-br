---
title: Compilador aviso (nível 1) C4237
ms.date: 11/04/2016
f1_keywords:
- C4237
helpviewer_keywords:
- C4237
ms.assetid: f2e86c4b-80d8-460e-9429-83c5f3f5d7ca
ms.openlocfilehash: 04fcb99e1dd1e348716e25affb22b54079d53aa9
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50472677"
---
# <a name="compiler-warning-level-1-c4237"></a>Compilador aviso (nível 1) C4237

palavra-chave de 'palavra-chave' ainda não tem suporte, mas reservada para uso futuro

Uma palavra-chave na especificação de C++ não é implementada no compilador do Visual C++, mas a palavra-chave não está disponível como um símbolo definido pelo usuário.

O exemplo a seguir gera C4237:

```
// C4237.cpp
// compile with: /W1 /c
int export;   // C4237
```