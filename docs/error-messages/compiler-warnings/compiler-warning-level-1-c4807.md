---
title: "Compilador (nível 1) de aviso C4807 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: C4807
dev_langs: C++
helpviewer_keywords: C4807
ms.assetid: 089c9f87-fd81-402e-9826-66a8ef1ef1fe
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: af604a1a045b9dbef7b3c27f9c7aabd0040aa318
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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