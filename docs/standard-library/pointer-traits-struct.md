---
title: Struct pointer_traits
ms.date: 11/04/2016
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
ms.assetid: 545aecf1-3561-4859-8b34-603c079fe1b3
ms.openlocfilehash: 1ed8d61a52c11ab48fe6f762ff342ea88d107b14
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88832692"
---
# <a name="pointer_traits-struct"></a>Struct pointer_traits

Fornece informações necessárias para um objeto do tipo `allocator_traits` para descrever um alocador com tipo de ponteiro `Ptr` .

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
   static pointer pointer_to(element_type& obj); // optional
};
```

## <a name="members"></a>Membros

### <a name="typedefs"></a>Typedefs

|Nome|Descrição|
|-|-|
|`typedef T2 difference_type`|O tipo `T2` é `Ptr::difference_type` se esse tipo de existir, caso contrário, `ptrdiff_t`. Se `Ptr` for um ponteiro bruto, o tipo será `ptrdiff_t`.|
|`typedef T1 element_type`|O tipo `T1` é `Ptr::element_type` se esse tipo de existir, caso contrário, `Ty`. Se `Ptr` for um ponteiro bruto, o tipo será `Ty`.|
|`typedef Ptr pointer`|O tipo é `Ptr`.|

### <a name="structs"></a>Estruturas

|Nome|Descrição|
|-|-|
|`rebind`|Tenta converter o tipo de ponteiro subjacente em um tipo especificado.|

### <a name="methods"></a>Métodos

|Nome|Descrição|
|----------|-----------------|
|[pointer_to](#pointer_to)|Converte uma referência arbitrária em um objeto da classe `Ptr`.|

### <a name="pointer_to"></a><a name="pointer_to"></a> pointer_to

O método estático que retorna `Ptr::pointer_to(obj)`, se essa função existir. Caso contrário, não é possível converter uma referência arbitrária para um objeto da classe `Ptr`. Se `Ptr` for um ponteiro bruto, esse método retornará `addressof(obj)`.

```cpp
static pointer pointer_to(element_type& obj);
```
