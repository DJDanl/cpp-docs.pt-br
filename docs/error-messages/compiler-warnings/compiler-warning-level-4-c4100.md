---
title: Compilador aviso (nível 4) C4100
ms.date: 11/04/2016
f1_keywords:
- C4100
helpviewer_keywords:
- C4100
ms.assetid: 478ed97d-e502-49e4-9afb-ac2a6c61194b
ms.openlocfilehash: ccb438cf7c80edb1403683ac4817617ffccc690d
ms.sourcegitcommit: 7d64c5f226f925642a25e07498567df8bebb00d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2019
ms.locfileid: "65447735"
---
# <a name="compiler-warning-level-4-c4100"></a>Compilador aviso (nível 4) C4100

'identifier': parâmetro formal não referenciado

O parâmetro formal não é referenciado no corpo da função. O parâmetro sem referência é ignorado.

C4100 também pode ser emitido quando o código chama um destrutor em um sem referência parâmetro de tipo primitivo.  Essa é uma limitação do Microsoft C++ compilador.

O exemplo a seguir produz C4100:

```
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