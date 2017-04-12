---
title: "Compilador aviso (nível 1) C4822 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4822
dev_langs:
- C++
helpviewer_keywords:
- C4822
ms.assetid: 0f231a30-2eb0-4722-aaa0-e2d19d3e7eea
caps.latest.revision: 7
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
ms.openlocfilehash: a7b3b5c848bbf0dd34fb30d3ce636285a3e12ae3
ms.lasthandoff: 02/25/2017

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
