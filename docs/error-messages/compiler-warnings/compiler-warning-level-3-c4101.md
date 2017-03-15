---
title: "Compilador aviso (nível 3) C4101 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4101
dev_langs:
- C++
helpviewer_keywords:
- C4101
ms.assetid: d98563cd-9dce-4aae-8f12-bd552a4ea677
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
ms.openlocfilehash: 068bec1a99af6ff934cd8afdd9fe6ca8ec31a0a8
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-3-c4101"></a>Compilador C4101 de aviso (nível 3)
'identifier': variável local sem referência  
  
 A variável local nunca é usada. Esse aviso ocorrerá na situação óbvio:  
  
```  
// C4101a.cpp  
// compile with: /W3  
int main() {  
int i;   // C4101  
}  
```  
  
 No entanto, esse aviso também ocorrerá ao chamar um **estático** função de membro por meio de uma instância da classe:  
  
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
  
 Nessa situação, o compilador usa informações sobre `si` para acessar o **estático** função, mas a instância da classe não é necessário chamar o **estático** função; portanto, o aviso. Para resolver esse aviso, você pode:  
  
-   Adicione um construtor, em que o compilador poderia usar a instância do `si` na chamada para `func`.  
  
-   Remover o **estático** palavra-chave da definição do `func`.  
  
-   Chamar o **estático** função explicitamente: `int y = S::func();`.
