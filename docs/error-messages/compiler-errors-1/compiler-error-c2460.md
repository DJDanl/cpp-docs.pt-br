---
title: C2460 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2460
dev_langs:
- C++
helpviewer_keywords:
- C2460
ms.assetid: d969fca9-3ac5-4e4e-88fc-df05510e2093
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
ms.openlocfilehash: b7ca5a715feca737635c9feb538de7348eb0feb9
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2460"></a>C2460 de erro do compilador
'identifier1': usa 'identifier2', que está sendo definida  
  
 Uma classe ou estrutura (`identifier2`) é declarada como um membro de si mesmo (`identifier1`). Não são permitidas definições de recursiva de classes e estruturas.  
  
 O exemplo a seguir gera C2460:  
  
```  
// C2460.cpp  
class C {  
   C aC;    // C2460  
};  
```  
  
 Em vez disso, use uma referência de ponteiro na classe.  
  
```  
// C2460.cpp  
class C {  
   C * aC;    // OK  
};  
```
