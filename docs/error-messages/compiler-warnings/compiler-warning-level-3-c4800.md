---
title: "Aviso (nível 3) do compilador C4800 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4800
dev_langs:
- C++
helpviewer_keywords:
- C4800
ms.assetid: 4f409799-a250-45ed-bb5f-657691b0d9f7
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: ca1217c8a88ad8271d3ee6117470d5f622bb2b33
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-3-c4800"></a>Aviso (nível 3) do compilador C4800
'type': forçar o valor bool 'true' ou 'false' (aviso de desempenho)  
  
 Esse aviso é gerado quando um valor que não é `bool` atribuído ou imposto para o tipo `bool`. Normalmente, essa mensagem é causada pela atribuição `int` variáveis `bool` variáveis onde o `int` variável contém apenas valores **true** e **false**e pode ser declarado novamente como tipo `bool`. Se você não é possível reescrever a expressão para usar o tipo `bool`, em seguida, você pode adicionar "`!=0`" à expressão, que fornece o tipo de expressão `bool`. A expressão para o tipo de conversão `bool` não desabilita o aviso, o que ocorre por design.  
  
 O exemplo a seguir gera C4800:  
  
```  
// C4800.cpp  
// compile with: /W3  
int main() {  
   int i = 0;  
  
   // try..  
   // bool i = 0;  
  
   bool j = i;   // C4800  
   j++;  
}  
```
