---
title: Erro do compilador C3270
ms.date: 11/04/2016
f1_keywords:
- C3270
helpviewer_keywords:
- C3270
ms.assetid: 70e6e76b-7415-48f5-a61e-2ed50caf08e4
ms.openlocfilehash: 91656ee893f2ad7b3f0c53cb157cd9faf129e4c7
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62366037"
---
# <a name="compiler-error-c3270"></a>Erro do compilador C3270

'field': o atributo FieldOffset só pode ser usado no contexto de StructLayout(Explicit), nesse caso, é necessário

Um campo foi marcado com **FieldOffset**, que só é permitido quando **StructLayout(Explicit)** está em vigor.

O exemplo a seguir gera C3270:

```
// C3270_2.cpp
// compile with: /clr /c
using namespace System::Runtime::InteropServices;

[ StructLayout(LayoutKind::Sequential) ]
// try the following line instead
// [ StructLayout(LayoutKind::Explicit) ]
public value struct MYUNION
{
   [FieldOffset(0)] int a;   // C3270
   // ...
};
```
