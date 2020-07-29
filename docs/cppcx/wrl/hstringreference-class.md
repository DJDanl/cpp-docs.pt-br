---
title: Classe HStringReference
ms.date: 07/15/2019
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HStringReference
- corewrappers/Microsoft::WRL::Wrappers::HStringReference::CopyTo
- corewrappers/Microsoft::WRL::Wrappers::HStringReference::Get
- corewrappers/Microsoft::WRL::Wrappers::GetRawBuffer
- corewrappers/Microsoft::WRL::Wrappers::HStringReference::HStringReference
- corewrappers/Microsoft::WRL::Wrappers::HStringReference::operator=
- corewrappers/Microsoft::WRL::Wrappers::HStringReference::operator==
- corewrappers/Microsoft::WRL::Wrappers::HStringReference::operator!=
- corewrappers/Microsoft::WRL::Wrappers::HStringReference::operator<
helpviewer_keywords:
- Microsoft::WRL::Wrappers::HStringReference class
- Microsoft::WRL::Wrappers::HStringReference::CopyTo method
- Microsoft::WRL::Wrappers::HStringReference::Get method
- Microsoft::WRL::Wrappers::HStringReference::HStringReference, constructor
- Microsoft::WRL::Wrappers::HStringReference::operator= operator
- Microsoft::WRL::Wrappers::HStringReference::operator== operator
- Microsoft::WRL::Wrappers::HStringReference::operator!= operator
- Microsoft::WRL::Wrappers::HStringReference::operator< operator
ms.assetid: 9bf823b1-17eb-4ac4-8c5d-27d27c7a4150
ms.openlocfilehash: 871696f4a970b1ef9d1f5d36d2e17184b93c9e8b
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87212976"
---
# <a name="hstringreference-class"></a>Classe HStringReference

Representa um HSTRING que é criado a partir de uma cadeia de caracteres existente.

## <a name="syntax"></a>Sintaxe

```cpp
class HStringReference;
```

## <a name="remarks"></a>Comentários

O tempo de vida do buffer de backup no novo HSTRING não é gerenciado pelo Windows Runtime. O chamador aloca uma cadeia de caracteres de origem no quadro de pilha para evitar uma alocação de heap e para eliminar o risco de um vazamento de memória. Além disso, o chamador deve garantir que a cadeia de caracteres de origem permaneça inalterada durante o tempo de vida do HSTRING anexado. Para obter mais informações, consulte [função WindowsCreateStringReference](/windows/win32/api/winstring/nf-winstring-windowscreatestringreference).

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

