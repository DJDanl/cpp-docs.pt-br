---
title: Compilador aviso (nível 1) C4228
ms.date: 11/04/2016
f1_keywords:
- C4228
helpviewer_keywords:
- C4228
ms.assetid: 9301d660-d601-464e-83f5-7ed844a3c6dc
ms.openlocfilehash: c737a48883b97970af70014e2bda4bdc508ab471
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62207562"
---
# <a name="compiler-warning-level-1-c4228"></a>Compilador aviso (nível 1) C4228

extensão não padrão usada: qualificadores após a vírgula na lista de declaradores são ignorados

Como uso de qualificadores **const** ou `volatile` depois que uma vírgula ao declarar variáveis é uma extensão da Microsoft ([/Ze](../../build/reference/za-ze-disable-language-extensions.md)).

## <a name="example"></a>Exemplo

```
// C4228.cpp
// compile with: /W1
int j, const i = 0;  // C4228
int k;
int const m = 0;  // ok
int main()
{
}
```