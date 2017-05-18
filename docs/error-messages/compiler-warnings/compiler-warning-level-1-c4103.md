---
title: "Compilador aviso (nível 1) C4103 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4103
dev_langs:
- C++
helpviewer_keywords:
- C4103
ms.assetid: 9021b514-375e-4d62-b261-ccb06f299e8e
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 4eeee87eaba08145e9dcaad0d8d3396e91dc3d1f
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4103"></a>Compilador C4103 de aviso (nível 1)
'filename': alinhamento alterado após incluir o cabeçalho, pode ser devido à ausência de #pragma pack(pop)  
  
 Remessa afeta o layout das classes e geralmente se remessa alterações em arquivos de cabeçalho, pode haver problemas.  
  
 Use #pragma [pacote](../../preprocessor/pack.md)(pop) antes de sair do arquivo de cabeçalho para resolver esse aviso.  
  
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
