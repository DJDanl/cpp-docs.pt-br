---
title: "Compilador (nível 1) de aviso C4144 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4144
dev_langs: C++
helpviewer_keywords: C4144
ms.assetid: a37b445d-dbc6-43b4-8d95-ffd0e4225464
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: d085cfdb4b84f6972dd42d83a94731ff56bfc2ed
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-1-c4144"></a>Compilador C4144 de aviso (nível 1)
'expression': expressão relacional como expressão de switch  
  
 Expressão relacional especificada foi usada como expressão de controle de um [alternar](../../cpp/switch-statement-cpp.md) instrução. As instruções casos associadas terá valores booleanos. O exemplo a seguir gera C4144:  
  
```  
// C4144.cpp  
// compile with: /W1  
int main()  
{  
   int i = 0;  
   switch(!i) {   // C4144, remove the ! to resolve  
      case 1:  
         break;  
      default:  
         break;  
   }  
}  
```