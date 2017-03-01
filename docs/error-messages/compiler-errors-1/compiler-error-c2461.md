---
title: C2461 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2461
dev_langs:
- C++
helpviewer_keywords:
- C2461
ms.assetid: e64ba651-f441-4fdb-b5cb-4209bbbe4db4
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
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 8cdc4c75f9fe2fafb8bf9e42172d6b2d927b365b
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2461"></a>C2461 de erro do compilador
'class': sintaxe do construtor sem parâmetros formais  
  
 O construtor da classe não especifique parâmetros formais. A declaração de um construtor deve especificar um parâmetro formal. (A lista pode ser nula).  
  
 Adicione um par de parênteses depois `class``::``class`.  
  
 O exemplo a seguir gera C2461:  
  
```  
// C2461.cpp  
// compile with: /c  
class C {  
   C::C;   // C2461  
   C::C();   // OK  
};  
```
