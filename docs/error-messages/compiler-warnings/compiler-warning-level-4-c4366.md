---
title: Aviso do compilador (nível 4) C4366
ms.date: 11/04/2016
f1_keywords:
- C4366
helpviewer_keywords:
- C4366
ms.assetid: 65d2942f-3741-42f4-adf2-4920d5a055ca
ms.openlocfilehash: fb4cead9367c5ef69627f607c521f480ad94271f
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74991057"
---
# <a name="compiler-warning-level-4-c4366"></a>Aviso do compilador (nível 4) C4366

O resultado do operador ' operator ' unário pode não estar alinhado

Se um membro de estrutura nunca fosse alinhado devido à embalagem, o compilador avisará quando o endereço desse membro for atribuído a um ponteiro alinhado. Por padrão, todos os ponteiros são alinhados.

Para resolver C4366, altere o alinhamento da estrutura ou declare o ponteiro com a palavra-chave [__unaligned](../../cpp/unaligned.md) .

Para obter mais informações, consulte __unaligned e [Pack](../../preprocessor/pack.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4366.

```cpp
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
