---
title: Compilador aviso (nível 1) C4674 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4674
dev_langs:
- C++
helpviewer_keywords:
- C4674
ms.assetid: 638dae0b-b82c-4865-9599-72630827ca09
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9b2f945982e80b49403387241f29a50876274e66
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46024873"
---
# <a name="compiler-warning-level-1-c4674"></a>Compilador aviso (nível 1) C4674

'method' deve ser declarado como 'static' e ter exatamente um parâmetro

A assinatura de um operador de conversão não está correta. O método não é considerado uma conversão definida pelo usuário. Para obter mais informações sobre como definir operadores, consulte [operadores definidos pelo usuário (C + + c++ CLI)](../../dotnet/user-defined-operators-cpp-cli.md) e [conversões definidas pelo usuário (C + + c++ CLI)](../../dotnet/user-defined-conversions-cpp-cli.md).

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
