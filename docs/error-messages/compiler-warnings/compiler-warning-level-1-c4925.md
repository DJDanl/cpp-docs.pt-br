---
title: "Compilador aviso (nível 1) C4925 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-csharp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4925
dev_langs:
- C++
helpviewer_keywords:
- C4925
ms.assetid: a4b206c0-016a-4f28-873a-bb8bb41bad50
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: afa8b609b28b278bb064090ff0e50c97630e0b6d
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4925"></a>Compilador C4925 de aviso (nível 1)
'method': método dispinterface não pode ser chamado de script  
  
 Linguagens de script não é possível criar um VT_BYREF 'parâmetro in', ele só pode criar VT_BYREF 'parâmetros out'.  
  
 Outra maneira de resolver esse aviso é não tornar o parâmetro (na definição e implementação) um tipo de ponteiro.  
  
 O exemplo a seguir gera C4925:  
  
```  
// C4925.cpp  
// compile with: /LD /W1  
#define _ATL_ATTRIBUTES 1  
#include <atlbase.h>  
#include <atlcom.h>  
[ module(name="Test")];  
  
[ dispinterface, uuid("00000000-0000-0000-0000-000000000001") ]  
__interface IDisp {  
   [id(9)] void f([in] int*);  
};  
  
[ coclass, uuid("00000000-0000-0000-0000-000000000002")  ]  
struct CDisp : IDisp {   // C4925  
   void f(int*) {}  
};  
```
