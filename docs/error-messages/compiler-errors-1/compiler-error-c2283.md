---
title: C2283 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C2283
dev_langs:
- C++
helpviewer_keywords:
- C2283
ms.assetid: 8a5b3175-b480-4598-a1f7-0b50504c5caa
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: c6c3a02fcd88f5bb61e6856ad841883a17718d1a
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2283"></a>C2283 de erro do compilador
'Identificador': especificador puro ou abstrato especificador de substituição não permitido no struct sem nome  
  
 Uma função de membro de uma estrutura ou classe sem nome foi declarada com um especificador puro, que não é permitido.  
  
 O exemplo a seguir gera C2283:  
  
```  
// C2283.cpp  
// compile with: /c  
struct {  
   virtual void func() = 0;   // C2283  
};  
struct T {  
   virtual void func() = 0;   // OK  
};  
```
