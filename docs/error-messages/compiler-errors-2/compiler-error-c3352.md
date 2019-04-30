---
title: Erro do compilador C3352
ms.date: 11/04/2016
f1_keywords:
- C3352
helpviewer_keywords:
- C3352
ms.assetid: f233bed7-474e-425f-aad2-7801578169d4
ms.openlocfilehash: 6641f05c8daa5ad505c0bcb8d29a369ad5fd9a9a
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62402626"
---
# <a name="compiler-error-c3352"></a>Erro do compilador C3352

'function': a função especificada não coincide com o tipo de delegado 'type'

A lista de parâmetros para `function` e o delegado não coincidem.

Para obter mais informações, consulte [delegado (extensões de componentes C++)](../../extensions/delegate-cpp-component-extensions.md).

O exemplo a seguir gera C3352:

```
// C3352.cpp
// compile with: /clr
delegate int D( int, int );
ref class C {
public:
   int mf( int ) {
      return 1;
   }

   // Uncomment the following line to resolve.
   // int mf(int, int) { return 1; }
};

int main() {
   C^ pC = gcnew C;
   System::Delegate^ pD = gcnew D( pC, &C::mf );   // C3352
}
```
