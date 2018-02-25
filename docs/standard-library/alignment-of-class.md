---
title: Classe alignment_of | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- type_traits/std::alignment_of
dev_langs:
- C++
helpviewer_keywords:
- alignment_of class
- alignment_of
ms.assetid: 4141c59a-f94e-41c4-93fd-9ea578b27387
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: e3bd3f2e306c09e69a37bef08f75fd33efb6fcb7
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="alignmentof-class"></a>Classe alignment_of
Obtém o alinhamento do tipo especificado. Este struct é implementado em termos de [alignof](../cpp/alignof-and-alignas-cpp.md). Use `alignof` diretamente quando você apenas precisar consultar um valor de alinhamento. Use alignment_of quando precisar de uma constante integral, por exemplo, ao fazer expedição de marcação.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class Ty>
struct alignment_of;
```  
  
#### <a name="parameters"></a>Parâmetros  
 `Ty`  
 O tipo a ser consultado.  
  
## <a name="remarks"></a>Comentários  
 A consulta de tipo contém o valor do alinhamento do tipo `Ty`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<type_traits>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [<type_traits>](../standard-library/type-traits.md)   
 [Classe aligned_storage](../standard-library/aligned-storage-class.md)
