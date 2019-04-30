---
title: Compilador aviso (nível 1) C4393
ms.date: 11/04/2016
f1_keywords:
- C4393
helpviewer_keywords:
- C4393
ms.assetid: 353a0539-d1ea-4c1b-8849-c9b321ec9842
ms.openlocfilehash: 4226c8ecd41e890d70fa5741decae605d45b620f
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62386922"
---
# <a name="compiler-warning-level-1-c4393"></a>Compilador aviso (nível 1) C4393

'var': const não tem efeito sobre membro de dados literal; ignorado

Um [literal](../../extensions/literal-cpp-component-extensions.md) membro de dados também foi especificado como const.  Como um membro de dados literal implica const, você não precisa adicionar const à declaração.

O exemplo a seguir gera C4393:

```
// C4393.cpp
// compile with: /clr /W1 /c
ref struct Y1 {
   literal const int staticConst = 10;   // C4393
   literal int staticConst2 = 10;   // OK
};
```