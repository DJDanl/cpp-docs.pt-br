---
title: Classe HString
ms.date: 09/24/2018
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HString
- corewrappers/Microsoft::WRL::Wrappers::HString::Attach
- corewrappers/Microsoft::WRL::Wrappers::HString::CopyTo
- corewrappers/Microsoft::WRL::Wrappers::HString::Detach
- corewrappers/Microsoft::WRL::Wrappers::HString::Get
- corewrappers/Microsoft::WRL::Wrappers::HString::GetAddressOf
- corewrappers/Microsoft::WRL::Wrappers::HString::HString
- corewrappers/Microsoft::WRL::Wrappers::HString::IsValid
- corewrappers/Microsoft::WRL::Wrappers::HString::MakeReference
- corewrappers/Microsoft::WRL::Wrappers::HString::operator=
- corewrappers/Microsoft::WRL::Wrappers::HString::operator==
- corewrappers/Microsoft::WRL::Wrappers::HString::operator!=
- corewrappers/Microsoft::WRL::Wrappers::HString::operator<
- corewrappers/Microsoft::WRL::Wrappers::HString::Release
- corewrappers/Microsoft::WRL::Wrappers::HString::Set
- corewrappers/Microsoft::WRL::Wrappers::HString::~HString
helpviewer_keywords:
- Microsoft::WRL::Wrappers::HString class
- Microsoft::WRL::Wrappers::HString::Attach method
- Microsoft::WRL::Wrappers::HString::CopyTo method
- Microsoft::WRL::Wrappers::HString::Detach method
- Microsoft::WRL::Wrappers::HString::Get method
- Microsoft::WRL::Wrappers::HString::GetAddressOf method
- Microsoft::WRL::Wrappers::HString::HString, constructor
- Microsoft::WRL::Wrappers::HString::IsValid method
- Microsoft::WRL::Wrappers::HString::MakeReference method
- Microsoft::WRL::Wrappers::HString::operator= operator
- Microsoft::WRL::Wrappers::HString::operator== operator
- Microsoft::WRL::Wrappers::HString::operator!= operator
- Microsoft::WRL::Wrappers::HString::operator< operator
- Microsoft::WRL::Wrappers::HString::Release method
- Microsoft::WRL::Wrappers::HString::Set method
- Microsoft::WRL::Wrappers::HString::~HString, destructor
ms.assetid: 6709dd2e-8d72-4675-8ec7-1baa7d71854d
ms.openlocfilehash: 19ef11a5d33e69bb77049e450df1b386528b7f7b
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62398284"
---
# <a name="hstring-class"></a>Classe HString

Uma classe auxiliar para gerenciar a vida útil de um [HSTRING](/windows/desktop/WinRT/hstring) usando o padrão RAII.

## <a name="syntax"></a>Sintaxe

```cpp
class HString;
```

## <a name="remarks"></a>Comentários

O tempo de execução do Windows fornece acesso às cadeias de caracteres através de [HSTRING](/windows/desktop/WinRT/hstring) identificadores. O `HString` classe fornece funções de conveniência e operadores para simplificar o uso de identificadores de HSTRING. Essa classe pode manipular o tempo de vida do HSTRING ela detém por meio de um padrão RAII.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

