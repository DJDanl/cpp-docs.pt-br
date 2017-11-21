---
title: Classe is_trivially_assignable | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: type_traits/std::is_trivially_assignable
dev_langs: C++
helpviewer_keywords: is_trivially_assignable
ms.assetid: 1284a8f7-4093-426d-9c9a-dabb46f90d6d
caps.latest.revision: "13"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 4d40adc84ae8e2a9bb8f53e78d3a90dda99fd7e8
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="istriviallyassignable-class"></a>Classe is_trivially_assignable
Testa se um valor do tipo `From` pode ser atribuído trivialmente ao tipo `To`  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class To, class From>  
struct is_trivially_assignable;
```  
  
#### <a name="parameters"></a>Parâmetros  
 Para  
 O tipo do objeto que recebe a atribuição.  
  
 De  
 O tipo do objeto que fornece o valor.  
  
## <a name="remarks"></a>Comentários  
 A expressão `declval<To>() = declval<From>()` deve ser bem formada e o compilador deve ter o conhecimento de que ela não requer operações não triviais. `From` e `To` devem ser tipos completos, `void` ou matrizes de limite desconhecido.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<type_traits>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [<type_traits>](../standard-library/type-traits.md)



