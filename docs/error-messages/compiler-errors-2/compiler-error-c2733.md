---
title: C2733 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2733
dev_langs:
- C++
helpviewer_keywords:
- C2733
ms.assetid: 67f83561-c633-407c-a2ee-f9fd16e165bf
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 22643ad7b1e801f2e4b9ee663c73f0d8fb97562d
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2733"></a>C2733 de erro do compilador
segundo vínculo a C de função sobrecarregada 'function' não permitido  
  
 Mais de uma função sobrecarregada foi declarada com vínculo a C. Ao usar o vínculo a C, somente um formulário de uma função especificada pode ser externo. Como funções sobrecarregadas tem o mesmo nome não decorado, não pode ser usados com programas de C.  
  
 O exemplo a seguir gera C2733:  
  
```  
// C2733.cpp  
extern "C" {  
   void F1(int);  
}  
  
extern "C" {  
   void F1();   // C2733  
   // try the following line instead  
   // void F2();  
}  
```
