---
title: Aviso do compilador (nível 4) C4559
ms.date: 08/27/2018
f1_keywords:
- C4559
helpviewer_keywords:
- C4559
ms.assetid: ed542f60-454d-45cb-85da-987ede61b1ab
ms.openlocfilehash: 66e782c2fbb9c39c6a189de496cd0dcb4f1f4991
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87218072"
---
# <a name="compiler-warning-level-4-c4559"></a>Aviso do compilador (nível 4) C4559

> '*função*': redefinição; a função ganha __declspec (*modificador*)

## <a name="remarks"></a>Comentários

Uma função foi redefinida ou redeclarada e a segunda definição ou declaração adicionou um **`__declspec`** modificador (*modificador*). Esse aviso é informativo. Para corrigir esse aviso, exclua uma das definições.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4559:

```cpp
// C4559.cpp
// compile with: /W4 /LD
void f();
__declspec(noalias) void f();   // C4559
```
