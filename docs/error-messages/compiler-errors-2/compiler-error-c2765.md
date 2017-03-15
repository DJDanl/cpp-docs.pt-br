---
title: C2765 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2765
dev_langs:
- C++
helpviewer_keywords:
- C2765
ms.assetid: 47ad86f3-a7e0-47ad-85ff-0f5534458cb9
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
ms.openlocfilehash: 0641a441d68dc411c344861af984dd6be3cff9f3
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2765"></a>C2765 de erro do compilador
'function': uma especialização explícita de um modelo de função não pode ter argumentos padrão  
  
 Argumentos padrão não são permitidos em uma especialização explícita de um modelo de função. Para obter mais informações, consulte [especialização explícita de modelos de função](../../cpp/explicit-specialization-of-function-templates.md).  
  
 O exemplo a seguir gera C2765:  
  
```  
// C2765.cpp  
template<class T> void f(T t) {};  
  
template<> void f<char>(char c = 'a') {}   // C2765  
// try the following line instead  
// template<> void f<char>(char c) {}  
```
