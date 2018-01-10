---
title: copyin | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: copyin
dev_langs: C++
helpviewer_keywords: copyin OpenMP clause
ms.assetid: 369efa88-613c-4cb1-9e11-7b9ee08a4b25
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 3190c1f6914ae8ea24b968a8cf286de1867938cf
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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
 `copyin`aplica-se para as seguintes diretivas:  
  
-   [parallel](../../../parallel/openmp/reference/parallel.md)  
  
-   [for](../../../parallel/openmp/reference/for-openmp.md)  
  
-   [seções](../../../parallel/openmp/reference/sections-openmp.md)  
  
 Para obter mais informações, consulte [2.7.2.7 copyin](../../../parallel/openmp/2-7-2-7-copyin.md).  
  
## <a name="example"></a>Exemplo  
 Consulte [threadprivate](../../../parallel/openmp/reference/threadprivate.md) para obter um exemplo de como usar `copyin`.  
  
## <a name="see-also"></a>Consulte também  
 [Cláusulas](../../../parallel/openmp/reference/openmp-clauses.md)