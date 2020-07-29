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
ms.openlocfilehash: 549e3fe2a83bb091bcf90e7957b20c219728bdbc
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87216577"
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
[HString:: HString](#hstring)        | Inicializa uma nova instância da classe `HString`.
[HString:: ~ HString](#tilde-hstring) | Destrói a instância atual da `HString` classe.

### <a name="public-methods"></a>Métodos públicos

Nome                                     | Descrição
---------------------------------------- | -------------------------------------------------------------------------------------------------------------
[HString:: Attach](#attach)               | Associa o `HString` objeto especificado ao objeto atual `HString` .
[HString::CopyTo](#copyto)               | Copia o `HString` objeto atual para um objeto HSTRING.
[HString::D Etach](#detach)               | Desassocia o objeto especificado `HString` do seu valor subjacente.
[HString:: Get](#get)                     | Recupera o valor do identificador HSTRING subjacente.
[HString:: getaddressof](#getaddressof)   | Recupera um ponteiro para o identificador HSTRING subjacente.
[HString:: GetRawBuffer](#getrawbuffer)   | Recupera um ponteiro para os dados de cadeia de caracteres subjacentes.
[HString:: IsValid](#isvalid)             | Indica se o `HString` objeto atual é válido.
[HString:: MakeReference](#makereference) | Cria um `HStringReference` objeto a partir de um parâmetro de cadeia de caracteres especificado.
[HString:: versão](#release)             | Exclui o valor de cadeia de caracteres subjacente e Intializes o `HString` objeto atual para um valor vazio.
[HString:: Set](#set)                     | Define o valor do objeto atual `HString` como a cadeia de caracteres largo ou o `HString` parâmetro especificado.

### <a name="public-operators"></a>Operadores públicos

Nome                                         | Descrição
-------------------------------------------- | ----------------------------------------------------------------------------
[HString:: Operator =](#operator-assign)       | Move o valor de outro `HString` objeto para o `HString` objeto atual.
[HString:: Operator = =](#operator-equality)    | Indica se os dois parâmetros são iguais.
[HString:: Operator! =](#operator-inequality)  | Indica se os dois parâmetros não são iguais.
[Operador HString::&lt;](#operator-less-than) | Indica se o primeiro parâmetro é menor que o segundo parâmetro.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`HString`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft:: WRL:: wrappers

## <a name="hstringhstring"></a><a name="tilde-hstring"></a>HString:: ~ HString

Destrói a instância atual da `HString` classe.

```cpp
~HString() throw()
```

## <a name="hstringattach"></a><a name="attach"></a>HString:: Attach

Associa o `HString` objeto especificado ao objeto atual `HString` .

```cpp
void Attach(
       HSTRING hstr
       ) throw()
```

### <a name="parameters"></a>parâmetros

*hstr*<br/>
Um objeto `HString` existente.

## <a name="hstringcopyto"></a><a name="copyto"></a>HString:: CopyTo

Copia o `HString` objeto atual para um objeto HSTRING.

```cpp
HRESULT CopyTo(
   _Out_ HSTRING *str
   ) const throw();
```

### <a name="parameters"></a>parâmetros

*str*<br/>
O HSTRING que recebe a cópia.

### <a name="remarks"></a>Comentários

Esse método chama a função [WindowsDuplicateString](/windows/win32/api/winstring/nf-winstring-windowsduplicatestring) .

## <a name="hstringdetach"></a><a name="detach"></a>HString::D Etach

Desassocia o objeto especificado `HString` do seu valor subjacente.

```cpp
HSTRING Detach() throw()
```

### <a name="return-value"></a>Valor retornado

O `HString` valor subjacente antes da operação de desanexação ser iniciada.

## <a name="hstringget"></a><a name="get"></a>HString:: Get

Recupera o valor do identificador HSTRING subjacente.

```cpp
HSTRING Get() const throw()
```

### <a name="return-value"></a>Valor retornado

O valor do identificador HSTRING subjacente

## <a name="hstringgetaddressof"></a><a name="getaddressof"></a>HString:: getaddressof

Recupera um ponteiro para o identificador HSTRING subjacente.

```cpp
HSTRING* GetAddressOf() throw()
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o identificador HSTRING subjacente.

### <a name="remarks"></a>Comentários

Após essa operação, o valor da cadeia de caracteres do identificador HSTRING subjacente será destruído.

## <a name="hstringgetrawbuffer"></a><a name="getrawbuffer"></a>HString:: GetRawBuffer

Recupera um ponteiro para os dados de cadeia de caracteres subjacentes.

```cpp
const wchar_t* GetRawBuffer(unsigned int* length) const;
```

### <a name="parameters"></a>parâmetros

*comprimento* Ponteiro para uma **`int`** variável que recebe o comprimento dos dados.

### <a name="return-value"></a>Valor retornado

Um **`const`** ponteiro para os dados de cadeia de caracteres subjacentes.

## <a name="hstringhstring"></a><a name="hstring"></a>HString:: HString

Inicializa uma nova instância da classe `HString`.

```cpp
HString() throw();
HString(HString&& other) throw();
```

### <a name="parameters"></a>parâmetros

*hstr*<br/>
Um identificador HSTRING.

*outros*<br/>
Um objeto `HString` existente.

### <a name="remarks"></a>Comentários

O primeiro construtor inicializa um novo `HString` objeto que está vazio.

O segundo construtor inicializa um novo `HString` objeto para o valor do *outro* parâmetro existente e, em seguida, destrói o *outro* parâmetro.

## <a name="hstringisvalid"></a><a name="isvalid"></a>HString:: IsValid

Indica se o `HString` objeto atual está vazio ou não.

```cpp
bool IsValid() const throw()
```

### <a name="parameters"></a>parâmetros

**`true`** Se o `HString` objeto atual não estiver vazio; caso contrário, **`false`** .

## <a name="hstringmakereference"></a><a name="makereference"></a>HString:: MakeReference

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

### <a name="parameters"></a>parâmetros

*mais dimensionado*<br/>
Um parâmetro de modelo que especifica o tamanho do buffer de destino `HStringReference` .

*str*<br/>
Uma referência a uma cadeia de caracteres largos.

*Len*<br/>
O comprimento máximo do buffer de parâmetro *Str* a ser usado nesta operação. Se o parâmetro *Len* não for especificado, todo o parâmetro *Str* será usado.

### <a name="return-value"></a>Valor retornado

Um `HStringReference` objeto cujo valor é igual ao parâmetro *Str* especificado.

## <a name="hstringoperator-operator"></a><a name="operator-assign"></a>Operador HString:: Operator =

Move o valor de outro `HString` objeto para o `HString` objeto atual.

```cpp
HString& operator=(HString&& other) throw()
```

### <a name="parameters"></a>parâmetros

*outros*<br/>
Um objeto `HString` existente.

### <a name="remarks"></a>Comentários

O valor do *outro* objeto existente é copiado para o `HString` objeto atual e, em seguida, o *outro* objeto é destruído.

## <a name="hstringoperator-operator"></a><a name="operator-equality"></a>Operador HString:: Operator = =

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

### <a name="parameters"></a>parâmetros

*lhs*<br/>
O primeiro parâmetro a ser comparado. o *LHS* pode ser `HString` um `HStringReference` objeto ou ou um identificador HSTRING.

*rhs*<br/>
O segundo parâmetro a ser comparado. o *RHS* pode ser um `HString` objeto ou ou `HStringReference` um identificador HSTRING.

### <a name="return-value"></a>Valor retornado

**`true`** Se os parâmetros *LHS* e *RHS* forem iguais; caso contrário, **`false`** .

## <a name="hstringoperator-operator"></a><a name="operator-inequality"></a>Operador HString:: Operator! =

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

### <a name="parameters"></a>parâmetros

*lhs*<br/>
O primeiro parâmetro a ser comparado. o *LHS* pode ser `HString` um `HStringReference` objeto ou ou um identificador HSTRING.

*rhs*<br/>
O segundo parâmetro a ser comparado. o *RHS* pode ser um `HString` objeto ou ou `HStringReference` um identificador HSTRING.

### <a name="return-value"></a>Valor retornado

**`true`** Se os parâmetros *LHS* e *RHS* não forem iguais; caso contrário, **`false`** .

## <a name="hstringoperatorlt-operator"></a><a name="operator-less-than"></a>Operador HString:: Operator &lt;

Indica se o primeiro parâmetro é menor que o segundo parâmetro.

```cpp
inline bool operator<(
    const HString& lhs,
    const HString& rhs) throw()
```

### <a name="parameters"></a>parâmetros

*lhs*<br/>
O primeiro parâmetro a ser comparado. o *LHS* pode ser uma referência a um `HString` .

*rhs*<br/>
O segundo parâmetro a ser comparado. o *RHS* pode ser uma referência a um `HString` .

### <a name="return-value"></a>Valor retornado

**`true`** Se o parâmetro *LHS* for menor que o parâmetro *RHS* ; caso contrário, **`false`** .

## <a name="hstringrelease"></a><a name="release"></a>HString:: versão

Exclui o valor de cadeia de caracteres subjacente e Intializes o `HString` objeto atual para um valor vazio.

```cpp
void Release() throw()
```

## <a name="hstringset"></a><a name="set"></a>HString:: Set

Define o valor do objeto atual `HString` como a cadeia de caracteres largo ou o `HString` parâmetro especificado.

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

### <a name="parameters"></a>parâmetros

*str*<br/>
Uma cadeia de caracteres largos.

*Len*<br/>
O comprimento máximo do parâmetro *Str* atribuído ao `HString` objeto atual.

*hstr*<br/>
Um objeto `HString` existente.
