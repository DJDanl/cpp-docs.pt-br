---
title: "Compilador (nível 2) do aviso C4756 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4756
dev_langs: C++
helpviewer_keywords: C4756
ms.assetid: 5a16df83-6b82-4619-83bd-319af4ef1d1d
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 8fe10174d8d4cb0e8b982c5da205c290fc1d53e7
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-2-c4756"></a>Compilador C4756 de aviso (nível 2)
Estouro em aritmética de constante  
  
 O compilador gerou uma exceção ao executar a aritmética de constante durante a compilação.  
  
 O exemplo a seguir gera C4756:  
  
```  
// C4756.cpp  
// compile with: /W2 /Od  
int main()  
{  
   float f = 1e100+1e100;   // C4756  
}  
```