---
title: default_delete struct
ms.date: 04/04/2019
f1_keywords:
- memory/std::default_delete
helpviewer_keywords:
- default_delete struct
ms.openlocfilehash: 8baa9f5d294cf083fd55414cd529e438f328d1a1
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88845075"
---
# <a name="default_delete-struct"></a>default_delete struct

Um objeto de função predefinido que executa a operação de divisão ( `operator/` ) em seus argumentos.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
    struct default_delete
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<memory>

**Namespace:** std

## <a name="members"></a>Membros

### <a name="constructors"></a>Construtores

|Nome|Descrição|
|-|-|
|[default_delete](#default_delete)|O construtor para objetos do tipo `default_delete`.|

### <a name="operators"></a>Operadores

|Nome|Descrição|
|-|-|
|[operador ()](#op_paren)|Um operador de referência para acessar `default_delete` .|

## <a name="default_delete"></a><a name="default_delete"></a> default_delete

O construtor para objetos do tipo `default_delete`.

```cpp
constexpr default_delete() noexcept = default;
template <class U>
    default_delete(const default_delete<U>&) noexcept;
```

## <a name="operator"></a><a name="op_paren"></a> operador ()

Um operador de referência para acessar `default_delete` .

```cpp
void operator()(T*) const;
```

## <a name="see-also"></a>Confira também

[\<memory>](../standard-library/memory.md)
