---
title: Struct pointer_traits | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- memory/std::pointer_traits::element_type
- memory/std::pointer_traits::pointer
- memory/std::pointer_traits
- memory/std::pointer_traits::difference_type
- memory/std::pointer_traits::rebind
- xmemory0/std::pointer_traits::element_type
- xmemory0/std::pointer_traits::pointer
- xmemory0/std::pointer_traits
- xmemory0/std::pointer_traits::difference_type
- xmemory0/std::pointer_traits::rebind
dev_langs:
- C++
ms.assetid: 545aecf1-3561-4859-8b34-603c079fe1b3
caps.latest.revision: 13
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
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 3a5633fa4c9f45629d655edf922d40b02b68aaca
ms.lasthandoff: 02/25/2017

---
# <a name="pointertraits-struct"></a>Struct pointer_traits
Fornece informações que são necessárias a um objeto da classe de modelo `allocator_traits` para descrever um alocador com o tipo de ponteiro `Ptr`.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
template <class Ptr>
struct pointer_traits;
```  
  
## <a name="remarks"></a>Comentários  
 Ptr pode ser um ponteiro bruto do tipo `Ty *` ou uma classe com as seguintes propriedades.  
```  
struct Ptr
   { // describes a pointer type usable by allocators
   typedef Ptr pointer;
   typedef T1 element_type; // optional
   typedef T2 difference_type; // optional
   template <class Other>
   using rebind = typename Ptr<Other, Rest...>; // optional
   static pointer pointer_to(element_type& obj);
   // optional
   };  
```
### <a name="typedefs"></a>Typedefs  
  
|Nome|Descrição|  
|----------|-----------------|  
|`typedef T2 difference_type`|O tipo `T2` é `Ptr::difference_type` se esse tipo de existir, caso contrário, `ptrdiff_t`. Se `Ptr` for um ponteiro bruto, o tipo será `ptrdiff_t`.|  
|`typedef T1 element_type`|O tipo `T1` é `Ptr::element_type` se esse tipo de existir, caso contrário, `Ty`. Se `Ptr` for um ponteiro bruto, o tipo será `Ty`.|  
|`typedef Ptr pointer`|O tipo é `Ptr`.|  
  
### <a name="structs"></a>Structs  
  
|Nome|Descrição|  
|----------|-----------------|  
|`pointer_traits::rebind`|Tenta converter o tipo de ponteiro subjacente em um tipo especificado.|  
  
### <a name="methods"></a>Métodos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[pointer_to](#pointer_traits__pointer_to_method)|Converte uma referência arbitrária em um objeto da classe `Ptr`.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<memory>  
  
 **Namespace:** std  
  
##  <a name="a-namepointertraitspointertomethoda--pointerto"></a><a name="pointer_traits__pointer_to_method"></a>  pointer_to  
 O método estático que retorna `Ptr::pointer_to(obj)`, se essa função existir. Caso contrário, não é possível converter uma referência arbitrária para um objeto da classe `Ptr`. Se `Ptr` for um ponteiro bruto, esse método retornará `addressof(obj)`.  
  
```cpp  
static pointer pointer_to(element_type& obj);
```  
  
## <a name="see-also"></a>Consulte também  
 [\<memory>](../standard-library/memory.md)   
 [Classe allocator_traits](../standard-library/allocator-traits-class.md)


