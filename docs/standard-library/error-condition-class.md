---
title: Classe error_condition
ms.date: 11/04/2016
f1_keywords:
- system_error/std::error_condition
- system_error/std::error_condition::value_type
- system_error/std::error_condition::assign
- system_error/std::error_condition::category
- system_error/std::error_condition::clear
- system_error/std::error_condition::message
- system_error/std::error_condition::operator bool
helpviewer_keywords:
- std::error_condition
- std::error_condition::value_type
- std::error_condition::assign
- std::error_condition::category
- std::error_condition::clear
- std::error_condition::message
ms.assetid: 6690f481-97c9-4554-a0ff-851dc96b7a06
ms.openlocfilehash: 1708a3f560f60fe3933406a904d95b4d29890a7f
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88830768"
---
# <a name="error_condition-class"></a>Classe error_condition

Representa códigos de erro definidos pelo usuário.

## <a name="syntax"></a>Sintaxe

```cpp
class error_condition;
```

## <a name="remarks"></a>Comentários

Um objeto do tipo `error_condition` armazena um valor de código de erro e um ponteiro para um objeto que representa uma [categoria](../standard-library/error-category-class.md) de códigos de erro usados para os erros relatados definidos pelo usuário.

## <a name="members"></a>Membros

### <a name="constructors"></a>Construtores

