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
ms.openlocfilehash: 050276da665ab6ed3eb53d9e65bfea06b88bcbea
ms.sourcegitcommit: 3590dc146525807500c0477d6c9c17a4a8a2d658
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/16/2019
ms.locfileid: "68268748"
---
# <a name="any-class"></a>qualquer classe

Armazena uma instância de qualquer tipo que satisfaça os requisitos de construtor ou ele não tem valor, que é chamado o estado da classe de qualquer objeto.

A instância armazenada é chamada o valor contido. Dois estados são os mesmos se ambos não têm nenhum valor, ou ambos têm um valor e os valores contidos são os mesmos.

## <a name="syntax"></a>Sintaxe

```cpp
class any
```

## <a name="members"></a>Membros

### <a name="constructors"></a>Construtores

|||
|-|-|
|[any](#any)|Constrói um objeto do tipo `any`.|

### <a name="functions"></a>Funções

|||
|-|-|
|[emplace](#emplace)|Define um valor de qualquer.|
|[has_value](#has_value)|Retorna **verdadeira** se qualquer uma tem um valor.|
|[reset](#reset)|Redefine qualquer.|
|[swap](#swap)|Troca dois objetos.|
|[type](#type)|Retorna o tipo any.|

### <a name="operators"></a>Operadores

|||
|-|-|
|[operator=](#op_eq)|Substitui a qualquer um com uma cópia de outro qualquer.|

## <a name="any"></a> Qualquer

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

## <a name="emplace"></a> emplace

Define um valor de qualquer.

```cpp
template <class T, class... Args>
    decay_t<T>& emplace(Args&& ...);
template <class T, class U, class... Args>
    decay_t<T>& emplace(initializer_list<U>, Args&&...);
```

## <a name="has_value"></a> has_value

Retorna **verdadeira** se qualquer uma tem um valor.

```cpp
bool has_value() const noexcept;
```

## <a name="op_eq"></a> operador =

Substitui a qualquer um com uma cópia de outro qualquer.

```cpp
any& operator=(const any& right);
any& operator=(any&& right) noexcept;
template <class T>
    any& operator=(T&& right);
```

### <a name="parameters"></a>Parâmetros

*Certo*\
A qualquer um que está sendo copiado para quaisquer.

## <a name="reset"></a> Redefinir

Redefine qualquer.

```cpp
void reset() noexcept;
```

## <a name="swap"></a> troca

Troca dois objetos.

```cpp
void swap(any& rhs) noexcept;
```

## <a name="type"></a> Tipo

Retorna o tipo any.

```cpp
const type_info& type() const noexcept;
```
