---
title: "Compilador aviso (nível 1) C4540 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4540
dev_langs:
- C++
helpviewer_keywords:
- C4540
ms.assetid: 8085e748-5f4d-43c2-b06d-eaf794edbf72
caps.latest.revision: 7
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
ms.openlocfilehash: d7893c9d67b517d85fd1eb7f35f48188a30fd75a
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4540"></a>Compilador C4540 de aviso (nível 1)
dynamic_cast usada para converter a base inacessível ou ambígua; tempo de execução de teste falhará ('type1' em 'type2')  
  
 Você usou `dynamic_cast` para converter de um tipo para outro. O compilador determinou que a conversão falhará sempre (retornar **nulo**) porque uma classe base está inacessível (`private`, por exemplo) ou ambíguo (aparece mais de uma vez na hierarquia de classe, por exemplo).  
  
 O exemplo a seguir mostra um exemplo desse aviso. Classe **B** é derivada da classe **um**. O programa usa `dynamic_cast` para conversão de classe **B** (a classe derivada) à classe **um**, que sempre falhará porque classe **B** é `private` e portanto inacessíveis. Alterando o acesso de **um** para **pública** resolverá o aviso.  
  
```  
// C4540.cpp  
// compile with: /W1  
  
struct A {   
   virtual void g() {}  
};  
  
struct B : private A {  
   virtual void g() {}  
};  
  
int main() {  
   B b;  
   A * ap = dynamic_cast<A*>(&b);   // C4540  
}  
```
