---
title: "Compilador aviso (nível 4) C4239 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4239
dev_langs:
- C++
helpviewer_keywords:
- C4239
ms.assetid: a23dc16a-649e-4870-9a24-275de1584fcd
caps.latest.revision: 10
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
ms.openlocfilehash: fac281bc4f4c0bb35dca0d2379b164c93bc5e241
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-4-c4239"></a>Compilador C4239 de aviso (nível 4)
extensão não padrão usada: 'token': conversão de 'type' para 'type'  
  
 Essa conversão de tipo não é permitido pelo padrão C++, mas é permitido aqui como uma extensão. Esse aviso é sempre seguido pelo menos uma linha de explicação que descreve a regra do idioma que está sendo violada.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4239.  
  
```  
// C4239.cpp  
// compile with: /W4 /c  
struct C {  
   C() {}  
};  
  
void func(void) {  
   C & rC = C();   // C4239  
   const C & rC2 = C();   // OK  
   rC2;  
}  
```  
  
## <a name="example"></a>Exemplo  
 Conversão de tipo integral em tipo enum não é estritamente permitido.  
  
 O exemplo a seguir gera C4239.  
  
```  
// C4239b.cpp  
// compile with: /W4 /c  
enum E { value };   
struct S {   
   E e : 2;   
} s = { 5 };   // C4239   
// try the following line instead  
// } s = { (E)5 };  
```
