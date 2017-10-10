---
title: C2800 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2800
dev_langs:
- C++
helpviewer_keywords:
- C2800
ms.assetid: a2f1a590-9fe6-44cb-ad09-b4505ef47c6a
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 330b859b4b24f741388be716fb464fc33c3abaa3
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2800"></a>C2800 de erro do compilador
'operator operador' não pode ser sobrecarregado  
  
 Os operadores a seguir não podem ser sobrecarregados: acesso de membro de classe (`.`), ponteiro para membro (`.*`), definir o escopo de resolução (`::`), a expressão condicional (`? :`), e `sizeof`.  
  
 O exemplo a seguir gera C2800:  
  
```  
// C2800.cpp  
// compile with: /c  
class C {  
   operator:: ();   // C2800  
};  
```
