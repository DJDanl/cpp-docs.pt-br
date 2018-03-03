---
title: "Compilador (nível 1) de aviso C4822 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4822
dev_langs:
- C++
helpviewer_keywords:
- C4822
ms.assetid: 0f231a30-2eb0-4722-aaa0-e2d19d3e7eea
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 89ed0dc851726b7b543ed2b8e1a319cc2ac6756e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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