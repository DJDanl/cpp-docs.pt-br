---
title: Compilador (nível 1) de aviso C4103 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4103
dev_langs:
- C++
helpviewer_keywords:
- C4103
ms.assetid: 9021b514-375e-4d62-b261-ccb06f299e8e
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f072db4a260d2c83d1dd4b373630cd6e585efc2b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-1-c4103"></a>Compilador C4103 de aviso (nível 1)
'filename': alinhamento mudou após inclusão de cabeçalho, pode ser devido à ausência de Pack (POP) #pragma  
  
 Empacotamento afeta o layout das classes e comumente, se as alterações em arquivos de cabeçalho de remessa, pode haver problemas.  
  
 Use #pragma [pacote](../../preprocessor/pack.md)(pop) antes de sair do arquivo de cabeçalho para resolver este aviso.  
  
 O exemplo a seguir gera C4103:  
  
```  
// C4103.h  
#pragma pack(push, 4)  
  
// defintions and declarations  
  
// uncomment the following line to resolve  
// #pragma pack(pop)  
```  
  
 E, em seguida,  
  
```  
// C4103.cpp  
// compile with: /LD /W1  
#include "c4103.h"   // C4103  
```