---
title: Compilador aviso (nível 4) C4211
ms.date: 11/04/2016
f1_keywords:
- C4211
helpviewer_keywords:
- C4211
ms.assetid: 3eea3455-6faa-4cdb-8730-73db7026bd1f
ms.openlocfilehash: 6d61191c4a7ed950d979158ccdfa3a390439b019
ms.sourcegitcommit: 35c4b3478f8cc310ebbd932a18963ad8ab846ed9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/08/2019
ms.locfileid: "59237088"
---
# <a name="compiler-warning-level-4-c4211"></a>Compilador aviso (nível 4) C4211

extensão não padrão usada: extern redefinido como estático

Com as extensões da Microsoft padrão (/Ze), você pode redefinir um `extern` identificador como **estático**.

## <a name="example"></a>Exemplo

```
// C4211.c
// compile with: /W4
extern int i;
static int i;   // C4211

int main()
{
}
```

Tais redefinições são inválidas para a compatibilidade com ANSI ([/Za](../../build/reference/za-ze-disable-language-extensions.md)).
