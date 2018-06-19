---
title: padrão (OpenMP) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: reference
f1_keywords:
- default
dev_langs:
- C++
helpviewer_keywords:
- default OpenMP clause
- defaults, OpenMP clause
ms.assetid: 96055106-a8f0-40b3-8319-e412b6e07bf8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 9fc39951270138e9bd243172b289e7bd96190f14
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33692315"
---
# <a name="default-openmp"></a>default (OpenMP)
Especifica o comportamento de variáveis sem escopo em uma região parallel.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
default(shared | none)  
```  
  
## <a name="remarks"></a>Comentários  
 `shared`, que está em vigor se o `default` cláusula não for especificada, significa que qualquer variável em uma região parallel será tratado como se ele tiver sido especificado com o [compartilhado](../../../parallel/openmp/reference/shared-openmp.md) cláusula. `none` significa que todas as variáveis usadas em uma região parallel que não estão no escopo com o [privada](../../../parallel/openmp/reference/private-openmp.md), [compartilhado](../../../parallel/openmp/reference/shared-openmp.md), [redução](../../../parallel/openmp/reference/reduction.md), [firstprivate](../../../parallel/openmp/reference/firstprivate.md), ou [lastprivate](../../../parallel/openmp/reference/lastprivate.md) cláusula causará um erro do compilador.  
  
 `default` aplica-se para as seguintes diretivas:  
  
-   [parallel](../../../parallel/openmp/reference/parallel.md)  
  
-   [for](../../../parallel/openmp/reference/for-openmp.md)  
  
-   [Seções](../../../parallel/openmp/reference/sections-openmp.md)  
  
 Para obter mais informações, consulte [2.7.2.5 padrão](../../../parallel/openmp/2-7-2-5-default.md).  
  
## <a name="example"></a>Exemplo  
 Consulte [privada](../../../parallel/openmp/reference/private-openmp.md) para obter um exemplo de como usar `default`.  
  
## <a name="see-also"></a>Consulte também  
 [Cláusulas](../../../parallel/openmp/reference/openmp-clauses.md)