|Nome|Descrição|
|-|-|
|[error_condition](#error_condition)|Constrói um objeto do tipo `error_condition`.|

### <a name="typedefs"></a>Typedefs

|Nome|Descrição|
|-|-|
|[value_type](#value_type)|Um tipo que representa o valor do código de erro armazenado.|

### <a name="functions"></a>Funções

|Nome|Descrição|
|-|-|
|[assign](#assign)|Atribui um valor de código de erro e categoria a uma condição de erro.|
|[category](#category)|Retorna a categoria de erro.|
|[formatação](#clear)|Limpa o valor do código de erro e a categoria.|
|[message](#message)|Retorna o nome do código de erro.|

### <a name="operators"></a>Operadores

|Nome|Descrição|
|-|-|
|[operador = =](#op_eq_eq)|Testa a igualdade entre objetos `error_condition`.|
|[operador! =](#op_neq)|Testa a desigualdade entre objetos `error_condition`.|
|[<do operador ](#op_lt)|Testa se o objeto `error_condition` é menor que o objeto `error_code` passado para comparação.|
|[operador =](#op_eq)|Atribui um novo valor de enumeração ao objeto `error_condition`.|
|[booliano de operador](#op_bool)|Converte uma variável do tipo `error_condition`.|

### <a name="assign"></a><a name="assign"></a> Cancele

Atribui um valor de código de erro e categoria a uma condição de erro.

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

### <a name="category"></a><a name="category"></a> Categorias

Retorna a categoria de erro.

```cpp
const error_category& category() const;
```

#### <a name="return-value"></a>Valor Retornado

Uma referência à categoria do erro armazenado

#### <a name="remarks"></a>Comentários

### <a name="clear"></a><a name="clear"></a> formatação

Limpa o valor do código de erro e a categoria.

```cpp
clear();
```

#### <a name="remarks"></a>Comentários

A função de membro armazena um valor zero de código de erro e um ponteiro para o objeto [generic_category](../standard-library/system-error-functions.md#generic_category).

### <a name="error_condition"></a><a name="error_condition"></a> error_condition

Constrói um objeto do tipo `error_condition`.

```cpp
error_condition();

error_condition(value_type val, const error_category& _Cat);

template <class _Enum>
error_condition(_Enum _Errcode,
    typename enable_if<is_error_condition_enum<_Enum>::value,
    error_code>::type* = 0);
```

#### <a name="parameters"></a>parâmetros

*Val*\
O valor de código de erro para armazenar em `error_condition`.

*_Cat*\
A categoria de erro para armazenar em `error_condition`.

*_Errcode*\
O valor da enumeração para armazenar em `error_condition`.

#### <a name="remarks"></a>Comentários

O primeiro construtor armazena um valor zero de código de erro e um ponteiro para [generic_category](../standard-library/system-error-functions.md#generic_category).

O segundo Construtor armazena *Val* como o valor do código de erro e um ponteiro para [error_category](../standard-library/error-category-class.md).

O terceiro construtor armazena `(value_type)_Errcode` como o valor de código de erro e um ponteiro para [generic_category](../standard-library/system-error-functions.md#generic_category).

### <a name="message"></a><a name="message"></a> Mensagem

Retorna o nome do código de erro.

```cpp
string message() const;
```

#### <a name="return-value"></a>Valor Retornado

Uma `string` que representa o nome do código de erro.

#### <a name="remarks"></a>Comentários

Essa função membro retorna `category().message(value())`.

### <a name="operator"></a><a name="op_eq_eq"></a> operador = =

Testa a igualdade entre objetos `error_condition`.

```cpp
bool operator==(const error_condition& right) const;
```

#### <a name="parameters"></a>parâmetros

*Certo*\
O objeto a ser testado quanto à igualdade.

#### <a name="return-value"></a>Valor Retornado

**`true`** Se os objetos forem iguais; **`false`** se os objetos não forem iguais.

#### <a name="remarks"></a>Comentários

O operador de membro retorna `category() == right.category() && value == right.value()`.

### <a name="operator"></a><a name="op_neq"></a> operador! =

Testa a desigualdade entre objetos `error_condition`.

```cpp
bool operator!=(const error_condition& right) const;
```

#### <a name="parameters"></a>parâmetros

*Certo*\
O objeto a ser testado quanto à desigualdade.

#### <a name="return-value"></a>Valor Retornado

**`true`** Se o `error_condition` objeto não for igual ao `error_condition` objeto transmitido *à direita*; caso contrário, **`false`** .

#### <a name="remarks"></a>Comentários

O operador de membro retorna `!(*this == right)`.

### <a name="operatorlt"></a><a name="op_lt"></a> operador&lt;

Testa se o objeto `error_condition` é menor que o objeto `error_code` passado para comparação.

```cpp
bool operator<(const error_condition& right) const;
```

#### <a name="parameters"></a>parâmetros

*Certo*\
O objeto `error_condition` a ser comparado.

#### <a name="return-value"></a>Valor Retornado

**`true`** Se o `error_condition` objeto for menor do que o `error_condition` objeto passado para comparação; Caso contrário, **`false`** .

#### <a name="remarks"></a>Comentários

O operador de membro retorna `category() < right.category() || category() == right.category() && value < right.value()`.

### <a name="operator"></a><a name="op_eq"></a> operador =

Atribui um novo valor de enumeração ao objeto `error_condition`.

```cpp
template <class _Enum>
error_condition(_Enum error,
    typename enable_if<is_error_condition_enum<_Enum>::value,
    error_condition>::type&
    operator=(Enum _Errcode);
```

#### <a name="parameters"></a>parâmetros

*_Errcode*\
O valor de enumeração a ser atribuído ao objeto `error_condition`.

#### <a name="return-value"></a>Valor Retornado

Uma referência ao objeto `error_condition` ao qual está sendo atribuído um novo valor de enumeração pela função de membro.

#### <a name="remarks"></a>Comentários

O operador membro armazena `(value_type)error` como o valor de código de erro e um ponteiro para [generic_category](../standard-library/system-error-functions.md#generic_category). Ele retorna **`*this`** .

### <a name="operator-bool"></a><a name="op_bool"></a> booliano de operador

Converte uma variável do tipo `error_condition`.

```cpp
explicit operator bool() const;
```

#### <a name="return-value"></a>Valor Retornado

O valor booliano do objeto `error_condition`.

#### <a name="remarks"></a>Comentários

O operador retornará um valor conversível **`true`** somente se o [valor](#value) não for igual a zero. O tipo de retorno é conversível apenas para **`bool`** , e não para `void *` ou outros tipos escalares conhecidos.

### <a name="value"></a><a name="value"></a> valor

Retorna o valor de código de erro armazenado.

```cpp
value_type value() const;
```

#### <a name="return-value"></a>Valor Retornado

O valor do código de erro armazenado do tipo [value_type](#value_type).

#### <a name="remarks"></a>Comentários

### <a name="value_type"></a><a name="value_type"></a> value_type

Um tipo que representa o valor do código de erro armazenado.

```cpp
typedef int value_type;
```

#### <a name="remarks"></a>Comentários

A definição de tipo é um sinônimo para **`int`** .
