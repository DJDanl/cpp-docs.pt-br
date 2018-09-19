---
title: Compilador aviso (nível 1) C4393 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4393
dev_langs:
- C++
helpviewer_keywords:
- C4393
ms.assetid: 353a0539-d1ea-4c1b-8849-c9b321ec9842
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 79a77e73e87d8ebc6a4bcff76fba296188233c1c
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46053850"
---
# <a name="compiler-warning-level-1-c4393"></a>Compilador aviso (nível 1) C4393

'var': const não tem efeito sobre membro de dados literal; ignorado

Um [literal](../../windows/literal-cpp-component-extensions.md) membro de dados também foi especificado como const.  Como um membro de dados literal implica const, você não precisa adicionar const à declaração.

O exemplo a seguir gera C4393:

```
// C4393.cpp
// compile with: /clr /W1 /c
ref struct Y1 {
   literal const int staticConst = 10;   // C4393
   literal int staticConst2 = 10;   // OK
};
```