---
title: Compilador (nível 1) de aviso C4807 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4807
dev_langs:
- C++
helpviewer_keywords:
- C4807
ms.assetid: 089c9f87-fd81-402e-9826-66a8ef1ef1fe
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 22710ee2b46a270e46aed7c043d4d988fcfaed62
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33282357"
---
# <a name="compiler-warning-level-1-c4807"></a>Compilador C4807 de aviso (nível 1)
'operação de ': mistura não segura de tipo 'type' e o campo de bits assinado do tipo 'type'  
  
 Esse aviso é gerado durante a comparação de um campo de bits assinado de um bit para um `bool` variável. Como um campo de bits de um bit, assinado pode conter somente os valores de -1 ou 0, é perigoso compará-la para `bool`. Nenhum aviso é gerado sobre misturar `bool` e um bit, sem sinal campos de bits desde que eles são idênticos a `bool` e só podem ter 0 ou 1.  
  
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