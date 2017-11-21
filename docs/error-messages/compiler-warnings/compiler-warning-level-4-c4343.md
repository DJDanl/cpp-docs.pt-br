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
ms.openlocfilehash: e6c45c8a2a595d819ecc6eeb2eb8b69a3b5f864e
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
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