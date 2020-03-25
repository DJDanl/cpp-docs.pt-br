---
title: Aviso do compilador (nível 1) C4273
ms.date: 11/04/2016
f1_keywords:
- C4273
helpviewer_keywords:
- C4273
ms.assetid: cc18611d-9454-40a4-ad73-69823d5888fb
ms.openlocfilehash: 2fcecc268d4d271bcb43b7094baa58a2d654d22e
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80199739"
---
# <a name="compiler-warning-level-1-c4273"></a>Aviso do compilador (nível 1) C4273

' function ': vinculação de DLL inconsistente

Duas definições em um arquivo diferem no uso de [DllImport](../../cpp/dllexport-dllimport.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4273.

```cpp
// C4273.cpp
// compile with: /W1 /c
char __declspec(dllimport) c;
char c;   // C4273, delete this line or the line above to resolve
```

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4273.

```cpp
// C4273_b.cpp
// compile with: /W1 /clr /c
#include <stdio.h>
extern "C" int printf_s(const char *, ...);   // C4273
```
