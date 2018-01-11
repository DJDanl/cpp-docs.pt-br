---
title: "Compilador (nível 1) de aviso C4319 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4319
dev_langs: C++
helpviewer_keywords: C4319
ms.assetid: 1fac8048-9bd6-4552-a21c-192c67772bb9
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: b7008b0f618048f5a4538a7aff55f03bab3d406d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-1-c4319"></a>Compilador C4319 de aviso (nível 1)
'operator': zero estendendo 'type' para 'type' de tamanho maior  
  
 O resultado da ~ operador (complemento bit a bit) é não assinado e, em seguida, estendido de zero quando ele é convertido em um tipo maior.  
  
 No exemplo a seguir, ~(a-1) é avaliada como uma expressão longo não assinada de 32 bits e, em seguida, convertida em 64 bits pela extensão de zero. Isso pode levar a resultados de operação inesperado.  
  
```  
// C4319.cpp  
// compile with: cl /W4 C4319.cpp  
int main() {  
   unsigned long a = 0;  
   unsigned long long q = 42;  
   q = q & ~(a - 1);    // C4319 expected  
}  
```