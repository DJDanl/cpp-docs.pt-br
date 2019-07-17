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
ms.openlocfilehash: cbadf6a22871cc9a23d37c095a398490c8a4c72c
ms.sourcegitcommit: 3590dc146525807500c0477d6c9c17a4a8a2d658
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/16/2019
ms.locfileid: "68245796"
---
# <a name="errorcondition-class"></a>Classe error_condition

Representa códigos de erro definidos pelo usuário.

## <a name="syntax"></a>Sintaxe

```cpp
class error_condition;
```

## <a name="remarks"></a>Comentários

Um objeto do tipo `error_condition` armazena um valor de código de erro e um ponteiro para um objeto que representa uma [categoria](../standard-library/error-category-class.md) de códigos de erro usados para os erros relatados definidos pelo usuário.

## <a name="members"></a>Membros

### <a name="constructors"></a>Construtores

|||
|-|-|
|[error_condition](#error_condition)|Constrói um objeto do tipo `error_condition`.|

### <a name="typedefs"></a>Typedefs

|||
|-|-|
|[value_type](#value_type)|Um tipo que representa o valor do código de erro armazenado.|

### <a name="functions"></a>Funções

|||
|-|-|
|[assign](#assign)|Atribui um valor de código de erro e categoria a uma condição de erro.|
|[category](#category)|Retorna a categoria de erro.|
|[clear](#clear)|Limpa o valor do código de erro e a categoria.|
|[message](#message)|Retorna o nome do código de erro.|

### <a name="operators"></a>Operadores

|||
|-|-|
|[operator==](#op_eq_eq)|Testa a igualdade entre objetos `error_condition`.|
|[operator!=](#op_neq)|Testa a desigualdade entre objetos `error_condition`.|
|[operator<](#op_lt)|Testa se o objeto `error_condition` é menor que o objeto `error_code` passado para comparação.|
|[operator=](#op_eq)|Atribui um novo valor de enumeração ao objeto `error_condition`.|
|[operator bool](#op_bool)|Converte uma variável do tipo `error_condition`.|

### <a name="assign"></a> Atribuir

Atribui um valor de código de erro e categoria a uma condição de erro.

```cpp
void assign(value_type val, const error_category& _Cat);
```

#### <a name="parameters"></a>Parâmetros

*Val*\
O valor de código de erro para armazenar em `error_code`.

*Esteja*\
A categoria de erro para armazenar em `error_code`.

#### <a name="remarks"></a>Comentários

A função membro armazena *val* como o valor de código de erro e um ponteiro para *esteja*.

### <a name="category"></a> categoria

Retorna a categoria de erro.

```cpp
const error_category& category() const;
```

#### <a name="return-value"></a>Valor de retorno

Uma referência à categoria do erro armazenado

#### <a name="remarks"></a>Comentários

### <a name="clear"></a> Limpar

Limpa o valor do código de erro e a categoria.

```cpp
clear();
```

#### <a name="remarks"></a>Comentários

A função de membro armazena um valor zero de código de erro e um ponteiro para o objeto [generic_category](../standard-library/system-error-functions.md#generic_category).

### <a name="error_condition"></a> error_condition

Constrói um objeto do tipo `error_condition`.

```cpp
error_condition();

error_condition(value_type val, const error_category& _Cat);

template <class _Enum>
error_condition(_Enum _Errcode,
    typename enable_if<is_error_condition_enum<_Enum>::value,
    error_code>::type* = 0);
```

#### <a name="parameters"></a>Parâmetros

*Val*\
O valor de código de erro para armazenar em `error_condition`.

*Esteja*\
A categoria de erro para armazenar em `error_condition`.

*_Errcode*\
O valor da enumeração para armazenar em `error_condition`.

#### <a name="remarks"></a>Comentários

O primeiro construtor armazena um valor zero de código de erro e um ponteiro para [generic_category](../standard-library/system-error-functions.md#generic_category).

O segundo construtor armazena *val* como o valor de código de erro e um ponteiro para [error_category](../standard-library/error-category-class.md).

O terceiro construtor armazena `(value_type)_Errcode` como o valor de código de erro e um ponteiro para [generic_category](../standard-library/system-error-functions.md#generic_category).

### <a name="message"></a> Mensagem

Retorna o nome do código de erro.

```cpp
string message() const;
```

#### <a name="return-value"></a>Valor de retorno

Uma `string` que representa o nome do código de erro.

#### <a name="remarks"></a>Comentários

Essa função membro retorna `category().message(value())`.

### <a name="op_eq_eq"></a> operador = =

Testa a igualdade entre objetos `error_condition`.

```cpp
bool operator==(const error_condition& right) const;
```

#### <a name="parameters"></a>Parâmetros

*Certo*\
O objeto a ser testado quanto à igualdade.

#### <a name="return-value"></a>Valor de retorno

**true** se os objetos forem iguais; **false** se os objetos não forem iguais.

#### <a name="remarks"></a>Comentários

O operador de membro retorna `category() == right.category() && value == right.value()`.

### <a name="op_neq"></a> operador! =

Testa a desigualdade entre objetos `error_condition`.

```cpp
bool operator!=(const error_condition& right) const;
```

#### <a name="parameters"></a>Parâmetros

*Certo*\
O objeto a ser testado quanto à desigualdade.

#### <a name="return-value"></a>Valor de retorno

**True** se o `error_condition` objeto não é igual ao `error_condition` objeto passado *direita*; caso contrário **false**.

#### <a name="remarks"></a>Comentários

O operador de membro retorna `!(*this == right)`.

### <a name="op_lt"></a> Operador&lt;

Testa se o objeto `error_condition` é menor que o objeto `error_code` passado para comparação.

```cpp
bool operator<(const error_condition& right) const;
```

#### <a name="parameters"></a>Parâmetros

*Certo*\
O objeto `error_condition` a ser comparado.

#### <a name="return-value"></a>Valor de retorno

**true** se o objeto `error_condition` for menor que o objeto `error_condition` passado para comparação. Caso contrário, **false**.

#### <a name="remarks"></a>Comentários

O operador de membro retorna `category() < right.category() || category() == right.category() && value < right.value()`.

### <a name="op_eq"></a> operador =

Atribui um novo valor de enumeração ao objeto `error_condition`.

```cpp
template <class _Enum>
error_condition(_Enum error,
    typename enable_if<is_error_condition_enum<_Enum>::value,
    error_condition>::type&
    operator=(Enum _Errcode);
```

#### <a name="parameters"></a>Parâmetros

*_Errcode*\
O valor de enumeração a ser atribuído ao objeto `error_condition`.

#### <a name="return-value"></a>Valor de retorno

Uma referência ao objeto `error_condition` ao qual está sendo atribuído um novo valor de enumeração pela função de membro.

#### <a name="remarks"></a>Comentários

O operador membro armazena `(value_type)error` como o valor de código de erro e um ponteiro para [generic_category](../standard-library/system-error-functions.md#generic_category). Ele retorna `*this`.

### <a name="op_bool"></a> operador bool

Converte uma variável do tipo `error_condition`.

```cpp
explicit operator bool() const;
```

#### <a name="return-value"></a>Valor de retorno

O valor booliano do objeto `error_condition`.

#### <a name="remarks"></a>Comentários

O operador retorna um valor conversível em **verdadeira** somente se [valor](#value) não é igual a zero. O tipo de retorno é conversível apenas em **bool**, não em `void *` ou outros tipos escalares conhecidos.

### <a name="value"></a> Valor

Retorna o valor de código de erro armazenado.

```cpp
value_type value() const;
```

#### <a name="return-value"></a>Valor de retorno

O valor do código de erro armazenado do tipo [value_type](#value_type).

#### <a name="remarks"></a>Comentários

### <a name="value_type"></a> value_type

Um tipo que representa o valor do código de erro armazenado.

```cpp
typedef int value_type;
```

#### <a name="remarks"></a>Comentários

A definição de tipo é um sinônimo de **int**.
