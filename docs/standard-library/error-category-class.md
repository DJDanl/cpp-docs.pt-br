---
title: Classe error_category
ms.date: 11/04/2016
f1_keywords:
- system_error/std::error_category
- system_error/std::error_category::value_type
- system_error/std::error_category::default_error_condition
- system_error/std::error_category::equivalent
- system_error/std::error_category::message
- system_error/std::error_category::name
helpviewer_keywords:
- std::error_category
- std::error_category::value_type
- std::error_category::default_error_condition
- std::error_category::equivalent
- std::error_category::message
- std::error_category::name
ms.assetid: e0a71e14-852d-4905-acd6-5f8ed426706d
ms.openlocfilehash: 3ed2eceb60c2efa78181faea58a256b0e35d489f
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80076609"
---
# <a name="error_category-class"></a>Classe error_category

Representa a base abstrata e comum para objetos e descreve uma categoria de códigos de erro.

## <a name="syntax"></a>Sintaxe

```cpp
class error_category;

constexpr error_category() noexcept;
virtual ~error_category();
error_category(const error_category&) = delete
```

## <a name="remarks"></a>Comentários

Dois objetos predefinidos implementam `error_category`: [generic_category](../standard-library/system-error-functions.md#generic_category) e [system_category](../standard-library/system-error-functions.md#system_category).

## <a name="members"></a>Membros

### <a name="typedefs"></a>Typedefs

|||
|-|-|
|[value_type](#value_type)|Um tipo que representa o valor do código de erro armazenado.|

### <a name="functions"></a>Funções

|||
|-|-|
|[default_error_condition](#default_error_condition)|Armazena o valor de código de erro para um objeto de condição de erro.|
|[equivalent](#equivalent)|Retorna um valor que especifica se os objetos de erro são equivalentes.|
|[generic_category](#generic)||
|[message](#message)|Retorna o nome do código de erro especificado.|
|[name](#name)|Retorna o nome da categoria.|
|[system_category](#system)||

### <a name="operators"></a>Operadores

|||
|-|-|
|[operator=](#op_as)||
|[operator==](#op_eq_eq)|Testa a igualdade entre objetos `error_category`.|
|[operator!=](#op_neq)|Testa a desigualdade entre objetos `error_category`.|
|[operator<](#op_lt)|Testa se um objeto [error_category](../standard-library/error-category-class.md) é menor que o objeto `error_category` passado para comparação.|

## <a name="default_error_condition"></a><a name="default_error_condition"></a>default_error_condition

Armazena o valor de código de erro para um objeto de condição de erro.

```cpp
virtual error_condition default_error_condition(int _Errval) const;
```

### <a name="parameters"></a>parâmetros

*_Errval*\
O valor de código de erro para armazenar em [error_condition](../standard-library/error-condition-class.md).

### <a name="return-value"></a>Valor retornado

Retorna `error_condition(_Errval, *this)`.

### <a name="remarks"></a>Comentários

### <a name="equivalent"></a><a name="equivalent"></a>equivalente

Retorna um valor que especifica se os objetos de erro são equivalentes.

```cpp
virtual bool equivalent(value_type _Errval,
    const error_condition& _Cond) const;

virtual bool equivalent(const error_code& _Code,
    value_type _Errval) const;
```

#### <a name="parameters"></a>parâmetros

*_Errval*\
O valor do código de erro a ser comparado.

*_Cond*\
O objeto [error_condition](../standard-library/error-condition-class.md) a ser comparado.

*_Code*\
O objeto [error_code](../standard-library/error-code-class.md) a ser comparado.

#### <a name="return-value"></a>Valor retornado

**true** se a categoria e o valor forem iguais; caso contrário, **false**.

#### <a name="remarks"></a>Comentários

A primeira função membro retorna `*this == _Cond.category() && _Cond.value() == _Errval`.

A segunda função membro retorna `*this == _Code.category() && _Code.value() == _Errval`.

### <a name="generic_category"></a><a name="generic"></a>generic_category

```cpp
const error_category& generic_category();
```

### <a name="message"></a><a name="message"></a>Mensagem

Retorna o nome do código de erro especificado.

```cpp
virtual string message(error_code::value_type val) const = 0;
```

#### <a name="parameters"></a>parâmetros

*valor*\
O valor do código de erro a ser descrito.

#### <a name="return-value"></a>Valor retornado

Retorna um nome descritivo do *valor* do código de erro para a categoria.

#### <a name="remarks"></a>Comentários

### <a name="name"></a><a name="name"></a>nomes

Retorna o nome da categoria.

```cpp
virtual const char *name() const = 0;
```

#### <a name="return-value"></a>Valor retornado

Retorna o nome da categoria como uma cadeia de caracteres de byte com terminação nula.

### <a name="operator"></a><a name="op_as"></a>operador =

```cpp
error_category& operator=(const error_category&) = delete;
```

### <a name="operator"></a><a name="op_eq_eq"></a>operador = =

Testa a igualdade entre objetos `error_category`.

```cpp
bool operator==(const error_category& right) const;
```

#### <a name="parameters"></a>parâmetros

\ *à direita*
O objeto a ser testado quanto à igualdade.

#### <a name="return-value"></a>Valor retornado

**true** se os objetos forem iguais; **false** se os objetos não forem iguais.

#### <a name="remarks"></a>Comentários

Esse operador de membro retorna `this == &right`.

### <a name="operator"></a><a name="op_neq"></a>operador! =

Testa a desigualdade entre objetos `error_category`.

```cpp
bool operator!=(const error_category& right) const;
```

#### <a name="parameters"></a>parâmetros

\ *à direita*
O objeto a ser testado quanto à desigualdade.

#### <a name="return-value"></a>Valor retornado

**true** se o objeto `error_category` não for igual ao objeto `error_category` passado para a *direita*; caso contrário, **false**.

#### <a name="remarks"></a>Comentários

O operador de membro retorna `(!*this == right)`.

### <a name="operatorlt"></a><a name="op_lt">Operador </a>&lt;

Testa se um objeto [error_category](../standard-library/error-category-class.md) é menor que o objeto `error_category` passado para comparação.

```cpp
bool operator<(const error_category& right) const;
```

#### <a name="parameters"></a>parâmetros

\ *à direita*
O objeto `error_category` a ser comparado.

#### <a name="return-value"></a>Valor retornado

**true** se o objeto `error_category` for menor que o objeto `error_category` passado para comparação. Caso contrário, **false**.

#### <a name="remarks"></a>Comentários

O operador de membro retorna `this < &right`.

### <a name="system_category"></a><a name="system"></a>system_category

```cpp
const error_category& system_category();
```

### <a name="value_type"></a><a name="value_type"></a>value_type

Um tipo que representa o valor do código de erro armazenado.

```cpp
typedef int value_type;
```

#### <a name="remarks"></a>Comentários

Essa definição de tipo é um sinônimo para **int**.
