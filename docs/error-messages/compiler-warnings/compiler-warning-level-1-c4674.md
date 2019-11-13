---
title: Aviso do compilador (nível 1) C4674
ms.date: 11/04/2016
f1_keywords:
- C4674
helpviewer_keywords:
- C4674
ms.assetid: 638dae0b-b82c-4865-9599-72630827ca09
ms.openlocfilehash: b9428a593ff59cbdfa6d8eb369413a560b4a5ad2
ms.sourcegitcommit: 458dcc794e3841919c01a3a5ff6b9a3767f8861b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/13/2019
ms.locfileid: "74052538"
---
# <a name="compiler-warning-level-1-c4674"></a>Aviso do compilador (nível 1) C4674

' method ' deve ser declarado como ' static ' e ter exatamente um parâmetro

A assinatura de um operador de conversão não estava correta. O método não é considerado uma conversão definida pelo usuário. Para obter mais informações sobre como definir operadores, consulte os [operadores definidosC++pelo usuário (/CLI)](../../dotnet/user-defined-operators-cpp-cli.md) e [conversões definidas peloC++usuário (/CLI)](../../dotnet/user-defined-conversions-cpp-cli.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4674.

```cpp
// C4674.cpp
// compile with: /clr /WX /W1 /LD
ref class G {
   int op_Implicit(int i) {   // C4674
      return 0;
   }
};
```
