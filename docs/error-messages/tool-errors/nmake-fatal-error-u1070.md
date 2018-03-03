---
title: NMAKE Erro Fatal U1070 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- U1070
dev_langs:
- C++
helpviewer_keywords:
- U1070
ms.assetid: 8639fc39-b4b1-48f5-ac91-0e9fb61680fd
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 5adf5321c96341cfce633a2329a52360be8a45da
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="nmake-fatal-error-u1070"></a>Erro fatal U1070 (NMAKE)
ciclo em definição de macro 'nomedamacro'  
  
 A definição de macro determinado continha uma macro cuja definição de macro determinada. As definições de macro circular são inválidas.  
  
## <a name="example"></a>Exemplo  
 As seguintes definições de macro  
  
```  
ONE=$(TWO)  
TWO=$(ONE)  
```  
  
 fazer com que o seguinte erro:  
  
```  
cycle in macro definition 'TWO'  
```