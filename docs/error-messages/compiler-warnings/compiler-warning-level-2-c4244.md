---
title: Aviso do compilador (nível 2) C4244
ms.date: 11/04/2016
f1_keywords:
- C4244
helpviewer_keywords:
- C4244
ms.assetid: 2c19d157-21d1-42c2-a6c0-3f30f2ce3813
ms.openlocfilehash: 43d8a992801d556ce85577f5f9da1bec584cb173
ms.sourcegitcommit: 458dcc794e3841919c01a3a5ff6b9a3767f8861b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/13/2019
ms.locfileid: "74052124"
---
# <a name="compiler-warning-level-2-c4244"></a>Aviso do compilador (nível 2) C4244

' Argument ': conversão de ' type1 ' para ' type2 ', possível perda de dados

Um tipo de ponto flutuante foi convertido em um tipo inteiro.  Pode ter ocorrido uma possível perda de dados.

Se você receber C4244, deverá alterar seu programa para usar tipos compatíveis ou adicionar alguma lógica ao seu código, para garantir que o intervalo de valores possíveis sempre seja compatível com os tipos que você está usando.

O C4244 também pode ser acionado no nível 3 e 4; consulte o [aviso do compilador (níveis 3 e 4) C4244](../../error-messages/compiler-warnings/compiler-warning-levels-3-and-4-c4244.md) para obter mais informações.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4244:

```cpp
// C4244_level2.cpp
// compile with: /W2

int f(int x){ return 0; }
int main() {
   double x = 10.1;
   int i = 10;
   return (f(x));   // C4244
   // try the following line instead
   // return (f(i));
}
```