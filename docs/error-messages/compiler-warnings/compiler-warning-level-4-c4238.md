---
title: "Compilador (nível 4) de aviso C4238 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4238
dev_langs:
- C++
helpviewer_keywords:
- C4238
ms.assetid: 5d4051d3-7b0f-43ea-8c8d-d194bfdceb71
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 8e8e52868d97d31243f92307e9bfd158c818c2f8
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-4-c4238"></a>Compilador C4238 de aviso (nível 4)
extensão não padrão usada: classe rvalue usada como lvalue  
  
 Para compatibilidade com versões anteriores do Visual C++, extensões da Microsoft (**/Ze**) permitem que você use um tipo de classe como um rvalue em um contexto que implicitamente ou explicitamente usa seu endereço. Em alguns casos, como o exemplo a seguir, isso pode ser perigoso.  
  
## <a name="example"></a>Exemplo  
  
```  
// C4238.cpp  
// compile with: /W4 /c  
struct C {  
   C() {}  
};  
  
C * pC = &C();   // C4238  
```  
  
 Esse uso causa um erro em compatibilidade ANSI ([/Za](../../build/reference/za-ze-disable-language-extensions.md)).