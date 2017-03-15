---
title: Classe is_constructible | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- is_constructible
- std.is_constructible
- std::is_constructible
- type_traits/std::is_constructible
dev_langs:
- C++
helpviewer_keywords:
- is_constructible
ms.assetid: 7cdec5ff-73cf-4f78-a9db-ced2e9c0fd7f
caps.latest.revision: 14
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
translationtype: Machine Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 6c4a5d8e24f22a79a4bf442ab690f1b1dbdca580
ms.lasthandoff: 02/25/2017

---
# <a name="isconstructible-class"></a>Classe is_constructible
Testa se um tipo pode ser construído quando os tipos de argumento especificados são usados.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class T, class... Args>  
struct is_constructible;
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo a ser consultado.  
  
 `Args`  
 Os tipos de argumento com que fazer a correspondência em um construtor de `T`.  
  
## <a name="remarks"></a>Comentários  
 Uma instância do predicado de tipo será verdadeira se o tipo `T` puder ser construído usando os tipos de argumento em `Args`; caso contrário, será falsa. O tipo `T` poderá ser construído se a definição da variável `T t(std::declval<Args>()...);` estiver bem formada. `T` e todos os tipos em `Args` devem ser tipos completos, `void` ou matrizes de limite desconhecido.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<type_traits>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [<type_traits>](../standard-library/type-traits.md)




