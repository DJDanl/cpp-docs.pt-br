---
title: Struct pointer_traits | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
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
- memory/std::pointer_traits::pointer_to
dev_langs:
- C++
ms.assetid: 545aecf1-3561-4859-8b34-603c079fe1b3
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d1485441dbea92f534314dafd9d86ab0ef8a4e69
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33856443"
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

```cpp
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
|[pointer_to](#pointer_to)|Converte uma referência arbitrária em um objeto da classe `Ptr`.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<memory>

**Namespace:** std

## <a name="pointer_to"></a>  pointer_to

O método estático que retorna `Ptr::pointer_to(obj)`, se essa função existir. Caso contrário, não é possível converter uma referência arbitrária para um objeto da classe `Ptr`. Se `Ptr` for um ponteiro bruto, esse método retornará `addressof(obj)`.

```cpp
static pointer pointer_to(element_type& obj);
```

## <a name="see-also"></a>Consulte também

[\<memory>](../standard-library/memory.md)<br/>
[Classe allocator_traits](../standard-library/allocator-traits-class.md)<br/>
