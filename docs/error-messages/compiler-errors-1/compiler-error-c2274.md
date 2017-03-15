---
title: C2274 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2274
dev_langs:
- C++
helpviewer_keywords:
- C2274
ms.assetid: 8e874903-f499-45ef-8291-f821eee4cc1c
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
ms.openlocfilehash: 8881e2f178a8cb52c5d7247f1471cb5eb5d6dbfb
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2274"></a>C2274 de erro do compilador
'type': ilegal como o lado direito de '.' operador  
  
 Um tipo aparece como o operando à direita de um operador de acesso de membro (.).  
  
 Esse erro pode ser causado pela tentativa de acessar uma conversão de tipo definido pelo usuário. Use a palavra-chave `operator` entre o período e `type`.  
  
 O exemplo a seguir gera C2286:  
  
```  
// C2274.cpp  
struct MyClass {  
   operator int() {  
      return 0;  
   }  
};  
  
int main() {  
   MyClass ClassName;  
   int i = ClassName.int();   // C2274  
   int j = ClassName.operator int();   // OK  
}  
```
