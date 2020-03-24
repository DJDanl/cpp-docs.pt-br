---
title: Aviso do compilador (nível 4) C4214
ms.date: 11/04/2016
f1_keywords:
- C4214
helpviewer_keywords:
- C4214
ms.assetid: 9b8db279-1f12-4a6b-a923-2db22acd1947
ms.openlocfilehash: 70dadb7d424352fbde8c5904053b22fe7cc6b77e
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80161276"
---
# <a name="compiler-warning-level-4-c4214"></a>Aviso do compilador (nível 4) C4214

extensão não padrão usada: tipos de campo de bits diferentes de int

Com as extensões padrão da Microsoft (/Ze), os membros da estrutura de bits podem ser de qualquer tipo inteiro.

## <a name="example"></a>Exemplo

```c
// C4214.c
// compile with: /W4
struct bitfields
{
   unsigned short j:4;  // C4214
};

int main()
{
}
```

Esses campos de bit são inválidos em compatibilidade com ANSI ([/za](../../build/reference/za-ze-disable-language-extensions.md)).
