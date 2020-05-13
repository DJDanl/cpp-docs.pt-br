---
title: Classe SRWLock
ms.date: 09/25/2018
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::SRWLock
- corewrappers/Microsoft::WRL::Wrappers::SRWLock::LockExclusive
- corewrappers/Microsoft::WRL::Wrappers::SRWLock::LockShared
- corewrappers/Microsoft::WRL::Wrappers::SRWLock::SRWLock
- corewrappers/Microsoft::WRL::Wrappers::SRWLock::SRWLock_
- corewrappers/Microsoft::WRL::Wrappers::SRWLock::~SRWLock
- corewrappers/Microsoft::WRL::Wrappers::SRWLock::TryLockExclusive
- corewrappers/Microsoft::WRL::Wrappers::SRWLock::TryLockShared
helpviewer_keywords:
- Microsoft::WRL::Wrappers::SRWLock class
- Microsoft::WRL::Wrappers::SRWLock::LockExclusive method
- Microsoft::WRL::Wrappers::SRWLock::LockShared method
- Microsoft::WRL::Wrappers::SRWLock::SRWLock, constructor
- Microsoft::WRL::Wrappers::SRWLock::SRWLock_ data member
- Microsoft::WRL::Wrappers::SRWLock::~SRWLock, destructor
- Microsoft::WRL::Wrappers::SRWLock::TryLockExclusive method
- Microsoft::WRL::Wrappers::SRWLock::TryLockShared method
ms.assetid: 4fa250e3-5f29-4b06-ac24-61b6c04ade93
ms.openlocfilehash: e305ad54e30455ce7c25f356c454791da0783591
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81377272"
---
# <a name="srwlock-class"></a>Classe SRWLock

Representa um bloqueio de leitor/escritor fino.

## <a name="syntax"></a>Sintaxe

```cpp
class SRWLock;
```

## <a name="remarks"></a>Comentários

Um bloqueio slim reader/writer é usado para sincronizar o acesso entre segmentos a um objeto ou recurso. Para obter mais informações, consulte [Funções de sincronização](/windows/win32/Sync/synchronization-functions).

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

Nome                | Descrição
------------------- | -------------------------------------------------------------------
`SyncLockExclusive` | Sinônimo de `SRWLock` um objeto que é adquirido no modo exclusivo.
`SyncLockShared`    | Sinônimo de `SRWLock` um objeto que é adquirido no modo compartilhado.

### <a name="public-constructors"></a>Construtores públicos

Nome                                     | Descrição
---------------------------------------- | --------------------------------------------------
[SRWLock::SRWLock](#srwlock-constructor) | Inicia uma nova instância da classe `SRWLock`.
[SRWLock::~SRWLock](#tilde-srwlock)      | Desinicializa uma instância `SRWLock` da classe.

### <a name="public-methods"></a>Métodos públicos

Nome                                           | Descrição
---------------------------------------------- | -------------------------------------------------------------------------------------------------------
[SRWLock::LockExclusive](#lockexclusive)       | Adquire um `SRWLock` objeto no modo exclusivo.
[SRWLock::LockShared](#lockshared)             | Adquire um `SRWLock` objeto no modo compartilhado.
[SRWLock::TrylockExclusive](#trylockexclusive) | Tentativas de `SRWLock` adquirir um objeto no modo `SRWLock` exclusivo para o objeto atual ou especificado.
[SRWLock::TryLockShared](#trylockshared)       | Tentativas de `SRWLock` adquirir um objeto no modo compartilhado `SRWLock` para o objeto atual ou especificado.

### <a name="protected-data-member"></a>Membro de dados protegidos

Nome                                      | Descrição
----------------------------------------- | -----------------------------------------------------------------------
[SRWLock::SRWLock_](#srwlock-data-member) | Contém a variável de bloqueio `SRWLock` subjacente para o objeto atual.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`SRWLock`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers.h

**Espaço de nome:** Microsoft::WRL::Wrappers

## <a name="srwlocksrwlock"></a><a name="tilde-srwlock"></a>SRWLock::~SRWLock

Desinicializa uma instância `SRWLock` da classe.

```cpp
~SRWLock();
```

## <a name="srwlocklockexclusive"></a><a name="lockexclusive"></a>SRWLock::LockExclusive

Adquire um `SRWLock` objeto no modo exclusivo.

```cpp
SyncLockExclusive LockExclusive();

static SyncLockExclusive LockExclusive(
   _In_ SRWLOCK* lock
);
```

### <a name="parameters"></a>Parâmetros

*Bloqueio*<br/>
Ponteiro para `SRWLock` um objeto.

### <a name="return-value"></a>Valor retornado

Um `SRWLock` objeto em modo exclusivo.

## <a name="srwlocklockshared"></a><a name="lockshared"></a>SRWLock::LockShared

Adquire um `SRWLock` objeto no modo compartilhado.

```cpp
SyncLockShared LockShared();

static SyncLockShared LockShared(
   _In_ SRWLOCK* lock
);
```

### <a name="parameters"></a>Parâmetros

*Bloqueio*<br/>
Ponteiro para `SRWLock` um objeto.

### <a name="return-value"></a>Valor retornado

Um `SRWLock` objeto no modo compartilhado.

## <a name="srwlocksrwlock"></a><a name="srwlock-constructor"></a>SRWLock::SRWLock

Inicia uma nova instância da classe `SRWLock`.

```cpp
SRWLock();
```

## <a name="srwlocksrwlock_"></a><a name="srwlock-data-member"></a>SRWLock::SRWLock_

Contém a variável de bloqueio `SRWLock` subjacente para o objeto atual.

```cpp
SRWLOCK SRWLock_;
```

## <a name="srwlocktrylockexclusive"></a><a name="trylockexclusive"></a>SRWLock::TrylockExclusive

Tentativas de `SRWLock` adquirir um objeto no modo `SRWLock` exclusivo para o objeto atual ou especificado. Se a chamada for bem sucedida, o segmento de chamada toma posse da fechadura.

```cpp
SyncLockExclusive TryLockExclusive();

static SyncLockExclusive TryLockExclusive(
   _In_ SRWLOCK* lock
);
```

### <a name="parameters"></a>Parâmetros

*Bloqueio*<br/>
Ponteiro para `SRWLock` um objeto.

### <a name="return-value"></a>Valor retornado

Se for `SRWLock` bem-sucedido, um objeto no modo exclusivo e o segmento de chamada toma posse do bloqueio. Caso contrário, `SRWLock` um objeto cujo estado é inválido.

## <a name="srwlocktrylockshared"></a><a name="trylockshared"></a>SRWLock::TryLockShared

Tentativas de `SRWLock` adquirir um objeto no modo compartilhado `SRWLock` para o objeto atual ou especificado.

```cpp
WRL_NOTHROW SyncLockShared TryLockShared();
WRL_NOTHROW static SyncLockShared TryLockShared(
   _In_ SRWLOCK* lock
);
```

### <a name="parameters"></a>Parâmetros

*Bloqueio*<br/>
Ponteiro para `SRWLock` um objeto.

### <a name="return-value"></a>Valor retornado

Se for `SRWLock` bem-sucedido, um objeto no modo compartilhado e o segmento de chamada assumem a propriedade do bloqueio. Caso contrário, `SRWLock` um objeto cujo estado é inválido.
