---
title: Classe error_code
ms.date: 11/04/2016
f1_keywords:
- system_error/std::error_code
- system_error/std::error_code::value_type
- system_error/std::error_code::assign
- system_error/std::error_code::category
- system_error/std::error_code::clear
- system_error/std::error_code::default_error_condition
- system_error/std::error_code::message
- system_error/std::error_code::operator bool
helpviewer_keywords:
- std::error_code
- std::error_code::value_type
- std::error_code::assign
- std::error_code::category
- std::error_code::clear
- std::error_code::default_error_condition
- std::error_code::message
ms.assetid: c09b4a96-cb14-4281-a319-63543f9b2b4a
ms.openlocfilehash: 3f272c25572ebebd95e5a59b50094d8e1872c90a
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87228278"
---
# <a name="error_code-class"></a>Classe error_code

Representa os erros de sistema de nível inferior específicos à implementação.

## <a name="syntax"></a>Sintaxe

```cpp
class error_code;
```

## <a name="remarks"></a>Comentários

Um objeto do tipo de classe `error_code` armazena um valor de código de erro e um ponteiro para um objeto que representa uma [categoria](../standard-library/error-category-class.md) de códigos de erro que descrevem erros de sistema de nível inferior relatados.

## <a name="members"></a>Membros

### <a name="constructors"></a>Construtores

