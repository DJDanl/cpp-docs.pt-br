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
ms.openlocfilehash: 919a2a81c66de9adf15deeae8cf8ff3dea08762e
ms.sourcegitcommit: 3590dc146525807500c0477d6c9c17a4a8a2d658
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/16/2019
ms.locfileid: "68245827"
---
# <a name="errorcode-class"></a>Classe error_code

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
|[clear](#clear)|Limpa o valor do código de erro e a categoria.|
|[default_error_condition](#default_error_condition)|Retorna a condição de erro padrão.|
|[message](#message)|Retorna o nome do código de erro.|

### <a name="operators"></a>Operadores

|||
|-|-|
|[operator==](#op_eq_eq)|Testa a igualdade entre objetos `error_code`.|
|[operator!=](#op_neq)|Testa a desigualdade entre objetos `error_code`.|
|[operator<](#op_lt)|Testa se o objeto `error_code` é menor que o objeto `error_code` passado para comparação.|
|[operator=](#op_eq)|Atribui um novo valor de enumeração ao objeto `error_code`.|
|[operator bool](#op_bool)|Converte uma variável do tipo `error_code`.|

### <a name="assign"></a> Atribuir

Atribui um valor de código de erro e categoria a um código de erro.

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

#### <a name="remarks"></a>Comentários

### <a name="clear"></a> Limpar

Limpa o valor do código de erro e a categoria.

```cpp
clear();
```

#### <a name="remarks"></a>Comentários

A função de membro armazena um valor zero de código de erro e um ponteiro para o objeto [generic_category](../standard-library/system-error-functions.md#generic_category).

### <a name="default_error_condition"></a> default_error_condition

Retorna a condição de erro padrão.

```cpp
error_condition default_error_condition() const;
```

#### <a name="return-value"></a>Valor de retorno

O [error_condition](../standard-library/error-condition-class.md) especificado por [default_error_condition](../standard-library/error-category-class.md#default_error_condition).

#### <a name="remarks"></a>Comentários

Essa função membro retorna `category().default_error_condition(value())`.

### <a name="error_code"></a> error_code

Constrói um objeto do tipo `error_code`.

```cpp
error_code();

error_code(value_type val, const error_category& _Cat);

template <class _Enum>
error_code(_Enum _Errcode,
    typename enable_if<is_error_code_enum<_Enum>::value,
    error_code>::type* = 0);
```

#### <a name="parameters"></a>Parâmetros

*Val*\
O valor de código de erro para armazenar em `error_code`.

*Esteja*\
A categoria de erro para armazenar em `error_code`.

*_Errcode*\
O valor da enumeração para armazenar em `error_code`.

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

Testa a igualdade entre objetos `error_code`.

```cpp
bool operator==(const error_code& right) const;
```

#### <a name="parameters"></a>Parâmetros

*Certo*\
O objeto a ser testado quanto à igualdade.

#### <a name="return-value"></a>Valor de retorno

**true** se os objetos forem iguais; **false** se os objetos não forem iguais.

#### <a name="remarks"></a>Comentários

O operador de membro retorna `category() == right.category() && value == right.value()`.

### <a name="op_neq"></a> operador! =

Testa a desigualdade entre objetos `error_code`.

```cpp
bool operator!=(const error_code& right) const;
```

#### <a name="parameters"></a>Parâmetros

*Certo*\
O objeto a ser testado quanto à desigualdade.

#### <a name="return-value"></a>Valor de retorno

**True** se o `error_code` objeto não é igual ao `error_code` objeto passado *direita*; caso contrário **false**.

#### <a name="remarks"></a>Comentários

O operador de membro retorna `!(*this == right)`.

### <a name="op_lt"></a> Operador&lt;

Testa se o objeto `error_code` é menor que o objeto `error_code` passado para comparação.

```cpp
bool operator<(const error_code& right) const;
```

#### <a name="parameters"></a>Parâmetros

*Certo*\
O objeto error_code a ser comparado.

#### <a name="return-value"></a>Valor de retorno

**true** se o objeto `error_code` for menor que o objeto `error_code` passado para comparação. Caso contrário, **false**.

#### <a name="remarks"></a>Comentários

O operador de membro retorna `category() < right.category() || category() == right.category() && value < right.value()`.

### <a name="op_eq"></a> operador =

Atribui um novo valor de enumeração ao objeto `error_code`.

```cpp
template <class _Enum>
typename enable_if<is_error_code_enum<_Enum>::value, error_code>::type&
    operator=(_Enum _Errcode);
```

#### <a name="parameters"></a>Parâmetros

*_Errcode*\
O valor de enumeração a ser atribuído ao objeto `error_code`.

#### <a name="return-value"></a>Valor de retorno

Uma referência ao objeto `error_code` ao qual está sendo atribuído um novo valor de enumeração pela função de membro.

#### <a name="remarks"></a>Comentários

O operador membro armazena `(value_type)_Errcode` como o valor de código de erro e um ponteiro para [generic_category](../standard-library/system-error-functions.md#generic_category). Ele retorna `*this`.

### <a name="op_bool"></a> operador bool

Converte uma variável do tipo `error_code`.

```cpp
explicit operator bool() const;
```

#### <a name="return-value"></a>Valor de retorno

O valor booliano do objeto `error_code`.

#### <a name="remarks"></a>Comentários

O operador retorna um valor conversível em **verdadeira** somente se [valor](#value) não é igual a zero. O tipo de retorno é conversível apenas em **bool**, não em `void *` ou outros tipos escalares conhecidos.

### <a name="value"></a> Valor

Retorna o valor de código de erro armazenado.

```cpp
value_type value() const;
```

### <a name="return-value"></a>Valor de retorno

O valor do código de erro armazenado do tipo [value_type](#value_type).

### <a name="value_type"></a> value_type

Um tipo que representa o valor do código de erro armazenado.

```cpp
typedef int value_type;
```

#### <a name="remarks"></a>Comentários

Essa definição de tipo é um sinônimo de **int**.
