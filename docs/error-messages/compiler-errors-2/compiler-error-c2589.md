---
title: C2589 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2589
dev_langs:
- C++
helpviewer_keywords:
- C2589
ms.assetid: 1d7942c7-8a81-4bb4-b272-76a0019e8513
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 5301caf0b52e61000a804e1d73b76343a8b7b2eb
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2589"></a>C2589 de erro do compilador
'Identificador': token inválido no lado direito de ':: '  
  
 Se uma classe, estrutura ou união nome aparece à esquerda do operador de resolução do escopo (dois-pontos duplos), o token da direita deve ser uma classe, estrutura ou membro de união. Caso contrário, qualquer identificador global pode aparecer à direita.  
  
 O operador de resolução do escopo não pode estar sobrecarregado.  
  
 O exemplo a seguir gera C2589:  
  
```  
// C2589.cpp  
void Test(){}  
class A {};  
void operator :: ();   // C2589  
  
int main() {  
   ::Test();  
}  
```
