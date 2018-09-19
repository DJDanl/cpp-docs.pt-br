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
ms.openlocfilehash: c87dfc47f7f2554e75567a1de4ea9cb2e06eaa00
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46028188"
---
# <a name="lastprivate"></a>lastprivate
Especifica que a versão do contexto delimitador da variável é definido igual da versão privada de qualquer thread que executa a iteração final (construção de loop) ou a última seção (#pragma seções).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
lastprivate(var)  
```  
  
### <a name="parameters"></a>Parâmetros
  
*var*<br/>
A variável que é definida igual da versão privada de qualquer thread que executa a iteração final (construção de loop) ou a última seção (#pragma seções).  
  
## <a name="remarks"></a>Comentários  
 `lastprivate` aplica-se para as seguintes diretivas:  
  
-   [for](../../../parallel/openmp/reference/for-openmp.md)  
  
-   [Seções](../../../parallel/openmp/reference/sections-openmp.md)  
  
 Para obter mais informações, consulte [2.7.2.3 lastprivate](../../../parallel/openmp/2-7-2-3-lastprivate.md).  
  
## <a name="example"></a>Exemplo  
 Ver [agendamento](../../../parallel/openmp/reference/schedule.md) para obter um exemplo de como usar `lastprivate` cláusula.  
  
## <a name="see-also"></a>Consulte também  
 [Cláusulas](../../../parallel/openmp/reference/openmp-clauses.md)