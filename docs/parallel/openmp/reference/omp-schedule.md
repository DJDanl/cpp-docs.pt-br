---
title: OMP_SCHEDULE | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: OMP_SCHEDULE
dev_langs: C++
helpviewer_keywords: OMP_SCHEDULE OpenMP environment variable
ms.assetid: 2295a801-e584-4d2f-826f-7ca4c88846a6
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 8aa1406b490128657da19f7c48c958d382850d96
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ompschedule"></a>OMP_SCHEDULE
Modifica o comportamento do [agenda](../../../parallel/openmp/reference/schedule.md) cláusula quando `schedule(runtime)` é especificado em uma `for` ou `parallel for` diretiva.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
set OMP_SCHEDULE[=type[,size]]  
```  
  
## <a name="remarks"></a>Comentários  
 onde,  
  
 `size` (opcional)  
 Especifica o tamanho de iterações. `size`deve ser um inteiro positivo. O padrão é 1, exceto quando `type` é estático. Não é válida quando `type` é `runtime`.  
  
 `type`  
 O tipo de agendamento:  
  
-   `dynamic`  
  
-   `guided`  
  
-   `runtime`  
  
-   `static`  
  
## <a name="remarks"></a>Comentários  
 O valor padrão na implementação do padrão OpenMP Visual C++ é `OMP_SCHEDULE=static,0`.  
  
 Para obter mais informações, consulte [OMP_SCHEDULE 4.1](../../../parallel/openmp/4-1-omp-schedule.md).  
  
## <a name="example"></a>Exemplo  
 O comando a seguir define o **OMP_SCHEDULE** variável de ambiente:  
  
```  
set OMP_SCHEDULE="guided,2"  
```  
  
 O comando a seguir exibe a configuração atual de **OMP_SCHEDULE** variável de ambiente:  
  
```  
set OMP_SCHEDULE  
```  
  
## <a name="see-also"></a>Consulte também  
 [Variáveis de ambiente](../../../parallel/openmp/reference/openmp-environment-variables.md)