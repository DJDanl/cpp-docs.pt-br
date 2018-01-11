---
title: "Compilador (nível 4) de aviso C4343 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: C4343
dev_langs: C++
helpviewer_keywords: C4343
ms.assetid: a721b710-e04f-4d15-b678-e4a2c8fd0181
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: bf7ab18e58a7c77da42e6497c39e716b632d2f7b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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