Nome                                | Descrição
----------------------------------- | -----------------------------------------------------
[HString::HString](#hstring)        | Inicializa uma nova instância da classe `HString`.
[HString::~HString](#tilde-hstring) | Destrói a instância atual do `HString` classe.

### <a name="public-methods"></a>Métodos públicos

Nome                                     | Descrição
---------------------------------------- | -------------------------------------------------------------------------------------------------------------
[HString::Attach](#attach)               | Associa a especificada `HString` objeto com o atual `HString` objeto.
[HString::CopyTo](#copyto)               | Copia atual `HString` objeto para um objeto HSTRING.
[HString::Detach](#detach)               | Desassocia especificado `HString` objeto do valor subjacente.
[HString::Get](#get)                     | Recupera o valor do identificador subjacente de HSTRING.
[HString::GetAddressOf](#getaddressof)   | Recupera um ponteiro para o identificador subjacente de HSTRING.
[HString::IsValid](#isvalid)             | Indica se o atual `HString` objeto é válido.
[HString::MakeReference](#makereference) | Cria um `HStringReference` objeto a partir de um parâmetro de cadeia de caracteres especificada.
[HString::Release](#release)             | Exclui o valor de cadeia de caracteres subjacente e inicializa atual `HString` objeto para um valor vazio.
[HString::Set](#set)                     | Define o valor do atual `HString` objeto para a cadeia de caracteres largos especificado ou `HString` parâmetro.

### <a name="public-operators"></a>Operadores públicos

Nome                                         | Descrição
-------------------------------------------- | ----------------------------------------------------------------------------
[HString::operator=](#operator-assign)       | Move o valor de outro `HString` o objeto atual `HString` objeto.
[HString::operator==](#operator-equality)    | Indica se os dois parâmetros são iguais.
[HString::operator!=](#operator-inequality)  | Indica se os dois parâmetros não são iguais.
[HString::operator&lt;](#operator-less-than) | Indica se o primeiro parâmetro é menor do que o segundo parâmetro.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`HString`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers

## <a name="tilde-hstring"></a>HString::~HString

Destrói a instância atual do `HString` classe.

```cpp
~HString() throw()
```

## <a name="attach"></a>HString::Attach

Associa a especificada `HString` objeto com o atual `HString` objeto.

```cpp
void Attach(
       HSTRING hstr
       ) throw()
```

### <a name="parameters"></a>Parâmetros

*hstr*<br/>
Um objeto `HString` existente.

## <a name="copyto"></a>HString::CopyTo

Copia atual `HString` objeto para um objeto HSTRING.

```cpp
HRESULT CopyTo(
   _Out_ HSTRING *str
   ) const throw();
```

### <a name="parameters"></a>Parâmetros

*str*<br/>
O HSTRING que recebe a cópia.

### <a name="remarks"></a>Comentários

Este método chama o [WindowsDuplicateString](/windows/desktop/api/winstring/nf-winstring-windowsduplicatestring) função.

## <a name="detach"></a>HString::Detach

Desassocia especificado `HString` objeto do valor subjacente.

```cpp
HSTRING Detach() throw()
```

### <a name="return-value"></a>Valor de retorno

Subjacente `HString` valor antes da operação de desanexação iniciada.

## <a name="get"></a>HString::Get

Recupera o valor do identificador subjacente de HSTRING.

```cpp
HSTRING Get() const throw()
```

### <a name="return-value"></a>Valor de retorno

O valor do identificador subjacente de HSTRING

## <a name="getaddressof"></a>HString::GetAddressOf

Recupera um ponteiro para o identificador subjacente de HSTRING.

```cpp
HSTRING* GetAddressOf() throw()
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o identificador subjacente de HSTRING.

### <a name="remarks"></a>Comentários

Depois dessa operação, o valor de cadeia de caracteres do identificador subjacente de HSTRING é destruído.

## <a name="hstring"></a>HString::HString

Inicializa uma nova instância da classe `HString`.

```cpp
HString() throw();
HString(HString&& other) throw();
```

### <a name="parameters"></a>Parâmetros

*hstr*<br/>
Um identificador de HSTRING.

*other*<br/>
Um objeto `HString` existente.

### <a name="remarks"></a>Comentários

O primeiro construtor inicializa um novo `HString` objeto que está vazio.

O segundo construtor inicializa uma nova `HString` objeto ao valor existente *outras* parâmetro e, em seguida, destrói o *outros* parâmetro.

## <a name="isvalid"></a>HString::IsValid

Indica se o atual `HString` objeto está vazio ou não.

```cpp
bool IsValid() const throw()
```

### <a name="parameters"></a>Parâmetros

**Verdadeiro** se o atual `HString` objeto não está vazio; caso contrário, **falso**.

## <a name="makereference"></a>HString::MakeReference

Cria um `HStringReference` objeto a partir de um parâmetro de cadeia de caracteres especificada.

```cpp
template<unsigned int sizeDest>
    static HStringReference MakeReference(
              wchar_t const (&str)[ sizeDest]);

    template<unsigned int sizeDest>
    static HStringReference MakeReference(
              wchar_t const (&str)[sizeDest],
              unsigned int len);
```

### <a name="parameters"></a>Parâmetros

*sizeDest*<br/>
Um parâmetro de modelo que especifica o tamanho do destino `HStringReference` buffer.

*str*<br/>
Uma referência a uma cadeia de caracteres largos.

*len*<br/>
O comprimento máximo do *str* buffer de parâmetro a ser usado nesta operação. Se o *len* parâmetro não for especificado, todo o *str* parâmetro é usado.

### <a name="return-value"></a>Valor de retorno

Uma `HStringReference` objeto cujo valor é o mesmo que o especificado *str* parâmetro.

## <a name="operator-assign"></a>Operador hstring:: Operator =

Move o valor de outro `HString` o objeto atual `HString` objeto.

```cpp
HString& operator=(HString&& other) throw()
```

### <a name="parameters"></a>Parâmetros

*other*<br/>
Um objeto `HString` existente.

### <a name="remarks"></a>Comentários

O valor de existente *outras* objeto é copiado para a atual `HString` objeto e, em seguida, o *outros* objeto é destruído.

## <a name="operator-equality"></a>Operador hstring:: Operator = =

Indica se os dois parâmetros são iguais.

```cpp
inline bool operator==(
               const HString& lhs,
               const HString& rhs) throw()

inline bool operator==(
                const HString& lhs,
                const HStringReference& rhs) throw()

inline bool operator==(
                const HStringReference& lhs,
                const HString& rhs) throw()

inline bool operator==(
                 const HSTRING& lhs,
                 const HString& rhs) throw()

inline bool operator==(
                 const HString& lhs,
                 const HSTRING& rhs) throw()
```

### <a name="parameters"></a>Parâmetros

*lhs*<br/>
O primeiro parâmetro a ser comparado. *LHS* pode ser uma `HString` ou `HStringReference` objeto ou um identificador de HSTRING.

*rhs*<br/>
O segundo parâmetro a ser comparado. *rhs* pode ser um `HString` ou `HStringReference` objeto ou um identificador de HSTRING.

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se o *lhs* e *rhs* parâmetros forem iguais; caso contrário, **false**.

## <a name="operator-inequality"></a>Hstring:: Operator! = operador

Indica se os dois parâmetros não são iguais.

```cpp
inline bool operator!=( const HString& lhs,
                        const HString& rhs) throw()

inline bool operator!=( const HStringReference& lhs,
                        const HString& rhs) throw()

inline bool operator!=( const HString& lhs,
                        const HStringReference& rhs) throw()

inline bool operator!=( const HSTRING& lhs,
                        const HString& rhs) throw()

inline bool operator!=( const HString& lhs,
                        const HSTRING& rhs) throw()
```

### <a name="parameters"></a>Parâmetros

*lhs*<br/>
O primeiro parâmetro a ser comparado. *LHS* pode ser uma `HString` ou `HStringReference` objeto ou um identificador de HSTRING.

*rhs*<br/>
O segundo parâmetro a ser comparado. *rhs* pode ser um `HString` ou `HStringReference` objeto ou um identificador de HSTRING.

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se o *lhs* e *rhs* parâmetros não forem iguais; caso contrário, **false**.

## <a name="operator-less-than"></a>Operador hstring::&lt; operador

Indica se o primeiro parâmetro é menor do que o segundo parâmetro.

```cpp
inline bool operator<(
    const HString& lhs,
    const HString& rhs) throw()
```

### <a name="parameters"></a>Parâmetros

*lhs*<br/>
O primeiro parâmetro a ser comparado. *LHS* pode ser uma referência a um `HString`.

*rhs*<br/>
O segundo parâmetro a ser comparado. *rhs* pode ser uma referência a um `HString`.

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se o *lhs* parâmetro é menor do que o *rhs* parâmetro; caso contrário, **false**.

## <a name="release"></a>HString::Release

Exclui o valor de cadeia de caracteres subjacente e inicializa atual `HString` objeto para um valor vazio.

```cpp
void Release() throw()
```

## <a name="set"></a>HString::Set

Define o valor do atual `HString` objeto para a cadeia de caracteres largos especificado ou `HString` parâmetro.

```cpp
HRESULT Set(
          const wchar_t* str) throw();
HRESULT Set(
          const wchar_t* str,
          unsigned int len
           ) throw();
HRESULT Set(
          const HSTRING& hstr
           ) throw();
```

### <a name="parameters"></a>Parâmetros

*str*<br/>
Uma cadeia de caracteres largos.

*len*<br/>
O comprimento máximo do *str* parâmetro que é atribuído ao atual `HString` objeto.

*hstr*<br/>
Um objeto `HString` existente.
