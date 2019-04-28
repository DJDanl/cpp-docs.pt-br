---
title: Compilador aviso (nível 4) C4565
ms.date: 08/27/2018
f1_keywords:
- C4565
helpviewer_keywords:
- C4565
ms.assetid: a71f1341-a4a1-4060-ad1e-9322531883ed
ms.openlocfilehash: b655dcfb456d32e45833e89e5a48926ad70d1d9e
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62220475"
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