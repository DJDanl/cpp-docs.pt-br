---
title: "Compilador aviso (nível 1) C4405 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4405
dev_langs:
- C++
helpviewer_keywords:
- C4405
ms.assetid: 155c64d6-58ae-4455-b61f-ccd711c5da96
caps.latest.revision: 6
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
ms.openlocfilehash: 4eece5fb4af37551459c67cf55a4453ce81a6fb0
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4405"></a>Compilador C4405 de aviso (nível 1)
'identifier': identificador é a palavra reservada  
  
 Uma palavra reservada para assembly embutido é usada como um nome de variável. Isso pode causar resultados imprevisíveis. Para corrigir esse aviso, evite nomes de variáveis com palavras reservadas para assembly embutido. O exemplo a seguir gera C4405:  
  
```  
// C4405.cpp  
// compile with: /W1  
// processor: x86  
void func1() {  
   int mov = 0, i = 0;  
   _asm {  
      mov mov, 0;   // C4405  
      // instead, try ..  
      // mov i, 0;  
   }  
}  
  
int main() {  
}  
```
