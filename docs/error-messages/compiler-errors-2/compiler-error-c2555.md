---
title: C2555 de erro do compilador | Microsoft Docs
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
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 64f66bf80e8e4b6ba7477691cb9675cec347807d
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2555"></a>C2555 de erro do compilador
'class1::function1': função virtual de substituição retornar tipo difere e não é covariante com 'class2::function2'  
  
 Uma função virtual e uma função de substituição derivada tem listas de parâmetro idênticos mas tipos diferentes de retorno. Uma função de substituição em uma classe derivada não pode ser diferentes de uma função virtual em uma classe base somente por seu tipo de retorno.  
  
 Para resolver esse erro, converta o valor de retorno após a função virtual foi chamado.  
  
 Você também poderá ver esse erro se você compilar com /clr.   Por exemplo, o Visual C++ equivalente a declaração c# a seguir:  
  
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
