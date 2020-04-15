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
ms.openlocfilehash: 625d7b7d6fc001a6fb63144807b5f29d3620485b
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371438"
---
# <a name="hstring-class"></a>Classe HString

Uma classe auxiliar para gerenciar a vida útil de um [HSTRING](/windows/win32/WinRT/hstring) usando o padrão RAII.

## <a name="syntax"></a>Sintaxe

```cpp
class HString;
```

## <a name="remarks"></a>Comentários

O Windows Runtime fornece acesso a strings através de alças [HSTRING.](/windows/win32/WinRT/hstring) A `HString` classe fornece funções de conveniência e operadores para simplificar o uso de alças HSTRING. Esta classe pode lidar com a vida útil do HSTRING que possui através de um padrão RAII.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

Nome                                | Descrição
----------------------------------- | -----------------------------------------------------
[HString::HString](#hstring)        | Inicia uma nova instância da classe `HString`.
[HString::~HString](#tilde-hstring) | Destrói a instância atual `HString` da classe.

### <a name="public-methods"></a>Métodos públicos

Nome                                     | Descrição
---------------------------------------- | -------------------------------------------------------------------------------------------------------------
[HString::Attach](#attach)               | Associa o `HString` objeto especificado `HString` com o objeto atual.
[HString::CopyTo](#copyto)               | Copia o `HString` objeto atual para um objeto HSTRING.
[HString::Detach](#detach)               | Desassocia o `HString` objeto especificado de seu valor subjacente.
[HString::Get](#get)                     | Recupera o valor da alça HSTRING subjacente.
[hstring::getAddressOf](#getaddressof)   | Recupera um ponteiro para a alça HSTRING subjacente.
[Hstring::GetRawBuffer](#getrawbuffer)   | Recupera um ponteiro para os dados de seqüência subjacentes.
[Hstring::IsValid](#isvalid)             | Indica se `HString` o objeto atual é válido.
[HString::MakeReference](#makereference) | Cria `HStringReference` um objeto a partir de um parâmetro de string especificado.
[HString::Lançamento](#release)             | Exclui o valor da seqüência de `HString` string subjacente e intializa o objeto atual a um valor vazio.
[HString::Set](#set)                     | Define o valor `HString` do objeto atual para a `HString` seqüência ou parâmetro de caractere amplo especificado.

### <a name="public-operators"></a>Operadores públicos

Nome                                         | Descrição
-------------------------------------------- | ----------------------------------------------------------------------------
[HString::operador=](#operator-assign)       | Move o valor `HString` de outro `HString` objeto para o objeto atual.
[HString::operator==](#operator-equality)    | Indica se os dois parâmetros são iguais.
[HString::operador!=](#operator-inequality)  | Indica se os dois parâmetros não são iguais.
[HString::operador&lt;](#operator-less-than) | Indica se o primeiro parâmetro é menor que o segundo parâmetro.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`HString`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers.h

**Espaço de nome:** Microsoft::WRL::Wrappers

## <a name="hstringhstring"></a><a name="tilde-hstring"></a>HString::~HString

Destrói a instância atual `HString` da classe.

```cpp
~HString() throw()
```

## <a name="hstringattach"></a><a name="attach"></a>HString::Attach

Associa o `HString` objeto especificado `HString` com o objeto atual.

```cpp
void Attach(
       HSTRING hstr
       ) throw()
```

### <a name="parameters"></a>Parâmetros

*hstr*<br/>
Um objeto `HString` existente.

## <a name="hstringcopyto"></a><a name="copyto"></a>Hstring::CopyTo

Copia o `HString` objeto atual para um objeto HSTRING.

```cpp
HRESULT CopyTo(
   _Out_ HSTRING *str
   ) const throw();
```

### <a name="parameters"></a>Parâmetros

*Str*<br/>
O HSTRING que recebe a cópia.

### <a name="remarks"></a>Comentários

Este método chama a função [WindowsDuplicateString.](/windows/win32/api/winstring/nf-winstring-windowsduplicatestring)

## <a name="hstringdetach"></a><a name="detach"></a>HString::Detach

Desassocia o `HString` objeto especificado de seu valor subjacente.

```cpp
HSTRING Detach() throw()
```

### <a name="return-value"></a>Valor retornado

O valor `HString` subjacente antes da operação de desapego começar.

## <a name="hstringget"></a><a name="get"></a>HString::Get

Recupera o valor da alça HSTRING subjacente.

```cpp
HSTRING Get() const throw()
```

### <a name="return-value"></a>Valor retornado

O valor da alça HSTRING subjacente

## <a name="hstringgetaddressof"></a><a name="getaddressof"></a>hstring::getAddressOf

Recupera um ponteiro para a alça HSTRING subjacente.

```cpp
HSTRING* GetAddressOf() throw()
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para a alça HSTRING subjacente.

### <a name="remarks"></a>Comentários

Após esta operação, o valor da corda da alça HSTRING subjacente é destruído.

## <a name="hstringgetrawbuffer"></a><a name="getrawbuffer"></a>Hstring::GetRawBuffer

Recupera um ponteiro para os dados de seqüência subjacentes.

```cpp
const wchar_t* GetRawBuffer(unsigned int* length) const;
```

### <a name="parameters"></a>Parâmetros

*comprimento* Ponteiro para uma variável **int** que recebe o comprimento dos dados.

### <a name="return-value"></a>Valor retornado

Um **ponteiro const** para os dados de seqüência subjacentes.

## <a name="hstringhstring"></a><a name="hstring"></a>HString::HString

Inicia uma nova instância da classe `HString`.

```cpp
HString() throw();
HString(HString&& other) throw();
```

### <a name="parameters"></a>Parâmetros

*hstr*<br/>
Uma alça HSTRING.

*Outros*<br/>
Um objeto `HString` existente.

### <a name="remarks"></a>Comentários

O primeiro construtor inicializa `HString` um novo objeto que está vazio.

O segundo construtor inicializa `HString` um novo objeto ao valor do *outro* parâmetro existente e, em seguida, destrói o *outro* parâmetro.

## <a name="hstringisvalid"></a><a name="isvalid"></a>Hstring::IsValid

Indica se `HString` o objeto atual está vazio ou não.

```cpp
bool IsValid() const throw()
```

### <a name="parameters"></a>Parâmetros

**verdade** se `HString` o objeto atual não estiver vazio; caso contrário, **falso**.

## <a name="hstringmakereference"></a><a name="makereference"></a>HString::MakeReference

Cria `HStringReference` um objeto a partir de um parâmetro de string especificado.

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

*tamanhoDest*<br/>
Um parâmetro de modelo que especifica `HStringReference` o tamanho do buffer de destino.

*Str*<br/>
Uma referência a uma seqüência de caracteres amplos.

*Len*<br/>
O comprimento máximo do tampão de parâmetro *str* para usar nesta operação. Se o parâmetro *len* não for especificado, o parâmetro *de str* inteiro será usado.

### <a name="return-value"></a>Valor retornado

Um `HStringReference` objeto cujo valor é o mesmo do parâmetro *de str* especificado.

## <a name="hstringoperator-operator"></a><a name="operator-assign"></a>HString::operador= Operador

Move o valor `HString` de outro `HString` objeto para o objeto atual.

```cpp
HString& operator=(HString&& other) throw()
```

### <a name="parameters"></a>Parâmetros

*Outros*<br/>
Um objeto `HString` existente.

### <a name="remarks"></a>Comentários

O valor do *outro* objeto existente é `HString` copiado para o objeto atual e, em seguida, o *outro* objeto é destruído.

## <a name="hstringoperator-operator"></a><a name="operator-equality"></a>HString::operator== Operador

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

*Lhs*<br/>
O primeiro parâmetro a ser comparado. *IHs* podem `HString` ser `HStringReference` um ou objeto, ou uma alça HSTRING.

*rhs*<br/>
O segundo parâmetro para comparar. *rhs* pode `HString` ser `HStringReference` um ou objeto, ou uma alça HSTRING.

### <a name="return-value"></a>Valor retornado

**verdade** se os *parâmetros lhs* e *rhs* são iguais; caso contrário, **falso**.

## <a name="hstringoperator-operator"></a><a name="operator-inequality"></a>HString::operador!= Operador

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

*Lhs*<br/>
O primeiro parâmetro a ser comparado. *IHs* podem `HString` ser `HStringReference` um ou objeto, ou uma alça HSTRING.

*rhs*<br/>
O segundo parâmetro para comparar. *rhs* pode `HString` ser `HStringReference` um ou objeto, ou uma alça HSTRING.

### <a name="return-value"></a>Valor retornado

**verdade** se os *parâmetros lhs* e *rhs* não forem iguais; caso contrário, **falso**.

## <a name="hstringoperatorlt-operator"></a><a name="operator-less-than"></a>HString::operador&lt;

Indica se o primeiro parâmetro é menor que o segundo parâmetro.

```cpp
inline bool operator<(
    const HString& lhs,
    const HString& rhs) throw()
```

### <a name="parameters"></a>Parâmetros

*Lhs*<br/>
O primeiro parâmetro a ser comparado. *LHS* pode ser uma `HString`referência a um .

*rhs*<br/>
O segundo parâmetro para comparar. *rhs* pode ser uma `HString`referência a um .

### <a name="return-value"></a>Valor retornado

**verdade** se o parâmetro *lhs* é menor do que o parâmetro *rhs;* caso contrário, **falso**.

## <a name="hstringrelease"></a><a name="release"></a>HString::Lançamento

Exclui o valor da seqüência de `HString` string subjacente e intializa o objeto atual a um valor vazio.

```cpp
void Release() throw()
```

## <a name="hstringset"></a><a name="set"></a>HString::Set

Define o valor `HString` do objeto atual para a `HString` seqüência ou parâmetro de caractere amplo especificado.

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

*Str*<br/>
Uma seqüência de caracteres largos.

*Len*<br/>
O comprimento máximo do parâmetro *str* atribuído ao `HString` objeto atual.

*hstr*<br/>
Um objeto `HString` existente.
