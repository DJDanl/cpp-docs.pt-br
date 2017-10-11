---
title: C2005 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2005
dev_langs:
- C++
helpviewer_keywords:
- C2005
ms.assetid: 090530ed-e0ec-4358-833a-ca24260e7ffe
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: f3fdca572b0ee94d97272db445a35e78b1ce37ea
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2005"></a>C2005 de erro do compilador
\#linha esperado um número de linha, encontrado 'token'  
  
 O `#line` diretiva deve ser seguida por um número de linha.  
  
 O exemplo a seguir gera C2005:  
  
```  
// C2005.cpp  
int main() {  
   int i = 0;  
   #line i   // C2005  
}  
```  
  
 Possível solução:  
  
```  
// C2005b.cpp  
int main() {  
   int i = 0;  
   #line 0  
}  
```
