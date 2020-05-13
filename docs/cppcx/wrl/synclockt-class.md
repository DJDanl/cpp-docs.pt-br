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
ms.openlocfilehash: 52c4404fa28f680a9a7a4592d03f535e8406d1a4
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81374278"
---
# <a name="synclockt-class"></a>Classe SyncLockT

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template <typename SyncTraits>
class SyncLockT;
```

### <a name="parameters"></a>Parâmetros

*SyncTraits*<br/>
O tipo que pode se apropriar de um recurso.

## <a name="remarks"></a>Comentários

Representa um tipo que pode ter propriedade exclusiva ou compartilhada de um recurso.

A `SyncLockT` classe é usada, por exemplo, para ajudar a implementar a classe [SRWLock.](srwlock-class.md)

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

Nome                                      | Descrição
----------------------------------------- | ----------------------------------------------------
[sincronia::SynclockT](#synclockt)        | Inicia uma nova instância da classe `SyncLockT`.
[Sincronia::~SynclockT](#tilde-synclockt) | Desinicializa uma instância `SyncLockT` da classe.

### <a name="protected-constructors"></a>Construtores Protegidos

Nome                               | Descrição
---------------------------------- | ----------------------------------------------------
[sincronia::SynclockT](#synclockt) | Inicia uma nova instância da classe `SyncLockT`.

### <a name="public-methods"></a>Métodos públicos

Nome                             | Descrição
-------------------------------- | --------------------------------------------------------------------------------------------------------------
[sincronia::islocked](#islocked) | Indica se `SyncLockT` o objeto atual possui um recurso; ou seja, `SyncLockT` o objeto está *bloqueado.*
[SynclockT::Unlock](#unlock)     | Libera o controle do recurso `SyncLockT` mantido pelo objeto atual, se houver.

### <a name="protected-data-members"></a>Membros de Dados Protegidos

Nome                      | Descrição
------------------------- | -------------------------------------------------------------------
[syncLockT::sync_](#sync) | Detém o recurso subjacente `SyncLockT` representado pela classe.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`SyncLockT`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers.h

**Espaço de nome:** Microsoft::WRL::Wrappers::Details

## <a name="synclocktsynclockt"></a><a name="tilde-synclockt"></a>Sincronia::~SynclockT

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
~SyncLockT();
```

### <a name="remarks"></a>Comentários

Desinicializa uma instância `SyncLockT` da classe.

Este destruidor também desbloqueia a `SyncLockT` instância atual.

## <a name="synclocktislocked"></a><a name="islocked"></a>sincronia::islocked

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
bool IsLocked() const;
```

### <a name="return-value"></a>Valor retornado

**verdade** se `SyncLockT` o objeto está bloqueado; caso contrário, **falso**.

### <a name="remarks"></a>Comentários

Indica se `SyncLockT` o objeto atual possui um recurso; ou seja, `SyncLockT` o objeto está *bloqueado.*

## <a name="synclocktsync_"></a><a name="sync"></a>syncLockT::sync_

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
typename SyncTraits::Type sync_;
```

### <a name="remarks"></a>Comentários

Detém o recurso subjacente `SyncLockT` representado pela classe.

## <a name="synclocktsynclockt"></a><a name="synclockt"></a>sincronia::SynclockT

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
SyncLockT(
   _Inout_ SyncLockT&& other
);

explicit SyncLockT(
   typename SyncTraits::Type sync = SyncTraits::GetInvalidValue()
);
```

### <a name="parameters"></a>Parâmetros

*Outros*<br/>
Uma referência de valor `SyncLockT` a outro objeto.

*Sincronização*<br/>
Uma referência `SyncLockWithStatusT` a outro objeto.

### <a name="remarks"></a>Comentários

Inicia uma nova instância da classe `SyncLockT`.

O primeiro construtor inicializa `SyncLockT` o objeto `SyncLockT` atual de outro objeto especificado por parâmetro `SyncLockT` *outro*e, em seguida, invalida o outro objeto. O segundo construtor `protected`é , e `SyncLockT` inicia o objeto atual para um estado inválido.

## <a name="synclocktunlock"></a><a name="unlock"></a>SynclockT::Unlock

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
void Unlock();
```

### <a name="remarks"></a>Comentários

Libera o controle do recurso `SyncLockT` mantido pelo objeto atual, se houver.
