---
title: C2133 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2133
dev_langs:
- C++
helpviewer_keywords:
- C2133
ms.assetid: 8942f9e8-9818-468f-97db-09dbd124fcae
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 878f6fa4a36e7de28bfc084f7f716d50b52c363a
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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