---
title: default_delete Struct
ms.date: 04/04/2019
f1_keywords:
- memory/std::default_delete
helpviewer_keywords:
- default_delete struct
ms.openlocfilehash: e9e1fcc68539e55486f4ea27e6dd5c49bed11fdf
ms.sourcegitcommit: 3590dc146525807500c0477d6c9c17a4a8a2d658
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/16/2019
ms.locfileid: "68269258"
---
# <a name="defaultdelete-struct"></a>default_delete Struct

Um objeto de função predefinido que executa a operação de divisão (`operator/`) em seus argumentos.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
    struct default_delete
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<memory>

**Namespace:** std

## <a name="members"></a>Membros

### <a name="constructors"></a>Construtores

|||
|-|-|
|[default_delete](#default_delete)|O construtor para objetos do tipo `default_delete`.|

### <a name="operators"></a>Operadores

|||
|-|-|
|[operator()](#op_paren)|Um operador de referência para acessar `default_delete`.|

## <a name="default_delete"></a> default_delete

O construtor para objetos do tipo `default_delete`.

```cpp
constexpr default_delete() noexcept = default;
template <class U>
    default_delete(const default_delete<U>&) noexcept;
```

## <a name="op_paren"></a> Operator)

Um operador de referência para acessar `default_delete`.

```cpp
void operator()(T*) const;
```

## <a name="see-also"></a>Consulte também

[\<memory>](../standard-library/memory.md)
