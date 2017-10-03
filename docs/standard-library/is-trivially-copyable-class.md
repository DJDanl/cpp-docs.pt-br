---
title: Classe is_trivially_copyable | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- type_traits/std::is_trivially_copyable
dev_langs:
- C++
helpviewer_keywords:
- is_trivially_copyable
ms.assetid: 89a53bf8-036c-4108-91e1-fe34adbde8b3
caps.latest.revision: 12
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.mt:
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
ms.translationtype: MT
ms.sourcegitcommit: 65f4e356ad0d46333b0d443d0fd6ac0b9f2b6f58
ms.openlocfilehash: bf4387901e53dee51ae3c700a756358c63f8631a
ms.contentlocale: pt-br
ms.lasthandoff: 10/03/2017

---
# <a name="istriviallycopyable-class"></a>Classe is_trivially_copyable
Testa se o tipo pode ser copiado de forma trivial.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class T>
struct is_trivially_copyable;
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo a ser consultado.  
  
## <a name="remarks"></a>Comentários  
 Uma instância do predicado de tipo será verdadeira se o tipo `T` puder ser copiado de forma trivial; caso contrário, será falsa. Tipos que podem ser copiados de forma trivial não têm operações de cópia não triviais, operações de movimentação ou destruidores. De modo geral, uma operação de cópia será considerada trivial se puder ser implementada como uma cópia bit a bit. Tipos internos e matrizes de tipos que podem ser copiados de forma trivial.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<type_traits>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [<type_traits>](../standard-library/type-traits.md)




