---
title: C2213 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2213
dev_langs:
- C++
helpviewer_keywords:
- C2213
ms.assetid: ff012278-7f3b-4d49-aaed-2349756f6225
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f51f734c8d795729b035d3b550e3cfdceea902a6
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c2213"></a>C2213 de erro do compilador
'modificador': argumento inválido para based  
  
 A modificação de argumento `__based` é inválido.  
  
 O exemplo a seguir gera C2213:  
  
```  
// C2213.cpp  
// compile with: /c  
int i;  
int *j;  
char __based(i) *p;   // C2213  
char __based(j) *p2;   // OK  
```