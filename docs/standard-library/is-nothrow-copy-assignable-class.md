---
title: Classe is_nothrow_copy_assignable | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- is_nothrow_copy_assignable
- std.is_nothrow_copy_assignable
- std::is_nothrow_copy_assignable
- type_traits/std::is_nothrow_copy_assignable
dev_langs:
- C++
helpviewer_keywords:
- is_nothrow_copy_assignable
ms.assetid: baa8abd6-4f53-489f-abba-8d5d5c53bbbc
caps.latest.revision: 23
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
ms.sourcegitcommit: 51fbd09793071631985720550007dddbe16f598f
ms.openlocfilehash: 64502f44f46280317028fc2e7092e28cfc75f343
ms.lasthandoff: 02/25/2017

---
# <a name="isnothrowcopyassignable-class"></a>Classe is_nothrow_copy_assignable
Testa se o tipo tem um operador de atribuição de cópia que o compilador sabe que não efetua lançamentos.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class T>
struct is_nothrow_copy_assignable;
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo a ser consultado.  
  
## <a name="remarks"></a>Comentários  
 Uma instância do predicado de tipo será verdadeira para um tipo que pode ser referenciado `T` em que `is_nothrow_assignable<T&, const T&>` for verdadeiro; caso contrário, será falsa.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<type_traits>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [<type_traits>](../standard-library/type-traits.md)   
 [Classe is_nothrow_assignable](../standard-library/is-nothrow-assignable-class.md)   






