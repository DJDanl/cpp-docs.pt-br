---
title: Classe HStringReference
ms.date: 09/25/2018
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HStringReference
- corewrappers/Microsoft::WRL::Wrappers::HStringReference::CopyTo
- corewrappers/Microsoft::WRL::Wrappers::HStringReference::Get
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
ms.openlocfilehash: b9d2e49d0a7e1321e2259c06e1313a90d55dc90e
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58783821"
---
# <a name="hstringreference-class"></a>Classe HStringReference

Representa um HSTRING que é criado a partir de uma cadeia de caracteres existente.

## <a name="syntax"></a>Sintaxe

```cpp
class HStringReference;
```

## <a name="remarks"></a>Comentários

O tempo de vida do buffer de backup no novo HSTRING não é gerenciado pelo tempo de execução do Windows. O chamador aloca uma cadeia de caracteres de origem no quadro da pilha para evitar uma alocação de heap e eliminar o risco de perda de memória. Além disso, o chamador deve garantir que a cadeia de caracteres de origem permaneça inalterada durante a vida útil do HSTRING anexado. Para obter mais informações, consulte [WindowsCreateStringReference função](/windows/desktop/api/winstring/nf-winstring-windowscreatestringreference).

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

Nome                                                    | Descrição
------------------------------------------------------- | -----------------------------------------------------------
[HStringReference::HStringReference](#hstringreference) | Inicializa uma nova instância da classe `HStringReference`.

### <a name="public-methods"></a>Métodos públicos

Membro                              | Descrição
----------------------------------- | ------------------------------------------------------------------
[HStringReference::CopyTo](#copyto) | Copia atual `HStringReference` objeto para um objeto HSTRING.
[HStringReference::Get](#get)       | Recupera o valor do identificador subjacente de HSTRING.

### <a name="public-operators"></a>Operadores públicos

Nome                                                  | Descrição
----------------------------------------------------- | ----------------------------------------------------------------------------------------------
[HStringReference::operator=](#operator-assign)       | Move o valor de outro `HStringReference` o objeto atual `HStringReference` objeto.
[HStringReference::operator==](#operator-equality)    | Indica se os dois parâmetros são iguais.
[HStringReference::operator!=](#operator-inequality)  | Indica se os dois parâmetros não são iguais.
[HStringReference::operator&lt;](#operator-less-than) | Indica se o primeiro parâmetro é menor do que o segundo parâmetro.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`HStringReference`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers

## <a name="copyto"></a>HStringReference::CopyTo

Copia atual `HStringReference` objeto para um objeto HSTRING.

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

## <a name="get"></a>HStringReference::Get

Recupera o valor do identificador subjacente de HSTRING.

```cpp
HSTRING Get() const throw()
```

### <a name="return-value"></a>Valor de retorno

O valor do identificador subjacente de HSTRING.

## <a name="hstringreference"></a>HStringReference::HStringReference

Inicializa uma nova instância da classe `HStringReference`.

```cpp
template<unsigned int sizeDest>
HStringReference(wchar_t const (&str)[ sizeDest]) throw();

template<unsigned int sizeDest>
HStringReference(wchar_t const (&str)[ sizeDest],
                 unsigned int len) throw();

HStringReference(HStringReference&& other) throw();
```

### <a name="parameters"></a>Parâmetros

*sizeDest*<br/>
Um parâmetro de modelo que especifica o tamanho do destino `HStringReference` buffer.

*str*<br/>
Uma referência a uma cadeia de caracteres largos.

*len*<br/>
O comprimento máximo do *str* buffer de parâmetro a ser usado nesta operação. Se o *len* parâmetro não for especificado, todo o *str* parâmetro é usado. Se *len* é maior que *sizeDest*, *len* é definido como *sizeDest*-1.

*other*<br/>
Outro `HStringReference` objeto.

### <a name="remarks"></a>Comentários

O primeiro construtor inicializa uma nova `HStringReference` objeto do mesmo tamanho, como o parâmetro *str*.

O segundo construtor inicializa uma nova `HStringReference` do objeto que o specifeid tamanho pelo parâmetro *len*.

O terceiro construtor inicializa uma nova `HStringReference` objeto para o valor da *outras* parâmetro e, em seguida, destrói o *outros* parâmetro.

## <a name="operator-assign"></a>HStringReference::operator=

Move o valor de outro `HStringReference` o objeto atual `HStringReference` objeto.

```cpp
HStringReference& operator=(HStringReference&& other) throw()
```

### <a name="parameters"></a>Parâmetros

*other*<br/>
Um objeto `HStringReference` existente.

### <a name="remarks"></a>Comentários

O valor de existente *outras* objeto é copiado para a atual `HStringReference` objeto e, em seguida, o *outros* objeto é destruído.

## <a name="operator-equality"></a>HStringReference::operator==

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

*lhs*<br/>
O primeiro parâmetro a ser comparado. *LHS* pode ser um `HStringReference` objeto ou um identificador de HSTRING.

*rhs*<br/>
O segundo parâmetro a ser comparado.  *rhs* pode ser um `HStringReference` objeto ou um identificador de HSTRING.

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se o *lhs* e *rhs* parâmetros forem iguais; caso contrário, **false**.

## <a name="operator-inequality"></a>HStringReference::operator!=

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

*lhs*<br/>
O primeiro parâmetro a ser comparado. *LHS* pode ser um `HStringReference` objeto ou um identificador de HSTRING.

*rhs*<br/>
O segundo parâmetro a ser comparado.  *rhs* pode ser um `HStringReference` objeto ou um identificador de HSTRING.

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se o *lhs* e *rhs* parâmetros não forem iguais; caso contrário, **false**.

## <a name="operator-less-than"></a>HStringReference::operator&lt;

Indica se o primeiro parâmetro é menor do que o segundo parâmetro.

```cpp
inline bool operator<(
    const HStringReference& lhs,
    const HStringReference& rhs) throw()
```

### <a name="parameters"></a>Parâmetros

*lhs*<br/>
O primeiro parâmetro a ser comparado. *LHS* pode ser uma referência a um `HStringReference`.

*rhs*<br/>
O segundo parâmetro a ser comparado.  *rhs* pode ser uma referência a um `HStringReference`.

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se o *lhs* parâmetro é menor do que o *rhs* parâmetro; caso contrário, **false**.
