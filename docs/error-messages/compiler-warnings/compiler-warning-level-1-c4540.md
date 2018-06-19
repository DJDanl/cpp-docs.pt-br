---
title: Compilador (nível 1) de aviso C4540 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4540
dev_langs:
- C++
helpviewer_keywords:
- C4540
ms.assetid: 8085e748-5f4d-43c2-b06d-eaf794edbf72
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3939ad2bbcba1ab3b492d83bdbb8f7076c2c5f2b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33283056"
---
# <a name="compiler-warning-level-1-c4540"></a>Compilador C4540 de aviso (nível 1)
dynamic_cast usado para converter para base inacessível ou ambígua; teste de tempo de execução falhará ('type1' em 'type2')  
  
 Você usou `dynamic_cast` para converter de um tipo para outro. O compilador determinado que a conversão sempre falhará (retornar **nulo**) como uma classe base é inacessível (`private`, por exemplo) ou ambíguo (aparece mais de uma vez na hierarquia de classe, por exemplo).  
  
 O exemplo a seguir mostra um exemplo deste aviso. Classe **B** é derivado da classe **um**. O programa usa `dynamic_cast` converter de classe **B** (a classe derivada) à classe **um**, que sempre irá falhar porque classe **B** é `private` e, portanto, inacessível. Alterando o acesso de **um** para **pública** resolverá o aviso.  
  
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