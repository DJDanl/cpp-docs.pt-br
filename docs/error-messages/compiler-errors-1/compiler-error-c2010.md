---
title: C2010 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2010
dev_langs:
- C++
helpviewer_keywords:
- C2010
ms.assetid: 5795ed1d-e206-410b-b7b4-528d125c67b4
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 0863e96dfc137cf262fe1aef977c83dc592b798c
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2010"></a>C2010 de erro do compilador
'character': inesperado na lista de parâmetros formais de macro  
  
 O caractere é usado incorretamente na lista de parâmetros formais de uma definição de macro. Remova o caractere para resolver o erro.  
  
 O exemplo a seguir gera C2010:  
  
```  
// C2010.cpp  
// compile with: /c  
#define mymacro(a|) (2*a)   // C2010  
#define mymacro(a) (2*a)   // OK  
```
