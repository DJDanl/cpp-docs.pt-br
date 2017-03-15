---
title: C2723 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2723
dev_langs:
- C++
helpviewer_keywords:
- C2723
ms.assetid: 86925601-2297-4cfd-94e2-2caf27c474c4
caps.latest.revision: 9
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
ms.openlocfilehash: 3619e1e4a127bad01d2668a6b1678edd55f020ce
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2723"></a>C2723 de erro do compilador
'function': especificador 'especificador' inválida na definição de função  
  
 O especificador não pode aparecer com uma definição de função fora de uma declaração de classe. O `virtual` especificador pode ser especificado somente em uma declaração de função de membro dentro de uma declaração de classe.  
  
 O exemplo a seguir gera C2723 e mostra como corrigi-lo:  
  
```  
// C2723.cpp  
struct X {  
   virtual void f();  
   virtual void g();  
};  
  
virtual void X::f() {}   // C2723  
  
// try the following line instead  
void X::g() {}  
```
