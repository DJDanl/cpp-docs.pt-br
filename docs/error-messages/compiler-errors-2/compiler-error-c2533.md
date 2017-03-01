---
title: C2533 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2533
dev_langs:
- C++
helpviewer_keywords:
- C2533
ms.assetid: 5b335652-076c-4824-87c8-a741f64a3ce0
caps.latest.revision: 11
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
ms.openlocfilehash: b297f25128d7ef67455ff68c9a60e3141550e737
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2533"></a>C2533 de erro do compilador
'identifier': os construtores não permitidos um tipo de retorno  
  
 Um construtor não pode ter um tipo de retorno (nem mesmo um `void` tipo de retorno).  
  
 Uma origem comum desse erro é um ponto e vírgula ausente entre o fim de uma definição de classe e a primeira implementação do construtor. O compilador considera a classe como uma definição do tipo de retorno da função de construtor e gera C2533.  
  
 O exemplo a seguir gera C2533 e mostra como corrigi-lo:  
  
```  
// C2533.cpp  
// compile with: /c  
class X {  
public:  
   X();     
};  
  
int X::X() {}   // C2533 - constructor return type not allowed  
X::X() {}   // OK - fix by using no return type  
```
