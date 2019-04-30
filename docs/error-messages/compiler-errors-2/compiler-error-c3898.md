---
title: Erro do compilador C3898
ms.date: 11/04/2016
f1_keywords:
- C3898
helpviewer_keywords:
- C3898
ms.assetid: d9a90df6-87e4-4fe7-ab01-c226ee86bf10
ms.openlocfilehash: 503f295d62c598e3138b1a001d6b350c0d90ea84
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62385440"
---
# <a name="compiler-error-c3898"></a>Erro do compilador C3898

'var': membros de dados de tipo só podem ser membros de tipos gerenciados

Uma [initonly](../../dotnet/initonly-cpp-cli.md) membro de dados foi declarado em uma classe nativa.  Um `initonly` membro de dados só pode ser declarado em uma classe CLR.

O exemplo a seguir gera C3898:

```
// C3898.cpp
// compile with: /clr
struct Y1 {
   initonly
   static int data_var = 9;   // C3898
};
```

Solução possível:

```
// C3898b.cpp
// compile with: /clr /c
ref struct Y1 {
   initonly
   static int data_var = 9;
};
```