---
title: C2194 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C2194
dev_langs: C++
helpviewer_keywords: C2194
ms.assetid: df6e631c-0062-4844-9088-4cc7a0ff879f
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: b8c1810653d182eece917628f9861e5618b60fe6
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2194"></a>C2194 de erro do compilador
'Identificador': é um segmento de texto  
  
 O `data_seg` pragma usa um nome de segmento usado com `code_seg`.  
  
 O exemplo a seguir gera C2194:  
  
```  
// C2194.cpp  
// compile with: /c  
#pragma code_seg("MYCODE")  
#pragma data_seg("MYCODE")   // C2194  
#pragma data_seg("MYCODE2")   // OK  
```