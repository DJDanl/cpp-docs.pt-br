---
title: "Compilador aviso (nível 4) C4238 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4238
dev_langs:
- C++
helpviewer_keywords:
- C4238
ms.assetid: 5d4051d3-7b0f-43ea-8c8d-d194bfdceb71
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: b5b6c2a2a040f419edee39e10c54362771d9ad65
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-4-c4238"></a>Compilador C4238 de aviso (nível 4)
extensão não padrão usada : classe rvalue usada como lvalue  
  
 Para compatibilidade com versões anteriores do Visual C++, extensões da Microsoft (**/Ze**) permitem que você use um tipo de classe como um rvalue em um contexto que implicitamente ou explicitamente usa seu endereço. Em alguns casos, como no exemplo abaixo, isso pode ser perigoso.  
  
## <a name="example"></a>Exemplo  
  
```  
// C4238.cpp  
// compile with: /W4 /c  
struct C {  
   C() {}  
};  
  
C * pC = &C();   // C4238  
```  
  
 Esse uso causa um erro em compatibilidade com ANSI ([/Za](../../build/reference/za-ze-disable-language-extensions.md)).
