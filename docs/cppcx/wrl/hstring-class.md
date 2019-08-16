---
title: Classe HString
ms.date: 07/15/2019
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HString
- corewrappers/Microsoft::WRL::Wrappers::HString::Attach
- corewrappers/Microsoft::WRL::Wrappers::HString::CopyTo
- corewrappers/Microsoft::WRL::Wrappers::HString::Detach
- corewrappers/Microsoft::WRL::Wrappers::HString::Get
- corewrappers/Microsoft::WRL::Wrappers::HString::GetRawBuffer
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
ms.openlocfilehash: 71ebc02dc56b45e8790bfac7b7d4bac80d5f7729
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69500493"
---
# <a name="hstring-class"></a>Classe HString

Uma classe auxiliar para gerenciar o tempo de vida de um [HSTRING](/windows/win32/WinRT/hstring) usando o padrão RAII.

## <a name="syntax"></a>Sintaxe

```cpp
class HString;
```

## <a name="remarks"></a>Comentários

O Windows Runtime fornece acesso a cadeias de caracteres por meio de identificadores [HSTRING](/windows/win32/WinRT/hstring) . A `HString` classe fornece funções e operadores de conveniência para simplificar o uso de identificadores de HSTRING. Essa classe pode manipular o tempo de vida do HSTRING que ele possui por meio de um padrão de RAII.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

