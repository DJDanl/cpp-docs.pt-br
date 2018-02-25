---
title: lastprivate | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- lastprivate
dev_langs:
- C++
helpviewer_keywords:
- lastprivate OpenMP clause
ms.assetid: 6ef87b31-375a-47e8-8d0d-281be45fb56a
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 7945edb879d81bb50753619c1206b9da575dbcda
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="lastprivate"></a>lastprivate
Especifica que a versão do contexto delimitador da variável é definida igual à versão particular de qualquer thread que executa a iteração final (construção de loop) ou a última seção (#pragma seções).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
lastprivate(var)  
```  
  
## <a name="remarks"></a>Comentários  
 onde,  
  
 `var`  
 A variável que é definida igual da versão privada de qualquer thread que executa a iteração final (construção de loop) ou a última seção (#pragma seções).  
  
## <a name="remarks"></a>Comentários  
 `lastprivate` aplica-se para as seguintes diretivas:  
  
-   [for](../../../parallel/openmp/reference/for-openmp.md)  
  
-   [sections](../../../parallel/openmp/reference/sections-openmp.md)  
  
 Para obter mais informações, consulte [2.7.2.3 lastprivate](../../../parallel/openmp/2-7-2-3-lastprivate.md).  
  
## <a name="example"></a>Exemplo  
 Consulte [agenda](../../../parallel/openmp/reference/schedule.md) para obter um exemplo do uso de `lastprivate` cláusula.  
  
## <a name="see-also"></a>Consulte também  
 [Cláusulas](../../../parallel/openmp/reference/openmp-clauses.md)