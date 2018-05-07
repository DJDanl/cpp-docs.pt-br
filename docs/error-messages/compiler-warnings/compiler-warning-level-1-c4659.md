---
title: Compilador (nível 1) de aviso C4659 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4659
dev_langs:
- C++
helpviewer_keywords:
- C4659
ms.assetid: e29ba8db-7917-43f6-8e34-868b752279ae
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 643b599cd11d0935f1769ad37dca4e764f0418e6
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-1-c4659"></a>Compilador C4659 de aviso (nível 1)
\#pragma 'pragma': uso de segmento reservado 'segmento' possui comportamento indefinido, use #pragma comment (linker,...)  
  
 A opção. drectve foi usada para passar uma opção para o vinculador. Em vez disso, use pragma [comentário](../../preprocessor/comment-c-cpp.md) para passar uma opção de vinculador.  
  
```  
// C4659.cpp  
// compile with: /W1 /LD  
#pragma code_seg(".drectve")   // C4659  
```