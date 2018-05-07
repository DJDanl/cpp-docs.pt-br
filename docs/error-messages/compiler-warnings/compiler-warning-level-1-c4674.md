---
title: Compilador (nível 1) de aviso C4674 | Microsoft Docs
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
ms.openlocfilehash: 6ede4ac8f8d0af94d998914b8a434cd8b2a9f482
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-1-c4674"></a>Compilador C4674 de aviso (nível 1)
'method' deve ser declarado como 'static' e ter exatamente um parâmetro  
  
A assinatura de um operador de conversão não está correta. O método não é considerado uma conversão definida pelo usuário. Para obter mais informações sobre como definir operadores, consulte [operadores definidos pelo usuário (C + + CLI)](../../dotnet/user-defined-operators-cpp-cli.md) e [conversões definidas pelo usuário (C + + CLI)](../../dotnet/user-defined-conversions-cpp-cli.md).  
  
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
