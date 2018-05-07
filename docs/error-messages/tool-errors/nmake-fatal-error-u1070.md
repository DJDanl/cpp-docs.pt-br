---
title: NMAKE Erro Fatal U1070 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- U1070
dev_langs:
- C++
helpviewer_keywords:
- U1070
ms.assetid: 8639fc39-b4b1-48f5-ac91-0e9fb61680fd
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 1fe39a5d6f6074596561cd8e32f7b9428bc60f6d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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