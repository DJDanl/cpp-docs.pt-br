---
title: "Compilador aviso (nível 4) C4913 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4913
dev_langs:
- C++
helpviewer_keywords:
- C4913
ms.assetid: b94aa52e-6029-4170-9134-017714931546
caps.latest.revision: 5
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: d0d1551defba0f2bb279527f2ce5dded793b6005
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-4-c4913"></a>Compilador C4913 de aviso (nível 4)
**usuário definido pelo operador binário ',' existe, mas nenhuma sobrecarga pode converter todos os operandos, o operador binário interna padrão ',' usado**  
  
 Uma chamada para o operador vírgula interno ocorreu em um programa que tinha também um operador de vírgula sobrecarregados; não especificou uma conversão ideias podem ter ocorrido.  
  
 O exemplo de código a seguir gera C4913:  
  
```  
// C4913.cpp  
// compile with: /W4  
struct A  
{  
};  
  
struct S  
{  
};  
  
struct B  
{  
   // B() { }  
   // B(S &s) { s; }  
};  
  
B operator , (A a, B b)     
{  
   a;  
   return b;  
}  
  
int main()  
{  
   A a;  
   B b;  
   S s;  
  
   a, b;   // OK calls user defined operator  
   a, s;   // C4913 uses builtin comma operator  
           // uncomment the conversion code in B to resolve.  
}  
```
