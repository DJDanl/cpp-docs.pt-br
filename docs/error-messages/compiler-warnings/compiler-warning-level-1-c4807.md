---
title: "Compilador aviso (nível 1) C4807 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4807
dev_langs:
- C++
helpviewer_keywords:
- C4807
ms.assetid: 089c9f87-fd81-402e-9826-66a8ef1ef1fe
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: a8eac43fd6f8f94567e3317f0d246638b61ca5cc
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4807"></a>Compilador C4807 de aviso (nível 1)
'operation': unsafe combinação do tipo 'type' e junte assinado do tipo 'type'  
  
 Esse aviso é gerado ao comparar um campo de bits assinado de um bit para um `bool` variável. Como um campo de bits assinado, um bit só pode conter os valores de -1 ou 0, é perigoso compará-la para `bool`. Nenhum aviso é gerado sobre a combinação de `bool` e não assinados, um bit campos de bits desde que sejam idênticos ao `bool` e só podem ter 0 ou 1.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4807:  
  
```  
// C4807.cpp  
// compile with: /W1  
typedef struct bitfield {  
   signed mybit : 1;  
} mybitfield;  
  
int main() {  
   mybitfield bf;  
   bool b = true;  
  
   // try..  
   // int b = true;  
  
   bf.mybit = -1;  
   if (b == bf.mybit) {   // C4807  
      b = false;  
   }  
}  
```
