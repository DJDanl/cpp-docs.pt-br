---
title: "Compilador aviso (nível 1) C4717 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4717
dev_langs:
- C++
helpviewer_keywords:
- C4717
ms.assetid: 5ef3c6c7-8599-4714-a973-0f5b69cdab3c
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
ms.openlocfilehash: 9e678379083d091d980cfe647f17e8aceb892c14
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4717"></a>Compilador C4717 de aviso (nível 1)
'function': recursiva em todos os caminhos de controle, função fará com que o estouro de pilha do tempo de execução  
  
 Cada caminho através de uma função contém uma chamada para a função. Como não há nenhuma maneira de sair de função sem primeiro chamar próprio recursivamente, a função nunca será encerrado.  
  
 O exemplo a seguir gera C4717:  
  
```  
// C4717.cpp  
// compile with: /W1 /c  
// C4717 expected  
int func(int x) {  
   if (x > 1)  
      return func(x - 1); // recursive call  
   else {  
      int y = func(0) + 1; // recursive call  
      return y;  
   }  
}  
  
int main(){  
   func(1);  
}  
```