Nome                                                    | Descrição
------------------------------------------------------- | -----------------------------------------------------------
[HStringReference::HStringReference](#hstringreference) | Inicializa uma nova instância da classe `HStringReference`.

### <a name="public-methods"></a>Métodos públicos

Membro                              | Descrição
----------------------------------- | ------------------------------------------------------------------
[HStringReference::CopyTo](#copyto) | Copia o `HStringReference` objeto atual para um objeto HSTRING.
[HStringReference:: Get](#get)       | Recupera o valor do identificador HSTRING subjacente.
[HStringReference::GetRawBuffer](#getrawbuffer) | Recupera um ponteiro para os dados de cadeia de caracteres subjacentes.

### <a name="public-operators"></a>Operadores públicos

Nome                                                  | Descrição
----------------------------------------------------- | ----------------------------------------------------------------------------------------------
[HStringReference:: Operator =](#operator-assign)       | Move o valor de outro `HStringReference` objeto para o `HStringReference` objeto atual.
[HStringReference:: Operator = =](#operator-equality)    | Indica se os dois parâmetros são iguais.
[HStringReference:: Operator! =](#operator-inequality)  | Indica se os dois parâmetros não são iguais.
[Operador HStringReference::&lt;](#operator-less-than) | Indica se o primeiro parâmetro é menor que o segundo parâmetro.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`HStringReference`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft:: WRL:: wrappers

## <a name="hstringreferencecopyto"></a><a name="copyto"></a>HStringReference:: CopyTo

Copia o `HStringReference` objeto atual para um objeto HSTRING.

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

## <a name="hstringreferenceget"></a><a name="get"></a>HStringReference:: Get

Recupera o valor do identificador HSTRING subjacente.

```cpp
HSTRING Get() const throw()
```

### <a name="return-value"></a>Valor retornado

O valor do identificador HSTRING subjacente.

## <a name="hstringreferencegetrawbuffer"></a><a name="getrawbuffer"></a>HStringReference::GetRawBuffer

Recupera um ponteiro para os dados de cadeia de caracteres subjacentes.

```cpp
const wchar_t* GetRawBuffer(unsigned int* length) const;
```

### <a name="parameters"></a>parâmetros

*comprimento* Ponteiro para uma **`int`** variável que recebe o comprimento dos dados.

### <a name="return-value"></a>Valor retornado

Um **`const`** ponteiro para os dados de cadeia de caracteres subjacentes.

## <a name="hstringreferencehstringreference"></a><a name="hstringreference"></a>HStringReference::HStringReference

Inicializa uma nova instância da classe `HStringReference`.

```cpp
template<unsigned int sizeDest>
HStringReference(wchar_t const (&str)[ sizeDest]) throw();

template<unsigned int sizeDest>
HStringReference(wchar_t const (&str)[ sizeDest],
                 unsigned int len) throw();

HStringReference(HStringReference&& other) throw();
```

### <a name="parameters"></a>parâmetros

*mais dimensionado*<br/>
Um parâmetro de modelo que especifica o tamanho do buffer de destino `HStringReference` .

*str*<br/>
Uma referência a uma cadeia de caracteres largos.

*Len*<br/>
O comprimento máximo do buffer de parâmetro *Str* a ser usado nesta operação. Se o parâmetro *Len* não for especificado, todo o parâmetro *Str* será usado. Se *Len* for maior do que o mais *dimensionado*, *Len* será definido com o *tamanho*mais 1.

*outros*<br/>
Outro `HStringReference` objeto.

### <a name="remarks"></a>Comentários

O primeiro construtor inicializa um novo `HStringReference` objeto que tem o mesmo tamanho que o parâmetro *Str*.

O segundo construtor inicializa um novo `HStringReference` objeto que o tamanho specifeid pelo parâmetro *Len*.

O terceiro construtor inicializa um novo `HStringReference` objeto para o valor do *outro* parâmetro e, em seguida, destrói o *outro* parâmetro.

## <a name="hstringreferenceoperator"></a><a name="operator-assign"></a>HStringReference:: Operator =

Move o valor de outro `HStringReference` objeto para o `HStringReference` objeto atual.

```cpp
HStringReference& operator=(HStringReference&& other) throw()
```

### <a name="parameters"></a>parâmetros

*outros*<br/>
Um objeto `HStringReference` existente.

### <a name="remarks"></a>Comentários

O valor do *outro* objeto existente é copiado para o `HStringReference` objeto atual e, em seguida, o *outro* objeto é destruído.

## <a name="hstringreferenceoperator"></a><a name="operator-equality"></a>HStringReference:: Operator = =

Indica se os dois parâmetros são iguais.

```cpp
inline bool operator==(
               const HStringReference& lhs,
               const HStringReference& rhs) throw()

inline bool operator==(
               const HSTRING& lhs,
               const HStringReference& rhs) throw()

inline bool operator==(
               const HStringReference& lhs,
               const HSTRING& rhs) throw()
```

### <a name="parameters"></a>parâmetros

*lhs*<br/>
O primeiro parâmetro a ser comparado. o *LHS* pode ser um `HStringReference` objeto ou um identificador HSTRING.

*rhs*<br/>
O segundo parâmetro a ser comparado.  o *RHS* pode ser um `HStringReference` objeto ou um identificador HSTRING.

### <a name="return-value"></a>Valor retornado

**`true`** Se os parâmetros *LHS* e *RHS* forem iguais; caso contrário, **`false`** .

## <a name="hstringreferenceoperator"></a><a name="operator-inequality"></a>HStringReference:: Operator! =

Indica se os dois parâmetros não são iguais.

```cpp
inline bool operator!=(
               const HStringReference& lhs,
               const HStringReference& rhs) throw()

inline bool operator!=(
               const HSTRING& lhs,
               const HStringReference& rhs) throw()

inline bool operator!=(
               const HStringReference& lhs,
               const HSTRING& rhs) throw()
```

### <a name="parameters"></a>parâmetros

*lhs*<br/>
O primeiro parâmetro a ser comparado. o *LHS* pode ser um `HStringReference` objeto ou um identificador HSTRING.

*rhs*<br/>
O segundo parâmetro a ser comparado.  o *RHS* pode ser um `HStringReference` objeto ou um identificador HSTRING.

### <a name="return-value"></a>Valor retornado

**`true`** Se os parâmetros *LHS* e *RHS* não forem iguais; caso contrário, **`false`** .

## <a name="hstringreferenceoperatorlt"></a><a name="operator-less-than"></a>Operador HStringReference::&lt;

Indica se o primeiro parâmetro é menor que o segundo parâmetro.

```cpp
inline bool operator<(
    const HStringReference& lhs,
    const HStringReference& rhs) throw()
```

### <a name="parameters"></a>parâmetros

*lhs*<br/>
O primeiro parâmetro a ser comparado. o *LHS* pode ser uma referência a um `HStringReference` .

*rhs*<br/>
O segundo parâmetro a ser comparado.  o *RHS* pode ser uma referência a um `HStringReference` .

### <a name="return-value"></a>Valor retornado

**`true`** Se o parâmetro *LHS* for menor que o parâmetro *RHS* ; caso contrário, **`false`** .
