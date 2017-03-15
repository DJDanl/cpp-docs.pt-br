---
title: "Compilador aviso (nível 4) C4460 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4460
dev_langs:
- C++
helpviewer_keywords:
- C4460
ms.assetid: c97ac1c9-598d-479e-bfff-c993690c4f3d
caps.latest.revision: 13
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: e08453025ca9d12dc79dd0d592d8dd17a32de102
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-4-c4460"></a>Compilador C4460 de aviso (nível 4)
WinRT ou CLR operador 'operator', parâmetro tiver passado por referência. WinRT ou CLR 'operador' tem uma semântica diferente do operador C++ 'operator', você pretendia passar por valor?  
  
 Um valor pode ser transmitido por referência a um operador definido pelo usuário em tempo de execução do Windows ou CLR. Se o valor for alterado dentro da função, observe que o valor retornado após a chamada de função será atribuída o valor de retorno da função. No C++ padrão, o valor alterado será refletido após a chamada de função.  
  
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
