---
title: C3536 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3536
dev_langs:
- C++
helpviewer_keywords:
- C3536
ms.assetid: 8d866075-866b-49eb-9979-ee27b308f7e3
caps.latest.revision: 6
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
ms.openlocfilehash: 6ae6728026560e1c88cefd32e987eed1a954e3e7
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3536"></a>C3536 de erro do compilador
'symbol': não pode ser usada antes de ser inicializado  
  
 O símbolo indicado não pode ser usado antes de ser inicializado. Na prática, isso significa que uma variável não pode ser usada para se inicializar.  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
1.  Não inicialize uma variável com ele próprio.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir produz C3536 porque cada variável é inicializada com ele próprio.  
  
```  
// C3536.cpp  
// Compile with /Zc:auto  
int main()  
{  
   auto a = a;     //C3536  
   auto b = &b;    //C3536  
   auto c = c + 1; //C3536  
   auto* d = &d;   //C3536  
   auto& e = e;    //C3536  
   return 0;  
};  
```  
  
## <a name="see-also"></a>Consulte também  
 [palavra-chave auto](../../cpp/auto-keyword.md)