|||
|-|-|
|[error_code](#error_code)|Constrói um objeto do tipo `error_code`.|

### <a name="typedefs"></a>Typedefs

|||
|-|-|
|[value_type](#value_type)|Um tipo que representa o valor do código de erro armazenado.|

### <a name="functions"></a>Funções

|||
|-|-|
|[assign](#assign)|Atribui um valor de código de erro e categoria a um código de erro.|
|[category](#category)|Retorna a categoria de erro.|
|[formatação](#clear)|Limpa o valor do código de erro e a categoria.|
|[default_error_condition](#default_error_condition)|Retorna a condição de erro padrão.|
|[message](#message)|Retorna o nome do código de erro.|

### <a name="operators"></a>Operadores

|||
|-|-|
|[operador = =](#op_eq_eq)|Testa a igualdade entre objetos `error_code`.|
|[operador! =](#op_neq)|Testa a desigualdade entre objetos `error_code`.|
|[<do operador](#op_lt)|Testa se o objeto `error_code` é menor que o objeto `error_code` passado para comparação.|
|[operador =](#op_eq)|Atribui um novo valor de enumeração ao objeto `error_code`.|
|[booliano de operador](#op_bool)|Converte uma variável do tipo `error_code`.|

### <a name="assign"></a><a name="assign"></a>Cancele

Atribui um valor de código de erro e categoria a um código de erro.

```cpp
void assign(value_type val, const error_category& _Cat);
```

#### <a name="parameters"></a>parâmetros

*Val*\
O valor de código de erro para armazenar em `error_code`.

*_Cat*\
A categoria de erro para armazenar em `error_code`.

#### <a name="remarks"></a>Comentários

A função membro armazena *Val* como o valor do código de erro e um ponteiro para *_Cat*.

### <a name="category"></a><a name="category"></a>Categorias

Retorna a categoria de erro.

```cpp
const error_category& category() const;
```

#### <a name="remarks"></a>Comentários

### <a name="clear"></a><a name="clear"></a>formatação

Limpa o valor do código de erro e a categoria.

```cpp
clear();
```

#### <a name="remarks"></a>Comentários

A função de membro armazena um valor zero de código de erro e um ponteiro para o objeto [generic_category](../standard-library/system-error-functions.md#generic_category).

### <a name="default_error_condition"></a><a name="default_error_condition"></a>default_error_condition

Retorna a condição de erro padrão.

```cpp
error_condition default_error_condition() const;
```

#### <a name="return-value"></a>Valor retornado

O [error_condition](../standard-library/error-condition-class.md) especificado por [default_error_condition](../standard-library/error-category-class.md#default_error_condition).

#### <a name="remarks"></a>Comentários

Essa função membro retorna `category().default_error_condition(value())`.

### <a name="error_code"></a><a name="error_code"></a>error_code

Constrói um objeto do tipo `error_code`.

```cpp
error_code();

error_code(value_type val, const error_category& _Cat);

template <class _Enum>
error_code(_Enum _Errcode,
    typename enable_if<is_error_code_enum<_Enum>::value,
    error_code>::type* = 0);
```

#### <a name="parameters"></a>parâmetros

*Val*\
O valor de código de erro para armazenar em `error_code`.

*_Cat*\
A categoria de erro para armazenar em `error_code`.

*_Errcode*\
O valor da enumeração para armazenar em `error_code`.

#### <a name="remarks"></a>Comentários

O primeiro construtor armazena um valor zero de código de erro e um ponteiro para [generic_category](../standard-library/system-error-functions.md#generic_category).

O segundo Construtor armazena *Val* como o valor do código de erro e um ponteiro para [error_category](../standard-library/error-category-class.md).

O terceiro construtor armazena `(value_type)_Errcode` como o valor de código de erro e um ponteiro para [generic_category](../standard-library/system-error-functions.md#generic_category).

### <a name="message"></a><a name="message"></a>Mensagem

Retorna o nome do código de erro.

```cpp
string message() const;
```

#### <a name="return-value"></a>Valor retornado

Uma `string` que representa o nome do código de erro.

#### <a name="remarks"></a>Comentários

Essa função membro retorna `category().message(value())`.

### <a name="operator"></a><a name="op_eq_eq"></a>operador = =

Testa a igualdade entre objetos `error_code`.

```cpp
bool operator==(const error_code& right) const;
```

#### <a name="parameters"></a>parâmetros

*Certo*\
O objeto a ser testado quanto à igualdade.

#### <a name="return-value"></a>Valor retornado

**`true`** Se os objetos forem iguais; **`false`** se os objetos não forem iguais.

#### <a name="remarks"></a>Comentários

O operador de membro retorna `category() == right.category() && value == right.value()`.

### <a name="operator"></a><a name="op_neq"></a>operador! =

Testa a desigualdade entre objetos `error_code`.

```cpp
bool operator!=(const error_code& right) const;
```

#### <a name="parameters"></a>parâmetros

*Certo*\
O objeto a ser testado quanto à desigualdade.

#### <a name="return-value"></a>Valor retornado

**`true`** Se o `error_code` objeto não for igual ao `error_code` objeto transmitido *à direita*; caso contrário, **`false`** .

#### <a name="remarks"></a>Comentários

O operador de membro retorna `!(*this == right)`.

### <a name="operatorlt"></a><a name="op_lt"></a>operador&lt;

Testa se o objeto `error_code` é menor que o objeto `error_code` passado para comparação.

```cpp
bool operator<(const error_code& right) const;
```

#### <a name="parameters"></a>parâmetros

*Certo*\
O objeto error_code a ser comparado.

#### <a name="return-value"></a>Valor retornado

**`true`** Se o `error_code` objeto for menor do que o `error_code` objeto passado para comparação; Caso contrário, **`false`** .

#### <a name="remarks"></a>Comentários

O operador de membro retorna `category() < right.category() || category() == right.category() && value < right.value()`.

### <a name="operator"></a><a name="op_eq"></a>operador =

Atribui um novo valor de enumeração ao objeto `error_code`.

```cpp
template <class _Enum>
typename enable_if<is_error_code_enum<_Enum>::value, error_code>::type&
    operator=(_Enum _Errcode);
```

#### <a name="parameters"></a>parâmetros

*_Errcode*\
O valor de enumeração a ser atribuído ao objeto `error_code`.

#### <a name="return-value"></a>Valor retornado

Uma referência ao objeto `error_code` ao qual está sendo atribuído um novo valor de enumeração pela função de membro.

#### <a name="remarks"></a>Comentários

O operador membro armazena `(value_type)_Errcode` como o valor de código de erro e um ponteiro para [generic_category](../standard-library/system-error-functions.md#generic_category). Ele retorna **`*this`** .

### <a name="operator-bool"></a><a name="op_bool"></a>booliano de operador

Converte uma variável do tipo `error_code`.

```cpp
explicit operator bool() const;
```

#### <a name="return-value"></a>Valor retornado

O valor booliano do objeto `error_code`.

#### <a name="remarks"></a>Comentários

O operador retornará um valor conversível **`true`** somente se o [valor](#value) não for igual a zero. O tipo de retorno é conversível apenas para **`bool`** , e não para `void *` ou outros tipos escalares conhecidos.

### <a name="value"></a><a name="value"></a> valor

Retorna o valor de código de erro armazenado.

```cpp
value_type value() const;
```

### <a name="return-value"></a>Valor retornado

O valor do código de erro armazenado do tipo [value_type](#value_type).

### <a name="value_type"></a><a name="value_type"></a>value_type

Um tipo que representa o valor do código de erro armazenado.

```cpp
typedef int value_type;
```

#### <a name="remarks"></a>Comentários

Essa definição de tipo é um sinônimo para **`int`** .
