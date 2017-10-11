---
title: C2008 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2008
dev_langs:
- C++
helpviewer_keywords:
- C2008
ms.assetid: e748ccbe-ffd4-4008-aca7-e53c25225209
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: fafc8567da4c9310a2ea96497f5764bbd1337137
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2008"></a>C2008 de erro do compilador
'character': inesperado na definição de macro  
  
 O caractere aparece imediatamente após o nome da macro. Para resolver o erro, deve haver um espaço após o nome da macro.  
  
 O exemplo a seguir gera C2008:  
  
```  
// C2008.cpp  
#define TEST1"mytest1"    // C2008  
```  
  
 Possível solução:  
  
```  
// C2008b.cpp  
// compile with: /c  
#define TEST2 "mytest2"  
```
