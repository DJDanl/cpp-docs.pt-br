---
title: Compilador aviso (nível 4) C4565 | Microsoft Docs
ms.custom: ''
ms.date: 08/27/2018
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4565
dev_langs:
- C++
helpviewer_keywords:
- C4565
ms.assetid: a71f1341-a4a1-4060-ad1e-9322531883ed
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c25f2f1fc16c6d45a7d1eddec8d3efe62db142f2
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43211256"
---
# <a name="compiler-warning-level-4-c4565"></a>Compilador aviso (nível 4) C4565

> '*função*': redefinição; símbolo foi declarado anteriormente com declspec (*modificador*)

## <a name="remarks"></a>Comentários

Um símbolo foi redefinido ou declarado novamente e a segunda definição ou declaração, ao contrário da primeira definição ou declaração, não tinha uma `__declspec` modificador (*modificador*). Esse aviso é informativo. Para corrigir este aviso, exclua uma das definições.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4565:

```cpp
// C4565.cpp
// compile with: /W4 /LD
__declspec(noalias) void f();
void f();   // C4565
```