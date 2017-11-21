---
title: "Compilador (nível 1) de aviso C4103 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4103
dev_langs: C++
helpviewer_keywords: C4103
ms.assetid: 9021b514-375e-4d62-b261-ccb06f299e8e
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 1ac53a33d64bede8351d3b981b9c2a7e324e3f1f
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
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