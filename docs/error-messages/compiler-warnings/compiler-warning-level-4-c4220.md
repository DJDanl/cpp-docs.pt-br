---
title: Compilador aviso (nível 4) C4220
ms.date: 11/04/2016
f1_keywords:
- C4220
helpviewer_keywords:
- C4220
ms.assetid: aba18868-825f-4763-9af6-3296406a80e4
ms.openlocfilehash: 177fb01ba4181f72740724d107fe08e6680ed492
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62401105"
---
# <a name="compiler-warning-level-4-c4220"></a>Compilador aviso (nível 4) C4220

varargs corresponde parâmetros restantes

Sob as extensões da Microsoft padrão (/Ze), um ponteiro para uma função corresponde a um ponteiro para uma função com argumentos semelhantes, mas a variável.

## <a name="example"></a>Exemplo

```
// C4220.c
// compile with: /W4

int ( *pFunc1) ( int a, ... );
int ( *pFunc2) ( int a, int b);

int main()
{
   if ( pFunc1 != pFunc2 ) {};  // C4220
}
```

Esses ponteiros não coincidem em compatibilidade com ANSI ([/Za](../../build/reference/za-ze-disable-language-extensions.md)).