---
title: OMP_NESTED | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- OMP_NESTED
dev_langs:
- C++
helpviewer_keywords:
- OMP_NESTED OpenMP environment variable
ms.assetid: c43f5287-a548-40d0-bd54-0c6b2b9f9a53
caps.latest.revision: 10
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 36d239d2422459152cd506bd115efdc0cec2f190
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="ompnested"></a>OMP_NESTED
Especifica se o paralelismo aninhado está habilitado, a menos que o paralelismo aninhado está habilitado ou desabilitado com `omp_set_nested`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
set OMP_NESTED[=TRUE | =FALSE]  
```  
  
## <a name="remarks"></a>Comentários  
 O `OMP_NESTED` variável de ambiente pode ser substituída do [omp_set_nested](../../../parallel/openmp/reference/omp-set-nested.md) função.  
  
 O valor padrão na implementação do Visual C++ do OpenMP padrão é `OMP_DYNAMIC=FALSE`.  
  
 Para obter mais informações, consulte [OMP_NESTED&4;.4](../../../parallel/openmp/4-4-omp-nested.md).  
  
## <a name="example"></a>Exemplo  
 O comando a seguir define o `OMP_NESTED` variável de ambiente para TRUE:  
  
```  
set OMP_NESTED=TRUE  
```  
  
 O comando a seguir exibe a configuração atual de `OMP_NESTED` variável de ambiente:  
  
```  
set OMP_NESTED  
```  
  
## <a name="see-also"></a>Consulte também  
 [Variáveis de ambiente](../../../parallel/openmp/reference/openmp-environment-variables.md)
