---
title: Compilador (nível 1) de aviso C4822 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4822
dev_langs:
- C++
helpviewer_keywords:
- C4822
ms.assetid: 0f231a30-2eb0-4722-aaa0-e2d19d3e7eea
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d9491d522c65eba3599c3618d510c57b55682876
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33283007"
---
# <a name="compiler-warning-level-1-c4822"></a>Compilador C4822 de aviso (nível 1)
'member': função de membro de classe local não tem um corpo  
  
 Uma função de membro de classe local foi declarada mas não definida na classe. Para usar uma função de membro de classe local, você deve defini-lo na classe. Você não pode declará-la na classe e defini-lo fora da classe.  
  
 Qualquer definição de fora da classe para uma função de membro de classe local será um erro.  
  
 O exemplo a seguir gera C4822:  
  
```  
// C4822.cpp  
// compile with: /W1  
int main() {  
   struct C {  
      void func1(int);   // C4822  
      // try the following line instead  
      // void func1(int){}  
  };  
}  
```