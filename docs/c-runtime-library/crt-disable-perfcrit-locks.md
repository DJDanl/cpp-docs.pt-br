---
title: _CRT_DISABLE_PERFCRIT_LOCKS | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- _CRT_DISABLE_PERFCRIT_LOCKS
- CRT_DISABLE_PERFCRIT_LOCKS
dev_langs: C++
helpviewer_keywords:
- CRT_DISABLE_PERFCRIT_LOCKS constant
- _CRT_DISABLE_PERFCRIT_LOCKS constant
ms.assetid: 36cc2d86-cdb1-4b2b-a03c-c0d3818e7c6f
caps.latest.revision: "4"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 07962266c94743968ff407aa5be78f66e189f6aa
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="crtdisableperfcritlocks"></a>_CRT_DISABLE_PERFCRIT_LOCKS
Desabilita o bloqueio de desempenho crítico em operações de E/S.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
#define _CRT_DISABLE_PERFCRIT_LOCKS  
```  
  
## <a name="remarks"></a>Comentários  
 A definição desse símbolo pode melhorar o desempenho em programas delimitados por E/S de single-thread, forçando todas as operações de E/S a assumir um modelo de single-thread. Para obter mais informações, consulte [Desempenho de bibliotecas multithread](../c-runtime-library/multithreaded-libraries-performance.md).  
  
## <a name="see-also"></a>Consulte também  
 [Constantes globais](../c-runtime-library/global-constants.md)