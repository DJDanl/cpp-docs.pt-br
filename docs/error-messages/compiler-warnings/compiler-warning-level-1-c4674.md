---
title: "Compilador (nível 1) de aviso C4674 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: C4674
dev_langs: C++
helpviewer_keywords: C4674
ms.assetid: 638dae0b-b82c-4865-9599-72630827ca09
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 43d34279ded00851962008837d0bf6cd76eaff7c
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
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
