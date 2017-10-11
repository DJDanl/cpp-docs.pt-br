---
title: C2374 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C2374
dev_langs:
- C++
helpviewer_keywords:
- C2374
ms.assetid: 73b51965-e91c-4e21-9732-f71c1449d22e
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 018f2924aeb59ae58975d41d9147fdfd60c8ee59
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2374"></a>C2374 de erro do compilador
'Identificador': redefinição; inicialização de vários  
  
 O identificador é inicializado em mais de uma vez.  
  
 O exemplo a seguir gera C2374:  
  
```  
// C2374.cpp  
// compile with: /c  
int i = 0;  
int i = 1;   // C2374  
int j = 1;   // OK  
```
