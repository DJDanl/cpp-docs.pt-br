---
title: C2734 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2734
dev_langs:
- C++
helpviewer_keywords:
- C2734
ms.assetid: e53a77b7-825c-42d1-a655-90e1c93b833e
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 75b82a9c892ecda312b13f1adc2925a9695b4db5
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2734"></a>C2734 de erro do compilador
'Identificador': objeto const deve ser inicializado quando não extern  
  
 O identificador é declarado `const` , mas não inicializado ou `extern`.  
  
 O exemplo a seguir gera C2734:  
  
```  
// C2734.cpp  
const int j;   // C2734  
extern const int i;   // OK, declared as extern  
```
