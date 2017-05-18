---
title: C2555 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2555
dev_langs:
- C++
helpviewer_keywords:
- C2555
ms.assetid: 5e49ebb8-7c90-457a-aa12-7ca7ab6574b2
caps.latest.revision: 8
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 1e63c3b4a57565f3623b6bd249be21a4a44bc1e4
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2555"></a>C2555 de erro do compilador
'class1::function1': substituindo a função virtual retornar o tipo é diferente e não é covariante de 'class2::function2'  
  
 Uma função virtual e uma função de substituição derivada têm listas de parâmetros idênticos mas diferentes tipos de retorno. Uma função de substituição em uma classe derivada não pode ser diferente de uma função virtual em uma classe base apenas por seu tipo de retorno.  
  
 Para resolver esse erro, converta o valor de retorno depois que a função virtual é chamada.  
  
 Você também poderá ver esse erro se você compilar com /clr.   Por exemplo, o Visual C++ equivalente para a declaração c# a seguir:  
  
```  
Guid[] CheckSources(Guid sourceID, Guid[] carouselIDs);  
```  
  
 is  
  
```  
Guid CheckSources(Guid sourceID, Guid carouselIDs[]) [];  
```  
  
 Para obter mais informações sobre C2555, consulte o artigo da Base de dados de Conhecimento Q240862.  
  
 O exemplo a seguir gera C2555:  
  
```  
// C2555.cpp  
// compile with: /c  
struct X {  
   virtual void func();  
};  
struct Y : X {  
   char func();  // C2555  
   void func2();   // OK  
};  
```
