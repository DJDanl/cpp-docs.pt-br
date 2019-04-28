---
title: Erro do compilador C3656
ms.date: 11/04/2016
f1_keywords:
- C3656
helpviewer_keywords:
- C3656
ms.assetid: 88965d85-73b0-4b35-8020-0650c9c94cd8
ms.openlocfilehash: 9709f3105e957012c05111ea818890b6d1df8259
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62227047"
---
# <a name="compiler-error-c3656"></a>Erro do compilador C3656

'override': substituir especificador não pode ser repetido

Uma palavra-chave de substituição explícita só pode ser especificada uma vez. Para obter mais informações, consulte [substituições explícitas](../../extensions/explicit-overrides-cpp-component-extensions.md).

O exemplo a seguir gera C3656:

```
// C3656.cpp
// compile with: /clr /c
public interface struct O {
   int f();
};

public ref struct V : O {
   int f() override override { return 0; }   // C3656
   // try the following line instead
   // int f() override { return 0; }
};
```