Nome                                | Descrição
----------------------------------- | -----------------------------------------------------
[HString::HString](#hstring)        | Inicializa uma nova instância da classe `HString`.
[HString::~HString](#tilde-hstring) | Destrói a instância atual da `HString` classe.

### <a name="public-methods"></a>Métodos públicos

Nome                                     | Descrição
---------------------------------------- | -------------------------------------------------------------------------------------------------------------
[HString::Attach](#attach)               | Associa o objeto `HString` especificado ao objeto atual `HString` .
[HString::CopyTo](#copyto)               | Copia o objeto `HString` atual para um objeto HSTRING.
[HString::Detach](#detach)               | Desassocia o objeto especificado `HString` do seu valor subjacente.
[HString::Get](#get)                     | Recupera o valor do identificador HSTRING subjacente.
[HString::GetAddressOf](#getaddressof)   | Recupera um ponteiro para o identificador HSTRING subjacente.
[HString::GetRawBuffer](#getrawbuffer)   | Recupera um ponteiro para os dados de cadeia de caracteres subjacentes.
[HString::IsValid](#isvalid)             | Indica se o objeto `HString` atual é válido.
[HString::MakeReference](#makereference) | Cria um `HStringReference` objeto a partir de um parâmetro de cadeia de caracteres especificado.
[HString:: versão](#release)             | Exclui o valor de cadeia de caracteres subjacente e `HString` Intializes o objeto atual para um valor vazio.
[HString:: Set](#set)                     | Define o valor do objeto atual `HString` como a cadeia de caracteres largo ou `HString` o parâmetro especificado.

### <a name="public-operators"></a>Operadores públicos

Nome                                         | Descrição
-------------------------------------------- | ----------------------------------------------------------------------------
[HString::operator=](#operator-assign)       | Move o valor de outro `HString` objeto para o objeto `HString` atual.
[HString::operator==](#operator-equality)    | Indica se os dois parâmetros são iguais.
[HString::operator!=](#operator-inequality)  | Indica se os dois parâmetros não são iguais.
[Operador HString::&lt;](#operator-less-than) | Indica se o primeiro parâmetro é menor que o segundo parâmetro.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`HString`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers

## <a name="tilde-hstring"></a>HString::~HString

Destrói a instância atual da `HString` classe.

```cpp
~HString() throw()
```

## <a name="attach"></a>HString:: Attach

Associa o objeto `HString` especificado ao objeto atual `HString` .

```cpp
void Attach(
       HSTRING hstr
       ) throw()
```

### <a name="parameters"></a>Parâmetros

*hstr*<br/>
Um objeto `HString` existente.

## <a name="copyto"></a>HString::CopyTo

Copia o objeto `HString` atual para um objeto HSTRING.

```cpp
HRESULT CopyTo(
   _Out_ HSTRING *str
   ) const throw();
```

### <a name="parameters"></a>Parâmetros

*str*<br/>
O HSTRING que recebe a cópia.

### <a name="remarks"></a>Comentários

Esse método chama a função [WindowsDuplicateString](/windows/win32/api/winstring/nf-winstring-windowsduplicatestring) .

## <a name="detach"></a>HString::Detach

Desassocia o objeto especificado `HString` do seu valor subjacente.

```cpp
HSTRING Detach() throw()
```

### <a name="return-value"></a>Valor de retorno

O valor `HString` subjacente antes da operação de desanexação ser iniciada.

## <a name="get"></a>HString::Get

Recupera o valor do identificador HSTRING subjacente.

```cpp
HSTRING Get() const throw()
```

### <a name="return-value"></a>Valor de retorno

O valor do identificador HSTRING subjacente

## <a name="getaddressof"></a>HString::GetAddressOf

Recupera um ponteiro para o identificador HSTRING subjacente.

```cpp
HSTRING* GetAddressOf() throw()
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o identificador HSTRING subjacente.

### <a name="remarks"></a>Comentários

Após essa operação, o valor da cadeia de caracteres do identificador HSTRING subjacente será destruído.

## <a name="getrawbuffer"></a>HString::GetRawBuffer

Recupera um ponteiro para os dados de cadeia de caracteres subjacentes.

```cpp
const wchar_t* GetRawBuffer(unsigned int* length) const;
```
### <a name="parameters"></a>Parâmetros

*comprimento* Ponteiro para uma variável **int** que recebe o comprimento dos dados.

### <a name="return-value"></a>Valor de retorno

Um ponteiro **const** para os dados de cadeia de caracteres subjacentes.


## <a name="hstring"></a>HString::HString

Inicializa uma nova instância da classe `HString`.

```cpp
HString() throw();
HString(HString&& other) throw();
```

### <a name="parameters"></a>Parâmetros

*hstr*<br/>
Um identificador HSTRING.

*other*<br/>
Um objeto `HString` existente.

### <a name="remarks"></a>Comentários

O primeiro construtor inicializa um novo `HString` objeto que está vazio.

O segundo construtor inicializa um novo `HString` objeto para o valor do *outro* parâmetro existente e, em seguida, destrói o *outro* parâmetro.

## <a name="isvalid"></a>HString::IsValid

Indica se o objeto `HString` atual está vazio ou não.

```cpp
bool IsValid() const throw()
```

### <a name="parameters"></a>Parâmetros

**true** se o objeto `HString` atual não estiver vazio; caso contrário, **false**.

## <a name="makereference"></a>HString::MakeReference

Cria um `HStringReference` objeto a partir de um parâmetro de cadeia de caracteres especificado.

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
Um parâmetro de modelo que especifica o tamanho do buffer `HStringReference` de destino.

*str*<br/>
Uma referência a uma cadeia de caracteres largos.

*len*<br/>
O comprimento máximo do buffer de parâmetro *Str* a ser usado nesta operação. Se o parâmetro *Len* não for especificado, todo o parâmetro *Str* será usado.

### <a name="return-value"></a>Valor de retorno

Um `HStringReference` objeto cujo valor é igual ao parâmetro *Str* especificado.

## <a name="operator-assign"></a>Operador HString:: Operator =

Move o valor de outro `HString` objeto para o objeto `HString` atual.

```cpp
HString& operator=(HString&& other) throw()
```

### <a name="parameters"></a>Parâmetros

*other*<br/>
Um objeto `HString` existente.

### <a name="remarks"></a>Comentários

O valor do *outro* objeto existente é copiado para o objeto `HString` atual e, em seguida, o *outro* objeto é destruído.

## <a name="operator-equality"></a>Operador HString:: Operator = =

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
O primeiro parâmetro a ser comparado. o *LHS* pode ser `HString` um `HStringReference` objeto ou ou um identificador HSTRING.

*rhs*<br/>
O segundo parâmetro a ser comparado. o *RHS* pode ser `HString` um `HStringReference` objeto ou ou um identificador HSTRING.

### <a name="return-value"></a>Valor de retorno

**true** se os parâmetros *LHS* e *RHS* forem iguais; caso contrário, **false**.

## <a name="operator-inequality"></a>Operador HString:: Operator! =

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
O primeiro parâmetro a ser comparado. o *LHS* pode ser `HString` um `HStringReference` objeto ou ou um identificador HSTRING.

*rhs*<br/>
O segundo parâmetro a ser comparado. o *RHS* pode ser `HString` um `HStringReference` objeto ou ou um identificador HSTRING.

### <a name="return-value"></a>Valor de retorno

**true** se os parâmetros *LHS* e *RHS* não forem iguais; caso contrário, **false**.

## <a name="operator-less-than"></a>Operador HString::&lt; Operator

Indica se o primeiro parâmetro é menor que o segundo parâmetro.

```cpp
inline bool operator<(
    const HString& lhs,
    const HString& rhs) throw()
```

### <a name="parameters"></a>Parâmetros

*lhs*<br/>
O primeiro parâmetro a ser comparado. o *LHS* pode ser uma referência a `HString`um.

*rhs*<br/>
O segundo parâmetro a ser comparado. o *RHS* pode ser uma referência a `HString`um.

### <a name="return-value"></a>Valor de retorno

**true** se o parâmetro *LHS* for menor que o parâmetro *RHS* ; caso contrário, **false**.

## <a name="release"></a>HString:: versão

Exclui o valor de cadeia de caracteres subjacente e `HString` Intializes o objeto atual para um valor vazio.

```cpp
void Release() throw()
```

## <a name="set"></a>HString:: Set

Define o valor do objeto atual `HString` como a cadeia de caracteres largo ou `HString` o parâmetro especificado.

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
O comprimento máximo do parâmetro *Str* atribuído ao objeto atual `HString` .

*hstr*<br/>
Um objeto `HString` existente.
