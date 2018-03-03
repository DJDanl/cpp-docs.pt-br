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
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: dc635f4527c40adb09d76d8fa57ae6837203b57d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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