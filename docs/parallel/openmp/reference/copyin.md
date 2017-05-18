---
title: copyin | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- copyin
dev_langs:
- C++
helpviewer_keywords:
- copyin OpenMP clause
ms.assetid: 369efa88-613c-4cb1-9e11-7b9ee08a4b25
caps.latest.revision: 7
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
ms.openlocfilehash: ff466d0ec280d4e31d49328a725da88d87bd2435
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

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
 O `threadprivate` variável será inicializado com o valor da variável no thread principal, conforme ele existe antes da construção parallel.  
  
## <a name="remarks"></a>Comentários  
 `copyin`aplica-se para as seguintes diretivas:  
  
-   [paralelo](../../../parallel/openmp/reference/parallel.md)  
  
-   [for](../../../parallel/openmp/reference/for-openmp.md)  
  
-   [seções](../../../parallel/openmp/reference/sections-openmp.md)  
  
 Para obter mais informações, consulte [2.7.2.7 copyin](../../../parallel/openmp/2-7-2-7-copyin.md).  
  
## <a name="example"></a>Exemplo  
 Consulte [threadprivate](../../../parallel/openmp/reference/threadprivate.md) para obter um exemplo de como usar `copyin`.  
  
## <a name="see-also"></a>Consulte também  
 [Cláusulas](../../../parallel/openmp/reference/openmp-clauses.md)
