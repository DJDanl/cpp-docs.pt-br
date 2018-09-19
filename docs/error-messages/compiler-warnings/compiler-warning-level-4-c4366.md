---
title: Compilador aviso (nível 4) C4366 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4366
dev_langs:
- C++
helpviewer_keywords:
- C4366
ms.assetid: 65d2942f-3741-42f4-adf2-4920d5a055ca
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: bb24c65605857124edf608bec88f1399d9df607d
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46047038"
---
# <a name="compiler-warning-level-4-c4366"></a>Compilador aviso (nível 4) C4366

O resultado do operador unário 'operator' deve ser unaligned

Se um membro da estrutura nunca pode ser não alinhado devido a empacotamento, o compilador avisará a quando que o endereço do membro é atribuído a um ponteiro alinhado. Por padrão, todos os ponteiros são alinhados.

Para resolver C4366, alterar o alinhamento da estrutura ou declare o ponteiro com o [unaligned](../../cpp/unaligned.md) palavra-chave.

Para obter mais informações, consulte unaligned e [pack](../../preprocessor/pack.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4366.

```
// C4366.cpp
// compile with: /W4 /c
// processor: IPF x64
#pragma pack(1)
struct X {
   short s1;
   int s2;
};

int main() {
   X x;
   short * ps1 = &x.s1;   // OK
   int * ps2 = &x.s2;   // C4366
}
```