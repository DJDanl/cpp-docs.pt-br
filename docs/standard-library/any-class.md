---
title: qualquer classe
ms.date: 04/04/2019
f1_keywords:
- any/std::any
- any/std::any::emplace
- any/std::any::has_value
- any/std::any::reset
- any/std::any::swap
- any/std::any::type
helpviewer_keywords:
- any/std::any
- any/std::any::emplace
- any/std::any::has_value
- any/std::any::reset
- any/std::any::swap
- any/std::any::type
ms.openlocfilehash: defec0f6ab8f59219afddcefc67ea93435347978
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88844737"
---
# <a name="any-class"></a>qualquer classe

Armazena uma instância de qualquer tipo que satisfaça os requisitos de construtor ou não tem nenhum valor, que é chamado de estado da classe qualquer objeto.

A instância armazenada é chamada de valor contido. Dois Estados são os mesmos se ambos não têm valor ou ambos têm um valor e os valores contidos são os mesmos.

## <a name="syntax"></a>Sintaxe

```cpp
class any
```

## <a name="members"></a>Membros

### <a name="constructors"></a>Construtores

|Nome|Descrição|
|-|-|
|[outro](#any)|Constrói um objeto do tipo `any`.|

### <a name="functions"></a>Funções

|Nome|Descrição|
|-|-|
|[emplace](#emplace)|Define um valor qualquer.|
|[has_value](#has_value)|Retorna **`true`** se algum tiver um valor.|
|[reset](#reset)|Redefine um any.|
|[permuta](#swap)|Troca dois objetos.|
|[tipo](#type)|Retorna o tipo any.|

### <a name="operators"></a>Operadores

|Nome|Descrição|
|-|-|
|[operador =](#op_eq)|Substitui o qualquer com uma cópia de outro.|

## <a name="any"></a><a name="any"></a> outro

Constrói um objeto do tipo `any`. Também inclui um destruidor.

```cpp
constexpr any() noexcept;
any(const any& other);
any(any&& other) noexcept;
template <class T>
    any(T&& value);
template <class T, class... Args>
    explicit any(in_place_type_t<T>, Args&&...);
template <class T, class U, class... Args>
    explicit any(in_place_type_t<T>, initializer_list<U>, Args&&...);

~any();
```

## <a name="emplace"></a><a name="emplace"></a> emplace

Define um valor qualquer.

```cpp
template <class T, class... Args>
    decay_t<T>& emplace(Args&& ...);
template <class T, class U, class... Args>
    decay_t<T>& emplace(initializer_list<U>, Args&&...);
```

## <a name="has_value"></a><a name="has_value"></a> has_value

Retorna **`true`** se algum tiver um valor.

```cpp
bool has_value() const noexcept;
```

## <a name="operator"></a><a name="op_eq"></a> operador =

Substitui o qualquer com uma cópia de outro.

```cpp
any& operator=(const any& right);
any& operator=(any&& right) noexcept;
template <class T>
    any& operator=(T&& right);
```

### <a name="parameters"></a>parâmetros

*Certo*\
O que está sendo copiado para o.

## <a name="reset"></a><a name="reset"></a> definido

Redefine um any.

```cpp
void reset() noexcept;
```

## <a name="swap"></a><a name="swap"></a> permuta

Troca dois objetos.

```cpp
void swap(any& rhs) noexcept;
```

## <a name="type"></a>Tipo<a name="type"></a>

Retorna o tipo any.

```cpp
const type_info& type() const noexcept;
```
