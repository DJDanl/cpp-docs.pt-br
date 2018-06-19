---
title: C2090 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2090
dev_langs:
- C++
helpviewer_keywords:
- C2090
ms.assetid: e8176e55-382b-453d-aa27-6597f0274afd
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 718ed5ba8d422c2657dc58591ce285b0d85857cf
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33166157"
---
# <a name="compiler-error-c2090"></a>C2090 de erro do compilador
função retorna a matriz  
  
 Uma função não pode retornar uma matriz. Em vez disso, retorne um ponteiro para uma matriz.  
  
 O exemplo a seguir gera C2090:  
  
```  
// C2090.cpp  
int func1(void)[] {}   // C2090  
```  
  
 Possível solução:  
  
```  
// C2090b.cpp  
// compile with: /c  
int* func2(int * i) {  
   return i;  
}  
```