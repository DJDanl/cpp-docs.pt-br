---
title: Classe is_nothrow_copy_assignable | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- type_traits/std::is_nothrow_copy_assignable
dev_langs:
- C++
helpviewer_keywords:
- is_nothrow_copy_assignable
ms.assetid: baa8abd6-4f53-489f-abba-8d5d5c53bbbc
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e540d6fe4c00772af01b187d24efae18fd62357f
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38957552"
---
# <a name="isnothrowcopyassignable-class"></a>Classe is_nothrow_copy_assignable

Testa se o tipo tem um operador de atribuição de cópia que o compilador sabe que não efetua lançamentos.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
struct is_nothrow_copy_assignable;
```

### <a name="parameters"></a>Parâmetros

*T* o tipo de consulta.

## <a name="remarks"></a>Comentários

Uma instância do predicado de tipo se aplica a um tipo pode ser referenciado *T* onde `is_nothrow_assignable<T&, const T&>` contém true; caso contrário, será falsa.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
[Classe is_nothrow_assignable](../standard-library/is-nothrow-assignable-class.md)<br/>
