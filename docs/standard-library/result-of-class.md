---
title: Classe result_of | Microsoft Docs
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
- type_traits/std::result_of
- type_traits/std::result_of_t
- type_traits/std::result_of::type
dev_langs:
- C++
helpviewer_keywords:
- ', '
ms.assetid: 5374a096-4b4a-4712-aa97-6852c5cdd6be
caps.latest.revision: 13
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
ms.openlocfilehash: 08e4fc22725962d06bee35ed1adf63e3c9230ced
ms.contentlocale: pt-br
ms.lasthandoff: 10/03/2017

---
# <a name="resultof-class"></a>Classe result_of
Determina o tipo de retorno do tipo callable que usa os tipos de argumento especificados.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<class>  
struct result_of; // Causes a static assert  
  
template <class Fn, class... ArgTypes>  
struct result_of<Fn(ArgTypes...)>;

// Helper type  
template<class T>
   using result_of_t = typename result_of<T>::type;
```  
  
#### <a name="parameters"></a>Parâmetros  
 `Fn`  
 O tipo callable para consulta.  
  
 `ArgTypes`  
 Os tipos de lista de argumentos para o tipo callable para consulta.  
  
## <a name="remarks"></a>Comentários  
 Use este modelo para determinar no tempo de compilação o tipo de resultado de `Fn`(`ArgTypes`), em que `Fn` é um tipo callable, referência à função ou a referência ao tipo callable, invocada usando uma lista de argumentos de tipos em `ArgTypes`. O membro `type` da classe de modelo nomeia o tipo de resultado de `decltype(std::invoke(declval<Fn>(), declval<ArgTypes>()...))` se a expressão não avaliada `std::invoke(declval<Fn>(), declval<ArgTypes>()...)` está bem formada. Caso contrário, a classe de modelo não terá nenhum membro `type`. O tipo `Fn` e todos os tipos de pacote de parâmetros `ArgTypes` devem ser tipos completos, `void` ou matrizes de associação desconhecida.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<type_traits>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [<type_traits>](../standard-library/type-traits.md)




