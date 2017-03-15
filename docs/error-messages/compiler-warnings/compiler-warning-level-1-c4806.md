---
title: "Compilador aviso (nível 1) C4806 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-csharp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4806
dev_langs:
- C++
helpviewer_keywords:
- C4806
ms.assetid: 79eb74cd-b925-4b5b-84e1-8ae6f33e38b3
caps.latest.revision: 6
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
ms.openlocfilehash: 08748dd2e3e6e18dd9be95ec12712f09db8e1dc0
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4806"></a>Compilador C4806 de aviso (nível 1)
'operation': operação unsafe: nenhum valor do tipo 'type' promovido para o tipo 'type' pode ser igual a constante determinada  
  
 Esta mensagem avisa contra código como `b == 3`, onde `b` tem tipo `bool`. A promoção regras causa `bool` para ser promovido para `int`. Isso é legal, mas nunca pode ser **true**. O exemplo a seguir gera C4806:  
  
```  
// C4806.cpp  
// compile with: /W1  
int main()  
{  
   bool b = true;  
   // try..  
   // int b = true;  
  
   if (b == 3)   // C4806  
   {  
      b = false;  
   }  
}  
```
