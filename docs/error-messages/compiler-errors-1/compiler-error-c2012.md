---
title: C2012 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C2012
dev_langs:
- C++
helpviewer_keywords:
- C2012
ms.assetid: 9f0d8162-c0b3-4234-a41f-836fdb75c84e
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 2e83597ba9224ab6cf5c70b319ff50348bd9135f
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2012"></a>C2012 de erro do compilador
faltando nome após ' <'  
  
 Um `#include` diretiva não tem o nome de arquivo necessário.  
  
 O exemplo a seguir gera C2012:  
  
```  
// C2012.cpp  
#include <   // C2012 include the filename to resolve  
```  
  
 Possível solução:  
  
```  
// C2012b.cpp  
// compile with: /c  
#include <stdio.h>  
```
