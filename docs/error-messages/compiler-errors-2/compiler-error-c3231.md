---
title: C3231 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3231
dev_langs:
- C++
helpviewer_keywords:
- C3231
ms.assetid: fe5dc352-e634-45fa-9534-3da176294c98
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
ms.openlocfilehash: 666234b53842a009a6b33bcd81f0b19deb2e5629
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3231"></a>C3231 de erro do compilador
'arg': argumento de tipo de modelo não é possível usar um parâmetro de tipo genérico  
  
 Modelos são instanciados em tempo de compilação, mas genéricos são instanciados em tempo de execução. Portanto, não é possível gerar código genérico que pode chamar o modelo porque o modelo não pode ser instanciado em tempo de execução quando o tipo genérico é conhecido por último.  
  
 O exemplo a seguir gera C3231:  
  
```  
// C3231.cpp  
// compile with: /clr /LD  
template <class T> class A;  
  
generic <class T>  
ref class C {  
   void f() {  
      A<T> a;   // C3231  
   }  
};  
```
