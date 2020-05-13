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
ms.openlocfilehash: fd064f97081fad1a9df9de0865bb7c46ad5b4484
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371418"
---
# <a name="hstringreference-class"></a>Classe HStringReference

Representa um HSTRING que é criado a partir de uma seqüência existente.

## <a name="syntax"></a>Sintaxe

```cpp
class HStringReference;
```

## <a name="remarks"></a>Comentários

A vida útil do buffer de backup no novo HSTRING não é gerenciada pelo Windows Runtime. O chamador aloca uma seqüência de origem no quadro de pilha para evitar uma alocação de pilhas e para eliminar o risco de um vazamento de memória. Além disso, o chamador deve garantir que a seqüência de origem permaneça inalterada durante a vida útil do HSTRING anexado. Para obter mais informações, consulte [a função WindowsCreateStringReference](/windows/win32/api/winstring/nf-winstring-windowscreatestringreference).

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

Nome                                                    | Descrição
------------------------------------------------------- | -----------------------------------------------------------
[HStringReference:HStringReference](#hstringreference) | Inicia uma nova instância da classe `HStringReference`.

### <a name="public-methods"></a>Métodos públicos

Membro                              | Descrição
----------------------------------- | ------------------------------------------------------------------
[HStringReference::CopyTo](#copyto) | Copia o `HStringReference` objeto atual para um objeto HSTRING.
[HStringReference::Get](#get)       | Recupera o valor da alça HSTRING subjacente.
[hstringreference::getrawBuffer](#getrawbuffer) | Recupera um ponteiro para os dados de seqüência subjacentes.

### <a name="public-operators"></a>Operadores públicos

Nome                                                  | Descrição
----------------------------------------------------- | ----------------------------------------------------------------------------------------------
[HStringReference::operador=](#operator-assign)       | Move o valor `HStringReference` de outro `HStringReference` objeto para o objeto atual.
[HStringReference::operator==](#operator-equality)    | Indica se os dois parâmetros são iguais.
[HStringReference::operador!=](#operator-inequality)  | Indica se os dois parâmetros não são iguais.
[HStringReference::operador&lt;](#operator-less-than) | Indica se o primeiro parâmetro é menor que o segundo parâmetro.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`HStringReference`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers.h

**Espaço de nome:** Microsoft::WRL::Wrappers

## <a name="hstringreferencecopyto"></a><a name="copyto"></a>HStringReference::CopyTo

Copia o `HStringReference` objeto atual para um objeto HSTRING.

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

## <a name="hstringreferenceget"></a><a name="get"></a>HStringReference::Get

Recupera o valor da alça HSTRING subjacente.

```cpp
HSTRING Get() const throw()
```

### <a name="return-value"></a>Valor retornado

O valor da alça HSTRING subjacente.

## <a name="hstringreferencegetrawbuffer"></a><a name="getrawbuffer"></a>hstringreference::getrawBuffer

Recupera um ponteiro para os dados de seqüência subjacentes.

```cpp
const wchar_t* GetRawBuffer(unsigned int* length) const;
```

### <a name="parameters"></a>Parâmetros

*comprimento* Ponteiro para uma variável **int** que recebe o comprimento dos dados.

### <a name="return-value"></a>Valor retornado

Um **ponteiro const** para os dados de seqüência subjacentes.

## <a name="hstringreferencehstringreference"></a><a name="hstringreference"></a>HStringReference:HStringReference

Inicia uma nova instância da classe `HStringReference`.

```cpp
template<unsigned int sizeDest>
HStringReference(wchar_t const (&str)[ sizeDest]) throw();

template<unsigned int sizeDest>
HStringReference(wchar_t const (&str)[ sizeDest],
                 unsigned int len) throw();

HStringReference(HStringReference&& other) throw();
```

### <a name="parameters"></a>Parâmetros

*tamanhoDest*<br/>
Um parâmetro de modelo que especifica `HStringReference` o tamanho do buffer de destino.

*Str*<br/>
Uma referência a uma seqüência de caracteres amplos.

*Len*<br/>
O comprimento máximo do tampão de parâmetro *str* para usar nesta operação. Se o parâmetro *len* não for especificado, o parâmetro *de str* inteiro será usado. Se *o len* for maior que o *tamanhoDest,* o *len* é definido como *tamanhoDest*-1.

*Outros*<br/>
Outro `HStringReference` objeto.

### <a name="remarks"></a>Comentários

O primeiro construtor inicializa `HStringReference` um novo objeto do mesmo tamanho que o parâmetro *str*.

O segundo construtor inicia um `HStringReference` novo objeto que o tamanho especifeid por parâmetro *len*.

O terceiro construtor inicializa `HStringReference` um novo objeto ao valor do *outro* parâmetro e, em seguida, destrói o *outro* parâmetro.

## <a name="hstringreferenceoperator"></a><a name="operator-assign"></a>HStringReference::operador=

Move o valor `HStringReference` de outro `HStringReference` objeto para o objeto atual.

```cpp
HStringReference& operator=(HStringReference&& other) throw()
```

### <a name="parameters"></a>Parâmetros

*Outros*<br/>
Um objeto `HStringReference` existente.

### <a name="remarks"></a>Comentários

O valor do *outro* objeto existente é `HStringReference` copiado para o objeto atual e, em seguida, o *outro* objeto é destruído.

## <a name="hstringreferenceoperator"></a><a name="operator-equality"></a>HStringReference::operator==

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

### <a name="parameters"></a>Parâmetros

*Lhs*<br/>
O primeiro parâmetro a ser comparado. *IHs* podem `HStringReference` ser um objeto ou uma alça HSTRING.

*rhs*<br/>
O segundo parâmetro para comparar.  *rhs* pode `HStringReference` ser um objeto ou uma alça HSTRING.

### <a name="return-value"></a>Valor retornado

**verdade** se os *parâmetros lhs* e *rhs* são iguais; caso contrário, **falso**.

## <a name="hstringreferenceoperator"></a><a name="operator-inequality"></a>HStringReference::operador!=

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

### <a name="parameters"></a>Parâmetros

*Lhs*<br/>
O primeiro parâmetro a ser comparado. *IHs* podem `HStringReference` ser um objeto ou uma alça HSTRING.

*rhs*<br/>
O segundo parâmetro para comparar.  *rhs* pode `HStringReference` ser um objeto ou uma alça HSTRING.

### <a name="return-value"></a>Valor retornado

**verdade** se os *parâmetros lhs* e *rhs* não forem iguais; caso contrário, **falso**.

## <a name="hstringreferenceoperatorlt"></a><a name="operator-less-than"></a>HStringReference::operador&lt;

Indica se o primeiro parâmetro é menor que o segundo parâmetro.

```cpp
inline bool operator<(
    const HStringReference& lhs,
    const HStringReference& rhs) throw()
```

### <a name="parameters"></a>Parâmetros

*Lhs*<br/>
O primeiro parâmetro a ser comparado. *LHS* pode ser uma `HStringReference`referência a um .

*rhs*<br/>
O segundo parâmetro para comparar.  *rhs* pode ser uma `HStringReference`referência a um .

### <a name="return-value"></a>Valor retornado

**verdade** se o parâmetro *lhs* é menor do que o parâmetro *rhs;* caso contrário, **falso**.
