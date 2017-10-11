---
title: C2369 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C2369
dev_langs:
- C++
helpviewer_keywords:
- C2369
ms.assetid: 2a3933f6-2313-40ff-800f-921b296fdbbf
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 6c835d306a144d21d07285abfb23a8145ebcca16
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2369"></a>C2369 de erro do compilador
'array': redefinição; subscritos diferentes  
  
 A matriz já foi declarada com um subscrito diferente.  
  
 O exemplo a seguir gera C2369:  
  
```  
// C2369.cpp  
// compile with: /c  
int a[10];  
int a[20];   // C2369  
int b[20];   // OK  
```
