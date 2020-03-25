---
title: Aviso do compilador (nível 4) C4559
ms.date: 08/27/2018
f1_keywords:
- C4559
helpviewer_keywords:
- C4559
ms.assetid: ed542f60-454d-45cb-85da-987ede61b1ab
ms.openlocfilehash: 0788824dd4180476d81d9682f99fb95883b8c4f0
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80198335"
---
# <a name="compiler-warning-level-4-c4559"></a>Aviso do compilador (nível 4) C4559

> '*função*': redefinição; a função ganha __declspec (*modificador*)

## <a name="remarks"></a>Comentários

Uma função foi redefinida ou redeclarada e a segunda definição ou declaração adicionou um modificador de **__declspec** (*modificador*). Esse aviso é informativo. Para corrigir esse aviso, exclua uma das definições.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4559:

```cpp
// C4559.cpp
// compile with: /W4 /LD
void f();
__declspec(noalias) void f();   // C4559
```
