---
title: Compilador aviso (nível 1) C4674
ms.date: 11/04/2016
f1_keywords:
- C4674
helpviewer_keywords:
- C4674
ms.assetid: 638dae0b-b82c-4865-9599-72630827ca09
ms.openlocfilehash: f7db2f37224a8defffb545b0cfaf018fd4654227
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62374541"
---
# <a name="compiler-warning-level-1-c4674"></a>Compilador aviso (nível 1) C4674

'method' deve ser declarado como 'static' e ter exatamente um parâmetro

A assinatura de um operador de conversão não está correta. O método não é considerado uma conversão definida pelo usuário. Para obter mais informações sobre como definir operadores, consulte [operadores definidos pelo usuário (C++/CLI)](../../dotnet/user-defined-operators-cpp-cli.md) e [conversões definidas pelo usuário (C++/CLI)](../../dotnet/user-defined-conversions-cpp-cli.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4674.

```
// C4674.cpp
// compile with: /clr /WX /W1 /LD
ref class G {
   int op_Implicit(int i) {   // C4674
      return 0;
   }
};
```
