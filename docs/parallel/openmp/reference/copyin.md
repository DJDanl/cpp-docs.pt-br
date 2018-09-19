---
title: copyin | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: reference
f1_keywords:
- copyin
dev_langs:
- C++
helpviewer_keywords:
- copyin OpenMP clause
ms.assetid: 369efa88-613c-4cb1-9e11-7b9ee08a4b25
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 27afaee16a87ddf428570f7854212eed34634d38
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46059323"
---
# <a name="copyin"></a>copyin
Permite que os threads acessar o valor do thread mestre, para um [threadprivate](../../../parallel/openmp/reference/threadprivate.md) variável.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
copyin(var)  
```  
  
## <a name="parameters"></a>Parâmetros
  
*var*<br/>
O `threadprivate` variável será inicializada com o valor da variável no thread mestre, como ela existe antes da construção parallel.  
  
## <a name="remarks"></a>Comentários  
 `copyin` aplica-se para as seguintes diretivas:  
  
-   [parallel](../../../parallel/openmp/reference/parallel.md)  
  
-   [for](../../../parallel/openmp/reference/for-openmp.md)  
  
-   [Seções](../../../parallel/openmp/reference/sections-openmp.md)  
  
 Para obter mais informações, consulte [2.7.2.7 copyin](../../../parallel/openmp/2-7-2-7-copyin.md).  
  
## <a name="example"></a>Exemplo  
 Ver [threadprivate](../../../parallel/openmp/reference/threadprivate.md) para obter um exemplo de como usar `copyin`.  
  
## <a name="see-also"></a>Consulte também  
 [Cláusulas](../../../parallel/openmp/reference/openmp-clauses.md)