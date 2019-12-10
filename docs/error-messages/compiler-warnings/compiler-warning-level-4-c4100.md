---
title: Aviso do compilador (nível 4) C4100
ms.date: 11/04/2016
f1_keywords:
- C4100
helpviewer_keywords:
- C4100
ms.assetid: 478ed97d-e502-49e4-9afb-ac2a6c61194b
ms.openlocfilehash: bcd51c66359d0553b7657d85f5b45ee22d4648ff
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74991654"
---
# <a name="compiler-warning-level-4-c4100"></a>Aviso do compilador (nível 4) C4100

“identificador”: parâmetro formal não referenciado

O parâmetro formal não é referenciado no corpo da função. O parâmetro sem referência é ignorado.

C4100 também pode ser enviado quando o código chama um destrutor em um parâmetro de outro modo sem referência de tipo primitivo.  Essa é uma limitação do compilador da C++ Microsoft.

O exemplo a seguir produz C4100:

```cpp
// C4100.cpp
// compile with: /W4
void func(int i) {   // C4100, delete the unreferenced parameter to
                     //resolve the warning
   // i;   // or, add a reference like this
}

int main()
{
   func(1);
}
```
