---
title: C2436 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2436
dev_langs:
- C++
helpviewer_keywords:
- C2436
ms.assetid: ca4cc813-bc1d-4c0a-9a2c-3a5fe673d084
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: ca7f9a160675009e1462b1e7c5c1b110180e10c5
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2436"></a>C2436 de erro do compilador
'Identificador': função membro ou classe aninhada na lista de inicializador de construtor  
  
 Funções de membro ou classes locais na lista de inicializador de construtor não podem ser inicializados.  
  
 O exemplo a seguir gera C2436:  
  
```  
// C2436.cpp  
struct S{  
   int f();  
   struct Inner{  
      int i;  
   };  
   S():f(10), Inner(0){}   // C2436  
};  
```
