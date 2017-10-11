---
title: C2394 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2394
dev_langs:
- C++
helpviewer_keywords:
- C2394
ms.assetid: 653fa9a0-29b3-48aa-bc01-82f98f717a2b
caps.latest.revision: 12
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: c716a3562a9f99ef0094d8ca7ba5fdf2d11f15f0
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2394"></a>C2394 de erro do compilador
'your_type::operator'op' ": CLR ou WinRToperator não é válido. Pelo menos um parâmetro deve ser dos seguintes tipos: ' t ^', ' t ^ %', ' t ^ &', onde T = 'your_type'  
  
 Um operador em um tempo de execução do Windows ou um tipo gerenciado não tem pelo menos um parâmetro cujo tipo é o mesmo que o tipo do valor de retorno do operador.  
  
 O exemplo a seguir gera C2394:  
  
```  
// C2394.cpp  
// compile with: /clr /c  
ref struct Y {  
   static Y^ operator -(int i, char c);   // C2394  
  
   // OK  
   static Y^ operator -(Y^ hY, char c);  
   // or  
   static Y^ operator -(int i, Y^& rhY);  
};  
```
