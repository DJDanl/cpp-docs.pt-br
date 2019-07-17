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
ms.openlocfilehash: 308fa1a2309ddfda1a02fe6a687360185c1e7c6e
ms.sourcegitcommit: 3590dc146525807500c0477d6c9c17a4a8a2d658
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/16/2019
ms.locfileid: "68245848"
---
# <a name="errorcategory-class"></a>Classe error_category

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

## <a name="default_error_condition"></a> default_error_condition

Armazena o valor de código de erro para um objeto de condição de erro.

```cpp
virtual error_condition default_error_condition(int _Errval) const;
```

### <a name="parameters"></a>Parâmetros

*_Errval*\
O valor de código de erro para armazenar em [error_condition](../standard-library/error-condition-class.md).

### <a name="return-value"></a>Valor de retorno

Retorna `error_condition(_Errval, *this)`.

### <a name="remarks"></a>Comentários

### <a name="equivalent"></a> equivalente

Retorna um valor que especifica se os objetos de erro são equivalentes.

```cpp
virtual bool equivalent(value_type _Errval,
    const error_condition& _Cond) const;

virtual bool equivalent(const error_code& _Code,
    value_type _Errval) const;
```

#### <a name="parameters"></a>Parâmetros

*_Errval*\
O valor do código de erro a ser comparado.

*_Cond*\
O objeto [error_condition](../standard-library/error-condition-class.md) a ser comparado.

*Code*\
O objeto [error_code](../standard-library/error-code-class.md) a ser comparado.

#### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se a categoria e valor forem iguais; caso contrário, **falso**.

#### <a name="remarks"></a>Comentários

A primeira função membro retorna `*this == _Cond.category() && _Cond.value() == _Errval`.

A segunda função membro retorna `*this == _Code.category() && _Code.value() == _Errval`.

### <a name="generic"></a> generic_category

```cpp
const error_category& generic_category();
```

### <a name="message"></a> Mensagem

Retorna o nome do código de erro especificado.

```cpp
virtual string message(error_code::value_type val) const = 0;
```

#### <a name="parameters"></a>Parâmetros

*Val*\
O valor do código de erro a ser descrito.

#### <a name="return-value"></a>Valor de retorno

Retorna um nome descritivo do código de erro *val* para a categoria.

#### <a name="remarks"></a>Comentários

### <a name="name"></a> Nome

Retorna o nome da categoria.

```cpp
virtual const char *name() const = 0;
```

#### <a name="return-value"></a>Valor de retorno

Retorna o nome da categoria como uma cadeia de caracteres de byte com terminação nula.

### <a name="op_as"></a> operador =

```cpp
error_category& operator=(const error_category&) = delete;
```


### <a name="op_eq_eq"></a> operador = =

Testa a igualdade entre objetos `error_category`.

```cpp
bool operator==(const error_category& right) const;
```

#### <a name="parameters"></a>Parâmetros

*Certo*\
O objeto a ser testado quanto à igualdade.

#### <a name="return-value"></a>Valor de retorno

**true** se os objetos forem iguais; **false** se os objetos não forem iguais.

#### <a name="remarks"></a>Comentários

Esse operador de membro retorna `this == &right`.

### <a name="op_neq"></a> operador! =

Testa a desigualdade entre objetos `error_category`.

```cpp
bool operator!=(const error_category& right) const;
```

#### <a name="parameters"></a>Parâmetros

*Certo*\
O objeto a ser testado quanto à desigualdade.

#### <a name="return-value"></a>Valor de retorno

**True** se o `error_category` objeto não é igual ao `error_category` objeto passado *direita*; caso contrário **false**.

#### <a name="remarks"></a>Comentários

O operador de membro retorna `(!*this == right)`.

### <a name="op_lt"></a> Operador&lt;

Testa se um objeto [error_category](../standard-library/error-category-class.md) é menor que o objeto `error_category` passado para comparação.

```cpp
bool operator<(const error_category& right) const;
```

#### <a name="parameters"></a>Parâmetros

*Certo*\
O objeto `error_category` a ser comparado.

#### <a name="return-value"></a>Valor de retorno

**true** se o objeto `error_category` for menor que o objeto `error_category` passado para comparação. Caso contrário, **false**.

#### <a name="remarks"></a>Comentários

O operador de membro retorna `this < &right`.

### <a name="system"></a> system_category

```cpp
const error_category& system_category();
```

### <a name="value_type"></a> value_type

Um tipo que representa o valor do código de erro armazenado.

```cpp
typedef int value_type;
```

#### <a name="remarks"></a>Comentários

Essa definição de tipo é um sinônimo de **int**.
