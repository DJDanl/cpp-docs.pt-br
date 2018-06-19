---
title: lastprivate | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: reference
f1_keywords:
- lastprivate
dev_langs:
- C++
helpviewer_keywords:
- lastprivate OpenMP clause
ms.assetid: 6ef87b31-375a-47e8-8d0d-281be45fb56a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 5aaf80e3061877c42154ab9ee5ccd30f47f17135
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33696221"
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
  
-   [Seções](../../../parallel/openmp/reference/sections-openmp.md)  
  
 Para obter mais informações, consulte [2.7.2.3 lastprivate](../../../parallel/openmp/2-7-2-3-lastprivate.md).  
  
## <a name="example"></a>Exemplo  
 Consulte [agenda](../../../parallel/openmp/reference/schedule.md) para obter um exemplo do uso de `lastprivate` cláusula.  
  
## <a name="see-also"></a>Consulte também  
 [Cláusulas](../../../parallel/openmp/reference/openmp-clauses.md)