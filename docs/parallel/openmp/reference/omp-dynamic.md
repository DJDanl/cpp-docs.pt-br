---
title: OMP_DYNAMIC | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- OMP_DYNAMIC
dev_langs:
- C++
helpviewer_keywords:
- OMP_DYNAMIC OpenMP environment variable
ms.assetid: e306049d-b644-4b73-8b63-46c835bff98b
caps.latest.revision: 9
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
ms.openlocfilehash: f39f99139d3f6107190c37e1a11e2c5cc69b5ecf
ms.lasthandoff: 02/25/2017

---
# <a name="ompdynamic"></a>OMP_DYNAMIC
Especifica se o tempo de execução de OpenMP pode ajustar o número de threads em uma região paralela.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
set OMP_DYNAMIC[=TRUE | =FALSE]  
```  
  
## <a name="remarks"></a>Comentários  
 O `OMP_DYNAMIC` variável de ambiente pode ser substituída do [omp_set_dynamic](../../../parallel/openmp/reference/omp-set-dynamic.md) função.  
  
 O valor padrão na implementação do Visual C++ do OpenMP padrão é `OMP_DYNAMIC=FALSE`.  
  
 Para obter mais informações, consulte [OMP_DYNAMIC&4;.3](../../../parallel/openmp/4-3-omp-dynamic.md).  
  
## <a name="example"></a>Exemplo  
 O comando a seguir define o `OMP_DYNAMIC` variável de ambiente para TRUE:  
  
```  
set OMP_DYNAMIC=TRUE  
```  
  
 O comando a seguir exibe a configuração atual de `OMP_DYNAMIC` variável de ambiente:  
  
```  
set OMP_DYNAMIC  
```  
  
## <a name="see-also"></a>Consulte também  
 [Variáveis de ambiente](../../../parallel/openmp/reference/openmp-environment-variables.md)
