---
title: Compilador (nível 4) de aviso C4343 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4343
dev_langs:
- C++
helpviewer_keywords:
- C4343
ms.assetid: a721b710-e04f-4d15-b678-e4a2c8fd0181
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 300bab652c88322ef7e3b28cbf2cafe304d361d5
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-4-c4343"></a>Compilador C4343 de aviso (nível 4)
\#pragma optimize("g",off) substitui opção /Og  
  
 Este aviso, somente válido no compilador família de processador Itanium (IPF), informa que um pragma [otimizar](../../preprocessor/optimize.md) substitui um [/Og](../../build/reference/og-global-optimizations.md) opção de compilador.  
  
 O exemplo a seguir gera C4343:  
  
```  
// C4343.cpp  
// compile with: /Og /W4 /LD  
// processor: IPF  
#pragma optimize ("g", off)   // C4343  
```