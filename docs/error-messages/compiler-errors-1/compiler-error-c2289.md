---
title: C2289 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C2289
dev_langs:
- C++
helpviewer_keywords:
- C2289
ms.assetid: cb41a29e-1b06-47dc-bfce-8d73bd63a0df
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 6c771780ad3bbaefd51be10c9ff1454127f8439b
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2289"></a>C2289 de erro do compilador
mesmo qualificador de tipo usado mais de uma vez  
  
 Uma declaração de tipo ou definição usa um qualificador de tipo (`const`, `volatile`, `signed`, ou `unsigned`) mais de uma vez, causando um erro em compatibilidade ANSI (**/Za**).  
  
 O exemplo a seguir gera C2286:  
  
```  
// C2289.cpp  
// compile with: /Za /c  
volatile volatile int i;   // C2289  
volatile int j;   // OK  
```
