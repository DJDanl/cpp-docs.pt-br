---
title: Compilador aviso (nível 4) C4100
ms.date: 11/04/2016
f1_keywords:
- C4100
helpviewer_keywords:
- C4100
ms.assetid: 478ed97d-e502-49e4-9afb-ac2a6c61194b
ms.openlocfilehash: 84a0b27203cd43e8a8992c4ba599f1400c6909ad
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62401391"
---
# <a name="compiler-warning-level-4-c4100"></a>Compilador aviso (nível 4) C4100

'identifier': parâmetro formal não referenciado

O parâmetro formal não é referenciado no corpo da função. O parâmetro sem referência é ignorado.

C4100 também pode ser emitido quando o código chama um destrutor em um sem referência parâmetro de tipo primitivo.  Essa é uma limitação do compilador do Visual C++.

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