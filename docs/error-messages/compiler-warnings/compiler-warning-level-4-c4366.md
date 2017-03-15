---
title: "Compilador aviso (nível 4) C4366 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4366
dev_langs:
- C++
helpviewer_keywords:
- C4366
ms.assetid: 65d2942f-3741-42f4-adf2-4920d5a055ca
caps.latest.revision: 14
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
ms.openlocfilehash: 70729752ad878a46654f05c1edc84d0c8201a127
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-4-c4366"></a>Compilador C4366 de aviso (nível 4)
O resultado do operador unário 'operator' pode ser não alinhado  
  
 Se um membro de estrutura pode nunca ser não alinhado devido a remessa, o compilador irá avisá-quando a que o endereço do membro é atribuído a um ponteiro alinhado. Por padrão, todos os ponteiros são alinhados.  
  
 Para resolver C4366, alterar o alinhamento da estrutura ou declare o ponteiro com o [unaligned](../../cpp/unaligned.md) palavra-chave.  
  
 Para obter mais informações, consulte unaligned e [pack](../../preprocessor/pack.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4366.  
  
```  
// C4366.cpp  
// compile with: /W4 /c  
// processor: IPF x64  
#pragma pack(1)  
struct X {  
   short s1;  
   int s2;  
};  
  
int main() {  
   X x;  
   short * ps1 = &x.s1;   // OK  
   int * ps2 = &x.s2;   // C4366  
}  
```
