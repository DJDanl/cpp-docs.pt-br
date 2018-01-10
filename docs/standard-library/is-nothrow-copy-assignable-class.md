---
title: Classe is_nothrow_copy_assignable | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: type_traits/std::is_nothrow_copy_assignable
dev_langs: C++
helpviewer_keywords: is_nothrow_copy_assignable
ms.assetid: baa8abd6-4f53-489f-abba-8d5d5c53bbbc
caps.latest.revision: "23"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 1fe17d40b104c1ae06ac8158db79925c0731d3ea
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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





