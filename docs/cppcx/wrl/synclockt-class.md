---
title: Classe SyncLockT
ms.date: 10/03/2018
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::Details::SyncLockT
- corewrappers/Microsoft::WRL::Wrappers::Details::SyncLockT::IsLocked
- corewrappers/Microsoft::WRL::Wrappers::Details::SyncLockT::sync_
- corewrappers/Microsoft::WRL::Wrappers::Details::SyncLockT::SyncLockT
- corewrappers/Microsoft::WRL::Wrappers::Details::SyncLockT::~SyncLockT
- corewrappers/Microsoft::WRL::Wrappers::Details::SyncLockT::Unlock
helpviewer_keywords:
- Microsoft::WRL::Wrappers::Details::SyncLockT class
- Microsoft::WRL::Wrappers::Details::SyncLockT::IsLocked method
- Microsoft::WRL::Wrappers::Details::SyncLockT::sync_ data member
- Microsoft::WRL::Wrappers::Details::SyncLockT::SyncLockT, constructor
- Microsoft::WRL::Wrappers::Details::SyncLockT::~SyncLockT, destructor
- Microsoft::WRL::Wrappers::Details::SyncLockT::Unlock method
ms.assetid: a967f6f7-3555-43d1-b210-2bb65d63d15e
ms.openlocfilehash: 6a6e176020624f02e778ba5684a374abfbafa9e4
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87184664"
---
# <a name="synclockt-class"></a>Classe SyncLockT

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template <typename SyncTraits>
class SyncLockT;
```

### <a name="parameters"></a>parâmetros

*SyncTraits*<br/>
O tipo que pode assumir a propriedade de um recurso.

## <a name="remarks"></a>Comentários

Representa um tipo que pode assumir a propriedade exclusiva ou compartilhada de um recurso.

A `SyncLockT` classe é usada, por exemplo, para ajudar a implementar a classe [SRWLock](srwlock-class.md) .

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

Nome                                      | Descrição
----------------------------------------- | ----------------------------------------------------
[SyncLockt:: SyncLockt](#synclockt)        | Inicializa uma nova instância da classe `SyncLockT`.
[SyncLockt:: ~ SyncLockt](#tilde-synclockt) | Desinicializa uma instância da `SyncLockT` classe.

### <a name="protected-constructors"></a>Construtores Protegidos

Nome                               | Descrição
---------------------------------- | ----------------------------------------------------
[SyncLockt:: SyncLockt](#synclockt) | Inicializa uma nova instância da classe `SyncLockT`.

### <a name="public-methods"></a>Métodos públicos

Nome                             | Descrição
-------------------------------- | --------------------------------------------------------------------------------------------------------------
[SyncLockt:: IsLocked](#islocked) | Indica se o `SyncLockT` objeto atual possui um recurso; ou seja, o `SyncLockT` objeto está *bloqueado*.
[SyncLockt:: desbloquear](#unlock)     | Libera o controle do recurso mantido pelo objeto atual `SyncLockT` , se houver.

### <a name="protected-data-members"></a>Membros de Dados Protegidos

Nome                      | Descrição
------------------------- | -------------------------------------------------------------------
[SyncLockt:: sync_](#sync) | Mantém o recurso subjacente representado pela `SyncLockT` classe.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`SyncLockT`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft:: WRL:: wrappers::D etalhes

## <a name="synclocktsynclockt"></a><a name="tilde-synclockt"></a>SyncLockt:: ~ SyncLockt

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
~SyncLockT();
```

### <a name="remarks"></a>Comentários

Desinicializa uma instância da `SyncLockT` classe.

Esse destruidor também desbloqueia a instância atual `SyncLockT` .

## <a name="synclocktislocked"></a><a name="islocked"></a>SyncLockt:: IsLocked

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
bool IsLocked() const;
```

### <a name="return-value"></a>Valor retornado

**`true`** Se o `SyncLockT` objeto estiver bloqueado; caso contrário, **`false`** .

### <a name="remarks"></a>Comentários

Indica se o `SyncLockT` objeto atual possui um recurso; ou seja, o `SyncLockT` objeto está *bloqueado*.

## <a name="synclocktsync_"></a><a name="sync"></a>SyncLockt:: sync_

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
typename SyncTraits::Type sync_;
```

### <a name="remarks"></a>Comentários

Mantém o recurso subjacente representado pela `SyncLockT` classe.

## <a name="synclocktsynclockt"></a><a name="synclockt"></a>SyncLockt:: SyncLockt

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
SyncLockT(
   _Inout_ SyncLockT&& other
);

explicit SyncLockT(
   typename SyncTraits::Type sync = SyncTraits::GetInvalidValue()
);
```

### <a name="parameters"></a>parâmetros

*outros*<br/>
Uma referência de rvalue a outro `SyncLockT` objeto.

*sincronizá*<br/>
Uma referência a outro `SyncLockWithStatusT` objeto.

### <a name="remarks"></a>Comentários

Inicializa uma nova instância da classe `SyncLockT`.

O primeiro construtor inicializa o `SyncLockT` objeto atual de outro `SyncLockT` objeto especificado por *outro*parâmetro e, em seguida, invalida o outro `SyncLockT` objeto. O segundo construtor é **`protected`** e inicializa o objeto atual `SyncLockT` para um estado inválido.

## <a name="synclocktunlock"></a><a name="unlock"></a>SyncLockt:: desbloquear

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
void Unlock();
```

### <a name="remarks"></a>Comentários

Libera o controle do recurso mantido pelo objeto atual `SyncLockT` , se houver.
