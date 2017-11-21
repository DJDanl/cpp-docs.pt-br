---
title: "Compilador aviso (nível 3) C4101 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4101
dev_langs: C++
helpviewer_keywords: C4101
ms.assetid: d98563cd-9dce-4aae-8f12-bd552a4ea677
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: edd99402978a41a115afa2d96f86abd63d72afa4
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-warning-level-3-c4101"></a>Compilador C4101 de aviso (nível 3)
'Identificador': variável local não referenciada  
  
 A variável local nunca é usada. Esse aviso ocorrerá na situação óbvia:  
  
```  
// C4101a.cpp  
// compile with: /W3  
int main() {  
int i;   // C4101  
}  
```  
  
 No entanto, esse aviso também será exibido ao chamar um **estático** função de membro por meio de uma instância da classe:  
  
```  
// C4101b.cpp  
// compile with:  /W3  
struct S {  
   static int func()  
   {  
      return 1;  
   }  
};  
  
int main() {  
   S si;   // C4101, si is never used  
   int y = si.func();  
   return y;  
}  
```  
  
 Nessa situação, o compilador usa informações sobre `si` para acessar o **estático** função, mas a instância da classe não é necessária para chamar o **estático** função; portanto, o aviso. Para resolver este aviso, você pode:  
  
-   Adicione um construtor, em que o compilador usará a instância de `si` na chamada para `func`.  
  
-   Remover o **estático** palavra-chave na definição de `func`.  
  
-   Chamar o **estático** função explicitamente: `int y = S::func();`.