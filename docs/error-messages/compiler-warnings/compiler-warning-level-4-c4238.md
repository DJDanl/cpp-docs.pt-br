---
title: Compilador (nível 4) de aviso C4238 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4238
dev_langs:
- C++
helpviewer_keywords:
- C4238
ms.assetid: 5d4051d3-7b0f-43ea-8c8d-d194bfdceb71
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 06dbec01da8d1b47cb7b93c90a22ae5266e9b4c8
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33292430"
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