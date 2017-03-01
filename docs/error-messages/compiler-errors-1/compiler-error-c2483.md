---
title: C2483 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2483
dev_langs:
- C++
helpviewer_keywords:
- C2483
ms.assetid: 5762b325-914b-442d-a604-e4617ba04038
caps.latest.revision: 10
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
ms.openlocfilehash: 391be3c032bc48a20304befec1fb61cbe14e7f60
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2483"></a>C2483 de erro do compilador
'identifier': objeto de construtor ou destruidor não pode ser declarado 'thread'  
  
 Variáveis declaradas com o `thread` atributo não pode ser inicializado com um construtor ou outra expressão que requer avaliação do tempo de execução. Uma expressão estática é necessário para inicializar `thread` dados.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C2483.  
  
```  
// C2483.cpp  
// compile with: /c  
__declspec(thread) struct A {  
   A(){}  
   ~A(){}  
} aa;   // C2483 error  
  
__declspec(thread) struct B {} b;   // OK  
```  
  
## <a name="see-also"></a>Consulte também  
 [thread](../../cpp/thread.md)
