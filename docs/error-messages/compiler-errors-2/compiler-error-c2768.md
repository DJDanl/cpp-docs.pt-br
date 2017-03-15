---
title: C2768 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2768
dev_langs:
- C++
helpviewer_keywords:
- C2768
ms.assetid: a7f6047a-6a80-4737-ad5c-c12868639fb5
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
ms.openlocfilehash: 18abc1897365e85e914f5c4432af07880477bd5b
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2768"></a>C2768 de erro do compilador
'function': uso inválido de argumentos de modelo explícitos  
  
 O compilador não pôde determinar se uma definição de função deveria para ser uma especialização explícita de um modelo de função ou se a definição da função deveria ser para uma nova função.  
  
 Esse erro foi introduzido no Visual Studio .NET 2003, como parte dos aprimoramentos de conformidade do compilador.  
  
 O exemplo a seguir gera C2768:  
  
```  
// C2768.cpp  
template<typename T>  
void f(T) {}  
  
void f<int>(int) {}   // C2768  
  
// an explicit specialization  
template<>  
void f<int>(int) {}   
  
// global nontemplate function overload  
void f(int) {}  
```
