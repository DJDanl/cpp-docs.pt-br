---
title: Aviso do compilador (nível 1) C4920
ms.date: 11/04/2016
f1_keywords:
- C4920
helpviewer_keywords:
- C4920
ms.assetid: 1e501f2e-93c1-4d27-a4fa-54fc86271ae7
ms.openlocfilehash: 7cbb29c8dae24a87fcd5a32b4cf46d7a8ac4c790
ms.sourcegitcommit: 458dcc794e3841919c01a3a5ff6b9a3767f8861b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/13/2019
ms.locfileid: "74050237"
---
# <a name="compiler-warning-level-1-c4920"></a>Aviso do compilador (nível 1) C4920

enum enum member membro = valor já visto em enum enum as member = Value

Se um. tlb que você passar para #import tiver o mesmo símbolo definido em duas ou mais enumerações, esse aviso indicará que símbolos idênticos subsequentes serão ignorados e serão comentados no arquivo. tlh.

Supondo um. tlb que contém:

```
library MyLib
{
    typedef enum {
        enumMember = 512
    } AProblem;

    typedef enum {
        enumMember = 1024
    } BProblem;
};
```

o exemplo a seguir gera C4920,

```cpp
// C4920.cpp
// compile with: /W1
#import "t4920.tlb"   // C4920

int main() {
}
```