---
title: C2246 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C2246
dev_langs:
- C++
helpviewer_keywords:
- C2246
ms.assetid: 4f3e4f83-21f3-4256-af96-43e0bb060311
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: ce194e9f08655e0acc7d1dab53f2a2392cceb4f4
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2246"></a>C2246 de erro do compilador
'Identificador': membro de dados static inválido em classe definida localmente  
  
 Um membro de uma classe, estrutura ou união com escopo local é declarado como `static`.  
  
 O exemplo a seguir gera C2246:  
  
```  
// C2246.cpp  
// compile with: /c  
void func( void ) {  
   class A { static int i; };   // C2246  i is local to func  
   static int j;   // OK  
};  
```
