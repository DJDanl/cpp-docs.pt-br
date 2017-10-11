---
title: C3126 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3126
dev_langs:
- C++
helpviewer_keywords:
- C3126
ms.assetid: e72658a3-5d85-4a31-89a4-dbc3d475973d
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 5b12b0ec06d45c68427856ab226e2ea09fc05920
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3126"></a>C3126 de erro do compilador
não é possível definir uma união 'union' dentro de 'type' do tipo gerenciado  
  
 Uma união não pode ser definida dentro de um tipo gerenciado.  
  
 O exemplo a seguir gera C3126:  
  
```  
// C3126_2.cpp  
// compile with: /clr /c  
ref class Test  
{  
   union x  
   {   // C3126  
      int a;  
      int b;  
   };  
};  
```  

