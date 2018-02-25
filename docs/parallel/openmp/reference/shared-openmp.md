---
title: compartilhado (OpenMP) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- Shared
dev_langs:
- C++
helpviewer_keywords:
- shared OpenMP clause
ms.assetid: 7887dc95-67a2-462f-a3a2-8e0632bf5d04
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 90491e6e8b415c79e21b4fa518f7e60327ac823e
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="shared-openmp"></a>shared (OpenMP)
Especifica que uma ou mais variáveis devem ser compartilhados entre todos os threads.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
shared(var)  
```  
  
## <a name="remarks"></a>Comentários  
 onde,  
  
 `var`  
 Um mais mais variáveis para compartilhar. Se mais de uma variável for especificada, separe os nomes de variável com uma vírgula.  
  
## <a name="remarks"></a>Comentários  
 Outra maneira de compartilhar variáveis entre threads é com o [copyprivate](../../../parallel/openmp/reference/copyprivate.md) cláusula.  
  
 `shared` aplica-se para as seguintes diretivas:  
  
-   [for](../../../parallel/openmp/reference/for-openmp.md)  
  
-   [parallel](../../../parallel/openmp/reference/parallel.md)  
  
-   [sections](../../../parallel/openmp/reference/sections-openmp.md)  
  
 Para obter mais informações, consulte [2.7.2.4 compartilhado](../../../parallel/openmp/2-7-2-4-shared.md).  
  
## <a name="example"></a>Exemplo  
 Consulte [privada](../../../parallel/openmp/reference/private-openmp.md) para obter um exemplo de como usar `shared`.  
  
## <a name="see-also"></a>Consulte também  
 [Cláusulas](../../../parallel/openmp/reference/openmp-clauses.md)