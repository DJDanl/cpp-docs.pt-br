---
title: C2133 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2133
dev_langs:
- C++
helpviewer_keywords:
- C2133
ms.assetid: 8942f9e8-9818-468f-97db-09dbd124fcae
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: c04452ec947adefa6b30928dc75de4edffc361fc
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2133"></a>C2133 de erro do compilador
'Identificador': tamanho desconhecido  
  
 Uma matriz sem tamanho é declarada como um membro de uma classe, estrutura, união ou enumeração. A opção /Za (ANSI C) não permite a matrizes sem tamanho do membro.  
  
 O exemplo a seguir gera C2133:  
  
```  
// C2133.cpp  
// compile with: /Za  
struct X {  
   int a[0];   // C2133 unsized array  
};  
```  
  
 Possível solução:  
  
```  
// C2133b.cpp  
// compile with: /c  
struct X {  
   int a[0];   // no /Za  
};  
```
