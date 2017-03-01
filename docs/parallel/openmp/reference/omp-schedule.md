---
title: OMP_SCHEDULE | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- OMP_SCHEDULE
dev_langs:
- C++
helpviewer_keywords:
- OMP_SCHEDULE OpenMP environment variable
ms.assetid: 2295a801-e584-4d2f-826f-7ca4c88846a6
caps.latest.revision: 8
author: mikeblome
ms.author: mblome
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
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 020ba85844942e78d10180e433061e7b84d45da2
ms.lasthandoff: 02/25/2017

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
 O valor padrão na implementação do Visual C++ do OpenMP padrão é `OMP_SCHEDULE=static,0`.  
  
 Para obter mais informações, consulte [OMP_SCHEDULE&4;.1](../../../parallel/openmp/4-1-omp-schedule.md).  
  
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
