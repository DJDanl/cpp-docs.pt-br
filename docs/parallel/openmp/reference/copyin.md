---
title: copyin | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- copyin
dev_langs:
- C++
helpviewer_keywords:
- copyin OpenMP clause
ms.assetid: 369efa88-613c-4cb1-9e11-7b9ee08a4b25
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: ae680b2af468b9b11a7d2de44966ad554eec0150
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="copyin"></a>copyin
Permite que os threads acessar o valor do thread principal, para um [threadprivate](../../../parallel/openmp/reference/threadprivate.md) variável.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
copyin(var)  
```  
  
## <a name="remarks"></a>Comentários  
 onde,  
  
 `var`  
 O `threadprivate` variável será inicializado com o valor da variável no thread principal, conforme existia antes da construção paralela.  
  
## <a name="remarks"></a>Comentários  
 `copyin` aplica-se para as seguintes diretivas:  
  
-   [parallel](../../../parallel/openmp/reference/parallel.md)  
  
-   [for](../../../parallel/openmp/reference/for-openmp.md)  
  
-   [sections](../../../parallel/openmp/reference/sections-openmp.md)  
  
 Para obter mais informações, consulte [2.7.2.7 copyin](../../../parallel/openmp/2-7-2-7-copyin.md).  
  
## <a name="example"></a>Exemplo  
 Consulte [threadprivate](../../../parallel/openmp/reference/threadprivate.md) para obter um exemplo de como usar `copyin`.  
  
## <a name="see-also"></a>Consulte também  
 [Cláusulas](../../../parallel/openmp/reference/openmp-clauses.md)