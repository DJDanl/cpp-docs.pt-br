---
title: Classe make_unsigned | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- type_traits/std::make_unsigned
dev_langs:
- C++
helpviewer_keywords:
- make_unsigned class
- make_unsigned
ms.assetid: 7a6a3c4f-1a4c-47e8-9ee2-ac1f7b669353
caps.latest.revision: 18
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 65f4e356ad0d46333b0d443d0fd6ac0b9f2b6f58
ms.openlocfilehash: fdd04e8b2b235e9711036fbb66f9ac0ed8a99e75
ms.contentlocale: pt-br
ms.lasthandoff: 10/03/2017

---
# <a name="makeunsigned-class"></a>Classe make_unsigned
Cria o tipo ou o menor tipo sem sinal maior ou igual em tamanho ao tipo.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class T>
struct make_unsigned;

template <class T>
using make_unsigned_t = typename make_unsigned<T>::type;
```  
  
#### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`T`|O tipo a ser modificado.|  
  
## <a name="remarks"></a>Comentários  
 Uma instância do modificador de tipo mantém um tipo modificado que será `T` se `is_unsigned<T>` manter true. Caso contrário, será o menor tipo com sinal `ST` para `sizeof (T) <= sizeof (ST)`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<type_traits>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [<type_traits>](../standard-library/type-traits.md)




