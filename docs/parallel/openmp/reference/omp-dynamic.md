---
title: OMP_DYNAMIC | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: OMP_DYNAMIC
dev_langs: C++
helpviewer_keywords: OMP_DYNAMIC OpenMP environment variable
ms.assetid: e306049d-b644-4b73-8b63-46c835bff98b
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 900f3e4ddd0e9901e72ed65f12bc036d87a6956e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ompdynamic"></a>OMP_DYNAMIC
Especifica se o OpenMP no tempo de execução pode ajustar o número de segmentos em uma região parallel.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
set OMP_DYNAMIC[=TRUE | =FALSE]  
```  
  
## <a name="remarks"></a>Comentários  
 O `OMP_DYNAMIC` variável de ambiente pode ser substituída pelo [omp_set_dynamic](../../../parallel/openmp/reference/omp-set-dynamic.md) função.  
  
 O valor padrão na implementação do padrão OpenMP Visual C++ é `OMP_DYNAMIC=FALSE`.  
  
 Para obter mais informações, consulte [OMP_DYNAMIC 4.3](../../../parallel/openmp/4-3-omp-dynamic.md).  
  
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