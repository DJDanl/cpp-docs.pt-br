---
title: C2042 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C2042
dev_langs:
- C++
helpviewer_keywords:
- C2042
ms.assetid: e111788f-41ce-405a-9824-a4c1c26059e6
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 7907e4407e58e6c05a4c352d78d744d4226153dd
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2042"></a>C2042 de erro do compilador
conectado/unsigned palavras-chave mutuamente exclusivas  
  
 As palavras-chave `signed` e `unsigned` são usados em uma única declaração.  
  
 O exemplo a seguir gera C2042:  
  
```  
// C2042.cpp  
unsigned signed int i;   // C2042  
```  
  
 Possível solução:  
  
```  
// C2042b.cpp  
// compile with: /c  
unsigned int i;  
signed int ii;  
```
