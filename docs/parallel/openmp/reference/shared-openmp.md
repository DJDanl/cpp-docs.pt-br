---
title: compartilhado (OpenMP) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: reference
f1_keywords:
- Shared
dev_langs:
- C++
helpviewer_keywords:
- shared OpenMP clause
ms.assetid: 7887dc95-67a2-462f-a3a2-8e0632bf5d04
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b2bc1a0bbf56623feccd4d3bd96f1e719e192d48
ms.sourcegitcommit: e9ce38decc9f986edab5543de3464b11ebccb123
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/13/2018
ms.locfileid: "42539732"
---
# <a name="shared-openmp"></a>shared (OpenMP)
Especifica que uma ou mais variáveis devem ser compartilhadas entre todos os threads.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
shared(var)  
```  
  
## <a name="remarks"></a>Comentários  
 onde,  
  
 `var`  
 Uma ou mais variáveis para compartilhar. Se mais de uma variável for especificada, separe os nomes de variável com uma vírgula.  
  
## <a name="remarks"></a>Comentários  
 Outra maneira de compartilhar variáveis entre threads é com o [copyprivate](../../../parallel/openmp/reference/copyprivate.md) cláusula.  
  
 `shared` aplica-se para as seguintes diretivas:  
  
-   [for](../../../parallel/openmp/reference/for-openmp.md)  
  
-   [parallel](../../../parallel/openmp/reference/parallel.md)  
  
-   [Seções](../../../parallel/openmp/reference/sections-openmp.md)  
  
 Para obter mais informações, consulte [2.7.2.4 compartilhado](../../../parallel/openmp/2-7-2-4-shared.md).  
  
## <a name="example"></a>Exemplo  
 Ver [privados](../../../parallel/openmp/reference/private-openmp.md) para obter um exemplo de como usar `shared`.  
  
## <a name="see-also"></a>Consulte também  
 [Cláusulas](../../../parallel/openmp/reference/openmp-clauses.md)