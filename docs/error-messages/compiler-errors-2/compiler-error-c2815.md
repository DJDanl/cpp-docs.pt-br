---
title: C2815 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2815
dev_langs:
- C++
helpviewer_keywords:
- C2815
ms.assetid: d0256fd6-0721-4c99-b03c-52d96e77a613
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
ms.sourcegitcommit: 65e7a7bd56096fbeec61b651ab494d82edef9c90
ms.openlocfilehash: 129ad6a0359fbee402b39c5e7ff498602e97479d
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2815"></a>C2815 de erro do compilador
'operador delete': o primeiro parâmetro formal deve ser ' void *', mas 'param' foi usada  
  
 Qualquer definidos pelo usuário [operador delete](../../standard-library/new-operators.md#operator_delete) função deve levar um primeiro parâmetro formal do tipo `void *`.  
  
 O exemplo a seguir gera C2815:  
  
```  
// C2815.cpp  
// compile with: /c  
class CMyClass {  
public:  
   void mf1(int *a);  
   void operator delete(CMyClass *);   // C2815  
   void operator delete(void *);   
};  
```
