---
title: C2355 de erro do compilador | Documentos do Microsoft
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 84bcd1b30bd5009d3f59c48b7daedbb09a529b53
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2355"></a>C2355 de erro do compilador
'this': só pode ser referenciada dentro de funções de membro não estático ou inicializadores de membro de dados não estáticos  
  
 O `this` ponteiro é válido somente dentro de funções de membro não estático ou em inicializadores de membro de dados não estáticos. Esse erro pode resultar quando o escopo de classe de uma definição de função de membro fora da declaração de classe não é qualificado corretamente. O erro também pode ocorrer quando o `this` ponteiro é usado em uma função que não é declarada na classe.  
  
 Para corrigir esse problema, certifique-se de uma declaração de função de membro na classe coincide com a definição da função de membro e que ele não está declarado como estático. Para inicializadores de membro de dados, verifique se o membro de dados não está declarado como estático.  
  
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
