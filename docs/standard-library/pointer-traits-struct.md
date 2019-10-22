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
ms.openlocfilehash: 6d89348867982bfb86c0bf2404a017f6a448d1a1
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72687134"
---
# <a name="pointer_traits-struct"></a>Struct pointer_traits

Fornece informações necessárias para um objeto do tipo `allocator_traits` para descrever um alocador com tipo de ponteiro `Ptr`.

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

|||
|-|-|
|`typedef T2 difference_type`|O tipo `T2` é `Ptr::difference_type` se esse tipo de existir, caso contrário, `ptrdiff_t`. Se `Ptr` for um ponteiro bruto, o tipo será `ptrdiff_t`.|
|`typedef T1 element_type`|O tipo `T1` é `Ptr::element_type` se esse tipo de existir, caso contrário, `Ty`. Se `Ptr` for um ponteiro bruto, o tipo será `Ty`.|
|`typedef Ptr pointer`|O tipo é `Ptr`.|

### <a name="structs"></a>Structs

|||
|-|-|
|`rebind`|Tenta converter o tipo de ponteiro subjacente em um tipo especificado.|

### <a name="methods"></a>Métodos

|Name|Descrição|
|----------|-----------------|
|[pointer_to](#pointer_to)|Converte uma referência arbitrária em um objeto da classe `Ptr`.|

### <a name="pointer_to"></a>pointer_to

O método estático que retorna `Ptr::pointer_to(obj)`, se essa função existir. Caso contrário, não é possível converter uma referência arbitrária para um objeto da classe `Ptr`. Se `Ptr` for um ponteiro bruto, esse método retornará `addressof(obj)`.

```cpp
static pointer pointer_to(element_type& obj);
```
