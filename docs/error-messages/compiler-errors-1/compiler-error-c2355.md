---
title: C2355 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2355
dev_langs:
- C++
helpviewer_keywords:
- C2355
ms.assetid: 0a947881-d61f-4f98-8409-32140f39500b
caps.latest.revision: 10
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 76d274ee94c20502a0ca6f167a9fce1f1dbf9465
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2355"></a>C2355 de erro do compilador
'this': só pode ser referenciada dentro de funções de membro não estático ou inicializadores de membros de dados não estático  
  
 O `this` ponteiro é válido somente em funções de membro não estático ou em inicializadores de membros de dados não estáticos. Esse erro pode resultar quando o escopo de classe de uma definição de função de membro fora da declaração de classe não está qualificado corretamente. O erro também pode ocorrer quando o `this` ponteiro é usado em uma função que não é declarada na classe.  
  
 Para corrigir esse problema, verifique se a definição da função de membro corresponde a uma declaração de função de membro da classe, e que ele não está declarado estático. Para inicializadores de membro de dados, verifique se o membro de dados não está declarado como estático.  
  
 O exemplo a seguir gera C2355 e mostra como corrigi-lo:  
  
```  
// C2355.cpp  
// compile with: /c  
class MyClass {};  
MyClass *p = this;   // C2355  
  
// OK  
class MyClass2 {  
public:  
   void Test() {  
      MyClass2 *p = this;  
   }  
};  
```
