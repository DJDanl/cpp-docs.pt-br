---
title: lastprivate | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: lastprivate
dev_langs: C++
helpviewer_keywords: lastprivate OpenMP clause
ms.assetid: 6ef87b31-375a-47e8-8d0d-281be45fb56a
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 7ad36a68078856706a4d1d994e72fd001c36dbaf
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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
 `lastprivate`aplica-se para as seguintes diretivas:  
  
-   [for](../../../parallel/openmp/reference/for-openmp.md)  
  
-   [seções](../../../parallel/openmp/reference/sections-openmp.md)  
  
 Para obter mais informações, consulte [2.7.2.3 lastprivate](../../../parallel/openmp/2-7-2-3-lastprivate.md).  
  
## <a name="example"></a>Exemplo  
 Consulte [agenda](../../../parallel/openmp/reference/schedule.md) para obter um exemplo do uso de `lastprivate` cláusula.  
  
## <a name="see-also"></a>Consulte também  
 [Cláusulas](../../../parallel/openmp/reference/openmp-clauses.md)