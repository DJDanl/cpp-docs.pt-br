---
title: C2032 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2032
dev_langs:
- C++
helpviewer_keywords:
- C2032
ms.assetid: 625d7c83-70b6-42c2-a558-81fbc0026324
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 1db268222f3b9f7ca6f9ce297680866185e6661d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33167210"
---
# <a name="compiler-error-c2032"></a>C2032 de erro do compilador
'Identificador': função não pode ser membro de struct/união 'structorunion'  
  
 A estrutura ou união tem uma função de membro, que é permitida em C++, mas não em C. Para resolver o erro, compilar como um programa C++ ou remova a função de membro.  
  
 O exemplo a seguir gera C2032:  
  
```  
// C2032.c  
struct z {  
   int i;  
   void func();   // C2032  
};  
```  
  
 Possível solução:  
  
```  
// C2032b.c  
// compile with: /c  
struct z {  
   int i;  
};  
```