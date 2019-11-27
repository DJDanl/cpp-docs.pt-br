---
title: Aviso do compilador (nível 4) C4100
ms.date: 11/04/2016
f1_keywords:
- C4100
helpviewer_keywords:
- C4100
ms.assetid: 478ed97d-e502-49e4-9afb-ac2a6c61194b
ms.openlocfilehash: 80794d270b40a8f40d44630da70455c015158423
ms.sourcegitcommit: 3ee06ec53153cf21910fc8cfef78a4f25f9633f3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/26/2019
ms.locfileid: "74541238"
---
# <a name="compiler-warning-level-4-c4100"></a>Aviso do compilador (nível 4) C4100

' identifier ': parâmetro formal não referenciado

O parâmetro formal não é referenciado no corpo da função. O parâmetro não referenciado é ignorado.

C4100 também pode ser emitido quando o código chama um destruidor em um parâmetro não referenciado de outro tipo primitivo.  Essa é uma limitação do compilador da C++ Microsoft.

O exemplo a seguir gera C4100:

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