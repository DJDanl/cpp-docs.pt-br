---
title: Aviso do compilador (nível 4) C4565
ms.date: 08/27/2018
f1_keywords:
- C4565
helpviewer_keywords:
- C4565
ms.assetid: a71f1341-a4a1-4060-ad1e-9322531883ed
ms.openlocfilehash: 5eccb3c29da612a39f7fcdf4ef25dedb898c8d43
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80198322"
---
# <a name="compiler-warning-level-4-c4565"></a>Aviso do compilador (nível 4) C4565

> '*função*': redefinição; o símbolo foi declarado anteriormente com __declspec (*modificador*)

## <a name="remarks"></a>Comentários

Um símbolo foi redefinido ou declarado novamente e a segunda definição ou declaração, diferentemente da primeira definição ou declaração, não tinha um modificador de `__declspec` (*modificador*). Esse aviso é informativo. Para corrigir esse aviso, exclua uma das definições.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4565:

```cpp
// C4565.cpp
// compile with: /W4 /LD
__declspec(noalias) void f();
void f();   // C4565
```
