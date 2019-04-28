---
title: Erro do compilador C2008
ms.date: 11/04/2016
f1_keywords:
- C2008
helpviewer_keywords:
- C2008
ms.assetid: e748ccbe-ffd4-4008-aca7-e53c25225209
ms.openlocfilehash: 0bd9193d6e305a4b6c6851ef2524a68ecc056816
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62208978"
---
# <a name="compiler-error-c2008"></a>Erro do compilador C2008

'character': inesperado na definição de macro

O caractere é exibido imediatamente após o nome da macro. Para resolver o erro, deve haver um espaço após o nome da macro.

O exemplo a seguir gera C2008:

```
// C2008.cpp
#define TEST1"mytest1"    // C2008
```

Solução possível:

```
// C2008b.cpp
// compile with: /c
#define TEST2 "mytest2"
```