---
title: "Compilador (nível 4) de aviso C4460 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4460
dev_langs:
- C++
helpviewer_keywords:
- C4460
ms.assetid: c97ac1c9-598d-479e-bfff-c993690c4f3d
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: aa925e8d0ef7779f21485cb154b9b9209ce2388e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-4-c4460"></a>Compilador C4460 de aviso (nível 4)
WinRT ou CLR operador 'operator', parâmetro tiver passado por referência. Operador 'operator WinRT ou CLR' tem semânticas diferentes do operador de C++ 'operator', você pretendia passar por valor?  
  
 Um valor pode ser transmitido por referência a um operador definido pelo usuário em tempo de execução do Windows ou CLR. Se o valor é alterado dentro da função, observe que o valor retornado depois que a chamada de função será atribuída o valor de retorno da função. Em C++ padrão, o valor alterado será refletido após a chamada de função.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4460 e mostra como corrigi-lo.  
  
```  
// C4460.cpp  
// compile with: /W4 /clr   
#include <stdio.h>  
  
public value struct V {  
   static V operator ++(V& me) {   // C4460  
   // try the following line instead  
   // static V operator ++(V me) {  
  
      printf_s(__FUNCSIG__ " called\n");  
      V tmp = me;  
      me.m_i++;  
      return tmp;  
   }  
   int m_i;  
};  
  
int main() {  
   V v;  
   v.m_i = 0;  
  
   printf_s("%d\n", v.m_i);   // Should print 0  
   v++;   // Translates to "v = V::operator ++(v)"  
   printf_s("%d\n", v.m_i);   // will print 0, hence the warning  
}  
```