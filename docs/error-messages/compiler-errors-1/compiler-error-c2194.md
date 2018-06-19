---
title: C2194 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2194
dev_langs:
- C++
helpviewer_keywords:
- C2194
ms.assetid: df6e631c-0062-4844-9088-4cc7a0ff879f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 61a2ca45df170245fae0795adc006349c1b62fb2
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33169238"
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