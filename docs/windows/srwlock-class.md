---
title: Classe SRWLock | Microsoft Docs
ms.custom: ''
ms.date: 09/25/2018
ms.technology:
- cpp-windows
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
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 771a375d46177bb3b9d263f0a5221039bb963bc2
ms.sourcegitcommit: 1d9bd38cacbc783fccd3884b7b92062161c91c84
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/03/2018
ms.locfileid: "48233964"
---
# <a name="srwlock-class"></a>Classe SRWLock

Representa um bloqueio de leitor/gravador reduzido.

## <a name="syntax"></a>Sintaxe

```cpp
class SRWLock;
```

## <a name="remarks"></a>Comentários

Um bloqueio de leitor/gravador reduzido é usado para sincronizar o acesso entre threads para um objeto ou recurso. Para obter mais informações, consulte [funções de sincronização](/windows/desktop/Sync/synchronization-functions).

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

Nome                | Descrição
------------------- | -------------------------------------------------------------------
`SyncLockExclusive` | Sinônimo de um `SRWLock` objeto que é adquirido em modo exclusivo.
`SyncLockShared`    | Sinônimo de um `SRWLock` objeto que é adquirido no modo compartilhado.

### <a name="public-constructors"></a>Construtores públicos

Nome                                     | Descrição
---------------------------------------- | --------------------------------------------------
[SRWLOCK:: SRWLOCK](#srwlock-constructor) | Inicializa uma nova instância da classe `SRWLock`.
[SRWLock:: ~ SRWLock](#tilde-srwlock)      | Realiza o desligamento de uma instância da `SRWLock` classe.

### <a name="public-methods"></a>Métodos públicos

Nome                                           | Descrição
---------------------------------------------- | -------------------------------------------------------------------------------------------------------
[SRWLOCK:: Lockexclusive](#lockexclusive)       | Adquire um `SRWLock` objeto no modo exclusivo.
[SRWLOCK:: Lockshared](#lockshared)             | Adquire um `SRWLock` objeto no modo compartilhado.
[SRWLOCK:: Trylockexclusive](#trylockexclusive) | Tenta adquirir um `SRWLock` objeto no modo exclusivo para o atual ou especificada `SRWLock` objeto.
[SRWLOCK:: Trylockshared](#trylockshared)       | Tenta adquirir um `SRWLock` objeto no modo compartilhado para o atual ou especificada `SRWLock` objeto.

### <a name="protected-data-member"></a>Membro de dados protegidos

Nome                                      | Descrição
----------------------------------------- | -----------------------------------------------------------------------
[SRWLock::SRWLock_](#srwlock-data-member) | Contém a variável subjacente de bloqueio atual `SRWLock` objeto.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`SRWLock`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers

## <a name="tilde-srwlock"></a>SRWLock:: ~ SRWLock

Realiza o desligamento de uma instância da `SRWLock` classe.

```cpp
~SRWLock();
```

## <a name="lockexclusive"></a>SRWLOCK:: Lockexclusive

Adquire um `SRWLock` objeto no modo exclusivo.

```cpp
SyncLockExclusive LockExclusive();

static SyncLockExclusive LockExclusive(
   _In_ SRWLOCK* lock
);
```

### <a name="parameters"></a>Parâmetros

*lock*<br/>
Ponteiro para um `SRWLock` objeto.

### <a name="return-value"></a>Valor de retorno

Um `SRWLock` objeto no modo exclusivo.

## <a name="lockshared"></a>SRWLOCK:: Lockshared

Adquire um `SRWLock` objeto no modo compartilhado.

```cpp
SyncLockShared LockShared();

static SyncLockShared LockShared(
   _In_ SRWLOCK* lock
);
```

### <a name="parameters"></a>Parâmetros

*lock*<br/>
Ponteiro para um `SRWLock` objeto.

### <a name="return-value"></a>Valor de retorno

Um `SRWLock` objeto no modo compartilhado.

## <a name="srwlock-constructor"></a>SRWLOCK:: SRWLOCK

Inicializa uma nova instância da classe `SRWLock`.

```cpp
SRWLock();
```

## <a name="srwlock-data-member"></a>SRWLock::SRWLock_

Contém a variável subjacente de bloqueio atual `SRWLock` objeto.

```cpp
SRWLOCK SRWLock_;
```

## <a name="trylockexclusive"></a>SRWLOCK:: Trylockexclusive

Tenta adquirir um `SRWLock` objeto no modo exclusivo para o atual ou especificada `SRWLock` objeto. Se a chamada for bem-sucedida, o thread de chamada assume a propriedade do bloqueio.

```cpp
SyncLockExclusive TryLockExclusive();

static SyncLockExclusive TryLockExclusive(
   _In_ SRWLOCK* lock
);
```

### <a name="parameters"></a>Parâmetros

*lock*<br/>
Ponteiro para um `SRWLock` objeto.

### <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, uma `SRWLock` objeto no modo exclusivo e o thread de chamada assume a propriedade do bloqueio. Caso contrário, um `SRWLock` objeto cujo estado é inválido.

## <a name="trylockshared"></a>SRWLOCK:: Trylockshared

Tenta adquirir um `SRWLock` objeto no modo compartilhado para o atual ou especificada `SRWLock` objeto.

```cpp
WRL_NOTHROW SyncLockShared TryLockShared();
WRL_NOTHROW static SyncLockShared TryLockShared(
   _In_ SRWLOCK* lock
);
```

### <a name="parameters"></a>Parâmetros

*lock*<br/>
Ponteiro para um `SRWLock` objeto.

### <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, uma `SRWLock` objeto no modo compartilhado e o thread de chamada assume a propriedade do bloqueio. Caso contrário, um `SRWLock` objeto cujo estado é inválido.
