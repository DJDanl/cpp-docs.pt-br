---
title: Classe is_trivially_copy_assignable | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- is_trivially_copy_assignable
- std.is_trivially_copy_assignable
- std::is_trivially_copy_assignable
- type_traits/std::is_trivially_copy_assignable
dev_langs:
- C++
helpviewer_keywords:
- is_trivially_copy_assignable
ms.assetid: 7410133e-f367-493f-92a7-e34e3ec5e879
caps.latest.revision: 12
author: corob-msft
ms.author: corob
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
translationtype: Machine Translation
ms.sourcegitcommit: 51fbd09793071631985720550007dddbe16f598f
ms.openlocfilehash: 97935fed1736f111557a0cb86811a86d60505107
ms.lasthandoff: 02/25/2017

---
# <a name="istriviallycopyassignable-class"></a>Classe is_trivially_copy_assignable
Testa se o tipo tem uma cópia trivial do operador de atribuição.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class Ty>
struct is_trivially_copy_assignable;
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo a ser consultado.  
  
## <a name="remarks"></a>Comentários  
 Uma instância do predicado de tipo será verdadeira se o tipo `T` for uma classe que tem um operador de atribuição de cópia trivial; caso contrário, será falsa.  
  
 Um construtor de atribuição para uma classe `T` será trivial se for implicitamente fornecido, a classe `T` não tiver funções virtuais, a classe `T` não tiver bases virtuais, as classes de todos os membros de dados não estáticos de tipo de classe tiverem operadores de atribuição triviais e as classes de todos os membros de dados não estáticos de matriz de tipo de classe tiverem operadores de atribuição trivial.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<type_traits>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [<type_traits>](../standard-library/type-traits.md)




